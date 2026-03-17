#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>

class MotorStatus {
private:
    uint8_t motorState;
    uint8_t overheatingMotors = 0;
    int turnCount;

    void initialize() {
        std::srand(static_cast<unsigned int>(time(0)));
        do {
            motorState = static_cast<uint8_t>(std::rand() % 256);
        } while (motorState == 0);
        turnCount = 0;
        updateOverheating();
    }

    void updateOverheating() {
        if ((motorState & static_cast<uint8_t>(~overheatingMotors)) == 0) {
            turnCount++;
            return;
        }
        else {
            int newMotor = 0;
            do {
                newMotor = std::rand() % 8;
            } while (((static_cast<uint8_t>(1u << newMotor) & motorState) == 0) ||
                ((static_cast<uint8_t>(1u << newMotor) & overheatingMotors) != 0));

            overheatingMotors |= static_cast<uint8_t>(1u << newMotor);
            turnCount++;
        }
    }

public:
    MotorStatus() {
        initialize();
    }

    void displayStatus() {
        std::cout << "\n-----------------------------" << std::endl;
        std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) << std::endl;
        std::cout << "Overheating Motors:   " << std::bitset<8>(overheatingMotors) << std::endl;
        std::cout << "Turn Count:           " << turnCount << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    // PART A: Logic to turn off motors
    bool turnOff(uint8_t guess) {
        // Identify motors that are BOTH overheating AND in the user's guess
        uint8_t toFix = guess & overheatingMotors;

        // Turn OFF those specific motors in the state
        // Logic: motorState = motorState AND (NOT toFix)
        motorState &= ~toFix;

        // Save original overheating state to verify the guess
        uint8_t target = overheatingMotors;

        // Remove the fixed motors from the overheating list
        overheatingMotors &= ~toFix;

        if (guess == target && target != 0) {
            std::cout << "\n>>> SUCCESS: All overheating motors neutralized! <<<" << std::endl;
            return true;
        }
        else {
            std::cout << "\n>>> ALERT: Incorrect guess. The heat is spreading! <<<" << std::endl;
            updateOverheating();
            return false;
        }
    }
};

// Helper to handle Binary and Hex strings
int checkInput(const std::string& s)
{
    int value = 0;
    if (s.size() == 8 && s.find_first_not_of("01") == std::string::npos) {
        for (char c : s) {
            value = (value << 1) | (c - '0');
        }
        return value;
    }
    else if (s.size() >= 3 && (s.substr(0, 2) == "0x" || s.substr(0, 2) == "0X")) {
        try {
            unsigned long temp = std::stoul(s, nullptr, 16);
            if (temp <= 255) return static_cast<int>(temp);
        }
        catch (...) {}
    }
    return -1;
}

// PART B: Improved Main Game Loop

int main()
{
    MotorStatus motorGame;
    std::string input;

    std::cout << "=== MOTOR MELTDOWN ACTIVATED ===" << std::endl;

    while (true)
    {
        // 1. Show the current situation
        motorGame.displayStatus();

        // 2. Get user input
        std::cout << "\nEnter guess (e.g., 00001111 or 0x0F) or 'q' to quit: ";
        if (!(std::cin >> input) || input == "q" || input == "Q") {
            std::cout << "Manual override. Exiting..." << std::endl;
            break;
        }

        // 3. Process the input
        int parsedValue = checkInput(input);
        if (parsedValue == -1) {
            // checkInput already prints an error message, restart loop
            continue;
        }

        // 4. Update game state and check for win
        uint8_t guess = static_cast<uint8_t>(parsedValue);
        if (motorGame.turnOff(guess))
        {
            std::cout << "\n>>> ALL SYSTEMS STABILIZED. YOU WIN! <<<" << std::endl;
            break;
        }
        else
        {
            std::cout << "\n>>> TRY AGAIN. THE HEAT IS SPREADING! <<<" << std::endl;
        }
    }

    return 0;
}

