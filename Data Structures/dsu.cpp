#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> r;

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

void uni(int x, int y)
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

int main()
{

}
