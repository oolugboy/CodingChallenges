#include <vector>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

enum substring_availability { Available, Unavailable, PossiblyAvailable };

substring_availability is_substring_available(string substring, string target_string, int start_index)
{
    substring_availability availability_result = Available;

    for(int i = 0; i < substring.size(); i++)
    {
        if(target_string[start_index + i] != substring[i])
        {
            if(target_string[start_index + i] == '?')
            {
                availability_result = PossiblyAvailable;
            }
            else
            {
                return Unavailable;
            }
        }
    }
    return availability_result;
}

string fill_for_substring(string substring, string target_string, int start_index)
{
    for(int i = 0; i < substring.size(); i++)
    {
        if(target_string[start_index + i] == '?')
        {
            target_string[start_index + i] = substring[i];
        }
    }
    return target_string;
}

string fill_placeholders(string target_string)
{
    for (int i = 0; i < target_string.size(); i++)
    {
        if(target_string[i] == '?')
        {
            target_string[i] = 'z'; 
        }
    }
    return target_string;
}

int get_available_result_amount(string test_substring, string target_string)
{
    int available_result_amount = 0;
    for (int i = 0; i <= (target_string.size() - test_substring.size()); i++)
    {
        substring_availability availability_result = is_substring_available(test_substring, target_string, i);

        if(availability_result == Available)
        {
            available_result_amount++;
        }
    }
    return available_result_amount;
}

vector<int> get_possible_result_start_indices(string test_substring, string target_string)
{
    vector<int>possible_result_start_indices;
    for (int i = 0; i <= (target_string.size() - test_substring.size()); i++)
    {
        substring_availability availability_result = is_substring_available(test_substring, target_string, i);

        if(availability_result == PossiblyAvailable)
        {
            possible_result_start_indices.push_back(i);
        }
    }
    return possible_result_start_indices;
}

int main()
{
    int T = 0;
    cin >> T;

    while(T--)
    {
        int n = 0;
        cin >> n;

        string s;
        cin >> s;

        string test_substring = "abacaba";

        string available_result = "";
        int available_result_amount = get_available_result_amount(test_substring, s);
        if(available_result_amount == 1)
        {
            available_result = fill_placeholders(s);
        }
        if (available_result_amount < 1)
        {
            vector<int> possible_result_start_indices = get_possible_result_start_indices(test_substring, s);

            if(possible_result_start_indices.size() > 0)
            {
                for(int i = 0; i < possible_result_start_indices.size(); i++)
                {
                    string filled_target_substring = fill_for_substring(test_substring, s, possible_result_start_indices[i]);
                    if(get_available_result_amount(test_substring, filled_target_substring) == 1)
                    {
                        available_result = fill_placeholders(filled_target_substring);
                        break;
                    }
                }
            }
        }

        if(available_result.size() > 0)
        {
            cout << "Yes" << endl;
            cout << available_result << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

