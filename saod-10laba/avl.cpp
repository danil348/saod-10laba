#include "avl.h"
#include <vector>
#include <string>

using namespace std;

Node* avl::insert(int data, Node* tree)
{
    if (tree == NULL)
    {
        tree = new Node;
        tree->data = data;
        tree->height = 0;
        tree->left = tree->right = NULL;
        tree->bigData = rand() % 120 * 100 + rand() % 120;
    }
    else if (data < tree->data)
    {
        tree->left = insert(data, tree->left);
        if (height(tree->left) - height(tree->right) == 2)
        {
            if (data < tree->left->data)
                tree = singleRightRotate(tree);
            else
                tree = doubleRightRotate(tree);
        }
    }
    else if (data > tree->data)
    {
        tree->right = insert(data, tree->right);
        if (height(tree->right) - height(tree->left) == 2)
        {
            if (data > tree->right->data)
                tree = singleLeftRotate(tree);
            else
                tree = doubleLeftRotate(tree);
        }
    }

    tree->height = max(height(tree->left), height(tree->right)) + 1;
    return tree;
}

Node* avl::singleRightRotate(Node*& tree)
{
    Node* TmpElement = tree->left;
    tree->left = TmpElement->right;
    TmpElement->right = tree;
    tree->height = max(height(tree->left), height(tree->right)) + 1;
    TmpElement->height = max(height(TmpElement->left), tree->height) + 1;
    return TmpElement;
}

Node* avl::singleLeftRotate(Node*& tree)
{
    Node* TmpElement = tree->right;
    tree->right = TmpElement->left;
    TmpElement->left = tree;
    tree->height = max(height(tree->left), height(tree->right)) + 1;
    TmpElement->height = max(height(tree->right), tree->height) + 1;
    return TmpElement;
}

Node* avl::doubleLeftRotate(Node*& tree)
{
    tree->right = singleRightRotate(tree->right);
    return singleLeftRotate(tree);
}

Node* avl::doubleRightRotate(Node*& tree)
{
    tree->left = singleLeftRotate(tree->left);
    return singleRightRotate(tree);
}

int avl::height(Node* tree)
{
    return (tree == NULL ? -1 : tree->height);
}

void avl::print(Node const* node, string prefix, bool root, bool last)
{
    if (node != NULL) {
        cout << prefix << (root ? "" : (last ? signs[1] : signs[0])) << (node ? std::to_string(node->data) : "") << endl;
    }
    if (!node || (!node->left && !node->right))
        return;

    print(node->left, prefix + (root ? "" : (last ? "   " : signs[2])), false, 0);
    print(node->right, prefix + (root ? "" : (last ? "   " : signs[2])), false, 1);
}

avl::avl()
{
    root = NULL;
}

void avl::inorder()
{
    inorder(root);
}

void avl::inorder(Node* tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    cout << tree->data << " ";
    inorder(tree->right);
}
void avl::insert(int data)
{
    root = insert(data, root);
}

void avl::display()
{
    print(root);
    cout << endl;
}

Node* avl::find(int value)
{
    return find(root, value);
}

Node* avl::find(Node* tree, int value)
{
    if (tree == NULL) {
        return NULL;
    }
    if (tree->data == value) {
        return tree;
    }
    if (tree->data > value) {
        find(tree->left, value);
    }
    else {
        find(tree->right, value);
    }
}