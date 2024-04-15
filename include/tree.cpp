#pragma once
#include <iostream>
#include <algorithm> 
using namespace std;
namespace function {

    struct Node {
        int _value;
        Node* _left;
        Node* _right;

        Node(int value) :_value(value) {};
        Node(int value, Node* left, Node* right) :_value(value), _left(left), _right(right) {};
    };


    class MySet {
    private:
        Node* root;


        Node* copyTree(const Node* node) {
            if (node == nullptr) {
                return nullptr;
            }
            return new Node(node->_value, copyTree(node->_left), copyTree(node->_right));
        }

        void destroyTree(Node* node) {
            if (node != nullptr) {
                destroyTree(node->_left);
                destroyTree(node->_right);
                delete node;
            }
        }

    public:


    }
};

