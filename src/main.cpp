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

std::ifstream file("Agaclar.txt");


int main() {
    if (!file) {
        std::cerr << "Agaclar.txt isimli dosya acilamadi...";
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
    char choice;
    int i = 0; // Move `i` outside the loop to keep track of the current tree

    while (true) {
        
        system("CLS"); // Clear the screen (for Windows)

        int startIndex = (i / MAX_TREES_ON_SCREEN) * MAX_TREES_ON_SCREEN;
        int cellCount = std::min(MAX_TREES_ON_SCREEN, treeCount - startIndex);
        createCells(cellCount, trees + startIndex, TOTAL_TREE_COUNT, startIndex);  // Pass startIndex here
        pointToCells(i % MAX_TREES_ON_SCREEN); // the arrows that show the current tree
        std::cout << std::endl;

        bool isMirrored;
        if(choice != 'w') { 
            trees[i].printTree();
        } else if(choice == 'w'){
            if(isMirrored) { // if the tree is already mirrored, print the tree
                trees[i].printTree();
                isMirrored = false;
                std::cout << "Tree is not mirrored.\n";
            } else { // if the tree is not mirrored, mirror the tree and print it
                trees[i].mirrorPrint();
                isMirrored = true;
                std::cout << "Tree is mirrored.\n";
            }
        }

        std::cout << "Sola gitmek icin 'a', saga gitmek icin 'd', agaci aynalamak icin 'w', silmek icin 's', cikis icin 'q': ";

        // Use _getch() to get a single character input without waiting for Enter
        // choice = _getch();

        std::cin >> choice;

        if (choice == 'q') {
            break; // Exit the loop
        } else if (choice == 'a') {
            if (i > 0) {
                i--; // Move to the previous tree
            } else {
                std::cout << "Zaten ilk agactasiniz.\n";
            }
        } else if (choice == 'd') {
            if (i < treeCount - 1) { // Ensure `i` doesn't exceed the last index
                i++; // Move to the next tree
            } else {
                std::cout << "Zaten son agactasiniz.\n";
            }
        } else if (choice == 's') { // deletion
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
                std::cout << "Agac silindi.\n";
            } else {
                std::cout << "Silinecek agac yok.\n";
            }
        } else {
            std::cout << "Gecersiz karakter. Lutfen gecerli bir karakter giriniz: 'a', 'd', 's', 'q'.\n";
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
    std::cout << "||||||||||||   \n";
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
    for(int i = 0; i < treeCount; i++) {
        std::cout << "." << std::setw(10);
        
        if(pageStartIndex + i + 1 < TOTAL_TREE_COUNT) {
            std::cout << reinterpret_cast<std::uintptr_t>(&trees[i+1])%1000;
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
