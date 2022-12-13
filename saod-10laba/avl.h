#pragma once

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
    int bigData;
};

class avl
{
    string signs[3] = { "|-", "\\-"  ,"| " };
    Node* root; // Корень дерева

    Node* insert(int data, Node* tree);

    Node* singleRightRotate(Node*& tree);
    Node* singleLeftRotate(Node*& tree);
    Node* doubleLeftRotate(Node*& tree);
    Node* doubleRightRotate(Node*& tree);

    int height(Node* tree);
    void print(Node const* node, string prefix = "", bool root = true, bool last = true);
    Node* find(Node* tree, int value);
public:

    avl();

    void insert(int data);
    void display();
    Node* find(int value);
};