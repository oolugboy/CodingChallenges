#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cycle_diff(int l, int r)
{
    return (122 + (l - 96) - r);
}

int main()
{
    int t = 0;
    cin >> t;

    while(t--)
    {
        int l = 0, p = 0, pos = 0;
        cin >> l >> p;

        pos = min(p - 1, (l - 1) - (p - 1));

        string s;
        cin >> s;

        short trans[(l/2)];
        int totalTrans = 0;
        int ml = -1, mr = -1;

        for(int i = 0; i < (l/2); i++)
        {
            int r = ((l - 1) - i);
            int currTrans = 0;
            if((int)s[r] > (int)s[i])
            {
                currTrans = min((int)s[r] - (int)s[i], cycle_diff((int)s[i], (int)s[r]));
            }
            else
            {
                currTrans = min((int)s[i] - (int)s[r], cycle_diff((int)s[r], (int)s[i]));
            }

            if(currTrans != 0)
            {
                if(ml == -1)
                {
                    ml = i;
                }
                else
                {
                    mr = i;
                }
            }
            
            totalTrans += currTrans;
        }

        if(mr == -1)
        {
            if(ml == -1)
            {
                ml = mr = 0;
            }
            else
            {
                mr = ml;
            }
        }

        int totalMoves = 0;
        int moveRange = (mr - ml);

        //cout << "Pos: " << pos << " mr " << mr << " ml " << ml << endl;
        
        if(ml > pos)
        {
            totalMoves = (ml - pos) + moveRange;    
        }
        else if(mr < p)
        {
            totalMoves = moveRange + (pos - mr);
        }
        else
        {
            totalMoves = min((mr - pos) + moveRange, ((pos - ml) + moveRange));
        }
        
        //cout << "Moves: " << totalMoves << " TotalTrans: " << totalTrans << endl;
        cout << (totalTrans + totalMoves) << endl;
    }
}
