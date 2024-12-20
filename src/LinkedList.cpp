#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* right;
    while (current != nullptr) {
        right = current->right;
        delete current;
        current = right;
    }
}

void LinkedList::L_insert(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->right != nullptr) {
            current = current->right;
        }
        current->right = newNode;
        newNode->left = current;
    }
}

void LinkedList::L_print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->right;
    }
    std::cout << std::endl;
}