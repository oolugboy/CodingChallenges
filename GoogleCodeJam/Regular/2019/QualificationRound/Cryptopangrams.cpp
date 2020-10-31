#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int getFirstPrime(int * vals, int l)
{
    for(int i = 1; i < l; i++ )
    {
        int gcdVal = gcd(vals[0], vals[i]);
        if(gcdVal != 1)
        {
            return min(gcdVal, min(vals[0]/gcdVal, vals[i]/gcdVal));
        }
    }
    return 0;
}

vector<int> setPrimePairsAndGetPrimes(int * vals, int * p1, int * p2, int l)
{
    bool set[l];
    for(int i = 0; i < l; i++)
    {
        set[i] = false;
    }
    vector<int> primes;
    primes.push_back(getFirstPrime(vals, l)); 

    for(int i = 0; i < (l + 1); i++)
    {
        for(int j = 0; j < l; j++)
        {
            if(!set[j])
            {
                if(vals[j] % primes[i] == 0)
                {
                    int newPrime = vals[j]/primes[i];
                    p1[j] = min(newPrime, primes[i]);
                    p2[j] = max(newPrime, primes[i]);

                    cout << "Pushing the new prime..." << newPrime << endl;
                    primes.push_back(newPrime);
                    set[j] = true;
                }
            }
        }
    }

    return primes;
}

string reconstructString(int * unsortedVals, unordered_map<int, int> sortedInds, int * p1, int * p2, unordered_map<int, int> sortedPrimeInds, int l)
{
    string res = "";
    int currPrime = 0, nextPrime = 0;
    for(int i = 0; i < (l + 1); i++)
    {
        if(i < l)
        {
            int currProdInd = sortedInds[unsortedVals[i]];

            if(i < (l - 1))
            {
                int nextProdInd = sortedInds[unsortedVals[i + 1]];

                if(p1[currProdInd] == p1[nextProdInd] || p2[currProdInd] == p1[nextProdInd])
                {
                    if(i == 0)
                    {
                        currPrime = p2[currProdInd];
                    }
                    nextPrime = p1[currProdInd];
                }
                else
                {
                    if(i == 0)
                    {
                        currPrime = p1[currProdInd];
                    }
                    nextPrime = p2[currProdInd];
                }
            }
            else
            {
                if(currPrime == p1[currProdInd])
                {
                    nextPrime = p2[currProdInd];
                }
                else
                {
                    nextPrime = p1[currProdInd];
                }
            }
        }
        res += (char)(sortedPrimeInds[currPrime] + 65);
        cout << "The currPrime is " << currPrime << endl; 
        currPrime = nextPrime; 
    }
    
    return res;
}

int main()
{
    int t = 0, testInd = 0;
    cin >> t;

    while(testInd < t)
    {
        testInd++;

        string n;
        cin >> n;

        int l = 0;
        cin >> l;

        int vals[l];
        int unsortedVals[l];
        for(int i = 0; i < l; i++)
        {
            cin >> vals[i];
            unsortedVals[i] = vals[i];
        }

        unordered_map <int, int> sortedInds;
        sort(vals, vals + l);
        for(int i = 0; i < l; i++)
        {
            sortedInds[vals[i]] = i;
        }

        int p1[l];
        int p2[l];
        vector<int> primes = setPrimePairsAndGetPrimes(vals, p1, p2, l);
        sort(primes.begin(), primes.end());

        unordered_map <int, int> sortedPrimeInds;
        for(int i = 0; i < (l + 1); i++)
        {
            cout << "The prime: " << primes[i] << endl;
            sortedPrimeInds[primes[i]] = i;
        }
        for(int i = 0; i < l; i++)
        {
            cout << "P1: " << p1[i] << " P2: " << p2[i] << endl;
        }
        string res = reconstructString(unsortedVals, sortedInds, p1, p2, sortedPrimeInds, l);

        cout << "Case #" << testInd << ": " << res << endl;
    }
}
