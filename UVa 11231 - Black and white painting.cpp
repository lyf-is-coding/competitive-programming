// C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, c;

    while(std::cin >> n >> m >> c && n != 0)
    {
        int carry = c == 1 ? 1 : 0;
        std::cout << ((n-7)*(m-7) + c) / 2 << '\n';
    }
}
