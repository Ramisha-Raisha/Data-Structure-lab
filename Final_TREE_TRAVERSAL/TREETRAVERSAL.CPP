
#include <iostream>

using namespace std;

// A binary tree node
struct Node {
  int data;
  Node* left;
  Node* right;
};

// Create a new node with given data
Node* newNode(int data) {
  Node* node = new Node; // Allocate memory for the new node
  node->data = data; // Set the data of the new node
  node->left = node->right = NULL; // Initialize left and right children as NULL
  return node;
}

// Preorder traversal (visit root, then left, then right)
void preOrder(Node* root) {
  if (root == NULL) return; // Base case: empty tree
  cout << root->data << " "; // Visit the root node
  preOrder(root->left); // Recursively traverse the left subtree
  preOrder(root->right); // Recursively traverse the right subtree
}

// Inorder traversal (visit left, then root, then right)
void inOrder(Node* root) {
  if (root == NULL) return; // Base case: empty tree
  inOrder(root->left); // Recursively traverse the left subtree
  cout << root->data << " "; // Visit the root node
  inOrder(root->right); // Recursively traverse the right subtree
}

// Postorder traversal (visit left, then right, then root)
void postOrder(Node* root) {
  if (root == NULL) return; // Base case: empty tree
  postOrder(root->left); // Recursively traverse the left subtree
  postOrder(root->right); // Recursively traverse the right subtree
  cout << root->data << " "; // Visit the root node
}

int main() {
  // Create a sample binary tree
  Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  // Print the tree using different traversals
  cout << "Preorder traversal: ";
  preOrder(root);
  cout << endl;

  cout << "Inorder traversal: ";
  inOrder(root);
  cout << endl;

  cout << "Postorder traversal: ";
  postOrder(root);
  cout << endl;

  return 0;
}
