#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define a 37
/*
h(s′) =h(s)R+s(n+1)
(s′) =h(s)−s1R^(n-1)
*/

int hashh(string s)
{
    int res=0;
    for (auto c : s) res = (res * a + (c - 'a' +1))%mod;
    return res;
}



int32_t main()
{
   
    int cnt=0;
    string s, t;
    cin >> s >> t;
    int patt = hashh(t);
    int l = t.size();
    string ss = s.substr(0, l);
    int x = hashh(ss);
    if(x==patt) cnt++;
    int pot = 1;
    for (int i=0; i<l-1; i++) pot = (pot * a)%mod;
    cout << patt<<endl;
    for (int i=0; i<s.size()-l; i++)
    {
        cout << x<<endl;
        char c = s[i];
        char cc = s[i+l];
        x = (((x - ((c-'a'+1)*pot)%mod)%mod) + mod )%mod;
        x = (x*a + (cc-'a'+1) )%mod;
        cout << x<<endl;
        if(x==patt) cnt++;
    }
    //cout << hashh("banana");
    cout <<cnt;
}