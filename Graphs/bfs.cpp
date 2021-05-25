#include <bits/stdc++.h>

using namespace std;

int N, M;
vector <vector <int> > adj_list (30);

int main()
{
    ifstream in ("/home/laura/input.txt");
    in >> N >> M;

    for (int i=0; i<M; i++)
    {
        int x, y;
        in >> x >> y;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);

    }

    queue<int> q;
    vector <bool> visited(N, false);

    q.push(0);
    visited[0]=true;
    vector <int> parent(N);
    vector <int> distance(N);

    parent[0]=0;
    distance[0]=0;

    while (!q.empty())
    {
        int x= q.front();
        cout << "Ho visitato il nodo " << x << endl << "Il suo parent è " << parent[x] << "La sua d è " << distance[x] << endl;
        q.pop();

        for (int i=0; i<adj_list[x].size(); i++)
        {
            if (visited[adj_list[x][i]]==false)
            {
                parent[adj_list[x][i]]=x;
                distance[adj_list[x][i]]= distance[x]+1;
                q.push(adj_list[x][i]);
                visited[adj_list[x][i]]=true;
            }



        }


    }

    int nodo=6;
    stack <int> s;

    while (nodo!=0)
    {
        s.push(nodo);
        nodo=parent[nodo];
    }

    s.push(0);
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();

    }
    return 0;
}
