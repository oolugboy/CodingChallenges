#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

long long int h;
int n;

long long int ceilDivide(long long int dividend, long long int divisor)
{
    long long int quot = abs(dividend) / abs(divisor);
    long long int modQuot = abs(dividend) % abs(divisor);

    if(modQuot > 0)
    {
        quot += 1;
    }

    return quot;
}

long long int getMaxFullRounds(long long int currSum, long long int roundSum)
{
    long long int rounds = ceilDivide((-1 * h) + abs(currSum), roundSum);
    return rounds;
}

long long int getFullRoundNeededRes(long long int * sums, long long int roundSum)
{
    long long int minRounds = numeric_limits<long long int>::max();
    int minRoundInd = 0;
    for(int i = 0; i < n; i++)
    {
        if(sums[i] < 0)
        {
            long long int currRounds = getMaxFullRounds(sums[i], roundSum);
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
    cin >> h >> n;

    int d[n];
    long long int sums[n];
    bool fullRoundNeeded = true;

    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    long long int roundSum = 0;
    int nonFullRoundNeededRes = 0;

    for(int i = 0; i < n; i++)
    {
        roundSum += d[i];
        sums[i] = roundSum;
        if(sums[i] <= (-1 * h))
        {
            fullRoundNeeded = false;
            nonFullRoundNeededRes = (i + 1);
            break;
        }
    }

    if(!fullRoundNeeded)
    {
        cout << nonFullRoundNeededRes << endl;
    }
    else
    {
        if(roundSum >= 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << getFullRoundNeededRes(sums, roundSum) << endl;
        }
    }
}
