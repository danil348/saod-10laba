#include <iostream>
#include "avl.h"
#include <Windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    avl tree;

    for (int i = 0; i < 40; i++) {
        tree.insert(rand() % 50);
    }
    tree.inorder();
    cout << endl;
    cout << endl;
    tree.display();

    int number;
    cout << "введите номер элмента, который будет найден в дереве ";
    cin >> number;
    cout << tree.find(number)->bigData << " - ";
    cout << tree.find(number)->data;
}