#include <bits/stdc++.h> 
#define size 9 
using namespace std;

int nearestNode(int dist[], bool visited[]){ 
    int min = INT_MAX, index; 
    for (int v = 0; v < size; v++) 
        if (visited[v] == false && dist[v] <= min){ 
            min = dist[v]; 
            index = v; 
        }
    return index; 
} 
   
void shortestPath(int graph[size][size], int head) { 
    int dist[size]; 
    bool visited[size];

    for (int i = 0; i < size; i++){
        dist[i] = INT_MAX; 
        visited[i] = false;
    }  
    dist[head] = 0; 
  
    for (int i = 0; i < size - 1; i++) { 
        int u = nearestNode(dist, visited); 
        visited[u] = true; 
  
        for (int v = 0; v < size; v++) 
            if ( !visited[v] && graph[u][v] 
                && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v] ) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
    cout<<"Vertex \t Distances"<<endl; 
    for (int i = 0; i < size; i++) 
        cout<<i<<" \t "<<dist[i]<<endl; 
} 
  
int main() 
{ 
    int graph[size][size] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                            { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                            { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                            { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                            { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                            { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                            { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    shortestPath(graph, 0); 
  
    return 0; 
} 