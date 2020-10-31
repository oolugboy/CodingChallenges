#include <iostream>
#include <string>

using namespace std;

string getResPath(string path)
{
    string res = "";

    for(int i = 0; i < path.length(); i++)
    {
        if(path[i] == 'S')
        {
            res += 'E';
        }
        else
        {
            res += 'S';
        }    
    }

    return res;
}

int main()
{
    int t = 0, testInd = 0;
    
    cin >> t;
    while(testInd < t)
    {
        testInd++;
        int n = 0;
        cin >> n;

        string path;
        cin >> path;

        cout << "Case #" << testInd << ": " << getResPath(path) << endl;
    }
}
