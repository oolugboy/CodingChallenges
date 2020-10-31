#include <iostream>

using namespace std;

int main()
{
    int testArray[6] = {3, 2, 1, 4, 2, 1};
    int sum = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = (i + 1); j < 6; j++)
        {
            for(int k = (j + 1); k < 6; k++)
            {
                cout << "(" << testArray[i] << " * " << testArray[j] << " * " << testArray[k] << ")" << endl;
                if(i < 3)
                {
                    cout << "     +     " << endl;
                }
                sum += (testArray[i] * testArray[j] * testArray[k]);
            }
        }
    }
    cout << sum << endl;
}
