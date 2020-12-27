#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while(t--)
    {
        int n = 0;
        cin >> n;

        int a[n];
        int max_a = -1;
        int min_a = 1000000001;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            max_a = max(a[i], max_a);
            min_a = min(a[i], min_a);
        }

        if(max_a != min_a)
        {
            for(int i = 0; i < n; i++)
            {
                bool is_pot_dominant = true;
                if(a[i] == max_a)
                {
                    if(i == 0 && i != (n - 1))
                    {
                        if(a[i + 1] == a[i])
                        {
                            is_pot_dominant = false;
                        }
                    }
                    if(i == (n - 1) && i != 0)
                    {
                        if(a[i - 1] == a[i])
                        {
                            is_pot_dominant = false;
                        }
                    }
                    if(i != 0 && i != (n - 1))
                    {
                        if(a[i - 1] == a[i] && a[i + 1] == a[i])
                        {
                            is_pot_dominant = false;
                        }
                    }
                    if(is_pot_dominant)
                    {
                        cout << (i + 1) << endl;
                        break;
                    }
                }
                else
                {
                    is_pot_dominant = false;
                }
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}


