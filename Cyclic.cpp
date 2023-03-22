#include <bits/stdc++.h>
using namespace std;

bool detect(int i, vector<int> &visited, vector<int> adj[])
{
    visited[i] = 1;
    queue<pair<int,int>> q;
    q.push({0,-1});
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        int node = t.first;
        int parent = t.second;
        for(auto it:adj[node])
        {
            if(visited[it] && it!=parent)
                return true;
            else if(!visited[it])
            {
                q.push({it,node});
                visited[it] = 1;
            }
        }
    }
    return false;
}

bool cyclicCheck(int V, vector<int> adj[])
{
    vector<int> visited(V,0);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            if(detect(i,visited,adj))
                return true;
        }
    }
    return false;
}

int main()
{
    int N,E;
    cin >> N >> E;
    vector<int> adj[N];
    for(int i=0; i<E; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << endl << "The graph is ";
    if(cyclicCheck(N,adj))
        cout << "cyclic";
    else
        cout << "not cyclic";

    return 0;
}
