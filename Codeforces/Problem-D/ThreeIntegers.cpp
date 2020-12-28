#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while(t--)
    {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;

        int min_diff = 40000;
        int min_A = 0, min_B = 0, min_C = 0;

        for(int A = 1; A < (2 * a); A++)
        {
            for(int B = A; B < (2 * b); B+=A)
            {
                int left_approx = B * (c / B);
                int right_approx = (B * ((c / B) + 1));
                int C = 0;
                if(abs(c - left_approx) <= abs(c - right_approx))
                {
                    C = left_approx;
                }
                else
                {
                    C = right_approx;
                }
                int total_diff = abs(A - a) + abs(B - b) + abs(C - c);
                if(total_diff < min_diff)
                {
                    min_diff = total_diff;
                    min_A = A;
                    min_B = B;
                    min_C = C;
                }
            }
        }
        cout << min_diff << endl;
        cout << min_A << " " << min_B << " " << min_C << endl;
    }
}
