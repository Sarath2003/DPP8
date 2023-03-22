#include <bits/stdc++.h>
using namespace std;

void topoSort(int N, vector<int> adj[])
{
    vector<int> indegree(N,0);
    for(int i=0; i<N; i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<N; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
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
    }

    topoSort(N,adj);
}

