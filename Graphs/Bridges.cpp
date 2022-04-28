#include <bits/stdc++.h> 
using namespace std;
#define INF 1000000000
typedef pair<int, int> pi;
/*
usare dfs per creare il DFS Tree. 
Nell'albero della dfs un arco (u, v) è un edge 
se nel sottoalbero di v non ci sono backedge 
che connettono un discendente a v o un suo ancestor
*/

vector<vector<int>> g;
vector<int> dist;
vector<int> span;
vector<bool> used;
vector<pi> br;

int fr = 0;

void dfs1(int u, int d)
{
    used[u] = 1;
    dist[u] = d;
    if(d==1) fr++;
    for (int v : g[u])
    {
        if(!used[v])  dfs1(v, d+1);
    }

}

void dfs2(int u, int p)
{
    used[u] = 1;
    for (int v : g[u])
    {
        if(!used[v])
        {
            dfs2(v, u);
            span[u] = min(span[u], span[v]);
        }
        if(v!=p) span[u] = min(span[u], dist[v]);
    }

}


int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n);
    span.resize(n, INF);
    used.resize(n, 0);

    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);

    }

    dfs1(0, 0);
    used.assign(n, 0);
    dfs2(0, 0);

    
    for (int i=0; i<n; i++)
    {
        
        for(int v : g[i]) 
        {
            if(span[v] > dist[i] && dist[v] == dist[i]+1) //controlla solo i suoi span edge
            {
                br.push_back({i, v});
            }
            
        }
        
    }
   // for (int i : span) cout << i<<endl;
    
    cout << br.size()<<endl;
    for(pi i : br) cout << i.first+1<<" "<<i.second+1<<endl;
}