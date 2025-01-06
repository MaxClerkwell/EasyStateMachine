#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "pound_engine.hpp"


namespace EasyStateMachine {

    struct Engine {
    private:
        enum State {
            Idle,
            DotHandler,
            PoundHandler,
            Exit
        };

        State currentState_;
        int dotCounts_      = 80;
        int poundCounts_    = 80;
        int dotWaitTime_    = 10;
        int poundWaitTime_  = 20;

        State handleDot() {
            std::cout << "Dot Handler Active: ";
            for (int i = 0; i < dotCounts_; ++i) {
                std::cout << '.';
                std::this_thread::sleep_for(std::chrono::milliseconds(dotWaitTime_));
            }
            std::cout << "\n" << "Returning to Idle..." << std::endl;
            return Idle;
        }

        
        State handlePound() {
            PoundEngine engine;
            while (engine.run() != PoundEngine::SubExit) {
                // Stay in sub-state machine
            }

            std::cout << "\nReturning to Idle...\n";
            return Idle;
        }

        char menu() {
            system("clear");
            std::cout << "Idle Menu:\n";
            std::cout << "Enter '.' to switch to Dot Handler.\n";
            std::cout << "Enter '#' to switch to Pound Handler.\n";
            std::cout << "Enter 'e' to Exit.\n";
            std::cout << "Your choice: ";
            
            char input;
            std::cin >> input;
            return input;
        }

        State runIdle() {
            char userInput = menu();
            if (userInput == '.') {
                return DotHandler;
            } else if (userInput == '#') {
                return PoundHandler;
            } else if (userInput == 'e') {
                return Exit;
            } else {
                std::cout << "Invalid input, please try again.\n";
                return Idle;
            }
        }

    public:
        int exec() {
            while (currentState_ != Exit) {
                switch (currentState_) {
                case Idle:
                    currentState_ = runIdle();
                    break;
                case DotHandler:
                    currentState_ = handleDot();
                    break;
                case PoundHandler:
                    currentState_ = handlePound();
                    break;
                case Exit:
                    std::cout << "Exiting program. Goodbye!\n";
                    break;
                }
            }
            system("clear");
            return 0;
        }

        Engine() : currentState_(Idle) {}
    };
}

int main() {
    EasyStateMachine::Engine UserInterface;
    return UserInterface.exec();
}
