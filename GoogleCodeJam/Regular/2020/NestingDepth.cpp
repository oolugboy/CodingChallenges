#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string get_next_string(int * vals, int * remnants, int n, int curr_ind)
{
    if(curr_ind == n)
    {
        return "";
    }
    string opening_brackets = "";
    for(int i = 0; i < remnants[curr_ind]; i++)
    {
        opening_brackets += "(";
    }
    int bottle_neck = 11;
    for(int i = curr_ind; i < n; i++)
    {
        bottle_neck = min(bottle_neck, remnants[i]);
    }
    for(int i = (curr_ind + 1); i < n; i++)
    {
        remnants[i] -= bottle_neck;
    }

    string local_closing_brackets = "";
    for(int i = 0; i < remnants[curr_ind] - bottle_neck; i++)
    {
        local_closing_brackets += ")";
    }

    string closing_brackets = "";
    for(int i = 0; i < bottle_neck; i++)
    {
        closing_brackets += ")";
    }

    return opening_brackets + to_string(vals[curr_ind]) + local_closing_brackets + get_next_string(vals, remnants, n, curr_ind + 1) + closing_brackets;  
}

int main()
{
    int t = 0;
    cin >> t;

    int case_no = 0;

    while(t--)
    {
        case_no++;
        string s = "";
        cin >> s;
        int vals[s.size()];
        int remnants[s.size()];

        int closing_braces = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int curr = (int)s[i] - (int)'0';
            vals[i] = remnants[i] = curr;
        }
        
        bool sub_string_start = false;
        bool sub_string_end = true;
        int sub_string_start_ind = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(vals[i] == 0)
            {
                if(!sub_string_start)
                {
                    sub_string_start = true;
                    sub_string_start_ind = i;
                }
            }
            else
            {
                if(sub_string_start)
                {
                    sub_string_end = false;
                }
            }
        }
        string result = "";
        if(sub_string_start && sub_string_end)
        {
            result = get_next_string(vals, remnants, sub_string_start_ind, 0);
            for(int i = sub_string_start_ind; i < s.size(); i++)
            {
                result += '0';
            }
        }
        else
        {
            result = get_next_string(vals, remnants, s.size(), 0);
        }
        cout << "Case #" << case_no << ": " << result << endl;
    }
}
