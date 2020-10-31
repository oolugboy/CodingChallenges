#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    int case_no = 0;
    while(t--)
    {
        case_no++;
        int n = 0;
        cin >> n;

        int row[n + 1][n + 1] = {0};
        int col[n + 1][n + 1] = {0};

        int trace_sum = 0;

        for (int i = 1; i < (n + 1); i++)
        {
            for(int j = 1; j < (n + 1); j++)
            {
                int cell_val = 0;
                cin >> cell_val;

                row[i][cell_val]++;
                col[j][cell_val]++;

                if(i == j)
                {
                    trace_sum += cell_val;
                }
            }
        }

        int row_rep_sum = 0;
        for(int i = 1; i < (n + 1); i++)
        {
            for(int val = 1; val < (n + 1); val++)
            {
                if(row[i][val] > 1)
                {
                    row_rep_sum++;
                    break;
                }
            }
        }

        int col_rep_sum = 0;
        for(int i = 1; i < (n + 1); i++)
        {
            for(int val = 1; val < (n + 1); val++)
            {   
                if(col[i][val] > 1)
                {
                    col_rep_sum++;
                    break;
                }
            }
        }

        cout << "Case #" << case_no << ": " << trace_sum << " " << row_rep_sum << " " << col_rep_sum << endl;
    }
}
