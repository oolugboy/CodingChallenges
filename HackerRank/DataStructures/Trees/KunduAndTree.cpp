#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    Node(){}
    vector<int> nInds;
};

Node nodes[100001];
bool visited[100001] = {0};
int compCount[100001] = {0};
int prefixCompCountSum[100001] = {0};
int pairSum[100001] = {0};
int prefixPairSum[100001] = {0};
int tripleSum[100001] = {0};
int modder = 1000000007;

void traverse(int currInd, int comp)
{
    visited[currInd] = true;
    compCount[comp]++;
    for(int i = 0; i < nodes[currInd].nInds.size(); i++)
    {
        int nInd = nodes[currInd].nInds[i];
        if(!visited[nInd])
        {
            traverse(nodes[currInd].nInds[i], comp);
        }
    }
}

int main()
{
    int n = 0;
    cin >> n;

    for(int i = 1; i < (n + 1); i++)
    {
        nodes[i] = Node();
    }
    
    for(int i = 0; i < (n - 1); i++)
    {
        int val = 0; int nVal = 0;
        char color;

        cin >> val >> nVal >> color;

        if(color != 'r')
        {
            nodes[val].nInds.push_back(nVal);
            nodes[nVal].nInds.push_back(val);
        }
    }

    int comps = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        if(visited[i] == 0)
        {
            comps++;
            traverse(i, comps);
        }
    }

//    string prefixSumDebug = "";
    prefixCompCountSum[comps] = compCount[comps];
//    prefixSumDebug = to_string(prefixCompCountSum[comps]) + prefixSumDebug;
    for(int i = (comps - 1); i >= 1; i--)
    {
        prefixCompCountSum[i] = (compCount[i] + prefixCompCountSum[i + 1]) % modder;
//        prefixSumDebug = to_string(prefixCompCountSum[i]) + " " + prefixSumDebug;
    }
//    prefixSumDebug = "Prefix Sums: " + prefixSumDebug;
//    cout << prefixSumDebug << endl;

//    string pairSumDebug = "";
    for(int i = (comps - 1); i >= 1; i--)
    {
        pairSum[i] = ((long long int)compCount[i] * prefixCompCountSum[i + 1]) % modder;
//        pairSumDebug = to_string(pairSum[i]) + " " + pairSumDebug;
    }
//    pairSumDebug = "Pair Sums: " + pairSumDebug;
//    cout << pairSumDebug << endl;

//    string prefixPairSumDebug = "";
    for(int i = (comps - 1); i >= 1; i--)
    {
        prefixPairSum[i] = (pairSum[i] + prefixPairSum[i + 1]) % modder;
//        prefixPairSumDebug = to_string(prefixPairSum[i]) + " " + prefixPairSumDebug;
    }
//    prefixPairSumDebug = "Prefix Pair Sum: " + prefixPairSumDebug;
//    cout << prefixPairSumDebug << endl;

//    string tripleSumDebug = "";
    for(int i = (comps - 1); i >= 1; i--)
    {
        tripleSum[i] = ((long long int)compCount[i] * prefixPairSum[i + 1]) % modder;
//        tripleSumDebug = to_string(tripleSum[i]) + " " + tripleSumDebug;
    }
//    tripleSumDebug = "Triple Sums : " + tripleSumDebug;
//    cout << tripleSumDebug << endl;

//    string resultSumDebug = "";
    int resultSum = 0;
    for(int i = (comps - 2); i >= 1; i--)
    {
        resultSum = (resultSum + tripleSum[i]) % modder;
//        resultSumDebug = to_string(resultSum) + " " + resultSumDebug;
    }
//    resultSumDebug = "Result Sum: " + resultSumDebug;
//    cout << resultSumDebug << endl;

    cout << resultSum << endl;
}
