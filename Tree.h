#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	int height;
	Node* left;
	Node* right;
};

class Tree
{
private:
	Node* root;

	Node* findMinNode(Node* node) {
		Node* current = node;
		while (current && current->left != nullptr) {
			current = current->left;
		}
		return current;
	}

	int findHeight(Node* temp)
	{
		int height = 0;
		if (temp != nullptr)
		{
			height = max(findHeight(temp->left), findHeight(temp->right)) + 1;
		}

		return height;
	}

	int findHeightDifference(Node* temp)
	{
		return findHeight(temp->left) - findHeight(temp->right);
	}

	Node* rightRotation(Node* node)
	{
		Node* buff = node->right;
		node->right = buff->left;
		buff->left = node;

		return buff;
	}

	Node* leftRotation(Node* node)
	{
		Node* buff = node->left;
		node->left = buff->right;
		buff->right = node;

		return buff;
	}

	Node* leftRightRotation(Node* node)
	{
		Node* buff = node->right;
		node->right = rightRotation(buff);

		return leftRotation(node);
	}

	Node* rightLeftRotation(Node* node)
	{
		Node* buff = node->right;
		node->right = leftRotation(buff);

		return rightRotation(node);
	}

	Node* balanceNode(Node* subTree)
	{
		int ratio = findHeightDifference(subTree);

		if (ratio > 1)
		{
			if (findHeightDifference(subTree->left) > 0)
			{
				subTree = leftRotation(subTree);
			}
			else
			{
				subTree = leftRightRotation(subTree);
			}
		}
		else if (ratio < -1)
		{
			if (findHeightDifference(subTree->right) > 0)
			{
				subTree = rightLeftRotation(subTree);
			}
			else
			{
				subTree = rightRotation(subTree);
			}
		}

		return subTree;
	}

	Node* balance(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		root->left = balanceNode(root->left);
		root->right = balanceNode(root->right);

		return balanceNode(root);
	}
public:
	Tree()
	{
		root = nullptr;
	}
	
	Node** getRoot()
	{
		return &root;
	}

	Node* insert(Node* node, int value)
	{
		if (node == nullptr)
		{
			node = new Node();
			node->value = value;
			node->left = nullptr;
			node->right = nullptr;

			return node;
		}

		if (value < node->value)
		{
			node->left = insert(node->left, value);
		}
		else if (value > node->value)
		{
			node->right = insert(node->right, value);
		}
		else
		{
			cout << "This value is already contained in AVL Tree " << endl;
			exit(1);
		}

		return balanceNode(node);
	}

	void bypass(Node* root)
	{
		if (root != nullptr)
		{
			cout << "Value: " << root->value << " ";
			bypass(root->left);
			bypass(root->right);
		}
	}

	Node* remove(Node* root, int value)
	{
		if (root == nullptr)
		{
			return root;
		}

		if (value < root->value)
		{
			root->left = remove(root->left, value);
		}
		else if (value > root->value)
		{
			root->right = remove(root->right, value);
		}
		else
		{
			if (root->left == nullptr || root->right == nullptr)
			{
				Node* temp = root->left ? root->left : root->right;
				if (temp == nullptr)
				{
					temp = root;
					root = nullptr;
				}
				else
				{
					*root = *temp;
				}

				delete temp;
			}
			else
			{
				Node* temp = findMinNode(root->right);
				root->value = temp->value;
				root->right = remove(root->right, temp->value);
			}
		}

		if (root == nullptr)
		{
			return root;
		}

		return balanceNode(root);
	}
};