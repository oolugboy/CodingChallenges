#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

long long int ceilDivide(long long int dividend, long long int divisor)
{
    int error = abs(3);
    long long int quot = abs(dividend) / abs(divisor);
    long long int modQuot = abs(dividend) % abs(divisor);

    if(modQuot > 0)
    {
        quot += 1;
    }
    return quot;
}

long long int getMaxFullRounds(long long int h, long long int currSum, long long int roundSum)
{
    long long int rounds = ceilDivide((-1 * h) + abs(currSum), roundSum);
    return rounds;
}

long long int getFullRoundNeededRes(long long int h, long long int * sums, long long int roundSum, int n)
{
    long long int minRounds = numeric_limits<long long int>::max();
    int minRoundInd = 0;
    for(int i = 0; i < n; i++)
    {
        if(sums[i] < 0)
        {
            long long int currRounds = getMaxFullRounds(h, sums[i], roundSum);
            if(currRounds < minRounds)
            {
                minRounds = currRounds;
                minRoundInd = i;
            }
        } 
    }

    return (minRounds * n) + (minRoundInd + 1); 
}

int main()
{
    long long int h;
    int n;
    int d[n];
    long long int sums[n];
    bool fullRoundNeeded = true;

    cin >> h >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    long long int roundSum = 0;

    long long int nonFullRoundNeededRes = 0;
    for(int i = 0; i < n; i++)
    {
        roundSum += d[i];
        sums[i] = roundSum;
        if(sums[i] < (-1 * h))
        {
            fullRoundNeeded = false;
            nonFullRoundNeededRes = sums[i];
        } 
    }

    if(roundSum >= 0)
    {
        cout << -1 << endl;
    }
    else
    {
        if(!fullRoundNeeded)
        {
            cout << nonFullRoundNeededRes << endl;
        }
        else
        {
            cout << getFullRoundNeededRes(h, sums, roundSum, n) << endl;    
        }
    }
}
