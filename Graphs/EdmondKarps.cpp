#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e12
typedef pair<int, int> pi;
int n, m;
/*struct edge
{
    int to, cap; //  par: verso che nodo, capacità residua, nodo del arco inverso
};*/

vector<vector<int>> g;
vector<vector<int>> cap;
vector<int> par;

int bfs(int s, int t) //trova augmenting-path s-t con capacità residue non nulle
{
    par.assign(n, -1);
    par[s]=-2;
    queue<pi> q;
    q.push({s, INF}); //nodo, maxflow in quel nodo;


    while(!q.empty())
    {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : g[u])
        {
            if(par[v]==-1 && cap[u][v]>0) //se non lo ho già visitato e la sua capacità residua > 0
            {
                par[v]=u; 
                int newflow = min(flow, cap[u][v]); //mi tengo la capacità residua minima del percorso
                if(v == t) return newflow;// se sono arrivata al pozzo finisco qui
                q.push({v, newflow });
            }            
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    int new_flow;

    while(new_flow = bfs(s, t)) //finchè trovo degli augmenting path 
    {
        flow+=new_flow; 
        //trasversa il path appena trovato al contrario e aggiorna le capacità
        int cur = t;
        while(cur!=s)
        {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }


    } 
    return flow;
}

int32_t main()
{
    cin >> n >> m;
    g.resize(n);
    cap.resize(n, vector<int> (n, 0));
    par.resize(n);
    for (int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        cap[a][b]+=c;
    }
    cout << maxflow(0, n-1)<<endl;


    
}