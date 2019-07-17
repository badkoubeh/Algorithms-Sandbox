#include "Header.h"

//************************************************************************************************************************************************
// Minimum Distance between two nodes in a graph

#define N 6 
#define M 6 

class NodeInfo
{
public:
	int row;
	int col;
	int dist;
	NodeInfo(int x, int y, int d) : row(x), col(y), dist(d) {}
};

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
		if ((point.row - 1) >= 0 && !visited[point.row - 1][point.col])
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
		if ((point.col - 1) >= 0 && !visited[point.row][point.col - 1])
		{
			cell_q.push(NodeInfo(point.row, point.col - 1, point.dist + 1));
			visited[point.row][point.col - 1] = true;
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

//************************************************************************************************************************************************
// Longest Path in a DAG
// longest path problem does not have optimal substructure property. it is a NP-Hard for a general graph


Grph::Grph(int v) : V(v)
{
	adj = new list<AdjList>[v];
}
void Grph::addEdge(int u, int v, int w)
{
	adj[u].push_back(AdjList(v, w));
}

void Grph::LongestPath(int s)
{
	stack<int> tp_sort_stack;
	int *dist = new int[V];
	
	// mark the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
		visited[i] = false;

	// topological sorting of all vertices
	for (int i = 0; i < V; ++i)
		if(!visited[i])
			topologicalSortUtil(i, visited, tp_sort_stack);

	//initialize distance to all vertices as infinite and distance to source as 0
	for (int i = 0; i < V; ++i)
		dist[i] = NINF;
	dist[s] = 0;

	while (!tp_sort_stack.empty())
	{
		int u = tp_sort_stack.top();
		tp_sort_stack.pop();

		if(dist[u] != NINF)
			for (auto itr = adj[u].begin(); itr != adj[u].end(); ++itr)
			{
				AdjList node = *itr;
				int v = node.v;
				int weight = node.weight;
				if (dist[v] < dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
				}
			}
	}
	// print the longest distancec
	cout << "longest distance from vertex " << s << endl;
	for (int i = 0; i < V; ++i)
	{
		if(dist[i]!= NINF)
			cout << "vertex " << i << " dist: " << dist[i] << "\t";
	}
	cout << endl;
}