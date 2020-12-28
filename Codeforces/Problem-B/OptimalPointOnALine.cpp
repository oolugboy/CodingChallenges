#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int coods[n];

    for(int i = 0; i < n; i++)
    {
        cin >> coods[i];
    }

    sort(coods, coods + n);

    cout << coods[(n - 1)/2] << endl;
}
