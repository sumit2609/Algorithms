#include <bits/stdc++.h>
using namespace std;

int main()
{
    //vertices,edges
    cout<<"enter no. of vertices and edges"<<endl;
    int N, m;
    cin >> N >> m;

    vector<pair<int, int>> adj[N];
    int a, b, wt;

    for (int i = 0; i < m; i++)
    {
        cout<<"enter edge "<<i+1<<" :"<<endl; 
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    int parent[N];
    int key[N];
    bool mst[N];

    for (int i = 0; i < N; i++)
    {
        mst[i] = false;
        key[i] = INT_MAX;
    }
    // for source node

    key[0] = 0;
    parent[0] = -1;

    //count is till N-1 because in each step we are selecting an edge and in mst if there are N nodes then there are N-1 edges 
    for (int count = 0; count < N - 1; count++)
    {
        int mini = INT_MAX, u;
        //edge with min weight
        for (int v = 0; v < N; v++)
            if (mst[v] == false && key[v] < mini)
                mini = key[v], u = v;

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (mst[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }
    }
    cout<<"from    -    to"<<endl;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << "       -    " << i << endl;
    }

    return 0;
}
