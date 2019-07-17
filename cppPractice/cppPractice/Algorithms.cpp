#include "Header.h"
// Algorithm Paradigms
// 1. Greedy Algorithms
// 2. DP
// 3. Divide and Conquer
// 4. Backtracking
// 5. Branch and Bound

//************************************************************************************************************************************************
// 1. Greedy Algorithms
//************************************************************************************************************************************************
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
	qsort(sorted_edges, graph->E, sizeof(graph->edge[0]), CompOpr); // O(E logE), worst case O(E^2)

	// Allocate memory for creating V subsets
	Subset *subsets = new Subset[V * sizeof(Subset)];

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// number of edges to be taken is equal to V-1
	while (i_result < V-1)
	{
		//Step 2: Pick the smallet edge and increment the index for the next iteraiton
		// find union operation is almost O(logV)
		Edge next_edge = sorted_edges[i_sorted++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		if (x != y) // if they don't create a cycle add the edge into the result array and take a union of them
		{
			result_MST[i_result++] = next_edge;
			Union(subsets, x, y);
		}
	} // O(ElogV) the whole while loop time ecomplexity

	for (int i = 0; i < V - 1; ++i)
	{
		cout << result_MST[i].src << " -- "<< result_MST[i].weight <<" -- " << result_MST[i].dest << endl;
	}
} // O(ElogV) + O(E logE) = O(E logE)
int CompOpr(const void* e1,const void* e2)
{
	Edge* edge1 = (Edge*)e1;
	Edge* edge2 = (Edge*)e2;
	return edge1->weight > edge2->weight;
}

//************************************************************************************************************************************************
// Prim's Minimum Spanning Tree 
// time complexity of Prim's algorithm for adjacency matrix is O(V^2)

// In case the graph is represented by adjacency list, 
// the time complexity can be reduced to O(ElogV) with the help of binary heap

// here is an implemention of Prim Algo for graphs represented by adjacency list  
void PrimMST(list<iPair> *adj, int V)
{
	// Create a priority queue to store vertices that 
	// are being preinMST.
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	// create a vector to store the distance of all vertices
	vector<int> cost(V, 9999); // initialize it with INF value
	cost[0] = 0;	// other than the first vetrex
	
	pq.push(make_pair(cost[0], 0));

	vector<int> parent(V,-1);
	vector<bool> is_inMST(V,false);
	parent[0] = 0;

	list<iPair>::iterator itr;
	 // loop through the min heap 
	while (!pq.empty())
	{
		int u = pq.top().second;
		is_inMST[u] = true;
		pq.pop();

		for (itr = adj[u].begin(); itr != adj[u].end(); ++itr)
		{
			int v = (*itr).first;
			int weight = (*itr).second;

			if (cost[v] > weight && is_inMST[v] == false)
			{
				cost[v] = weight;
				pq.push(make_pair(cost[v], v));
				parent[v] = u;	// include the vertex with min distance in MST
			}
		}
	}
	int cost_MST = 0;
	for (int i=1; i<V; ++i)
	{
		cost_MST += cost[i];
		cout << parent[i] <<"--"<< i << " weight: "<<cost[i]<<endl;
	}
	cout << "MST cost= " << cost_MST << endl;
}


//************************************************************************************************************************************************
// Shortest Path Algorithms:
// if all edge weights were equal or 1 a siple BFS can be used to find the shortest path
// buhere weights can take any value, three different algorithms come handy
// Disktra and Floyd-Warshall  

//Dijkstra’s Shortest Path Algorithm
// Note that it will only work for graphs with positive weights
// time complexity O(ElogV)

typedef pair<int, int> iPair;

void Dijkstra(list<iPair> *adj, int V, int source)
{
	// Min Heap or priority queue to store proccessed points
	// the vertex with shortest distance will be stored at top of the heap
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	// store the distance of all vertices
	vector<int> dist(V, 9999);
	dist[source] = 0;

	pq.push(make_pair(dist[source], source));

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
// 4. Backtracking
//************************************************************************************************************************************************
// Backtracking algorithms in Graphs
// Detect Hamiltonian Cycle

// Applying DFS with backtracking will help to check if a Hamiltonina path exists

void HamiltonianCycle(bool graph[5][5], int V)
{
	// to store hamiltonian cycle
	vector<int> path(V, -1);
	path[0] = 0;

	//path index starting from 1 becasue 0 is already added
	int i_path = 1;

	if (HamiltonianCycleUtil(graph, V, path, i_path))
	{
		for (auto x : path)
			cout << x << "\t";
		cout << endl;
	}
	else
		cout << " Hamiltonian Cycle NOT found." << endl;
}

bool HamiltonianCycleUtil(bool graph[5][5], int V, vector<int> &path, int i_path)
{
	// base case
	if (i_path == V)
		if (graph[path[i_path - 1]][path[0]])
			return true;
		else
			return false;

	for (int v = 1; v < V; ++v)
	{
		if (isValid(graph,path,i_path, v))
		{
			path[i_path] = v;
			if (HamiltonianCycleUtil(graph, V, path, i_path + 1))
				return true;

			// remove the vertix if it does not lead to Hamiltonian Cycle (Backtraking)
			path[i_path] = -1;
		}
	}
	return false;
}
bool isValid(bool graph[5][5], vector<int> &path, int i_path, int v)
{
	if (graph[path[i_path-1]][v] == 0)
		return false;
	
	for (int i = 0; i < i_path; ++i)
		if (path[i] == v)
			return false;

	return true;
}

//************************************************************************************************************************************************
// Ford-Folkerson Algorithm for Maximum Flow network

