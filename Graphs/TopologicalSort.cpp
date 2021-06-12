#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<vector<int>> rg;
vector<int> order;
vector<bool> used;
int mx=0;
int cnt;
void dfs(int u)
{
    used[u] = 1;
    for( int v : g[u])
    {
        if(!used[v]) dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u)
{
    used[u] = 1;
    //add to component
    cnt++;
    mx = max(mx, cnt);
    for (int v : rg[u])
    {
        if(!used[v]) dfs2(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, 0);
    rg.resize(n);
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    for(int i=0; i<n; i++)
    {
        if(!used[i]) dfs(i);
    }
    reverse(order.begin(), order.end());
    used.assign(n, 0);
    for (int i=0; i<n; i++)
    {
        int j = order[i];
        cnt=0;
        if(!used[j])
        {
            dfs2(j);
            //cout << cnt<<endl;
        }
    }
    if(mx>1) cout <<"IMPOSSIBLE"<<endl;
    else for (int i : order) cout << i+1<<" ";
}