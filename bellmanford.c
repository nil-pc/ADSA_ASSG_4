//Bellmanford Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
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
 		               StoreDistance[v] = StoreDistance[u] + weight;
        	}
    	}
 	for (i = 0; i < E; i++)
    	{
        	u = g->edge[i].source;
 		v = g->edge[i].destination;
 		weight = g->edge[i].weight;
 		if (StoreDistance[u] + weight < StoreDistance[v])
           	{ 
			printf("1\n");
		    	exit(0);
	   	}
   	}
	printf("-1\n"); 
    	return;
}
 
void main()
{
	int V,E,S,i; 
    	scanf("%d",&V);
    	scanf("%d",&E);
    	S=0;
    	graph* g = create_graph(V, E);  
    	for(i=0;i<E;i++)
    	{
        
        	scanf("%d",&g->edge[i].source);
        	scanf("%d",&g->edge[i].destination);
        	scanf("%d",&g->edge[i].weight);
    	}
    	BellmanFord(g, S);
    	return;
}