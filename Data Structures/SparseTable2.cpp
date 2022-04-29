#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
vector<int> v;
vector<vector<int>> t;
int L;
int n;

void SparseTable()
{
    t.resize(n, vector<int>(L+1, INF));
    for (int i=0; i<n; i++) t[i][0] = v[i];
    for (int j=1; j<=L; j++)
    {
        int k = (1 << j);
        for(int i=0; i+k-1<n; i++) t[i][j] = min (t[i][j-1], t[i+k/2][j-1]);
    
    }
    
}

int getmin(int a, int b)
{
    int l = b-a+1;
    l = log2(l);

    return min(t[a][l], t[b-(1<<l)+1][l] );
}


int main()
{
    int q;
    cin >> n >> q;
    v.resize(n);
    for (int i = 0; i<n; i++) cin >> v[i];
    L = log2(n);
    SparseTable();



    for (int i=0; i<q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << getmin(a, b)<<endl;
    }
}