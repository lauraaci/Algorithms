#include <bits/stdc++.h> 
using namespace std;
#define INF 1000000000
/*
usare dfs per creare il DFS Tree. 
Nell'albero della dfs un vertice u è un articulation point
se una delle due condizioni è vera
- u è la radice ed ha almeno due figli
- u non è la radice è ha un figlio v tale che nessun vertice del sottoalbero 
radicato in v compreso v ha un backedge verso uno degli antenati di u nel dfs tree
*/

vector<vector<int>> g;
vector<int> dist;
vector<int> span;
vector<bool> used;
vector<int> ap;

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

void dfs2(int u)
{
    used[u] = 1;
    for (int v : g[u])
    {
        if(!used[v])
        {
            dfs2(v);
            span[u] = min(span[u], span[v]);
        }
        span[u] = min(span[u], dist[v]);
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
    dfs2(0);

    if (fr>=2) ap.push_back(0);
    for (int i=1; i<n; i++)
    {
        for(int v : g[i]) //controlla solo i suoi span edge
        {
            if(span[v] >= dist[i] && dist[v] == dist[i]+1)
            {
                ap.push_back(i);
                break;
            }
        }
    }
    cout << ap.size()<<endl;
    for(int i : ap) cout << i+1<<" ";
}