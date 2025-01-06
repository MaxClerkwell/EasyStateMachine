#ifndef POUND_ENGINE_H
#define POUND_ENGINE_H

#include <iostream>
#include <thread>


namespace EasyStateMachine {

    class PoundEngine {
    private:
        int count_ = 20; // Initial count of #
        int waitTime_ = 5;

    public:
        enum SubState {
            SubIdle,
            SubExit
        };

        SubState run() {
            char input;
            system("clear");
            std::cout << "Pound Engine Active. Current count: " << count_ << "\n";
            for (int i = 0; i < count_; ++i) {
                std::cout << '#' << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(waitTime_));
            }
            std::cout << std::endl;
            std::cout << "Enter '+' to increment, '-' to decrement, or 'g' to go back: ";
            std::cin >> input;

            if (input == '+') {
                count_ += 10;
                if (count_ > 80) {
                    std::cout << "too many #\n";
                    count_ = 80;
                }
            } else if (input == '-') {
                count_ -= 10;
                if (count_ < 0) {
                    std::cout << "too few #\n";
                    count_ = 0;
                }
            } else if (input == 'g') {
                return SubExit;
            } else {
                std::cout << "Invalid input.\n";
            }

            return SubIdle;
        }
    };

} // namespace EasyStateMachine

#endif // POUND_ENGINE_H
