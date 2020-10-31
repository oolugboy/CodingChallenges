#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0, a = 0;

    cin >> n >> a;

    int vertexInd = 1;
    int rightSideInd = 2;
    int leftSideInd = 3;
    
    float unitAngle = 360.0f / (n * 2);
    float unitAm = max(a / unitAngle, 1.0f);

    if(unitAm <= floor(unitAm) + 0.5f)
    {
        leftSideInd = min(n, (int)(rightSideInd + floor(unitAm)));    
    }
    else
    {
        leftSideInd = min(n, (int)(rightSideInd + floor(unitAm) + 1));
    }
    
    cout << rightSideInd << " " << vertexInd << " " << leftSideInd << endl;
}
