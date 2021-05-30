#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<vector<pi>> g;
vector<int> dist;


void dijkstra(int s) 
{ 
    
    priority_queue< pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});
    dist[s]=0;

    while(!pq.empty())
    {
        pi u = pq.top();
        pq.pop();

        for (pi v : g[u.second])
        {
            int adj= v.second;
            if(dist[adj] > dist[u.second] + v.first)
            {
                dist[adj]= dist[u.second] + v.first;
                pq.push({dist[adj], adj});
            }
        }
    }

}

int main()
{
    //get input
}


