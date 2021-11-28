// C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>

int image[30][30];
int visited[30][30];
int n;

bool is_valid_position(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

void dfs(int i, int j)
{
    if (visited[i][j] == true)
        return;
    else
        visited[i][j] = true;

    // check all neighbours(8 direction)
    // if any of them is 1
    // dfs it :)

    // ^ top
    if (is_valid_position(i + 1, j) && image[i + 1][j] == 1)
        dfs(i + 1, j);

    // /^ top right
    if (is_valid_position(i + 1, j + 1) && image[i + 1][j + 1] == 1)
        dfs(i + 1, j + 1);

    // ^\ top left
    if (is_valid_position(i + 1, j - 1) && image[i + 1][j - 1] == 1)
        dfs(i + 1, j - 1);

    // > right
    if (is_valid_position(i, j + 1) && image[i][j + 1] == 1)
        dfs(i, j + 1);

    // < left
    if (is_valid_position(i, j - 1) && image[i][j - 1] == 1)
        dfs(i, j - 1);

    // v bottom
    if (is_valid_position(i - 1, j) && image[i - 1][j] == 1)
        dfs(i - 1, j);

    // \v bottom right
    if (is_valid_position(i - 1, j + 1) && image[i - 1][j + 1] == 1)
        dfs(i - 1, j + 1);

    // v/ bottom left
    if (is_valid_position(i - 1, j - 1) && image[i - 1][j - 1] == 1)
        dfs(i - 1, j - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string row;
    int counter, index = 0;

    while (std::cin >> n)
    {
        ++index;

        // reset visited array
        memset(visited, 0, sizeof(visited));

        counter = 0;

        // input image
        for (int i = 0; i < n; ++i)
        {
            std::cin >> row;

            for (int j = 0; j < n; ++j)
            {
                image[i][j] = row[j] - 48;
            }
        }

        // iterating through all pos
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (image[i][j] == 1 && visited[i][j] == false)
                {
                    dfs(i, j);
                    ++counter;
                }
            }
        }

        std::cout << "Image number " << index << " contains " << counter << " war eagles." << '\n';
    }
}
