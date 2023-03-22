#include <bits/stdc++.h>
using namespace std;

void traverse(int i, vector<int> adj[], vector<int> &visited)
{
    visited[i] = 1;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it]=1;
            }
        }
    }
}

void BFS(int V, vector<int> adj[])
{
    vector<int> visited(V,0);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            traverse(i,adj,visited);
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

    cout << endl << "BFS of given graph: " << endl;
    BFS(N,adj);
}
