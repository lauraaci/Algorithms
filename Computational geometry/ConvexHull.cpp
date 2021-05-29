#include <bits/stdc++.h>
using namespace std;
#define int long long
struct pt
{
    int x, y;
    pt(){}
    pt(int a, int b){x=a; y=b;}
};

pt operator +(pt a, pt b){ return {a.x+b.x, a.y+b.y};}
pt operator -(pt a, pt b){ return {a.x-b.x, a.y-b.y};}
bool operator ==(pt a, pt b){ return a.x==b.x && a.y==b.y;}
int operator ^(pt a, pt b){ return a.x*b.y - a.y*b.x;}

bool cmpx(pt a, pt b) {return (a.x < b.x) || (a.x == b.x && a.y < b.y) ;}
bool cmpy(pt a, pt b) {return (a.y < b.y) || (a.y == b.y && a.x < b.x) ;}


bool compatibile(pt a, pt b, pt c)
{
    int x = (a-c)^(b-c);
    return x>0;
}


vector<pt> convexhull(vector<pt>& v)
{
    vector<pt> ch;
    for (int i=0; i<v.size(); i++)
    {
        pt p = v[i];
        while(ch.size()>=2 && compatibile(ch[ch.size()-2], ch[ch.size()-1], p))
        {
            ch.pop_back();
        }

        ch.push_back(p);
    }
    return ch;
}

int32_t main()
{
  //  ifstream cin ("input.txt");
    
    while(1)
    {
        int n;
        cin >> n;
        if(n==0) break;
        vector<pt> v(n);
        for (int i=0; i<n; i++) cin >> v[i].x >> v[i].y;

        sort(v.begin(), v.end(), cmpx);
        v.resize(distance(v.begin(), unique(v.begin(), v.end())));
        if(v.size()==1)
        {
            cout << 1<<endl<<v[0].x<<" "<<v[0].y<<endl;
            continue;
        } 
        vector<pt> chu;
        vector<pt> chd;
       
        chd = convexhull(v);
        for (pt& p : v) p.y=-p.y;
        chu = convexhull(v);
        for (pt& p : chu) p.y=-p.y;

        vector<pt> ch(chd.begin(), chd.end()-1);
        ch.insert(ch.end(), chu.begin()+1, chu.end());

        cout << ch.size()<<endl;
        for (pt x : ch) cout <<x.x<<" "<<x.y<<endl;

    }
}