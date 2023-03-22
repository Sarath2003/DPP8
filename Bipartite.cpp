#include <bits/stdc++.h>
using namespace std;

bool detect(int i, int col, vector<int> &color, vector<int> adj[])
{
    color[i] = col;
    for(auto it:adj[i])
    {
        if(color[it] == -1)
            detect(it,!col,color,adj);
        else if(color[it] == col)
            return false;
    }
    return true;
}

bool Bipartite(int V, vector<int> adj[])
{
    vector<int> color(V,-1);
    for(int i=0; i<V; i++)
    {
        if(color[i] == -1)
        {
            if(!detect(i,0,color,adj))
                return false;
        }
    }
    return true;
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
    if(Bipartite(N,adj))
        cout << "Bipartite";
    else
        cout << "not bipartite";
}
