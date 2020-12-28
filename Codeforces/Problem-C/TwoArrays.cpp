#include <iostream>

using namespace std;

int main()
{
    int modder = 1000000000 + 7;
    int n = 0, m = 0;
    cin >> n >> m;

    int amount[m + 2][n + 1] = { 0 };

    for(int pos = 1; pos < (m + 1); pos++)
    {
        for(int i = 1; i < (n + 1); i++)
        {
            if(pos == 1)
            {
                amount[pos][i] = 1 + amount[pos][i - 1];
            }
            else
            {
                int prev_amount = 0;
                if(i > 1)
                {
                    prev_amount = amount[pos][i - 1];
                }
                amount[pos][i] = (prev_amount + amount[pos - 1][i]) % modder;
            }
        }
    }

    
    /**for(int i = 1; i < (n + 1); i++)
    {
        for(int pos = 1; pos < (m + 2); pos++)
        {
            cout << amount[pos][i] << "  ";
        }
        cout << endl;
    } **/

    int prev_agg = 0;
    int total_matches = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        int local_amount = 0;
        if(i == 1)
        {
            local_amount = amount[m][i]; 
        }
        else
        {
            if(amount[m][i] < amount[m][i - 1])
            {
                local_amount = ((modder - amount[m][i - 1]) + amount[m][i]) % modder;
            }
            else
            {
                local_amount = (amount[m][i] - amount[m][i - 1]);
            }
        }

        //cout << "The local amount is " << local_amount << endl;

        int local_matches = ((long long int)local_amount * (long long int)amount[m][(n + 1) - i]) % (long long int)modder;

        //cout << " The local matches are " << local_matches << endl;

        total_matches = (total_matches + local_matches) % modder;
    }

    cout << total_matches << endl;
}
