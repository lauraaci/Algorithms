// CSES Poliche Chase
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
typedef pair<int, int> pi;

vector<vector<int>> g;
vector<vector<int>> cap;
vector<int> par;
int mxflow;
int n, m;


int bfs(int s, int t)
{
    int res = INF;
    par.assign(n, -1);
    par[s] = -2;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        //cout << "u: "<<u<<endl;
        q.pop();
        for(int v : g[u])
        {
            if(par[v]==-1 && cap[u][v]>0)
            {
                par[v] = u;
                res = min(res, cap[u][v]);
                if(v==t) return res;
                q.push(v);
            }
        }
    }
    return 0;
}

void maxflow(int s, int t)
{
    int newflow;
    while( (newflow = bfs(s, t)) != 0)
    {
        //cout <<"newflow: "<< newflow<<endl;
        mxflow += newflow;
        int curr = t, prev = t;
        while(prev != s)
        {
            prev = par[curr];
            cap[prev][curr] -= newflow;
            cap[curr][prev] += newflow;
            curr = prev;
        }
    }
}

void dfs(int u)
{
    par[u] = 1;
    for (int v : g[u])
    {
        if(par[v]==0 && cap[u][v]>0) dfs(v);
    }
}


int main()
{
    cin >> n >> m;
    g.resize(n);
    cap.resize(n, vector<int>(n));
    par.resize(n);

    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);

        cap[a][b] = 1;
        cap[b][a] = 1;
    }

    maxflow(0, n-1);
    //cout <<endl<< mxflow<<endl;
    par.assign(n, 0);
    dfs(0);
    vector<pi> ed;
    for (int i=0; i<n; i++)
    {
        if(par[i])
        {

            for (int v : g[i])
            {
                if(par[v]==0) ed.push_back({i, v});
            }
        }

    }
    cout << ed.size()<<endl;
    for (pi i : ed) cout << i.first+1<<" "<<i.second+1<<endl;

    
}

