// C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

#include <bits/stdc++.h>

void inline print(int& step, int& mod, bool& bad)
{
    std::cout << std::setw(10) << step << std::setw(10) << mod << "    ";

    if (bad)
            std::cout << "Bad Choice\n\n";
        else
            std::cout << "Good Choice\n\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int step, mod;
    std::unordered_map<int, int> appear_count;

    while(std::cin >> step >> mod)
    {
        if (step == -1)
        {
            std::cout << std::endl;
            break;
        }

        int appear_count[mod-1];
        memset(appear_count, 0, sizeof(appear_count)+4);
        bool bad = false;
        int num = 0;

        while(true)
        {
            num = (num + step)%mod;

            ++appear_count[num];

            // appear 2nd time. -> new cycle
            if (appear_count[num] == 2)
            {
                for (int i=0; i < mod; ++i)
                {
                    if (appear_count[i] == 0)
                    {
                        bad = true;
                        break;
                    }
                }

                break;
            }
        }

        print(step, mod, bad);
    }
}

