#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int S_MAX_LENGTH = 200001;
int occurs[200001] = { 0 };

bool can(int val, int k)
{
    int columns = 0;
    for(int i = 1; i < S_MAX_LENGTH; i++)
    {
        columns += occurs[i]/val;

        if(columns >= k)
        {
            return true;    
        }
    }
    return false;
}

pair<bool, int> getMaxVal(int leftInd, int rightInd, int k)
{
    if(rightInd == leftInd)
    {
        return make_pair(true, rightInd);
    }

    int midInd = leftInd + ((rightInd - leftInd)/2);

    if(can(midInd, k))
    {
        if(can(midInd + 1, k))
        {
            return getMaxVal(midInd + 1, rightInd, k);
        }
        else
        {
            return make_pair(true, midInd);
        }
    }
    else
    {
        return getMaxVal(leftInd, midInd - 1, k);
    }
}

void printResultArr(int maxVal, int k)
{
    int printed = 0; 
    for(int i = 1; i < S_MAX_LENGTH; i++)
    {
        for(int j = 0; j < occurs[i]/maxVal; j++)
        {
            cout << i << " ";
            printed++;
            if(printed == k)
            {
                cout << endl;
                return;
            }
        }
    }
}

int main()
{
    int n = 0, k = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;

        occurs[val]++;
    }
    
    int maxVal = getMaxVal(1, n, k).second;
    printResultArr(maxVal, k); 
}
