#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<vector<pi>> g;
vector<int> d;


void dijkstra(int s) 
{ 
    
    d[s]=0;
    priority_queue<pi, vector<pi> greater<pi>()> pq;
    pq.push(make_pair(0, s));
    
    
    while (!daprocessare.empty())
    
    { 
        priority_queue< pi, vector<pi>, greater<pi>> pq;
        pi u = make_pair(0, s);
        pq.push(u);

        while(!pq.empty())
        {
            pi v = pq.top();
            pq.pop();

            for (int i=0; i<g[v.second].size(); i++)
            {
                int adj= g[v.second][i].second;
                if(dist[adj]>dist[v.second]+g[v.second][i].first)
                {
                    dist[adj]= dist[v.second]+g[v.second][i].first;
                    pq.push(make_pair(dist[adj], adj));
                }
            }
        }

}


