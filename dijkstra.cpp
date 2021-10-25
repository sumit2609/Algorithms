#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int,int>>> &adj, int u,int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void dijkstra(int src, int n, vector<vector<pair<int,int>>> adj){
    vector<int> dis(n,INT_MAX);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dis[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto it: adj[node]){
            if(dis[it.first]>dist+it.second){
                dis[it.first] = dist+it.second;
                pq.push({dis[it.first],it.first});
            }
        }  
    }

    for(int i = 0; i<n; i++)
        cout<<i<<"    "<<dis[i]<<endl;

}

int main(){
    int n = 9;

    vector<vector<pair<int,int>>> adj(n);
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    dijkstra(0, n, adj);

    return 0;
}