#include <iostream>
#include <algorithm>

using namespace std;

struct Person {
    bool xConds[2];
    int xConts[2];
    bool yConds[2];
    int yConts[2];
    
    Person()
    {}

    Person(int x, int y, char d)
    {
        xConds[0] = xConds[1] = false;
        yConds[0] = yConds[1] = false;

        if(d == 'N')
        {
            yConds[0] = true;
            yConts[0] = y;
        }
        if(d == 'S')
        {
            yConds[1] = true;
            yConts[1] = y;

        }
        if(d == 'E')
        {
            xConds[0] = true;
            xConts[0] = x; 
        }
        if(d == 'W')
        {
            xConds[1] = true;
            xConts[1] = x; 
        }
    }

    void applyConstraints(int & x, int & y)
    {
        if(yConds[0])
        {
            y = max(y, yConts[0] + 1);
        }
        if(yConds[1])
        {
            y = min(y, yConts[1] - 1);
        }
        if(xConds[0])
        {
            x = max(x, xConts[0] + 1);
        }
        if(xConds[1])
        {
            x = min(x, xConts[1] - 1);
        }
    }
};

int main()
{
    int T = 0;
    cin >> T;

    int caseNo = 0;

    while(T--)
    {
        caseNo++;
        int P = 0, Q = 0;
        cin >> P >> Q;

        Person Persons[P];

        int resX = 0, resY = 0;
        for(int i = 0; i < P; i++)
        {
            int x = 0, y = 0;
            char d;
            cin >> x >> y >> d;
            Persons[i] = Person(x, y, d);
            Persons[i].applyConstraints(resX, resY);
        }
        
        cout << "Case #" << caseNo << ": " << resX << " " << resY << endl;
    }
}
