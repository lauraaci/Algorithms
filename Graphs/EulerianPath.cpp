#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef pair<int, int> pi;
vector<vector<pi>> g;
int n, m, a, b;
vector<int> cycle;

void EulerianPath(int u)
{
    for (pi& adj : g[u])
    {
        int v = adj.first;
        int valido = adj.second;
        if(valido)
        {
            adj.second = 0; //tolgo l'arco;
            for (pi& vv : g[v])
            {
                if(vv.first == u && vv.second)
                {
                    vv.second = 0; //tolgo l'arco anche nell'altro senso
                    break;
                } 
            }
            EulerianPath(v);
        }
    }
    cycle.push_back(u);
}

int main()
{
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    cin >> n >> m >> a >> b;
    a--;
    b--;
    g.resize(n);
    for (int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back({y, 1});
        g[y].push_back({x, 1});
    }
    EulerianPath(a);
    reverse(cycle.begin(), cycle.end());
   // cout << endl<<endl;
    for (int i=0; i<cycle.size()-1; i++)
    {
        cout << cycle[i]+1<<" "<<cycle[i+1]+1<<endl;
    }

}