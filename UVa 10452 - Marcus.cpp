// C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <unordered_map>

int i, j;

// word {row, column}
std::unordered_map<char, std::pair<int, int>> word_pos
{
    {'@',{0, 0}},
    {'I',{0, 0}},
    {'E',{0, 0}},
    {'H',{0, 0}},
    {'O',{0, 0}},
    {'V',{0, 0}},
    {'A',{0, 0}},
    {'#',{0, 0}},
};

void check_god_word(const char& word, const int& i, const int& j)
{
    switch(word)
    {
        case('@'):
        case('I'):
        case('E'):
        case('H'):
        case('O'):
        case('V'):
        case('A'):
        case('#'):
        {
            // save pos to word_pos  {row, column}
            word_pos[word] = {i, j};
            break;
        }
    }
}

// word1 -> word2
// word {row, column}
std::string find_direction(const std::pair<int, int>& word1, const std::pair<int, int>& word2)
{
    int row_delta = word2.first - word1.first;
    int column_delta = word2.second - word1.second;

    // word1 - word2
    if (row_delta == 0 && column_delta == 1)
        return "right";

    // word2 - word1
    if (row_delta == 0 && column_delta == -1)
        return "left";

    // word2
    //   |
    // word1
    if (row_delta == -1 && column_delta == 0)
        return "forth";

    return "";
}

std::string res;

void find_path()
{
    // @ -> I
    res += find_direction(word_pos['@'], word_pos['I']) + ' ';

    // I -> E
    res += find_direction(word_pos['I'], word_pos['E']) + ' ';

    // E -> H
    res += find_direction(word_pos['E'], word_pos['H']) + ' ';

    // H -> O
    res += find_direction(word_pos['H'], word_pos['O']) + ' ';

    // O -> V
    res += find_direction(word_pos['O'], word_pos['V']) + ' ';

    // V -> A
    res += find_direction(word_pos['V'], word_pos['A']) + ' ';

    // A -> #
    res += find_direction(word_pos['A'], word_pos['#']);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, row, column;
    std::cin >> n;

    std::string str_row;

    while (n--)
    {
        std::cin >> row >> column;

        // iterate through every line
        for(i=0; i<row; ++i)
        {
            std::cin >> str_row;

            for(j=0; j<column; ++j)
            {
                check_god_word(str_row[j], i, j);
            }
        }

        // find path
        find_path();
        std::cout << res << '\n';

        res = ""; // reset result
    }
}
