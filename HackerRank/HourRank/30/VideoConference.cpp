#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n = 0; 
    cin >> n;
    
    unordered_map<string, int> aliasPrefixMap;

    while(n--)
    {
        string s = "";
        cin >> s;
    
        string resultAlias = "";
        for(int i = 1; i <= s.length(); i++)
        {
            string testPrefix = s.substr(0, i);

            if(aliasPrefixMap.find(testPrefix) == aliasPrefixMap.end())
            {
                aliasPrefixMap.insert(make_pair(testPrefix, 1));
                if(resultAlias.length() == 0)
                {
                    resultAlias = testPrefix; 
                }
            }
            else
            {
                if(i == s.length() && resultAlias.length() == 0)
                {
                    aliasPrefixMap[s]++;
                    resultAlias = s + " " + to_string(aliasPrefixMap[s]);
                }
            }
        }

        cout << resultAlias << endl;
    }
}
