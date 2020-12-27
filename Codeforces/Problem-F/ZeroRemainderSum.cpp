#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int INF = 1000000000;

int mod(int a, int m)
{
    if(a >= 0)
    {
        int ans = a % m;
        return ans;
    }
    else
    {
        int ans = a - (m * -1 * ceil(abs(a) / float(m)));
        return ans;
    }
}

int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    int a[n + 1][m + 1];

    for (int i = 1; i < (n + 1); i ++)
    {
        for (int j = 1; j < (m + 1); j++)
        {
            cin >> a[i][j];            
        }
    }
    int max_count = (m / 2);
    int dp[n + 1][m + 1][max_count + 1][k];
  
    for (int x = 1; x < (n + 1); x++)
    {
        for(int y = 0; y < (m + 1); y++)
        {
            for(int rem = 0; rem < k; rem++)
            {
                if (x == 1)
                {
                    if(rem == 0)
                    {
                        dp[x][y][0][rem] = 0;
                    }
                    else
                    {
                        dp[x][y][0][rem] = -1 * INF;
                    }
                }
                else
                {
                    dp[x][y][0][rem] = dp[x - 1][m][max_count][rem];
                }
            }
        }
        for (int cnt = 1; cnt < (max_count + 1); cnt++)
        {
            for(int rem = 0; rem < k; rem++)
            {
                dp[x][0][cnt][rem] = dp[x][0][0][rem];
            }
        }
        for(int y = 1; y < (m + 1); y++)
        {
            for(int cnt = 1; cnt < (max_count + 1); cnt++)
            {
                for(int rem = 0; rem < k; rem++)
                {
                    dp[x][y][cnt][rem] = max(dp[x][y - 1][cnt][rem], a[x][y] + dp[x][y - 1][cnt - 1][mod(rem - a[x][y], k)]);
                }
            }
        }
    }

    cout << dp[n][m][max_count][0] << endl;
}
