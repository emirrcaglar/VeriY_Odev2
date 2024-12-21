#include "LinkedList.hpp"
#include "Tree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdint>
#include <conio.h>

    void createCells(int cellCount, Tree trees[]);
    void pointToCells(int space);


int main() {

    std::ifstream file("Agaclar.txt");
    if (!file) {
        std::cerr << "Unable to open file Agaclar.txt";
        return 1;
    }
    const int MAX_TREES = 100; // Maximum number of trees
    Tree trees[MAX_TREES]; // Array to store trees
    int treeCount = 0; // Counter for the number of trees

    std::string line;
    while (std::getline(file, line) && treeCount < MAX_TREES) {
        Tree tree;
        for (char ch : line) {
            tree.insert(ch);
        }
        trees[treeCount] = tree;
        treeCount++;
    }

    char secim;
    int i = 0; // Move `i` outside the loop to keep track of the current tree

    while (true) {
        system("CLS"); // Clear the screen (for Windows)
        std::cout << "TREE VALUE: " << std::endl << trees[i].treeValue(0) << std::endl;
        
        createCells(treeCount, trees);
        pointToCells(i);
        std::cout << std::endl;
        std::cout << "Tree " << i << ":\n" << trees[i] << std::endl << std::endl;

        std::cout << "Enter 'a' to move left, 'd' to move right, 's' to exit: ";
        
        // Use _getch() to get a single character input without waiting for Enter
        secim = _getch();

        if (secim == 's') {
            break; // Exit the loop
        } else if (secim == 'a') {
            if (i > 0) {
                i--; // Move to the previous tree
            } else {
                std::cout << "Already at the first tree.\n";
            }
        } else if (secim == 'd') {
            if (i < treeCount - 1) { // Ensure `i` doesn't exceed the last index
                i++; // Move to the next tree
            } else {
                std::cout << "Already at the last tree.\n";
            }
        } else {
            std::cout << "Invalid input. Please enter 'a', 'd', or 's'.\n";
        }
    }

    file.close();
    return 0;
}

void pointToCells(int space) {

/*  
    if(space > 9){
        space -= space %= 10;
    }
*/

    for(int i = 0; i < space; i++){
        std::cout << "               ";
    }
    std::cout << "^^^^^^^^^^^^   ";
    std::cout << std::endl;
    for(int i = 0; i < space; i++){
        std::cout << "               ";
    }
    std::cout << "||||||||||||   ";
}

void fillCells(int i, Tree trees[]) {
    std::cout << trees[i].treeValue(0);
}

void createCells(int cellCount, Tree trees[]) {
/*
    if(cellCount > 9){
        cellCount -= cellCount % 10;
    }        
*/

    for(int i = 0; i < cellCount; i++){
        std::cout << "............   "; 
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "." << std::setw(10);
        std::cout << reinterpret_cast<std::uintptr_t>(&trees[i])%1000;
        std::cout << ".   ";
        // fillCells(i);
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "............   "; 
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "............   "; 
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "." << std::setw(10);
        std::cout << trees[i].treeValue(0);
        std::cout << ".   "; 
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "............   "; 
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "............   "; 
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "." << std::setw(10);
        if(i+1 < cellCount){
            std::cout << reinterpret_cast<std::uintptr_t>(&trees[i+1])%1000;
        } else{
            std::cout << "0";
        }
        std::cout << ".   ";
    }
    std::cout << std::endl;
    for(int i = 0; i < cellCount; i++){
        std::cout << "............   "; 
    }
        std::cout << std::endl;
}