#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> used;

void dfs(int u)
{
    used[u]=true;
    for (int v : g[u])
    {
        if(!used[v]) dfs(v);
    }
}
int main()
{

}