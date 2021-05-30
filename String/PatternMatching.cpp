#include <bits/stdc++.h>
using namespace std;


vector<int> prefix(string s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int l=0, r=1;
    for (int i=1; i<n; i++)
    {
        if(i >= r) // se è fuori dell'intervallo
        {
            l=i;
            r=i;
            while(r<n && s[r]==s[r-l]) r++; //allargo l'intervallo finchè posso
            z[i]=r-l;
        }
        else
        {
            int k = i-l;
            if(z[k]<r-i) z[i]=z[k]; //se sta dentro l'intervallo so già quanto vale
            else
            {
                l=i; //altrimenti spotso la finestra da i 
                while(r<n && s[r]==s[r-l]) r++; //vado avanti finchè posso
                z[i]=r-l;
            }
        }
    }
    return z;
}

int matching(string txt, string patt)
{
    string s = patt+"$"+txt;
    vector<int> z = prefix(s); 
   // for (int i : z) cout<< i<<" ";
    return count(z.begin(), z.end(), patt.size());

}


int main()
{
    string s, t;
    cin >> s >> t;
    cout << matching(s, t);
}