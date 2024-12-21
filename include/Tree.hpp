#ifndef Tree_HPP
#define Tree_HPP
#include "Node.hpp"
#include <iostream>

const int MAX = 200;

class Tree
{
private:
    Node* root;
    int left(int index);
    int right(int index);
    int parent(int index);
    bool isFull(int index);
    bool isFullRight(int index); 
    bool isFullLeft(int index);
    int treeValue(int index, bool isLeft);


public:
	enum STATE{
		EMPTY=0,
		FULL=1
	};
    STATE state[MAX];
    int* cells;
    Tree();
    ~Tree();
    friend std::ostream& operator<<(std::ostream& os, Tree& tree);
    void insert(char data);
    int height(int index);
    int treeValue(int index);
    void printTree();
    void deleteTree(int index);
};

#endif