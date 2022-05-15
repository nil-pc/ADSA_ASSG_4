//Bellmanford Algorithm

#include <string.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h> 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;

typedef struct Edge
{
    int source, destination, weight;
}Edge;
 

typedef struct Graph
{
    int V, E;
    Edge* edge;
}graph;
 
graph* create_graph(int V, int E)
{
    graph* g= (graph*) malloc(sizeof(graph));
    g->V=V;   
    g->E=E;
    g->edge = (Edge*) malloc(g->E*sizeof(Edge));
    return g;
}
 
void BellmanFord(graph* g, int source)
{
	int V=g->V;
	int E=g->E;
 	int StoreDistance[V];
    int Parent[V];
 	int i,j,u,v,weight;
 	for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
 	StoreDistance[source] = 0;
 
	for (i = 1; i <= V-1; i++)
    {
    	for (j = 0; j < E; j++)
    	{
    		u = g->edge[j].source;
            v = g->edge[j].destination;
            weight = g->edge[j].weight;
 			if (StoreDistance[u] + weight < StoreDistance[v])
            {
 		        StoreDistance[v] = StoreDistance[u] + weight;
                Parent[v] = u;
            }

    	}
    }
 	for (i = 0; i < V; i++)
    {
        cout<<"\nDistance of vertex "<<source<<" to "<<i<<" is "<<StoreDistance[i];
   	}
}
 
int main()
{
	int V,E,S,i;
    cout<<"\nEnter number of vertices and edges : ";
    cin>>V>>E;
    graph* g = create_graph(V, E);
    cout<<"\nEnter each edge and its weight (u, v, wt) : ";
    for(i=0;i<E;i++)
    {
        
    	cin>>g->edge[i].source;
    	cin>>g->edge[i].destination;
    	cin>>g->edge[i].weight;
    }
    cout<<"\nEnter the source vertex : ";
    cin>>S;
    BellmanFord(g, S);
    return 0;
}