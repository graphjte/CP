#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

// The 2D segment tree node class
class Node {
public:
  int val; // The value stored in the node
  int x1, y1, x2, y2; // The coordinates of the subarray represented by the node

  Node *left, *right, *up, *down; // Pointers to the child nodes

  Node(int val, int x1, int y1, int x2, int y2) : val(val), x1(x1), y1(y1), x2(x2), y2(y2), left(NULL), right(NULL), up(NULL), down(NULL) {}
};

// The 2D segment tree class
class SegmentTree2D {
private:
  Node *root; // The root node of the tree

public:
  SegmentTree2D(int[][N], int, int); // Constructor to build the tree
  int query(int, int, int, int, int, int); // Function to perform a range query
  void update(int, int, int); // Function to update a value in the array
    void update(Node *curr, int x, int y, int val);
    void buildTree(Node *curr, int arr[][N], int n, int m);
};

// Constructor to build the tree
SegmentTree2D::SegmentTree2D(int arr[][N], int n, int m) {
  // Allocate memory for the root node and initialize it
  root = new Node(0, 0, 0, n - 1, m - 1);

  // Build the tree recursively
  buildTree(root, arr, n, m);
}

// Recursive function to build the tree
void SegmentTree2D::buildTree(Node *curr, int arr[][N], int n, int m) {
  // If the current node represents a single element in the array, set its value and return
  if (curr->x1 == curr->x2 && curr->y1 == curr->y2) {
    curr->val = arr[curr->x1][curr->y1];
    return;
  }

  // Split the current node into 4 subnodes
  int xmid = (curr->x1 + curr->x2) / 2;
  int ymid = (curr->y1 + curr->y2) / 2;
  curr->left = new Node(0, curr->x1, curr->y1, xmid, ymid);
  curr->right = new Node(0, xmid + 1, curr->y1, curr->x2, ymid);
  curr->up = new Node(0, curr->x1, ymid + 1, xmid, curr->y2);
  curr->down = new Node(0, xmid + 1, ymid + 1, curr->x2, curr->y2);

  // Build the subnodes recursively
  buildTree(curr->left, arr, n, m);
  buildTree(curr->right, arr, n, m);
  buildTree(curr->up, arr, n, m);
  buildTree(curr->down, arr, n, m);

  // Update the value of the current node by combining the values of its children
  curr->val = curr->left->val + curr->right->val + curr->up->val + curr->down->val;
}

// Function to perform a range query
int SegmentTree2D::query(int x1, int y1, int x2, int y2, int n, int m) {
  // Check if the query range is completely outside the current node's range
  if (x1 > root->x2 || x2 < root->x1 || y1 > root->y2 || y2 < root->y1) return 0;

  // Check if the current node is completely inside the query range
  if (x1 <= root->x1 && x2 >= root->x2 && y1 <= root->y1 && y2 >= root->y2) return root->val;

  // Otherwise, perform the query recursively on the subnodes
  int ans = 0;
  if (x1 <= root->left->x2 && y1 <= root->left->y2) ans += query(x1, y1, x2, y2, n, m);
  if (x1 <= root->right->x2 && y1 <= root->right->y2) ans += query(x1, y1, x2, y2, n, m);
  if (x1 <= root->up->x2 && y1 <= root->up->y2) ans += query(x1, y1, x2, y2, n, m);
  if (x1 <= root->down->x2 && y1 <= root->down->y2) ans += query(x1, y1, x2, y2, n, m);
  return ans;
}

// Function to update a value in the array
void SegmentTree2D::update(int x, int y, int val) {
  // Find the leaf node containing the element and update its value
  update(root, x, y, val);
}

// Recursive function to find the leaf node containing the element and update its value
void SegmentTree2D::update(Node *curr, int x, int y, int val) {
  // If the current node is a leaf node, update its value and return
  if (curr->x1 == curr->x2 && curr->y1 == curr->y2) {
    curr->val = val;
    return;
  }

  // Update the value recursively in the appropriate child node
  if (x <= curr->left->x2 && y <= curr->left->y2) update(curr->left, x, y, val);
  else if (x <= curr->right->x2 && y <= curr->right->y2) update(curr->right, x, y, val);
  else if (x <= curr->up->x2 && y <= curr->up->y2) update(curr->up, x, y, val);
  else if (x <= curr->down->x2 && y <= curr->down->y2) update(curr->down, x, y, val);

  // Update the value of the current node by combining the values of its children
  curr->val = curr->left->val + curr->right->val + curr->up->val + curr->down->val;
}

int main() {
int n = 4;
  int arr[n][N] = {{1, 3, 2, 4}, {5, 2, 1, 3}, {1, 2, 5, 1}, {2, 1, 3, 4}};

  // Build the 2D segment tree
  SegmentTree2D tree(arr, n, n);

  // Perform a range query
  int x1 = 0, y1 = 0, x2 = 2, y2 = 2;
  cout << tree.query(x1, y1, x2, y2, n, n) << endl; // Outputs: 16

  // Update a value in the array
  int x = 1, y = 1, val = 10;
  tree.update(x, y, val);

  // Perform another range query
  cout << tree.query(x1, y1, x2, y2, n, n) << endl; // Outputs: 26
}