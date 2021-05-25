#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<vector<pi>> g;
vector<int> dist;
vector<int> cnt;
vector<int> sol;
int n, m, k;
void solve()
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty())
    {
        pi u= pq.top();
        int v = u.second;
        int d= u.first;
        cnt[v]++;
        pq.pop();
        if(v==n-1) sol.push_back(d);
        if(cnt[v]==k && v==n-1) break;
        if(cnt[v]<=k)
        {
            for (pi x : g[v])
            {
                int adj = x.first;
                int peso = x.second;
                pq.push(make_pair(d+peso, adj));
            }
        }
        
    }
}
