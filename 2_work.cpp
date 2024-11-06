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
    char name[10];
    std::chrono::steady_clock::time_point timestamp;
    //Default constructor
    TimerClass(const char* name) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        timestamp = std::chrono::steady_clock::now();
        printf("Created TimerClass with name: %s\n", this->name);
    }
    //Copy Destructor
    TimerClass(const TimerClass& other) : timestamp(std::chrono::steady_clock::now()) {
        strncpy(this->name, other.name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        printf("The coppy constructor is called for Timer: %s\n", this->name);
    }

    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            timestamp = std::chrono::steady_clock::now();
            strncpy(this->name, other.name, sizeof(this->name) - 1);
            this->name[sizeof(this->name) - 1] = '\0';
            printf("The copy assignment is called for Timer: %s\n", this->name);
        }
        return *this;
    }
    //Operator assignment operator
    TimerClass(TimerClass&& other) noexcept : timestamp(other.timestamp) {
        strncpy(this->name, other.name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        other.timestamp = std::chrono::steady_clock::time_point();
        printf("The move constructor has been called for Timer: %s\n", this->name);
    }
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this != &other) {
            timestamp = std::chrono::steady_clock::now();
            strncpy(this->name, other.name, sizeof(this->name) - 1);
            this->name[sizeof(this->name) - 1] = '\0';
            printf("The assignment operator is called for Timer: %s\n", this->name);
        }
        return *this;
    }
    //Destructor
    ~TimerClass() {
        if (timestamp.time_since_epoch().count() != 0) {
            auto end_line = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_line - timestamp).count();
            printf("%s Timer %s live object %ld milliseconds%s\n", colors[0], this->name, duration, reset);
        }
    }
};

int main() {
    TimerClass timer1("Timer1");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    TimerClass timer2 = std::move(timer1);

    TimerClass timer3("Timer3");
    timer3 = std::move(timer2);

    return 0;
}
