#include <iostream>
#include <unordered_map>
#include <string>
#include <tuple>

using namespace std;

char generate_needed_letter(char a, char b)
{
    if(a != b)
    {
        tuple<char, char> a_b_tuple = make_tuple(a, b);

        if(a_b_tuple == make_tuple('S', 'E') || a_b_tuple == make_tuple('E', 'S'))
        {
            return 'T';
        }
        else if (a_b_tuple == make_tuple('S', 'T') || a_b_tuple == make_tuple('T', 'S'))
        {
            return 'E';
        }
        else
        {
            return 'S';
        }
    }
    else
    {
        return a;
    }
}

string generate_needed_hand(string hand1, string hand2, int k)
{
    string needed_hand = "";
    for(int i = 0; i < k; i++)
    {
        needed_hand += generate_needed_letter(hand1[i], hand2[i]); 
    }
    return needed_hand;
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;

    string hands[n];
    unordered_map<string, int> hands_map;
    for(int i = 0; i < n; i++)
    {
        string input_hand;
        cin >> input_hand;
        hands[i] = input_hand;
        hands_map[input_hand] = i;
    }
    long long int result = 0;
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = (i + 1); j < n; j++)
        {
            string needed_hand = generate_needed_hand(hands[i], hands[j], k);
            if(hands_map.find(needed_hand) != hands_map.end())
            {
                if(hands_map[needed_hand] > j)
                {
                    result++;
                }
            }
        }
    }
    cout << result << endl;
}
