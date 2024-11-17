#include <iostream>
#include <vector>
#include <algorithm>

void proces(int x) {
    std::cout << x << '\n';
}

int main() {

    std::vector<int> A;

    for (int i = 0; i < 10; i++) {
        A.push_back(i);
    }

    // НЕУКЛЮЖАЯ ВЕРСИЯ
    std::cout << "Iterator1:\n";
    std::vector<int>::iterator it1 = A.begin();
    while (it1 != A.end()) {
        std::cout << "Iterator1: " << *it1 << "\n";
        it1++;
    }

    // почти НЕУКЛЮЖАЯ ВЕРСИЯ
    std::cout << "Iterator2:\n";
    auto it2 = A.begin();
    while (it2 != A.end()) {
        std::cout << "Iterator2: " << *it2 << "\n";
        it2++;
    }

    for (auto it3 = A.begin(); it3 != A.end(); it3++) {
        std::cout << "Iterator3: " << *it3 << "\n";
    }

    std::cout << "for_each:\n";
    std::for_each(A.begin(), A.end(), proces);

    for (auto x: A) {
        std::cout << x << ' ';
    }
}
