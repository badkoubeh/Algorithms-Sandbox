#include<iostream>
#include <vector>
#include <list>
#include <forward_list>
#include<deque>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include <iterator> 
#include <algorithm>
#include <string>
#include <bitset>
#include<math.h>
using namespace std;
typedef pair<int, int> iPair;
#pragma once
#ifndef ISUNIQUECHARS_H_INCLUDED_
#define ISUNIQUECHARS_H_INCLUDED_
bool isUniqueChars(char str[]);
#endif


#ifndef CHECKPERMUTATION_H_INCLUDED_
#define CHECKPERMUTATION_H_INCLUDED_
bool checkPermutation(string str1, string str2);
#endif

#ifndef CANFORMPALINDROME_H_INCLUDED_
#define CANFORMPLINDROME_H_INCLUDED_
bool canFormPalindrome(string str);
#endif

#ifndef ISEDITDISTANCEISONE_H_INCLUDED_
#define ISEDITDISTANCEISONE_H_INCLUDED_
bool isEditDistanceOne(string str1, string str2);
#endif

#ifndef REMOVEDUPLINKEDLIST_H_INCLUDED_
#define REMOVEDUPLINKEDLIST_H_INCLUDED_
void RemoveDupLinkedList(list<int> &ls);
#endif

#ifndef SUMLINKEDLIST_H_INCLUDED_
#define SUMLINKEDLIST_H_INCLUDED_
list<int> SumLinkedList(list<int> &ls1, list<int> &ls2);
#endif

#ifndef GRAYCODE_H_INCLUDED_
#define GRAYCODE_H_INCLUDED_
bool isConsequitiveGrayCode(unsigned char h1, unsigned char h2);
void bin(unsigned char);
#endif

#ifndef MERGESORT_H_INCLUDED_
#define MERGESORT_H_INCLUDED_
void mergeSort(int arr[], int arr_size);
void mergeSort(int arr[], int left_start, int right_end);
void mergeHalves(int arr[], int left_start, int right_end, int mid);
#endif

#ifndef NEARESTPOINT_H_INCLUDED_
#define NEARESTPOINT_H_INCLUDED_
class Point
{
public:
	int x;
	int y;
	int dist;
	Point(int n, int m);
	void EuclideanDist(Point p0);
};
struct Compare
{
	bool operator()(Point &a, Point &b) {
		return a.x*a.x + a.y*a.y > b.x*b.x + b.y*b.y;
	}
};

void NearestPoints(vector<Point> &points, Point &origin, int k);

#endif

#ifndef GRAPH_H_INCLUDED_
#define GRAPH_H_INCLUDED_
#define N 6 
#define M 6 

struct Subset
{
	int parent;
	int rank;
};

class Edge
{
public:
	int src, dest;
	int weight = 1;
};

class Graph
{
private:
	bool is_weighted_;
	void DFSUtil(int source, bool visited[]);
	void TopologicalSortUtil(int source, bool visited[], stack<int> &sorted_stack);
	int find(int parent[], int i);
	void unionUtil(int parent[], int x, int y);
	bool isCyclicUtil(int v, bool visited[], bool *recStack);
public:
	// 1. graph can be represented as an array of adjacency list
	list<int> *adj;
	list<iPair> *adj_w;

	// 2. graph can be represented as an 2D matrix

	// 3. graph can be represented as an array of edges
	Edge* edge;
	// V-> Number of vertices, E-> Number of edges 
	int V, E;
	Graph(int V, bool is_weighted = false);	// to represent a graph by adjacency list 
	Graph(int V, int E);	// to represent a graph by Edge structure
	void addEdge(int v, int u, bool is_directed=false);
	void addEdge(int v, int u, int w, bool is_directed = false);
	void displayVertices();
	void BFS(int source);
	void DFS();
	void TopologicalSort();
	bool isCyclic();
	bool isCycleUndirectedG();
};

class NodeInfo
{
public:
	int row;
	int col;
	int dist;
	NodeInfo(int x, int y, int d);
};

int MinDistance(char grid[N][M]);
#endif

#ifndef LINKEDLIST_H_INCLUDED_
#define LINKEDLIST_H_INCLUDED_
class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *head;
	Node *tail;
public:
	LinkedList();
	void CreateNode(int value);
	bool LoopDetection(Node *head);
	void DisplayNodes();
	void DeleteDup();
};
#endif

#ifndef TRAVELEDDISTANCE_H_INCLUDED_
#define TRAVELEDDISTANCE_H_INCLUDED_
class Gps
{
public:
	double latitude;
	double longintude;
	Gps(double lat, double lng);
	~Gps();
};
int CalculateDistance(Gps point1, Gps point2);
#endif

#ifndef STACKWITHMIN_H_INCLUDED_
#define STACKWITHMIN_H_INCLUDED_
class StackWithMin
{
private:
	stack<int> stk_;
	vector<int> min_;
public:
	StackWithMin();
	void push(int val);
	void pop();
	int peek();
	int min();
};
#endif

#ifndef BINARYTREE_H_INCLUDED_
#define BINARYTREE_H_INCLUDED_
struct TreeNode
{
	int data;
	TreeNode *left, *right;
};
class AvgTree
{
public:
	TreeNode* node;
	int sum, size;
	AvgTree(TreeNode* node, int sum, int size);
};
TreeNode* NewNode(int data);
TreeNode* insert(TreeNode* root, int new_val);
int binarySearch(int *arr, int left_start_index, int right_end_index, int search_value);
void InorderTraversal(TreeNode* root);
void StoreNodes2Set(TreeNode* root, set<int>& s);
void Set2BST(set<int>& s, TreeNode* root);
void BinaryTree2BST(TreeNode* root);
int FindLagestSubtreeSum(TreeNode* root);
int MaximumAvgNode(TreeNode* root);
int MaximumAvgNode(TreeNode* root);
AvgTree* MaxAvgSubtree(TreeNode* root);
TreeNode* minimalTree(int *arr, int arr_size);
TreeNode* minimalTreeUtil(int *arr, int left_start, int right_end);
vector<list<TreeNode*>> createLevelLinkedList(TreeNode* root);
bool isBalanced(TreeNode* root);
int checkHeight(TreeNode* root);
bool checkBST(TreeNode* root);
bool checkBST(TreeNode* root, int min, int max);
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* node);
#endif

#ifndef SORTAMAZONORDERLIST_H_INCLUDED_
#define SORTAMAZONORDERLIST_H_INCLUDED_
vector<string> SortAmazonOrderList(vector<string> order_list);
void OrderStringParser(string str, string &token_id, string &token_metadata);
bool comp(string a, string b);
#endif

#ifndef SOERSTACK_H_INCLUDED_
#define SOERSTACK_H_INCLUDED_
stack<int> sortStack(stack<int> &s);
void sortStackRecu(stack<int> &s);
void sortedInsert(stack<int> &s, int top);
#endif

#ifndef BASICMATHOPERATION_H_INCLUDED_
#define BASICMATHOPERATION_H_INCLUDED_
int Gcd(int a, int b);
int Lcm(int a, int b);
void primeFactors(int n);
#endif

#ifndef ALGORITHMS_H_INCLUDED_
#define ALGORITHMS_H_INCLUDED_
void KruskalMST(Graph *graph);
int find(Subset *subsets, int i);
void Union(Subset *subsets, int x, int y);
int CompOpr(const void* e1, const void* e2);
void Dijkstra(list<iPair> *adj, int V, int source);
#endif

#ifndef PHONELEYPADPROBLEM_H_INCLUDED_
#define PHONELEYPADPROBLEM_H_INCLUDED_
void letterCombinaiton(string number);
void letterCombinaitonUtil(string number, int index, map<int, string> keypad, vector<string> &result, char str_builder[]);
#endif

#ifndef COMBINATION_H_INCLUDED_
#define COMBINATION_H_INCLUDED_
void CombinationRepetitionUtil(int chosen[], int arr[],
	int index, int r, int start, int end);
void CombinationRepetition(int arr[], int n, int r);
void CombinationNoRepetition(int arr[], int n, int r);
void combinationNoRepetitionUtil(int arr[], int data[],
	int start, int end,
	int index, int r);
#endif

#ifndef PERMUTATION_H_INCLUDED_
#define PERMUTATION_H_INCLUDED_
void PermutationRepetition(char set[], int k, int n);
void permutationRepetitionUtil(char set[], string prefix, int n, int k);
void swap(char *x, char *y);
void permute(char *a, int l, int r);
#endif
