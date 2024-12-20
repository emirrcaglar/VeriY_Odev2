#ifndef LinkedList_HPP
#define LinkedList_HPP
#include "Node.hpp"
class LinkedList
{
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();
    void L_insert(int data);
    void L_print();
};

#endif