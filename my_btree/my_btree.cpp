//
//  Github: ranystephan
//  my_btree.cpp
//  ranystephan.rcs04.asst2
//
//  Created by Rany STEPHAN
//

#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
struct treeNode
{
    T *data;
    struct treeNode *left;
    struct treeNode *right;
};

/*
requires: requires a Node with key of type integer or char, and a data 
of type integer or char
effects: creates a node with data as a key and adds it to the smallest path
inside the tree.

testing strategy: 
1) passing a node/data with Null value
2) passing a node/data with integer type
3) passing a node/data with char type
*/
template <typename T>
void addNode(treeNode<T> *node, T *data)
{
    if (node->data == NULL)
    {
        node->data = data;
        node->left = new treeNode<T>;
        node->right = new treeNode<T>;
    }
    else
    {
        if (node->left->data == NULL)
        {
            addNode(node->left, data);
        }
        else if (node->right->data == NULL)
        {
            addNode(node->right, data);
        }
        else
        {
            addNode(node->left, data);
        }
    }
};


/*
requires: requires a Node with key of type integer or char, and a data 
of type integer or char
effects: deletes a leaf node with a specified data as a key. If that node
is parent to a none Null Node, prints(CANNOT DELETE NODE)
testing strategy: 
1) passing a node/data with Null value
2) passing a node/data with integer type
3) passing a node/data with char type
*/
template <typename T>
void deleteNode(treeNode<T> *node, T *data)
{
    if (node->data == NULL)
    {
        return;
    }
    else
    {
        if (node->data == data)
        {
            if (node->left->data == NULL && node->right->data == NULL)
            {
                node->data = NULL;
                delete node->left;
                delete node->right;
            }
            else
            {
                cout << "CANNOT DELETE NODE" << endl;
            }
        }
        else
        {
            deleteNode(node->left, data);
            deleteNode(node->right, data);
        }
    }
};

/*
requires: requires a Node with key of type integer or char
effects: return an integer of how many Nodes are linked in the tree
testing strategy: 
1) passing a node with Null value
2) passing a node with integer type
3) passing a node with char type
*/
template <typename T>
int treeSize(treeNode<T> *node)
{
    if (node->data == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + treeSize(node->left) + treeSize(node->right);
    }
};

/*
requires: requires a Node with key of type integer or char
effects: return an integer of how many Nodes are linked to the Node
with a specific key value
testing strategy: 
1) passing a node/data with Null value
2) passing a node/data with integer type
3) passing a node/data with char type
*/
template <typename T>
int subtreeSize(treeNode<T> *node, T *data)
{
    if (node->data == NULL)
    {
        return 0;
    }
    else
    {
        if (node->data == data)
        {
            return 1 + subtreeSize(node->left, data) + subtreeSize(node->right, data);
        }
        else
        {
            return subtreeSize(node->left, data) + subtreeSize(node->right, data);
        }
    }
};


/*
requires: requires a Node with key of type integer or char
effects: prints out the tree in post order traversal
testing strategy: 
1) passing a node with Null value
2) passing a node with integer type
3) passing a node with char type
*/
template <typename T>
void postOrderPrint(treeNode<T> *node)
{
    if (node->data == NULL)
    {
        return;
    }
    else
    {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        cout << *node->data << endl;
    }
};

/*
requires: requires a Node with key of type integer or char
effects: prints out the tree in pre order traversal
testing strategy: 
1) passing a node with Null value
2) passing a node with integer type
3) passing a node with char type
*/
template <typename T>
void preOrderPrint(treeNode<T> *node)
{
    if (node->data == NULL)
    {
        return;
    }
    else
    {
        cout << *node->data << endl;
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
};

/*
requires: requires a Node with key of type integer or char
effects: prints out the tree in in order traversal
testing strategy: 
1) passing a node with Null value
2) passing a node with integer type
3) passing a node with char type
*/
template <typename T>
void inOrderPrint(treeNode<T> *node)
{
    if (node->data == NULL)
    {
        return;
    }
    else
    {
        inOrderPrint(node->left);
        cout << *node->data << endl;
        inOrderPrint(node->right);
    }
};

int main()
{
    treeNode<int> *root = new treeNode<int>;
    root->data = NULL;
    root->left = NULL;
    root->right = NULL;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    addNode(root, &a);
    addNode(root, &b);
    addNode(root, &c);
    addNode(root, &d);

    cout << "Tree Size: " << treeSize(root) << endl;
    cout << "Subtree Size: " << subtreeSize(root, &a) << endl;
    cout << "Post Order Print: " << endl;
    postOrderPrint(root);
    cout << "Pre Order Print: " << endl;
    preOrderPrint(root);
    cout << "In Order Print: " << endl;
    inOrderPrint(root);
    deleteNode(root, &a);
    cout << "Tree Size: " << treeSize(root) << endl;
    cout << "Subtree Size: " << subtreeSize(root, &a) << endl;
    cout << "Post Order Print: " << endl;
    postOrderPrint(root);
    cout << "Pre Order Print: " << endl;
    preOrderPrint(root);
    cout << "In Order Print: " << endl;
    inOrderPrint(root);
    return 0;
}