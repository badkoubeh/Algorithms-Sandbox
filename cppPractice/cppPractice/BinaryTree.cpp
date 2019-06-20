#include "Header.h"

using namespace std;



// Helper fuction to create a node
TreeNode* NewNode(int data)
{
	TreeNode* temp = new TreeNode();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int binarySearch(int arr[], int left_start_index, int right_end_index,int search_value)
{
	if (left_start_index > right_end_index)
		return -1;

	int mid = left_start_index + (right_end_index - left_start_index) / 2;
	int right_start_index = mid + 1;
	int left_end_index = mid;

	if (arr[mid] == search_value)
		return mid;


	// search left half if x is smaller than mid value
	if (arr[mid] > search_value)
		return binarySearch(arr, left_start_index, left_end_index, search_value);

	return binarySearch(arr, right_start_index, right_end_index, search_value);

} //The worst case time complexity of search and insert operations is O(h) where h is height of Binary Search Tree. 

/* A utility function to insert a new node with given key in BST */
TreeNode* insert(TreeNode* root, int new_val)
{
	/* If the tree is empty, return a new node */
	if (root == NULL) return NewNode(new_val);

	/* Otherwise, recur down the tree */
	if (new_val < root->data)
		root->left = insert(root->left, new_val);
	else if (new_val > root->data)
		root->right = insert(root->right, new_val);

	/* return the (unchanged) node pointer */
	return root;
} // The worst case time complexity of search and insert operations is O(h) where h is height of Binary Search Tree. 

void InorderTraversal(TreeNode* root)
{
	if (!root)
		return;

	InorderTraversal(root->left);
	cout << root->data << "\t";
	InorderTraversal(root->right);
}

// level order traversal in tree is BFS in fact
void levelOrderTraversal(TreeNode* root)
{
	if (root == NULL)
		return;

	queue<TreeNode*> bfs_q;

	// Enqueue Root and initialize height
	bfs_q.push(root);
	int level = 1;

	while (!bfs_q.empty())
	{
		TreeNode* node = bfs_q.front();
		bfs_q.pop();

		cout << node->data <<endl;

		//enqueue left child
		if (root->left != NULL)
		{
			bfs_q.push(node->left);
		}

		//enqueue right child
		if (node->right != NULL)
		{
			bfs_q.push(node->right);
		}
			
	}

} // time complexity O(n)



void StoreNodes2Set(TreeNode* root, set<int>& s)
{
	if (!root)
		return;

	//visit the left subtree first
	StoreNodes2Set(root->left, s);

	//insertion takes order of O(logn) for sets
	s.insert(root->data);

	//visit the right subtgree
	StoreNodes2Set(root->right, s);
} // time complexity O(nlogn)

void Set2BST(set<int>& s, TreeNode* root)
{
	if (!root)
		return;

	// first move to the left subtree
	Set2BST(s, root->left);

	auto itr = s.begin();

	// copying the item at beginning of set(sorted) to the tree
	root->data = *itr;

	s.erase(itr);

	// now move to right subtree and update items
	Set2BST(s, root->right);

} //T(n) = o(nlogn) time

void BinaryTree2BST(TreeNode* root)
{
	set<int> s;

	StoreNodes2Set(root, s);

	Set2BST(s, root);
} //T(n)= O(nlogn), s(n)= O(n)

int FindLagestSubtreeSumUtil(TreeNode* root, int& ans)
{
	if (root == NULL)
		return 0;

	// Subtree sum rooted at current node. 
	int curr_sum = root->data + FindLagestSubtreeSumUtil(root->left, ans)
		+ FindLagestSubtreeSumUtil(root->right, ans);

	ans = max(ans, curr_sum);

	return curr_sum;
}

int FindLagestSubtreeSum(TreeNode* root)
{
	if (root == NULL)
		return 0;

	int ans = 0;

	FindLagestSubtreeSumUtil(root, ans);

	return ans;
}

// Find subtree with maximum average value and return its top node/root
AvgTree::AvgTree(TreeNode* node, int sum, int size) : node(node), sum(sum), size(size) {};

AvgTree* result = NULL;

int MaximumAvgNode(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	AvgTree* result = MaxAvgSubtree(root);
	return result->node->data;
}

AvgTree* MaxAvgSubtree(TreeNode* root)
{
	if (!root)
		return new AvgTree(NULL,0,0);


	AvgTree* left_result = MaxAvgSubtree(root->left);


	AvgTree* right_result = MaxAvgSubtree(root->right);

	AvgTree* current_result = new AvgTree(root,
		left_result->sum + right_result->sum + root->data,
		left_result->size + right_result->size + 1);
	cout << "current result " << current_result->node->data << endl;
	
	if (result == NULL || current_result->sum * result->size > result->sum * current_result->size)
		result = current_result;

	return current_result;
}

//Minimal Tree: a sorted arry -> a minimal tree : the root must be the middle point then
TreeNode* minimalTree(int *arr, int arr_size)
{

	return minimalTreeUtil(arr, 0, arr_size-1);

}
TreeNode* minimalTreeUtil(int *arr, int left_start, int right_end)
{
	if (left_start> right_end)
	{
		return NULL;
	}

	//since array is sorted, we just need to find the middle point
	int mid = left_start + (right_end - left_start) / 2;
	int right_start = mid + 1;
	TreeNode* root = NewNode(arr[mid]);

	root->left = minimalTreeUtil(arr, left_start, mid-1);
	root->right = minimalTreeUtil(arr, right_start, right_end);

	return root;
}

//Connect nodes at same level in a linked list
// Apply BFS on each level rather than each node
vector<list<TreeNode*>> createLevelLinkedList(TreeNode* root)
{
	vector<list<TreeNode*>> result;

	list<TreeNode*> current;
	current.push_back(root);

	while (current.size() > 0)
	{

		result.push_back(current);	//add previous level
		list<TreeNode*> parents = current;
		current.erase(current.begin(),current.end());
		
		for (auto itr = parents.begin(); itr != parents.end(); ++itr)
		{
			TreeNode* parent = *itr;
			//cout << "data: " << parent->data << endl;
			if (parent->left != NULL)
				current.push_back(parent->left);

			if (parent->right != NULL)
				current.push_back(parent->right);
		}
	}
	return result;
}

// Check if a binary tree is height balanced
bool isBalanced(TreeNode* root)
{
	return (checkHeight(root) != 0);
}


int checkHeight(TreeNode* root)
{
	int left_height = 0;
	int right_height = 0;

	if (root == NULL)
		return 1;

	left_height = checkHeight(root->left);
	right_height = checkHeight(root->right);
	
	int diff = abs(left_height - right_height);
	if (diff > 1)
	{
		//cout << diff << endl;
		return 0;
	}
	else
		return max(left_height, right_height) + 1;
}


// check BST is balanced or not
bool checkBST(TreeNode* root)
{
	return checkBST(root, NULL, NULL);
}

bool checkBST(TreeNode* root, int min, int max)
{
	if (root == NULL)
		return true;

	if ((min != NULL && root->data <= min) || (max != NULL && root->data >= max))
		return false;

	if (!checkBST(root->left, min, root->data) || !checkBST(root->right, root->data, max))
		return false;

	return true;
} // O(n) time complexity, O(log n) space complexity

TreeNode* minValue(TreeNode* node)
{
	TreeNode *minNode = node;

	// loop down to find the leftmost leaf which has the minimum value of a tree 
	while (minNode != NULL)
	{
		minNode = minNode->left;
	}
	return minNode;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* node)
{
	if (node->right != NULL)
		return minValue(node->right);

	TreeNode* succ = NULL;

	//start from root and search for successor down the tree
	while (root != NULL)
	{
		if (node->data < root->data)		// the successor will be in left subtree so go to left
		{
			succ = root;
			root = root->left;
		}
		else if (node->data > root->data)  // the successor will be in left subtree
			root = root->right;
		else
			break;
	}

	return succ;

} // O(h) h = tree height


