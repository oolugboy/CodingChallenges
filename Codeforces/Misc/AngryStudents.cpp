#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    short t = 0;
    cin >> t;
    while(t--)
    {
        short n = 0;
        cin >> n;
        short max_throws_needed = 0;
        short throws_needed = 0;
        bool angry_student_set = false;
        for(short i = 0; i < n; i++)
        {
            char state;
            cin >> state;
            if(state == 'A')
            {
                max_throws_needed = max(max_throws_needed, throws_needed);
                throws_needed = 0;
                angry_student_set = true;
            }
            else
            {
                if(angry_student_set)
                {
                    throws_needed++;
                }
            }
        }
        max_throws_needed = max(max_throws_needed, throws_needed);
        cout << max_throws_needed << endl;
    }
}
