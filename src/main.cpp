#include <iostream>
#include <string>
#include <thread>
#include <chrono>


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
            std::cout << "Pound Handler Active: ";
            for (int i = 0; i < poundCounts_; ++i) {
                std::cout << '#' << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(poundWaitTime_)); 
            }
            std::cout << "\n" << "Returning to Idle..." << std::endl;
            return Idle;
        }

        State runIdle() {
            char userInput;

            std::cout << "\nIdle Menu:\n";
            std::cout << "Enter '.' to switch to Dot Handler.\n";
            std::cout << "Enter '#' to switch to Pound Handler.\n";
            std::cout << "Enter 'e' to Exit.\n";
            std::cout << "Your choice: ";
            std::cin >> userInput;

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
            return 0;
        }

        Engine() : currentState_(Idle) {}
    };
}

int main() {
    EasyStateMachine::Engine UserInterface;
    return UserInterface.exec();
}
