#include <iostream>
#include <cstdlib>

int main() {
    int nums[10];
    int a, b, t;
    int size = 10;

    for (t = 0; t < size; t++) {
        nums[t] = rand() % 40;
    }

    std::cout << "Исходный массив: ";
    for (t = 0; t < size; t++) {
        std::cout << nums[t] << ' ';
    }
    std::cout << "\n";

    for (a = 0; a < size; a++) {
        for (b = 0; b < size - 1; b++) {
            if (nums[b] > nums[b + 1]) {
                t = nums[b];
                nums[b] = nums[b + 1];
                nums[b + 1] = t;
            }
        }
    }
    std::cout << "Отсортированный массив: ";
    for (t = 0; t < size; t++) {
        std::cout << nums[t] << ' ';
    }
    return 0;
}
