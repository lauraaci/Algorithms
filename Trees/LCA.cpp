#include <bits/stdc++.h>
using namespace std;
#define N 100000

int L;
anc[N][30];
vector<int> liv;
vector<vector<int>> g;

int lift(int u, int h)
{
    for (int i=L; i>=0; i--)
    {
        if(liv[u]-(1 << L) > h)
        {
            u = anc[u][i];
        }
    }

    return u;
}


void dfs(int u, int p)
{
    anc[u][0]=p;
    for (int i=1; i<=L; i++) anc[u][i] = anc[anc[u][i-1]][i-1];
    for (v : g[u])
    {
        if(v!=p)
        {
            liv[v] = liv[u]+1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v)
{
    if(liv[u] < liv[v]) swap(u, v);

    u = lift(u, liv[v]);
    if(u==v) return v;

    for (int i=L; i>=0; i--)
    {
        if(anc[u][i]!=anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return anc[u][0];
}


int main()
{

}