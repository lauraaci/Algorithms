#include <bits/stdc++.h>
using namespace std;

long res=0;
void computeLPS(string pat,  int M, int lps[] )
{
    int len=0;
    lps[0]=0;
    int i=1;
    while (i < M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;

        }
        else
        {
            if (len!=0) len = lps[len - 1];
            else 
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMP( string pat, string txt)
{
    int m=pat.length();
    int n= txt.length();

    int lps[m];
    computeLPS(pat, m, lps);

    int i=0;
    int j=0;

    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            res++;
            j=lps[j-1];
        }

        else if (i < n && pat[j] != txt[i])
        {
            if (j != 0) j = lps[j - 1];
                 
            else i++;
                
        }
    }
}

int main()
{

}