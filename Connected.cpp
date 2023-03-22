#include <bits/stdc++.h>
using namespace std;

void traverse(int i, vector<int> &visited, vector<int> adj[])
{
    visited[i] = 1;
    for(auto it:adj[i])
    {
        if(!visited[it])
            traverse(it,visited,adj);
    }
}

int DFS(int V, vector<int> adj[])
{
    vector<int> visited(V,0);
    visited[0] = 1;
    traverse(0,visited,adj);
    for(auto it:visited)
    {
        if(it == 0)
            return 0;
    }
    return 1;
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
    if(DFS(N,adj))
        cout << "connected";
    else
        cout << "unconnected";
}

