#include <iostream>
#include "avl.h"
#include <Windows.h>

using namespace std;

int main()
{
    avl tree;

    for (int i = 0; i < 40; i++) {
        tree.insert(rand() % 50);
    }
    tree.display();


    cout << tree.find(11)->bigData << " - ";
    cout << tree.find(11)->data;

}