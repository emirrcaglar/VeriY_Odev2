#include "LinkedList.hpp"
#include "Tree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
        std::cout << "Tree " << i << ":\n" << trees[i] << std::endl << std::endl;

        std::cout << "Enter 'a' to move left, 'd' to move right, 's' to exit: ";
        std::cin >> secim;

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
