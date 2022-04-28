#include <bits/stdc++.h>
using namespace std;

int L;
int n;
vector<int> v;
vector<vector<int>> table;
void sparsetable()
{
    for (int i=0; i<n; i++) table[i][i] = v[i];
    for (int l=1; l<=L; l++)
    {
        int k = (1 << l);
        for (int i = 0; i<n-k+1; i++)
        {
            int m = k/2;
            table[i][i+k-1] = min(table[i][i+m-1], table[i+m][i+k-1]);
        }
    }
}
int getmin(int a, int b)
{
    int p = log2(b-a+1);
    return min(table[a][a+p-1], table[b-p+1][b]);
}

int main()
{
    v = {2, 4, 5, 1, 7, 2, 3};
    n = v.size();
    table.resize(n, vector<int>(n));
    L = log2(n);

    sparsetable();
    cout << getmin(1, 2);


}