#include <iostream>

int main()
{
    int color = 91;
    for (;;)
    {
        std::cout << "\e[" << color << "m" << "hello, world" << "\e[0" << "m" << "\r" << std::flush;
        color = (color > 96) ? 91 : color + 1;

        for (int i = 0; i < 100000000; i++) {};
    }
    return 0;
}
