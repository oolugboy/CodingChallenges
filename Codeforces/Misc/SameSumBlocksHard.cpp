#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<int> suffixSets[n];

    for(int i = 0; i < n; i++)
    {
        int currSum = 0;
        for(int j = i; j < n; j++)
        {
            currSum += a[j];
            suffixSets[i].insert(currSum);
        }
    }
    
    vector< pair<int, int> > indices;
    int maxCount = 0;
    for(int i = 0; i < n; i++)
    {
        int currSum = 0;
        for(int j = i; j < n; j++)
        {
            currSum += j[i];
            int k = (i + j + 1);
            while(suffixSets[k].find(currSum) != suffixSets[k].end())
            {
                indices.push_back(make_pair((
            }
        }
    }

}
