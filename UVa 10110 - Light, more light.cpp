// C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long walk;
    double sqrt;

    std::cin >> walk;

    do
    {
        sqrt = std::sqrt(walk);

        if ( std::floor(sqrt) - sqrt == 0 )
            std::cout << "yes\n";
        else
            std::cout << "no\n";

        std::cin >> walk;
    }
    while (walk != 0);
}