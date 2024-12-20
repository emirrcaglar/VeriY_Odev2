#ifndef Node_HPP
#define Node_HPP

class Node {
    public:
        Node(char data);
        char data;
        Node* left;
        Node* right;
    private:
};

#endif