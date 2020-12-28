#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int fact[n + 1];
    int modder = 998244353;

    for(int i = 0; i < (n + 1); i++)
    {
        if(i == 0)
        {
            fact[i] = 1;
        }
        else
        {
            fact[i] = ((long long int)i * fact[i - 1]) % modder;
        }
    }

    int nonCrossTotal = fact[n];

    int crossTotal = 0;

    int possAgg = 1;

    for(int i = (n - 1); i >= 2; i--)
    {
        possAgg = ((long long int)possAgg * (i + 1)) % modder;
        int locCrossTotal = ((long long int)possAgg * (fact[i] - 1)) % modder;
        crossTotal = ((long long int)crossTotal + locCrossTotal) % modder;
    }

    int result = (crossTotal + nonCrossTotal) % modder;
    cout << result << endl;

    return 0;
}
