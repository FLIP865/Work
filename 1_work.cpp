#include <cstdio>
#include <chrono>
#include <ratio>
#include <thread>
#include <utility>
#include <cstring>

const char *colors[] {
    "\033[31m",
};

const char *reset = "\033[0m";

struct TimerClass {
    std::chrono::steady_clock::time_point timestamp;
    //Default constructor
    TimerClass() : timestamp(std::chrono::steady_clock::now()) {
       printf("Created object TimerClass\n");
    }
    //Copy Destructor
    TimerClass(const TimerClass& other) : timestamp(std::chrono::steady_clock::now()) {
        printf("The copy constructor is called\n");
    }

    TimerClass& operator=(const TimerClass& other) {
        timestamp = std::chrono::steady_clock::now();
        printf("The copy assignment is called:\n");
        return *this;
    }
    //Operator assignment operator
    TimerClass(TimerClass&& other) noexcept : timestamp(other.timestamp) {
        other.timestamp = std::chrono::steady_clock::time_point();
        printf("The move constructor has been called\n");
    }
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this != &other) {
            timestamp = other.timestamp;
            other.timestamp = std::chrono::steady_clock::time_point();
            printf("The assignment operator is called:\n");
        }
        return *this;
    }
    //Destructor
    ~TimerClass() {
        if (timestamp.time_since_epoch().count() != 0) {
            auto end_line = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_line - timestamp).count();
            printf("%s Timer live object %ld milliseconds%s\n", colors[0], duration, reset);
        }
    }
};

int main() {
    TimerClass timer1;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    TimerClass timer2 = std::move(timer1);

    TimerClass timer3;
    timer3 = std::move(timer2);

    return 0;
}
