#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

struct MinQueue
{
    int s, t;
    deque<pi> q;
    MinQueue (int x) {s=x; t=0;}

    void push(int x)
    {
        while(!q.empty() && q.back().first > x ) q.pop_back(); // se l'elemento in fondo è maggiore di x lo scarto perchè ne ho trovato uno successivo minore
        q.push_back({x, t});
        t++;
        while(q.front().second < t-s) q.pop_front();
    }
    int getmin()
    {
        return q.front().first;
    }
};

int main()
{

}