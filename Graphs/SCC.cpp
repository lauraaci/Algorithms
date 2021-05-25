#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int n;

vi dfs_num, dfs_low, S, visited;
int cnt;
typedef pair<int,int> ii;
vector<vector<ii>> g;
int numSCC;
void TarjanSCC(int u)
{
    dfs_low[u]=dfs_num[u]=cnt++;
    S.push_back(u);
    visited[u]=1;
    for (int i=0; i<g[u].size(); i++)
    {
        ii v=g[u][i];
        if(dfs_num[v.first]== -1 ) TarjanSCC(v.first);
        if(visited[v.first]) dfs_low[u]=min(dfs_low[u], dfs_low[v.first]);
    }

    if(dfs_low[u]==dfs_num[u]) //start of a SCC
    {
       ++numSCC;
        while(1)
        {
            int v= S.back(); 
            S.pop_back(); 
            visited[v]=0;
            if(u==v) break;
        }

    }
}

int main()
{
    dfs_num.resize(n, -1);
    dfs_low.resize(n, 0);
    visited.resize(n, 0);
    cnt=numSCC=0;
    for (int i=0; i<n; i++)
    {
        if (dfs_num[i]==-1) TarjanSCC(i);
    }
}

