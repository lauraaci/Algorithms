#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int fp[N];
vector<int> pr;

void primes()
{
    for (int i=2; i<N; i++)
    {
        //cout << i<<endl;
        if(fp[i]==0)
        {
            pr.push_back(i);
            fp[i]=i;
        }
        for (int j=0; j<pr.size() && pr[j]<=fp[i] && i*pr[j]<N; j++) 
        fp[i*pr[j]]=pr[j];
    }
}

int main()
{
    primes();
    cout << pr.size();
}
