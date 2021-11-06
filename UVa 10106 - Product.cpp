// C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
  
    std::string s1, s2, res;
    int s1_len, s2_len, a[600], tmp, n, carry = 0;

    while (std::cin >> s1)
    {
        std::cin >> s2;

        if (s1 == "0" || s2 == "0")
        {
            std::cout << "0\n";
            continue;
        }

        s1_len = s1.length();
        s2_len = s2.length();

        memset(a, 0, sizeof(a));

        for (int i = s2_len - 1; i >= 0; --i)
        {
            tmp = s2[i] - '0';

            for (int j = s1_len - 1; j >= 0; --j)
            {

                a[i + j] += tmp * (s1[j] - '0');
            }
        }

        n = s1_len + s2_len - 1;

        for (int i = n - 1; i >= 0; --i)
        {
            tmp = a[i] % 10 + carry;
        
            carry = a[i] / 10 + tmp / 10;

            if (tmp > 9)
            {
                res += tmp % 10 + '0';
            }
            else
            {
                res += tmp + '0';
            }
        }

        if (carry)
        {
            res += carry + '0';
            carry = 0;
        }

        std::reverse(res.begin(), res.end());

        std::cout << res << '\n';

        res.clear();
    }
}

