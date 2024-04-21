#pragma once

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
	Node* temp;
public:
	Tree()
	{
		root = nullptr;
		temp = nullptr;
	}
	
	Node** getRoot()
	{
		return &root;
	}

	int findHeight(Node* temp)
	{
		int height = 0;
		if (temp != nullptr)
		{
			int left = findHeight(temp->left);
			int right = findHeight(temp->right);
			int maxHeight = max(left, right);

			height = maxHeight + 1;
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
};