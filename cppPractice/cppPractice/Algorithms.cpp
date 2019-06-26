#include "Header.h"
// Algorithm Paradigms
// 1. Greedy Algorithms
// 2. DP
// 3. Divide and Conquer
// 4. Backtracking
// 5. Branch and Bound


// 1. Greedy Algorithms
//Greedy Algorithms in Graphs :
//
//Kruskal’s Minimum Spanning Tree
//Prim’s Minimum Spanning Tree
//Boruvka’s Minimum Spanning Tree
//Reverse delete algorithm for MST
//Problem Solving for Minimum Spanning Trees(Kruskal’s and Prim’s)
//Dijkastra’s Shortest Path Algorithm
//Dial’s Algorithm
//Dijkstra’s Algorithm for Adjacency List Representation
//Prim’s MST for adjacency list representation
//Correctness of Greedy Algorithms
//Minimum cost to connect all cities
//Max Flow Problem Introduction
//Number of single cycle components in an undirected graph

//************************************************************************************************************************************************
//Kruskal's Minimum Spanning Tree (MST)
// MST of given connected, undirected and weighted graph
// Algorithm: Pick an edge, if no cycle is formed iclude it in the MST.

// Applications of MST: Steiner tree (combination of MST and shortest path problem next algortihm)
// Approximation of NP-hard problems like Traveling Salesman Problem (TSP).
// other applicaitons: Clustring analysis, Netwokr design, 
void KruskalMST(Graph *graph)	// a graph represented by edge structure
{
	int V = graph->V;
	Edge *result_MST = new Edge[V-1];
	int i_result = 0;
	int i_sorted = 0;

	//Step 1: sort all edges in non-decreasing order of their weight. 
	Edge *sorted_edges = graph->edge;
	qsort(sorted_edges, graph->E, sizeof(graph->edge[0]), CompOpr);

	// Allocate memory for creating V subsets
	Subset *subsets = new Subset[V * sizeof(Subset)];

	// Create V subsets with singl elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// number of edges to be taken is equal to V-1
	while (i_result < V - 1)
	{
		//Step 2: Pick the smallet edge and increment the index for the next iteraiton
		Edge next_edge = sorted_edges[i_sorted++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		if (x != y)
		{
			result_MST[i_result++] = next_edge;
			Union(subsets, x, y);
		}
	}

	for (int i = 0; i < V - 1; ++i)
	{
		cout << result_MST[i].src << " -- "<< result_MST[i].weight <<" -- " << result_MST[i].dest << endl;
	}
}
int CompOpr(const void* e1,const void* e2)
{
	Edge* edge1 = (Edge*)e1;
	Edge* edge2 = (Edge*)e2;
	return edge1->weight > edge2->weight;
}

//************************************************************************************************************************************************
//Dijkstra’s Shortest Path Algorithm
// Note this will only work for graphs with positive weights
// time complexity O(ElogV)

typedef pair<int, int> iPair;

void Dijkstra(list<iPair> *adj, int V, int source)
{
	// Min Heap or priority queue to store proccessed points
	// the vertex with shortest distance will be stored at top of the heap
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	// store the distance of all vertices
	vector<int> dist(V, 9999);

	pq.push(make_pair(0, source));
	dist[source] = 0;

	list<iPair>::iterator itr;

	while (!pq.empty())
	{
		auto u = pq.top().second;
		pq.pop();

		for (itr = adj[u].begin(); itr != adj[u].end(); ++itr)
		{
			int v = (*itr).first;
			int weight = (*itr).second;

			// here is where greedy paradigm is implemented. 
			// shorter distance is the condition to process a node.
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}		
		}
	}

	for (auto i = 0; i < V; ++i)
	{
		cout << "node: "<<i<<" dist: "<<dist[i] << endl;
	}
}

//************************************************************************************************************************************************
//Union-Find by Rank algorithm 
//which makes the union-find more efficient to 
// O(logn)

// find set of an element i
int find(Subset *subsets, int i)
{
	// find root and make it as parent of i (path compression)
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(Subset *subsets, int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// Attach smaller rank tree under root of high rank tree
	// Union by Rank
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	
	// If ranks are the same, then make one as root and increment 
    // its rank by one 
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
//************************************************************************************************************************************************
