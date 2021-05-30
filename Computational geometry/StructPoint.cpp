#include <bits/stdc++.h>
using namespace std;

struct pt
{
    int x, y;
    pt(){}
    pt(int a, int b){x=a; y=b;}
};

pt operator +(pt a, pt b){ return {a.x+b.x, a.y+b.y};}
pt operator -(pt a, pt b){ return {a.x-b.x, a.y-b.y};}
int operator ^(pt a, pt b){ return a.x*b.y - a.y*b.x;}

bool cmpx(pt a, pt b) {return (a.x < b.x) || (a.x == b.x && a.y < b.y) ;}
bool cmpy(pt a, pt b) {return (a.y < b.y) || (a.y == b.y && a.x < b.x) ;}

bool intersezionefrarette(pt a, pt b, pt c, pt d)
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

bool intersezionefrasegmenti(pt a, pt b, pt c, pt d)
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

    if(pv1==0 && pv2==0 && pv3==0 && pv4==0) // i due segmenti sono allineati
    {
        if(a.x>b.x) swap(a.x, b.x);
        if(c.x>d.x) swap(c.x, d.x);
        if(a.y>b.y) swap(a.y, b.y);
        if(c.y>d.y) swap(c.y, d.y);
        if( a.x<c.x && b.x>c.x || c.x<a.x && d.x>a.x )   // condizione x
        {
            return (a.y<c.y && b.y>c.y || c.y<a.x && d.y>a.y);    // condizione y
        }
    }

    return (s1==!s2 && s3==!s4);

}

int main()
{
    int T;
    cin >> T;
    for (int t=0; t<T; t++)
    {

        int x,y;
        cin >> x >> y;
        pt a(x, y);
        cin >> x >> y;
        pt b(x, y);
        cin >> x >> y;
        pt c(x, y);
        cin >> x >> y;
        pt d(x, y);

        if (intersezionefrasegmenti(a, b, c, d)) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }

    

}