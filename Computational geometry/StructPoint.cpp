#include <bits/stdc++.h>
using namespace std;
#define int long long

struct pt
{
    int x, y;
    pt(){}
    pt(int a, int b){x=a; y=b;}
};

ostream& operator<<(ostream&o,const pt&p) {o<<"("<<p.x<<","<<p.y<<")"; return o;}
istream& operator>>(istream&i, pt&p){i>>p.x>>p.y;return i;}
pt operator +(pt a, pt b){ return {a.x+b.x, a.y+b.y};}
pt operator -(pt a, pt b){ return {a.x-b.x, a.y-b.y};}
int operator ^(pt a, pt b){ return a.x*b.y - a.y*b.x;}

bool cmpx(pt a, pt b) {return (a.x < b.x) || (a.x == b.x && a.y < b.y) ;}
bool cmpy(pt a, pt b) {return (a.y < b.y) || (a.y == b.y && a.x < b.x) ;}

bool LineIntersect(pt a, pt b, pt c, pt d)
{
    int pv1, pv2, pv3, pv4;
    pv1 = (c-a)^(d-a);
    pv2 = (c-b)^(d-b);
    pv3 = (a-c)^(b-c);
    pv4 = (a-d)^(b-d);

    bool s1, s2, s3, s4;
    s1 = (pv1 > 0) ? 1 : 0;
    s2 = (pv2 > 0) ? 1 : 0;
    s3 = (pv3 > 0) ? 1 : 0;
    s4 = (pv4 > 0) ? 1 : 0;

    return (s1==!s2 && s3==!s4);
} 

int sign(int x)
{
  return (x==0) ? 0 : (x>0) ? 1 : -1;
}

bool SegmentIntersect(pt a, pt b, pt c, pt d)
{
    int pv1, pv2, pv3, pv4;
    pv1 = (c-a)^(d-a);
    pv2 = (c-b)^(d-b);
    pv3 = (a-c)^(b-c);
    pv4 = (a-d)^(b-d);

    int s1, s2, s3, s4;
    s1 = sign(pv1);
    s2 = sign(pv2);
    s3 = sign(pv3);
    s4 = sign(pv4);

    if(s1==0 && s2==0 && s3==0 && s4==0) // i due segmenti sono allineati
    {
        if(a.x == b.x) // sono allineati verticalmente
        {
            if(a.y > b.y) swap(a, b);
            if(c.y > d.y) swap(c, d);
            if(a.y > c.y) {swap(a, c); swap(b, d);}

            return (c.y <= b.y);
        }
        else // confronto le x
        {
            if(a.x > b.x) swap(a, b);
            if(c.x > d.x) swap(c, d);
            if(a.x > c.x) {swap(a, c); swap(b, d);}
            if(c.y>d.y) swap(c.y, d.y);

            return (c.x <= b.x);
        }
    }
    
    return (s1*s2<=0 && s3*s4<=0); 

}

double Area(vector<pt>& v) 
{
    int n = v.size();
    double area=0;
    for (int i=0; i<n-1; i++) area += v[i]^v[i+1];
    area += v[n-1]^v[0];
    area = 0.5*abs(area);
    
    return area;
}

int32_t main()
{
    
    int n;
    cin >> n;
    vector<pt> v(n);
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    
    cout << Area(v);
    

    

}