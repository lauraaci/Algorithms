#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e14
vector<vector<int>> dist;
vector<vector<int>> arco;


int32_t main()
{
    int n,  m, q;
    cin >> n >> m >> q;
    dist.resize(n, vector<int> (n, INF));
    arco.resize(n, vector<int> (n, -1));
    for (int i=0; i<n; i++)
    {
        dist[i][i] = 0;
        arco[i][i] = i;
    } 
    for (int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[a][b]);
        arco[a][b] = b;
        arco[b][a] = a;
    }

    for (int k=0; k<n; k++)
    {
        for (int i=0; i<n; i++)
        {
            
            for (int j=0; j<n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    arco[i][j] = k;
                }
            }
        }
    }

    for (int i=0; i<q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(dist[a][b] ==INF) dist[a][b] = -1;
        cout << dist[a][b]<<" ";
    }
}