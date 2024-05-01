#pragma once
#include <iostream>
#include <algorithm> 
#include <stdexcept>
using namespace std;

namespace function {
    template <typename T>
    struct Node {
        T _value;
        Node* _left;
        Node* _right;

        Node<T>(T value) :_value(value), _left(nullptr), _right(nullptr) {};
    };

    template <typename T>
    class MySet {
    private:
        Node<T>* root;
        template<typename T>
        void destroyTree(Node<T>* node) {
            if (node != nullptr) {
                destroyTree(node->_left);
                destroyTree(node->_right);
                delete node;
            }
        }

        void print(Node<T>* cur) {
            if (cur) {
                print(cur->_left);
                std::cout << cur->_value << " ";
                print(cur->_right);
            }
        }

        template <typename T>
        Node<T>* insert(Node<T>* root, int key) {
            if (root == nullptr) {
                root = new Node<T>(key);
                return root;
            }
            if (root->_value == key) {
                return root;
            }
            if (key < root->_value) {
                root->_left = insert(root->_left, key);
            }
            else {
                root->_right = insert(root->_right, key);
            }
            return root;
        }

        

        template <typename T>
        bool deleteNode(Node<T>*& node, int key) {
            if (!node) {
                return false;
            }

            if (node->_value > key) {
                return deleteNode(node->_left, key);
            }

            else if (node->_value < key) {
                return deleteNode(node->_right, key);
            }
            else {
                if (!node->_left) {
                    Node<T>* tmp = node->_right;
                    delete node;
                    node = tmp;
                }
                else if (!node->_right) {
                    Node<T>* tmp = node->_left;
                    delete node;
                    node = tmp;
                }
                else {
                    Node<T>* tmp = node->_right;
                    while (tmp->_left) {
                        tmp = tmp->_left;
                    }
                    node->_value = tmp->_value;
                    deleteNode(node->_right, tmp->_value);
                }
                return true;
            }
        }
    public:
        MySet() : root(nullptr) {}

        MySet(const int* data) {
            root = nullptr;

            int l = 0;

            for (size_t i = 0; i < sizeof(data); i++) {
                insert(data[i]);
            }
        }
        
        template <typename T>
        Node<T>* copyTree(const Node<T>* node) {
            if (node == nullptr) {
                return nullptr;
            }
            return new Node(node->_value, copyTree(node->_left), copyTree(node->_right));
        }

        MySet(const MySet& other) {
            root = copyTree(other.root);
        }

        ~MySet() {
            destroyTree(root);
        }

        MySet operator=(MySet other) {
            swap(root, other.root);
            return *this;
        }


        void print() {
            print(root);
        }

        bool insert(int key) {
            root = insert(root, key);
            return true;
        }

        template <typename T>
        bool contains(Node<T>* node, int key) {
            if (!node) return false;

            if (node->_value > key)

                return contains(node->_left, key);

            else if (node->_value < key)

                return contains(node->_right, key);

            return true;
        }

       

        void erase(int key) {
            deleteNode(root, key);
        }

    };
}

