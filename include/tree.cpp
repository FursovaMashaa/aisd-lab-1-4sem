#pragma once
#include <iostream>
#include <algorithm> 
#include <stdexcept>
#include<vector>
#include <random>
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
    std::vector<int> findDuplicates(const std::vector<int>& vec) {
        std::vector<int> duplicates;
        for (size_t i = 0; i < vec.size(); ++i) {
            bool isDuplicate = false;
            for (size_t j = 0; j < i; ++j) {
                if (vec[i] == vec[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate) {
                bool isAlreadyAdded = false;
                for (int dup : duplicates) {
                    if (vec[i] == dup) {
                        isAlreadyAdded = true;
                        break;
                    }
                }
                if (!isAlreadyAdded) {
                    duplicates.push_back(vec[i]);
                }
            }
        }
        return duplicates;
    }
    std::vector<int> random(int a, int b, size_t n, size_t i) {
        std::vector<int> res;
        std::mt19937 gen(i);
        std::uniform_int_distribution<> distribution(a, b);
        for (size_t j = 0; j < n; j++) {
            size_t x = distribution(gen);
            res.push_back(x);
        }
        return res;
    }

    int random(int a, int b, size_t i) {
        std::mt19937 gen(i);
        std::uniform_int_distribution<> distribution(a, b);
        return distribution(gen);
    }
}

