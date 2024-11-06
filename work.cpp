#include <cstdio>
#include <chrono>
#include <thread>
#include <cstring>

const char *colors[] {
    "\033[31m",
};

const char *reset = "\033[0m";

struct TimerClass {
    std::chrono::steady_clock::time_point timestamp;
    //Default constructor
    TimerClass() {
       timestamp = std::chrono::steady_clock::now();
       printf("Created object TimerClass\n");
    }
    //Copy Destructor
    TimerClass(const TimerClass& other) {
        timestamp = other.timestamp;
        printf("The copy constructor is called\n");
    }
    //Operator assignment operator
    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            timestamp = other.timestamp;
            printf("The copy assignment operator is called:\n");
        }
        return *this;
    }

    //Destructor
    ~TimerClass() {
        auto end_line = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_line - timestamp).count();
        printf("%s Time live object %ld milliseconds%s\n", colors[0], duration, reset);
    }
};

int main() {
    TimerClass timer1;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    TimerClass timer2 = timer1;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    TimerClass timer3;
    timer3 = timer1;
    return 0;
}
