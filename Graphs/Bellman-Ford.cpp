#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e12
typedef pair<int, int> pi;
int n, m;
vector<vector<pi>> g;
vector<int> dist;
vector<int> par;
vector<int> c;
int cycle;
 
 
 
int solve(int r)
{
    dist[r] = 0;
    int changes = 0;
    for (int i=0; i<n; i++)
    {
        changes=0;
        for (int u=0; u<n; u++)
        {
            for (pi v: g[u])
            {
                if(dist[u] + v.second < dist[v.first])
                {
                    changes++;
                    par[v.first] = u;
                    cycle = v.first;
                    dist[v.first] = dist[u] + v.second;
                }
            }
        }
       /* for (int x : dist) cout << x<<" ";
        cout << endl;*/
    }
 
    if(changes > 0)
    {
        vector<bool> used(n, 0);
        while(!used[cycle])
        {
            c.push_back(cycle);
            used[cycle] = 1;
            cycle = par[cycle];
 
        }
        c.push_back(cycle);
        return 1;
    }
    return 0;
}
 
 
int32_t main()
{
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, INF);
    par.resize(n);
    for (int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
    }
 
    if(solve(0)) 
    {
        cout << "YES"<<endl;
        reverse(c.begin(), c.end());
        int x = c[0];
        cout << x+1<<" ";
        for (int i=1; i<c.size(); i++)
        {
            if(c[i]==x)
            {
                cout << x+1;
                break;
            } 
            else cout << c[i]+1<<" ";
        }
        
    }
    else cout << "NO";
}