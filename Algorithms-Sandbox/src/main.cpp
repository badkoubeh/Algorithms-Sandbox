 
#include "Header.h"

using namespace std;

void addIntBytestoVector(std::vector<char> &buf, int num)
{
	for (int i = 4; i > 0; i--)
	{
		cout << hex << (num >> 8 * (i - 1)) << endl;
		buf.push_back((num >> 8 * (i - 1)) & 0xff);
	}
};

void main()
{
	
	/*bool test = isUniqueChars("hello");

	string str1 = "abbccddee";
	string str2 = "edcba";
	string str3 = "abbccdde";
	checkPermutation(str1, str2);
	
	canFormPalindrome(str1);

	if (isEditDistanceOne(str1, str3))
		cout << "one Edit distance" << endl;
	else
		cout << "More than one edit" << endl;*/

	//Linked List
	/*LinkedList linked_list;
	linked_list.CreateNode(4);
	linked_list.CreateNode(6);
	linked_list.CreateNode(8);
	linked_list.DisplayNodes();
*/
	/*
	Gps point1(51, -141);
	Gps point2(52, -141);
	cout << CalculateDistance(point1, point2) << endl;

	// Vector
	vector<int> vec;
	for (int i=1; i <=5; i++)
	{
		vec.push_back(i);
	}
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << "\t";
	}
	cout << endl;
	cout << vec.at(4) << endl;
	vec.insert(vec.begin(),10);
	cout << vec.at(0) << endl;
	*/

	
	//// List (doubly linked list)
	//list<int> ls;
	//list<int> ::iterator it;
	//list<int> ::iterator it2;
	//
	//for (int i = 0; i <= 5; ++i)
	//	ls.push_front(i);

	//ls.remove(8);
	//it = ls.begin();
	//advance(it, 3);
	//ls.insert(it,1,4);

	//for (it = ls.begin(); it != ls.end(); ++it)
	//{
	//	cout << *it << "\t";
	//}
	//cout << endl;
	//
	//list<int> ls1 = ls;

	//RemoveDupLinkedList(ls);

	//for (it = ls.begin(); it != ls.end(); ++it)
	//{
	//	cout << *it << "\t";
	//}
	//cout << endl;

	//list<int> res = SumLinkedList(ls1, ls);
	//
	//for (list<int>::reverse_iterator it = res.rbegin(); it != res.rend(); ++it)
	//{
	//	cout << *it << "\t";
	//}
	//cout << endl;

	/*

	// Deque
	deque<int> dq;

	for (int i = 10; i <= 20; ++i)
		dq.push_back(i * 2);

	deque<int> ::iterator it_dq;
	int i = 0;
	for (it_dq = dq.begin(); it_dq != dq.end(); ++it_dq)
	{

		cout << dq.at(i) << "\t";
		i++;
		cout << *it_dq << "\t";
	}
	cout << endl;
	*/

	////Stack
	//stack<int> stk;

	//for (int i = 40; i <= 50; ++i)
	//	stk.push(i * 2);

	//while (!stk.empty())
	//{
	//	cout << stk.top() << "\t";
	//	stk.pop();
	//}
	//cout << endl;
	//
	//StackWithMin stk2;
	//stk2.push(2);
	//stk2.push(3);
	//stk2.push(5);
	//stk2.push(7);
	//cout << stk2.min() << endl;
	//stk2.push(1);
	//cout << stk2.min() << endl;
	//stk2.pop();
	//cout << stk2.min() << endl;

	/*
	// Set
	set<char> st; // greater <int> sort the elemet from large to small
	
	for (int i = 0; i <= 6; ++i)
	{
		st.insert(int('a')+i);
	}
	set<char> ::iterator it_st;

	for (it_st = st.begin(); it_st != st.end(); ++it_st)
	{
		cout << *it_st << "\t";
	}
	cout << endl;
	it_st = st.find('a');
	cout << *it_st << endl;
	/*
	// Hash Map 
	map<int, char> mp;
	for (int i = 0; i <= 7; ++i)
	{
		mp.insert(pair<int, char>(i, 'a' + i));
	}
	map<int, char> ::iterator it_mp;
	for (it_mp = mp.begin(); it_mp != mp.end(); ++it_mp)
	{
		cout << it_mp->first << ": " << it_mp->second << "\t";
	}
	cout << endl;
	it_mp = mp.find(3);
	cout << it_mp->second << endl;
	
	/*
	// Heap
	vector<int> vec2 = { 20, 30, 15, 10, 60, 5 };
	vector<int> ::iterator it_vec;
	//make_heap(vec2.begin(), vec2.end());

	cout << vec2.front() << endl;
	
	for (auto i = vec2.begin(); i != vec2.end(); ++i)
	{
		cout << *i << "\t";
	}
	cout << endl;

	sort(vec2.begin(), vec2.end());

	//sort_heap(vec2.begin(), vec2.end());
	for (int &x : vec2)
		cout << x << "\t";
	cout << endl;

	bool is_here = binary_search(vec2.begin(), vec2.end(), 40);
	if (is_here)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	//practice
	string str1 = "Hello World";
	string str2 = "Hello roldw";
	for (int i=0;i < str1.length(); ++i)
	{
		auto c = str1.at(i);
		if (c >= 'A' & c <= 'Z')
		{
			char low = tolower(str1.at(i));
			str1[i] = low;
		}
		
	}
	for (int i = 0; i < str2.length(); ++i)
	{
		auto c = str2.at(i);
		if (c >= 'A' & c <= 'Z')
		{
			char low = tolower(str2.at(i));
			str2[i] = low;
		}

	}
	cout << str2 << endl;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	cout << (str1==str2) << endl;
	*/
	
	//Graph
	/*Graph *g = new Graph(9);
	g->addEdge(0, 1);
	g->addEdge(0, 7);
	g->addEdge(1, 2);
	g->addEdge(1, 7);
	g->addEdge(2, 3);
	g->addEdge(2, 8);
	g->addEdge(2, 5);
	g->addEdge(3, 4);
	g->addEdge(3, 5);
	g->addEdge(4, 5);
	g->addEdge(5, 6);
	g->addEdge(6, 7);
	g->addEdge(6, 8);
	g->addEdge(7, 8);*/
	////g.displayVertices();
	//cout << "Following is Breadth First Traversal ";
	//g.BFS(2);			// O(V+E) tim ecomplexity
	//cout << endl;
	//cout << "Following is Deep First Traversal \n";
	//g->DFS();	//O(V +E)
	
	/*
	// find shortest path on a map
	char grid[N][M] = { { '0', '*', '0', '*','*', 's' },
						{ '*', '0', '*', '*', '*','*' },
						{ '0', 'd', '0', '*', '*','*' },
						{ '0', '*', '*', '0', '*','*' },
						{ '0', '*', '*', '*', '0','*' },
						{ '*', '*', '*', '*', '*', '0' } };
	cout << MinDistance(grid) << endl;
	*/
	// Dijkstra shortest path
	/*int V = 9;
	bool is_weighted = true;
	Graph g(V,is_weighted);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	Dijkstra(g.adj_w, V, 0);*/

//********************************************************************************************************************************************
	//Kruskal Minimum spanning tree
	 /* Let us create following weighted graph
			 10
		0--------1
		|  \     |
	   6|   5\   |15
		|      \ |
		2--------3
			4       */
	//int V = 4;  // Number of vertices in graph 
	//int E = 5;  // Number of edges in graph 
	//Graph *g = new Graph(V, E);
	//
	//g->edge[0].src = 0;
	//g->edge[0].dest = 1;
	//g->edge[0].weight = 10;

	//g->edge[1].src = 0;
	//g->edge[1].dest = 2;
	//g->edge[1].weight = 6;

	//g->edge[2].src = 0;
	//g->edge[2].dest = 3;
	//g->edge[2].weight = 5;

	//g->edge[3].src = 1;
	//g->edge[3].dest = 3;
	//g->edge[3].weight = 15;

	//g->edge[4].src = 2;
	//g->edge[4].dest = 3;
	//g->edge[4].weight = 4;

	//KruskalMST(g);

//************************************************************************************************************************************************
	// Prim's MST
	/*int V = 9;
	bool is_weighted = true;
	Graph *g = new Graph(V,is_weighted);
	g->addEdge(0, 1, 4);
	g->addEdge(0, 7, 8);
	g->addEdge(1, 2, 8);
	g->addEdge(1, 7, 11);
	g->addEdge(2, 3, 7);
	g->addEdge(2, 8, 2);
	g->addEdge(2, 5, 4);
	g->addEdge(3, 4, 9);
	g->addEdge(3, 5, 14);
	g->addEdge(4, 5, 10);
	g->addEdge(5, 6, 2);
	g->addEdge(6, 7, 1);
	g->addEdge(6, 8, 6);
	g->addEdge(7, 8, 7);

	PrimMST(g->adj_w, g->V);*/

//************************************************************************************************************************************************
	// Hamiltonina Cycle
	  /* 
		(0)--(1)--(2)
		|	       |
		|		   |
		|          |
		(3)-------(4) 
		*/
	bool g1[5][5] = { {0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{0, 1, 1, 1, 0} };
	/*
	(0)--(1)--(2)
	|   / \   |
	|  /   \  |
	| /     \ |
	(3)      (4)		*/

	bool g2[5][5] = { {0, 1, 0, 1, 0},
					{1, 0, 1, 1, 1},
					{0, 1, 0, 0, 1},
					{1, 1, 0, 0, 0},
					{0, 1, 1, 0, 0} };
	//HamiltonianCycle(g1, 5);
	
	Grph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 1);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int s = 1;
	g.LongestPath(s);

//************************************************************************************************************************************************
	/*unsigned char h1 = 0xffff;
	unsigned char h2 = 0xfffe;
	cout << isConsequitiveGrayCode(h1, h2) << endl;
	bin(h1);*/

	// Nearest point
	//vector<Point> points;
	//points.push_back(Point(3, 3));
	//points.push_back(Point(5, -1));
	//points.push_back(Point(-2, 4));
	//points.push_back(Point(6, 3));
	//Point origin(0, 0);
	//NearestPoints(points, origin, 3);

	// Binary Tree
	/*TreeNode* root = NewNode(2);
	root->left = NewNode(-2);
	root->right = NewNode(14);
	root->right->left = NewNode(5);
	root->left->left = NewNode(-1);
	root->left->right = NewNode(1);
	root->right->right = NewNode(-1);*/
	//root->right->right->right = NewNode(2);
	//root->right->right->right->right = NewNode(3);
	/* Constructing tree given in the above figure
	   2
	 /   \
	-2    14
   /\    / \
 -1  1  5  -1
			 \
			  2
			   \
			    3*/
	//cout << isBalanced(root) << endl;
	/*TreeNode* root = NULL;
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);
	TreeNode* node = root->left->right->right;
	TreeNode* succ = inorderSuccessor(root, node);
	cout << succ->data << endl;*/

	/*InorderTraversal(root);
	cout << endl;*/
	/* Constructing tree given in the above figure
		   1
		 /   \
		-5    11
	   /\    / \
	  1  2  4  -2   */

	//Node* root = NewNode(1);
	//root->left = NewNode(-5);
	//root->right = NewNode(11);
	//root->right->left = NewNode(4);
	//root->left->left = NewNode(1);
	//root->left->right = NewNode(2);
	//root->right->right = NewNode(-2);

	//  // converting the above Binary tree to BST 
	///*BinaryTree2BST(root);
	//cout << "Inorder traversal of BST is: " << endl;
	//InorderTraversal(root);*/

	////cout << FindLagestSubtreeSum(root) << endl;
	//cout << MaximumAvgNode(root) << endl;

	// Amazon Order list
	//vector<string> order_list;
	//order_list.push_back("zld 93 12");
	//order_list.push_back("fpa kindle book");
	//order_list.push_back("10a echo show");
	//order_list.push_back("17g 12 25 6");
	//order_list.push_back("ab1 kindle book");
	//order_list.push_back("125 echo dot second generation");

	//vector<string> sorted_list = SortAmazonOrderList(order_list);
	//for (auto i = sorted_list.begin(); i != sorted_list.end(); ++i)
	//{
	//	cout << *i << endl;
	//}

	//const int arr_size = 11;
	//int arr[arr_size] = { 38, 27, 43, 3, 9, 82, 10, 1, 100, 20,0 };
	//mergeSort(arr, arr_size);
	////sort(arr, arr + arr_size);


	////stack<int> s;
	//for (int i = 0; i < arr_size; ++i)
	//{
	//	//s.push(arr[i]);
	//	cout << arr[i] << "\t";
	//}
	//cout << endl;

	////sortStackRecu(s);
	//stack<int> sorted_stack = sortStack(s);
	//for (int i = 0; i < arr_size; ++i)
	//{
	//	cout<< sorted_stack.top()<<"\t";
	//	sorted_stack.pop();
	//}
	//cout << endl;

	//TreeNode* root = minimalTree(arr, arr_size);
	//InorderTraversal(root);

	// create level linked list
	/*vector<list<TreeNode*>> result = createLevelLinkedList(root);
	cout << "number of lists: " << result.size() << endl;*/

	//cout << checkBST(root) << endl;

	//cout << Lcm(15, 10) << endl;

	//cout << binarySearch(arr, 0, arr_size - 1, 43) << endl;

	// --------Letter combination of phone keypad for any entered digits
	//letterCombinaiton("234");

	//int arr[] = { 1, 2, 3, 4, 5 };
	//int r = 3;
	//int n = sizeof(arr) / sizeof(arr[0]);
	////CombinationRepetition(arr, n, r);
	//CombinationNoRepetition(arr, n, r);
	/*char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n-1);*/
	/*char set2[] = { 'a', 'b', 'c', 'd' };
	int k = 3;
	PermutationRepetition(set2, k, 3);*/

	//Dijkstra minimum path algorithm
	

	cin.get();
	//return 0;
}