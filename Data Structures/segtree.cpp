
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
typedef long long ll;
#define INF 100000000
vector<ll> b;
ll n;
struct item
{
    ll mn, sm;
};

struct op
{
    ll plus, change;
};

struct segm
{
    vector<item> values;
    vector<op> operation;
    ll size;

    void inittree(ll n)
    {
        size=1;
        values.resize(4*n, {INF, 0});
        operation.resize(4*n, {0, INF});
    }

    item merge(item x, item y)
    {
        item res;
        res.mn=min(x.mn, y.mn);
        res.sm=x.sm+y.sm;
        return res;
    }

    void build(ll v, ll l ,ll r)
    {
        if(l==r) values[v]={b[l], b[l]};
        else
        {
            ll m=(l+r)/2;
            build(2*v, l, m);
            build(2*v+1, m+1, r);

            values[v] = merge(values[2*v], values[2*v+1]);

        }
    }

    item applyoperation( item x, ll l, ll r, ll val1, ll val2)
    {
        item res=x;
        if(val2!=INF) 
        {
            res.mn=val2;
            res.sm=(r-l+1)*val2;
        }
        res.mn=res.mn+val1;
        res.sm=res.sm + (r-l+1)*val1;
        
        return res;
    }

    void propagate(ll v, ll l, ll r)
    {
        if(l==r) return;
        op y = operation[v];
        ll m = (l+r)/2;
        if(y.plus==0 && y.change==INF) return;
        values[2*v]=applyoperation(values[2*v], l, m, y.plus, y.change);
        values[2*v+1]=applyoperation(values[2*v+1], m+1, r, y.plus, y.change);
        if(y.change!=INF)
        {
            operation[2*v] = y;
            operation[2*v+1] = y;
        }
        else
        {
            operation[2*v].plus+=y.plus;
            operation[2*v+1].plus+=y.plus;        
        }
        operation[v]={0, INF};
    }

    void addrange(ll v, ll l, ll r, ll i, ll j, ll val)
    {
        propagate(v, l, r);
        if(l>j || r<i ) return ;
        if(l>=i && r<=j)
        {
            //applica l'operazione 
            values[v]= applyoperation(values[v], l, r, val, INF);
            // stora l'operazione sicuramente ho propagato prima tutto quello che avevo storato quindi operazioni[v] è vuoto
            operation[v]={val, INF};
            return;
        }
        ll m=(l+r)/2;
        addrange(2*v, l, m, i, j, val);
        addrange(2*v+1, m+1, r, i, j, val);
        values[v]= merge(values[2*v], values[2*v+1]);


    }
    void changerange(ll v, ll l, ll r, ll i, ll j, ll val)
    {
        propagate(v, l, r);
        if(l>j || r<i ) return;
        if(l>=i && r<=j)
        {
            //applica l'operazione
            values[v]= applyoperation(values[v], l, r, 0, val);
            // stora l'operazione sicuramente ho propagato prima tutto quello che avevo storato quindi operazioni[v] è vuoto
            operation[v]={0, val};
            return;
        }
        ll m=(l+r)/2;
        changerange(2*v, l, m, i, j, val);
        changerange(2*v+1, m+1, r, i, j, val);
        values[v]= merge(values[2*v], values[2*v+1]);
    }

    item getinfo(ll v, ll l, ll r, ll i, ll j)
    {
        propagate(v, l, r);
        if(l>j || r<i) return {INF, 0};
        if(l>=i && r<=j) return values[v];
        ll m=(l+r)/2;
        item x, y, res;
        x = getinfo(2*v, l, m, i, j);
        y = getinfo(2*v+1, m+1, r, i, j);
        res= merge(x, y);
        return res;
    }

    ll lower(ll v, ll l, ll r, ll i, ll j,  ll val)
    {
        propagate(v, l, r);
        if(values[v].mn>val) return -1;
        if(r<i || l>j) return -1;
        if(l==r) return l;
        ll m=(l+r)/2;
        ll res= lower(2*v, l, m, i, j, val);
        if(res==-1) res=lower(2*v+1, m+1, r, i, j,  val);
        return res;
 
    }

    void stampa()
    {
       cout <<endl<<"CARICA"<<endl;
        for (int i=0; i<size; i++) cout << "v: "<<i<<" "<<carica[i]<<" ";
        cout << endl;
        cout <<endl<<"SVUOTA"<<endl;
        for (int i=0; i<size; i++) cout << "v: "<<i<<" "<<svuota[i]<<" ";
        cout << endl;

    }


};

segm tree;

void init(vector<long long> a) 
{
    n=a.size();
    b=a;
    tree.inittree(n);
    tree.build(1, 0, n-1);
    //for (ll i=0; i<tree.size; i++) cout <<i<<": "<< tree.values[i].mn <<" "<<tree.values[i].sm<<" "<<tree.values[i].mx<<endl;
}

long long get_sum(int l, int r) {
	
    item ans = tree.getinfo(1, 0, n-1, l, r-1);
    return ans.sm;
}

void add(int l, int r, long long x) {
	
    tree.addrange(1, 0, n-1, l, r-1, x);
   // for (ll i=0; i<tree.size; i++) cout <<i<<": "<< tree.values[i].mn <<" "<<tree.values[i].sm<<" "<<tree.values[i].mx<<endl;
   //cout << endl<<endl;
}

void set_range(int l, int r, long long x) {
	
    tree.changerange(1, 0, n-1, l, r-1, x);
   // for (ll i=0; i<tree.size; i++) cout <<i<<": "<< tree.values[i].mn <<" "<<tree.values[i].sm<<" "<<tree.values[i].mx<<endl;
    //cout << endl<<endl;
}

long long get_min(int l, int r) {
	
    item ans = tree.getinfo(1, 0, n-1, l, r-1);
   // for (ll i=0; i<tree.size; i++) cout <<i<<": "<< tree.values[i].mn <<" "<<tree.values[i].sm<<" "<<tree.values[i].mx<<endl;
   // cout << endl<<endl;
    return ans.mn;
}

int lower_bound(int l, int r, long long x) {
	
    return tree.lower(1, 0, n-1, l, r-1, x);
}
