#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   string s;
   cin >> s;

    int singles_count[26] = {0};
    long long int doubles_count[26][26] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        int c = (int)s[i] - (int)'a';
        for(int x = 0; x < 26; x++)
        {
            doubles_count[x][c] += singles_count[x];
        }
        singles_count[c]++;
    }

    long long int result = 0;

    for(int i = 0; i < 26; i++)
    {
        result = max(result, (long long int)singles_count[i]);
    }

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            result = max(result, doubles_count[i][j]);
        }
    }

    cout << result << endl;
}
