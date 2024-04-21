#include "Tree.h"
#include "prototypes.h"

using namespace std;


int main()
{
    int countNode = 0;
    cout << "Enter a count of nodes for AVL Tree ";
    cin >> countNode;

    if (countNode <= 0)
    {
        cout << "The count of vertices must be greater than 0";
        exit(1);
    }

    Tree avlTree;
    Node* root = nullptr;
    int value;

    for (int i = 0; i < countNode; i++)
    {
        cout << "Enter a value for node ";
        cin >> value;
        root = avlTree.insert(root, value);
    }

	cout << "AVL Tree" << endl;
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