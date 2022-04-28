#include <bits/stdc++.h>
using namespace std;

struct fen
{
    vector<int> T;
    
    fen(int n)
    {
        
        T.resize(n+1, 0); // one based;
    }

    void add(int pos, int val)
    {
        pos++; //one based
        for (pos; pos < T.size(); pos += (pos&-(pos))) T[pos] += val; //vado avanti della dimensione del range coperto in quella posizione
    }

    int sum(int pos) // [0, b]
    {
        int res = 0;
        pos++;
        for (pos; pos > 0; pos -= (pos&(-pos))) res += T[pos];
        return res;
    }

    int sumrange(int a, int b)
    {
        if(a == 0) return sum(b)
        else return sum(b) - sum(a-1);
    }
};

int main()
{

}