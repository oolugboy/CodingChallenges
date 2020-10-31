#include <iostream>
#include <string>

using namespace std;

pair<string, string> getOperands(string orig)
{
    string a, b;
    for(int i = orig.length() - 1; i >= 0; i--)
    {
        if(orig[i] == '4')
        {
            a = '3' + a;
            b = '1' + b;
        }
        else
        {
            a = orig[i] + a;
            b = '0' + b;
        }
    }
    return make_pair(a, b);
}

int main()
{
    int testInd = 0;
    int t = 0;

    cin >> t;

    while(testInd < t)
    {
        string orig;
        cin >> orig;

        pair<string, string> res = getOperands(orig);
        
        cout << "Case #" << (testInd + 1) << ": " << res.first << " " << res.second << endl;
        testInd++;
    }

}
