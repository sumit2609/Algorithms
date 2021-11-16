#include<bits/stdc++.h>
using namespace std;

//Time complexity of floyd warshell O(v^3) 
//Space complexity O(v^2)

#define V 6	 //no.vertices

void floyd_warshall(int graph[V][V])
{
    int dist[V][V];

    //assign value of graph to dist 
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    //Find all pairs shortest path by trying all possible paths
    for(int k = 0; k<V; k++){ //intermediate node
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                else if(dist[i][k]+dist[k][j]<dist[i][j]){ //checking if distance via k is smaller
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    // check for negative edge weight cycle
    for(int i = 0; i<V; i++){
        if(dist[i][i]<0)
        {
            cout<<"Negative edge weight cycle is present\n";
            return;
        }
    }

    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            cout<<i<<" to "<<j<<" distance is "<<dist[i][j]<<endl;
        }
        cout<<endl;
    }

}

int main(){

    int graph[V][V] = {
        {0,1,4,INT_MAX,INT_MAX,INT_MAX},
        {INT_MAX,0,4,2,7,INT_MAX},
        {INT_MAX,INT_MAX,0,3,4,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,0,INT_MAX,4},
        {INT_MAX,INT_MAX,INT_MAX,3,0,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,0}
    };

    // int graph[V][V] = {
    //     {0,3,INT_MAX,1},
    //     {2,0,INT_MAX,INT_MAX},
    //     {INT_MAX,1,0,INT_MAX},
    //     {INT_MAX,INT_MAX,2,0}
    // };

    floyd_warshall(graph);

    return 0;
};


