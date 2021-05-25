#include <bits/stdc++.h>
using namespace std;

#define UNVISITED -1
#define VISITED 1
int n;
vector<int> dfs_low;
vector<int> dfs_num;
typedef pair<int,int> ii;
vector<vector<ii>> g;
int dfscnt=0;
vector<int> dfs_parent;
int dfsroot;
int rootChildren;
vector<bool> articulation_point;
void articulationPointAndBridge(int u)
{
    dfs_low[u]=dfs_num[u]= dfscnt++;
    for (int j=0; j<g[u].size(); j++)
    {
        ii v= g[u][j];
        if(dfs_num[v.first]==UNVISITED)
        {
            dfs_parent[v.first]=u;
            if(u==dfsroot) rootChildren++;

            articulationPointAndBridge(v.first);
            
            if(dfs_low[v.first]>=dfs_num[u]) articulation_point[u]=true;
            if(dfs_low[v.first]> dfs_num[u]) ; // u-v.first is a bridge

            dfs_low[u]=min(dfs_low[u], dfs_low[v.first]);

        }
        else if(v.first != dfs_parent[u]) //back edge
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
}

int main()
{
    dfscnt=0;
    dfs_num.resize( n, UNVISITED);
    dfs_low.resize(n, 0);
    dfs_parent.resize(n, 0);
    articulation_point.resize(n, false);

    for (int i=0; i<n; i++)
    {
        if(dfs_num[i]==UNVISITED)
        {
            dfsroot=i;
            rootChildren=0;
            articulationPointAndBridge(i);
            articulation_point[dfsroot]= (rootChildren > 1);
        }
    }

}