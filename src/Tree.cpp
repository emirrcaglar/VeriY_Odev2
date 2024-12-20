#include "Tree.hpp"
#include "Node.hpp"
#include "FileRead.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

Tree::Tree()
{ // constructor
    cells = new int[MAX];
    for(int i = 0; i < MAX; i++) {
        state[i] = EMPTY;
    }
}

Tree::~Tree() { // destructor
    // destroy(root);
}

void Tree::insert(char data) {
    int next = 0;
    while(true) {
        if(state[next] == EMPTY) {
            cells[next] = data;
            state[next] = FULL;
            break;
        }
    else if(data < cells[next]) {
        next = left(next);
    }
    else if(data > cells[next]) {
        next = right(next);
    }
    else {
        return;
    }
    }
}



int Tree::left(int index)
{
    return index * 2 + 1;
}

int Tree::right(int index)
{
    return index * 2 + 2;
}

int Tree::parent(int index)
{
    return (index - 1) / 2;
}

bool Tree::isFull(int index)
{
    if(state[index] == FULL) {
        return true;
    }
    return false;
}

bool Tree::isFullRight(int index) 
{
	if(state[right(index)]==FULL)
        return true;
    return false;
}

bool Tree::isFullLeft(int index) 
{
	if(state[left(index)]==FULL)
        return true;
    return false;
}



int Tree::height(int index) 
{
	if(isFull(index))
    {
        return 1+std::max(  height(left(index)),
                            height(right(index)));
    }
    return -1;
}

void printSpaces(std::ostream& os, char ch, int count) {
    for (int i = 0; i < count; ++i) {
        os << ch;
    }
}



// 1, 2, 4, 8, 16, 32, 64, 128, 256, 512


std::ostream& operator<<(std::ostream& os, Tree& tree) {
    int height = tree.height(0); // Maximum height of the tree

    for (int level = 0; level <= height; ++level) {
        int levelStart = (1 << level) - 1;     // Start index for the current level
        int levelEnd = (1 << (level + 1)) - 2; // End index for the current level
        int space = (1 << (height - level+2));   // Space between nodes

        os << std::setw(space/2); // initial padding for the level
        for (int i = levelStart; i <= levelEnd; ++i) {
            if (i < MAX && tree.state[i] != Tree::EMPTY) {
                os << static_cast<char>(tree.cells[i]); // Node value
            } else {
                os << "_"; // Node value
            }
            os << std::setw(space); // Space between nodes            
        }
        os<<std::endl << std::endl;
        os << std::endl << std::endl; // Padding for the next level
    }
    return os;
}
