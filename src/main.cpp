#include "LinkedList.hpp"
#include "Tree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdint>
#include <conio.h>

void createCells(int treeCount, Tree trees[], int const TOTAL_TREE_COUNT, int pageStartIndex);
void pointToCells(int space);
int const MAX_TREES_ON_SCREEN = 10;

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
        if (line.empty()) {
            continue; // Skip empty lines
        }
        Tree tree;
        for (char ch : line) {
            tree.insert(ch);
        }
        trees[treeCount] = tree;
        treeCount++;
    }
    int const TOTAL_TREE_COUNT = treeCount;
    char secim;
    int i = 0; // Move `i` outside the loop to keep track of the current tree

    while (true) {
        
        system("CLS"); // Clear the screen (for Windows)

        int pageStartIndex = (i / MAX_TREES_ON_SCREEN) * MAX_TREES_ON_SCREEN;   // the index of the first tree on the current page
        int cellCount = std::min(MAX_TREES_ON_SCREEN, treeCount - pageStartIndex);  // the number of cells to show
        createCells(cellCount, trees + pageStartIndex, TOTAL_TREE_COUNT, pageStartIndex); // the cells that show the tree values 
        pointToCells(i % MAX_TREES_ON_SCREEN); // the arrows that show the current tree
        std::cout << std::endl;

        trees[i].printTree(); // Print the current tree

        std::cout << "Enter 'a' to move left, 'd' to move right, 's' to delete, 'q' to exit: ";
        // Use _getch() to get a single character input without waiting for Enter
        secim = _getch();

        if (secim == 'q') {
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
        } else if (secim == 's') { // deletion
            if (treeCount > 0) {
                trees[i].deleteTree(0); // Delete the current tree                
                for(int j = i; j < treeCount - 1; j++) {
                    trees[j] = trees[j + 1]; // Shift the trees to the left
                }
                treeCount--; // Decrease the tree count
                if (i >= treeCount) {
                    i = treeCount - 1; // Adjust `i` if it goes out of bounds
                }
                if(i < 0) {
                    i = 0; // Move to the first tree
                }
                std::cout << "Tree deleted.\n";
            } else {
                std::cout << "No trees to delete.\n";
            }
        } else {
            std::cout << "Invalid input. Please enter 'a', 'd', 's', or 'q'.\n";
        }
    }

    file.close();
    return 0;
}

void pointToCells(int space) {
    std::cout << std::endl;
    for (int i = 0; i < space; i++) {
        std::cout << "               ";
    }
    std::cout << "^^^^^^^^^^^^   ";
    std::cout << std::endl;
    for (int i = 0; i < space; i++) {
        std::cout << "               ";
    }
    std::cout << "||||||||||||   ";
}

void createCells(int treeCount, Tree trees[], int const TOTAL_TREE_COUNT, int pageStartIndex) {
    for (int i = 0; i < treeCount; i++) {
        std::cout << "............   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "." << std::setw(10);
        std::cout << reinterpret_cast<std::uintptr_t>(&trees[i]) % 1000;
        std::cout << ".   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "............   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "............   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "." << std::setw(10);
        std::cout << trees[i].treeValue(0);
        std::cout << ".   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "............   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "............   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "." << std::setw(10);
        if (pageStartIndex + i + 1 < TOTAL_TREE_COUNT) {
            std::cout << reinterpret_cast<std::uintptr_t>(&trees[i + 1]) % 1000;
        } else {
            std::cout << "0";
        }
        std::cout << ".   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < treeCount; i++) {
        std::cout << "............   ";
    }
}
