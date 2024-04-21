#include "Tree.h"
#include "prototypes.h"

using namespace std;


int main()
{
    Tree avlTree;
    Node* root = nullptr;

	cout << "AVL Tree" << endl;

    root = avlTree.insert(root, 30);
    root = avlTree.insert(root, 20);
    root = avlTree.insert(root, 40);
    root = avlTree.insert(root, 10);
    root = avlTree.insert(root, 25);
    root = avlTree.insert(root, 35);
    root = avlTree.insert(root, 50);

    avlTree.bypass(root);
    cout << endl;
    printTree(root);
}


int getMaxLevel(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(getMaxLevel(root->left), getMaxLevel(root->right)) + 1;
}

void printLevel(Node* root, int level, int maxLevel)
{
    if (root == nullptr || level > maxLevel)
    {
        if (level == maxLevel)
        {
            cout << setw(4 * (1 << (maxLevel - level + 1))) << " ";
        }
        return;
    }

    if (level == 1)
    {
        cout << setw(4) << root->value;
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1, maxLevel);
        printLevel(root->right, level - 1, maxLevel);
    }
}

void printTree(Node* root)
{
    int maxLevel = getMaxLevel(root);

    for (int i = 1; i <= maxLevel; ++i)
    {
        printLevel(root, i, maxLevel);
        cout << endl;
    }
}