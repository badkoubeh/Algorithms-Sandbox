#include "Header.h"



using namespace std;

Graph::Graph(int V, bool is_weighted): V(V)
{
	if (!is_weighted)
		adj = new list<int> [V];
	else
		adj_w = new list<iPair> [V];
}

Graph::Graph(int V, int E): V(V), E(E)
{
	this->edge = new Edge[this->E * sizeof(Edge)];
}

// addEdge() creates an edge between vertices v and u.
// is_directed bool value defines if the graph is directed or undirected.
// if is_directed is defaulted to false unless determined by user
void Graph::addEdge(int v, int u, bool is_directed)
{
		if (is_directed)
			adj[v].push_back(u); //Add u to v's list
		else
		{
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
}

void Graph::addEdge(int v, int u, int w, bool is_directed)
{
	if (is_directed)
		adj_w[v].push_back(make_pair(w, u));
	else
	{
		adj_w[v].push_back(make_pair(u, w));
		adj_w[u].push_back(make_pair(v, w));
	}
}


void Graph::displayVertices()
{
	list<int>::iterator itr;

	for (int i = 0; i < V; ++i)
	{
		for (itr = adj[i].begin(); itr != adj[i].end(); ++itr)
		{
			cout << i << "--" << *itr << "\t";
		}
		cout << endl;
	}
		
}
void Graph::DFSUtil(int source, bool visited[])
{
	visited[source] = true;
	cout << " vertix: " << source << "\t";

	//Recur for all the vertices adjacent to this vertex
	list<int>::iterator itr;
	for (itr = adj[source].begin(); itr != adj[source].end(); ++itr)
	{
		if (!visited[*itr])
		{
			DFSUtil(*itr, visited);
		}
	}

}

void Graph::DFS()
{
	// Mark all the vertices as not visited 
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print DFS traversal
	// Starting from all vertices one by one
	for (int i = 0; i < V; ++i)
		if(!visited[i])
			DFSUtil(i, visited);
}

// time complexity O(V+E) 
// In worst case for directed graphs, E= V(V-1) and undirected grpahs, E=V(V-1)/2 => O(V^2)
void Graph::BFS(int source)
{
	//Mark all vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}

	// create a queue for BFS
	queue<int> bsf_q;

	// mark the current node as visited and enqueue it
	visited[source] = true;
	bsf_q.push(source);

	// vertices of a vertex
	list<int>::iterator itr;

	while (!bsf_q.empty())
	{
		// Dequeue a vertex from queue and print it
		source = bsf_q.front();
		cout << source << " ";
		bsf_q.pop();

		// Get all adjacent vertices of the dequeued
		for (itr = adj[source].begin(); itr != adj[source].end(); ++itr)
		{
			if (!visited[*itr])
			{
				bsf_q.push(*itr);
				visited[*itr] = true;
			}
		}
	}
}

// This sort is for Directed Acyclic Graphs (DAG) and is a linear ordering of vertices such that
// for every directed edge(u,v), vetex u comes before v in the ordering. 
// Topological Sort is NOT unique
void Graph::TopologicalSort()
{
	// Mark all the vertices as not visited 
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	stack<int> sorted_stack;

	// Call the recursive helper function
	for (int i = 0; i < V; ++i)
		if (!visited[i])
			TopologicalSortUtil(i, visited, sorted_stack);
}
void Graph::TopologicalSortUtil(int v, bool visited[], stack<int> &sorted_stack)
{
	visited[v] = true;

	for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
			TopologicalSortUtil(*i, visited, sorted_stack);
		
	}
	sorted_stack.push(v);
}// O(V+E)

// Cycle detection in a directed Graph-------------------------------------------------------------------------------------------------
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack)
{
	if (visited[v] == false)
	{
		// Mark the current node as visited and part of recursion stack 
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex 
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])
				return true;
		}

	}
	recStack[v] = false;  // remove the vertex from recursion stack 
	return false;
}

// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited and not part of recursion 
	// stack 
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different 
	// DFS trees 
	for (int i = 0; i < V; i++)
		if (isCyclicUtil(i, visited, recStack))
			return true;

	return false;
}

// Cycle Detection in a undirected graph, Union Find Algorithm (assume there is no self-loop)
// there is a more efficinet impelemntaiton of this algorithm in Algorithm.cpp
bool Graph::isCycleUndirectedG()
{
	// Allocate memory for creating V subsets
	int *parent = new int[V * sizeof(int)];

	// Initialize all subsets as single element sets
	memset(parent, -1, sizeof(int) * V);

	for (int i = 0; i < E; i++)
	{
		int x = find(parent, edge[i].src);
		int y = find(parent, edge[i].dest);
		if (x == y)
			return true;
		else
			unionUtil(parent, x, y);
	}

	return false;
}
// utility func to find the subset of an element i
int Graph::find(int parent[], int i)
{
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}
// a utility func to do union of two subsets
void Graph::unionUtil(int parent[], int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);
	if (xset != yset)
		parent[xset] = yset;
}

// for undirected graph we can also use DFS with visited array and passing parent value for cycle detection O(V+E)
// bool isCycleUndirectedGUtil(int source, bool viisted[], int parent)



NodeInfo::NodeInfo(int x, int y, int d): row(x), col(y), dist(d){}

int MinDistance(char grid[N][M])
{
	NodeInfo source(0, 0, 0);

	// mark danger spots at true so we won't visit
	bool visited[N][M];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (grid[i][j] == '0')
				visited[i][j] = true;
			else
				visited[i][j] = false;

			//Finding source
			if (grid[i][j] == 's')
			{
				visited[i][j] = true;
				source.row = i;
				source.col = j;
			}
		}
	}

	// Applying BFS on matrix cells from source
	queue<NodeInfo> cell_q;
	cell_q.push(source);

	while (!cell_q.empty())
	{
		NodeInfo point = cell_q.front();
		cell_q.pop();

		//Destination found conditon
		if (grid[point.row][point.col] == 'd')
			return point.dist;

		// moving up
		if ((point.row -1) >= 0 && !visited[point.row -1][point.col])
		{
			cell_q.push(NodeInfo(point.row - 1, point.col, point.dist + 1));
			visited[point.row - 1][point.col] = true;
		}

		// moving down
		if ((point.row + 1) < N && !visited[point.row + 1][point.col])
		{
			cell_q.push(NodeInfo(point.row + 1, point.col, point.dist + 1));
			visited[point.row + 1][point.col] = true;
		}

		//moving left
		if ((point.col - 1) >= 0 && !visited[point.row][point.col -1])
		{
			cell_q.push(NodeInfo(point.row, point.col - 1, point.dist + 1));
			visited[point.row][point.col -1] = true;
		}

		//moving right
		if ((point.col + 1) < M && !visited[point.row][point.col + 1])
		{
			cell_q.push(NodeInfo(point.row, point.col + 1, point.dist + 1));
			visited[point.row][point.col + 1] = true;
		}
	}
	return -1;

}