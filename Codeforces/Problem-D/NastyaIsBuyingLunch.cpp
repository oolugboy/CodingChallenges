#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int index[300001]

void sortFunc(int p1, int p2)
{
    return index[p1] > index[p2];
}
struct Person
{
    Person(int val): num(val)
    {
    }
    int num;
    vector<int>swap;
}
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    Person people[n];

    for(int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;
        people[i] = Person(val);
        index[val] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int u = 0, v = 0;
        cin >> u >> v;

        people[index[u]].swap.push_back(v);
    }

    for(int i = 0; i < n; i++)
    {
        if(people[i].swap.size() > 0)
        {
           sort(swap.begin(), swap.end(), sortFunc); 
        }
    }

    int moves = 0;
    for(int i = (n - 2); i >= 0; i--)
    {
        int twosInd = people[i].swap.size() - 1;

        if(twosInd > 0)
        {
            if(people[i].swap[twosInd] == people[n - 1])
            {

            }
        }
    }
}

