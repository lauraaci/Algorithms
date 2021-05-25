#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<vector<pi>> g;
vector<edge> archi;
vector<edge> solarchi;
vector<int> p;
vector<int> r;
int sol=0;
void makeset(int x)
{
    p[x]=x;
    r[x]=0;
}

int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}

void unisci(int x, int y)
{
    int a=find(x);
    int b=find(y);
    if(a!=b)
    {
        if(r[a]<r[b]) p[a]=b;
        else 
        {
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
        }
    }
}

struct edge
{
    int a, b, w;
}
bool cmp(edge x, edge y) return {x.w<y.w};

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    archi.resize(m);
    for (int i=0; i<n; i++) makeset(i);
    sort(archi.begin(), archi.end());
    int sol=0;
    for (int i=0; i<m; i++)
    {
        edge z=archi[i];
        int x, y;
        x=edge.a;
        y=edge.b;
        if(find(x)!=find(y))
        {
            sol+=z.w;
            solarchi.push_back(z);
            unisci(x, y);
        }
    }




}