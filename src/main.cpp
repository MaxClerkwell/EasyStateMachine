#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Enum for the states
enum State {
    Idle,
    DotHandler,
    PoundHandler,
    Exit
};

// Function prototypes
void handleDot();
void handlePound();

int main() {
    State currentState = Idle;
    char userInput;

    while (currentState != Exit) {
        switch (currentState) {
            case Idle:
                std::cout << "\nIdle Menu:\n";
                std::cout << "Enter '.' to switch to Dot Handler.\n";
                std::cout << "Enter '#' to switch to Pound Handler.\n";
                std::cout << "Enter 'e' to Exit.\n";
                std::cout << "Your choice: ";
                std::cin >> userInput;

                if (userInput == '.') {
                    currentState = DotHandler;
                } else if (userInput == '#') {
                    currentState = PoundHandler;
                } else if (userInput == 'e') {
                    currentState = Exit;
                } else {
                    std::cout << "Invalid input, please try again.\n";
                }
                break;

            case DotHandler:
                handleDot();
                currentState = Idle;
                break;

            case PoundHandler:
                handlePound();
                currentState = Idle;
                break;

            case Exit:
                std::cout << "Exiting program. Goodbye!\n";
                break;
        }
    }

    return 0;
}

void handleDot() {
    std::cout << "Dot Handler Active: ";
    for (int i = 0; i < 80; ++i) {
        std::cout << '.';
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // wait for 10ms
    }
    std::cout << "\nReturning to Idle...\n";
}

void handlePound() {
    std::cout << "Pound Handler Active: ";
    for (int i = 0; i < 80; ++i) {
        std::cout << '#' << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // wait for 20ms
    }
    std::cout << "\nReturning to Idle...\n";
}
