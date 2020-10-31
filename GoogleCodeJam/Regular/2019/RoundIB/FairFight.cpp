#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>


using namespace std;

long long int sum(int val)
{
    return ((long long int)val * (val + 1))/2;
}

int main()
{
    int T = 0;
    cin >> T;

    int caseNo = 0;

    while(T--)
    {
        caseNo++;
        int N = 0, K = 0;
        cin >> N >> K;

        int C[N];
        for(int i = 0; i < N; i++)
        {
            cin >> C[i];
        }

        int D[N];
        for(int i = 0; i < N; i++)
        {
            cin >> D[i];
        }

        bool fair[N];
        int fairAmount = 0;
        vector<int> fairIndices;
        for(int i = 0; i < N; i++)
        {
            if(abs(C[i] - D[i]) <= K)
            {
                fair[i] = true;
                fairAmount++;
                fairIndices.push_back(i);
            }
        }
        
        long long int res = 0;

        for(int amountInc = 1; amountInc < (fairAmount + 1); amountInc++)
        {   
            cout << "The amount included are " << amountInc << endl;
            int runAm = ceil((double)fairAmount/amountInc);
            int prevL = fairIndices[0];
            for(int run = 0; run < runAm; run++)
            {
                int l = prevL;
                int r = prevL + (amountInc - 1);
                int rangeOff = r - l;
                int remaining = fairAmount - amountInc;
                
                int leftRemaining = amountInc - 1;
                int rightRemaining = fairAmount - amountInc;
                int usedN = min(l - 0, (N - 1) - r);
                int maxSym = usedN + 1;
                int all = sum(maxSym) + sum(maxSym - 1) + N - (maxSym + maxSym - 1);

                res += (all - rangeOff - remaining);
                
                prevL = l;
            }
        }
        cout << "Case #" << caseNo << ": " << res << endl;
    }
}
