#include <bits/stdc++.h>
using namespace std;

void traverse(int i, vector<int> &visited, vector<int> adj[])
{
    visited[i] = 1;
    cout << i << " ";
    for(auto it:adj[i])
    {
        if(!visited[it])
            traverse(it,visited,adj);
    }
}

void DFS(int V, vector<int> adj[])
{
    vector<int> visited(V,0);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            traverse(i,visited,adj);
            cout << endl;
        }
    }
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

    cout << endl << "DFS of given graph: " << endl;
    DFS(N,adj);
}
