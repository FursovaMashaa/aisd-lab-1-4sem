#pragma once
#include <iostream>
#include <cstdio> 
#include <stdexcept>
#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
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
        bool contains(T val) {
            if (!root) {
                return false;
            }
            Node<T>* cur = root;
            while (cur) {
                if (cur->_value == val) {
                    return true;
                }
                else if (cur->_value < val) {
                    cur = cur->_right;
                }
                else if (cur->_value > val) {
                    cur = cur->_left;
                }
            }
            return false;
        }

       

        void erase(int key) {
            deleteNode(root, key);
        }

    
        vector<int> random(int a, int b, size_t n) {
            vector<int> res;
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> distribution(a, b);
            for (size_t j = 0; j < n; j++) {
                int x = distribution(gen);
                res.push_back(x);
            }
            return res;
        }


        void fillTreeWithRandomNumbers(int count) {
            double time_count_vec = 0;
            double time_count_tree = 0;
            for (int j = 0; j < 100; j++) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(-100000, 100000);

                auto start_vec = chrono::high_resolution_clock::now();
                vector<int> vec = random(-100000, 100000, count);
                auto end_vec = chrono::high_resolution_clock::now();


                auto start = chrono::high_resolution_clock::now();
                for (int i = 0; i < count; ++i) {
                    int randomNum = dist(gen);
                    insert(randomNum);
                }
                auto end = chrono::high_resolution_clock::now();
                time_count_tree += chrono::duration<double>(end - start).count();
                time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
            }
            cout << "Time spent filling in the tree " << count << " numbers: " << time_count_tree / 100 << " seconds" << endl;
            cout << "Time spent filling in the vec " << count << " numbers: " << time_count_vec / 100 << " seconds" << endl;
        }

        void containsTreeWithRandomNumbers(int count_t) {
            double time_count_vec = 0;
            double time_count_tree = 0;

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(-100000, 100000);
            for (int i = 0; i < count_t; ++i) {
                int randomNum = dist(gen);
                insert(randomNum);
            }
            auto start_tree = chrono::high_resolution_clock::now();
            for (int j = 0; j < 1000; j++) {
                int randomNum = dist(gen);
                contains(randomNum);
            }
            auto end_tree = chrono::high_resolution_clock::now();
            vector<int> vec = random(-100000, 100000, count_t);
            for (int i = 0; i < 1000; i++) {
                auto start_vec = chrono::high_resolution_clock::now();
                int cnt = count(vec.begin(), vec.end(), random(-10000, 10000, count_t)[0]);
                auto end_vec = chrono::high_resolution_clock::now();
                time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
            }
            time_count_tree += chrono::duration<double>(end_tree - start_tree).count();

            cout << "Time taken to contains the tree with " << count_t << " numbers: " << time_count_tree / 1000 << " seconds" << endl;
            cout << "Time taken to contains the vec with " << count_t << " numbers: " << time_count_vec / 1000 << " seconds" << endl;
        }

        void insertTreeWithRandomNumbers(int count) {
            double time_count_vec = 0;
            double time_count_tree = 0;

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(-100000, 100000);
            for (int i = 0; i < count; ++i) {
                int randomNum = dist(gen);
                insert(randomNum);
            }
            for (int j = 0; j < 1000; j++) {
                auto start_tree = chrono::high_resolution_clock::now();
                int randomNum = dist(gen);
                insert(randomNum);
                auto end_tree = chrono::high_resolution_clock::now();
                erase(randomNum);
                time_count_tree += chrono::duration<double>(end_tree - start_tree).count();
            }
            for (int i = 0; i < 1000; i++) {
                vector<int> vec = random(-100000, 100000, count);
                auto start_vec = chrono::high_resolution_clock::now();
                int randomNum = dist(gen);
                vec.push_back(randomNum);
                auto end_vec = chrono::high_resolution_clock::now();
                time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
            }
            cout << "Time taken to insert the tree with " << count << "  numbers: " << time_count_tree / 1000 << " seconds" << endl;
            cout << "Time taken to insert the vec with " << count << "  numbers: " << time_count_vec / 1000 << " seconds" << endl;
        }

        void eraseTreeWithRandomNumbers(int count) {
            double time_count_vec = 0;
            double time_count_tree = 0;

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(-100000, 100000);
            for (int i = 0; i < count; ++i) {
                int randomNum = dist(gen);
                insert(randomNum);
            }
            for (int j = 0; j < 1000; j++) {
                auto start_tree = chrono::high_resolution_clock::now();
                int randomNum = dist(gen);
                erase(randomNum);
                auto end_tree = chrono::high_resolution_clock::now();
                insert(randomNum);
                time_count_tree += chrono::duration<double>(end_tree - start_tree).count();

            }
            for (int i = 0; i < 1000; i++) {
                vector<int> vec = random(-100000, 100000, count);
                auto start_vec = chrono::high_resolution_clock::now();
                int randomNum = dist(gen);
                for (size_t j = 0; j < count; j++) {
                    if (vec[j] == randomNum) {
                        vec.erase(vec.begin() + j);
                        break;
                    }
                }
                auto end_vec = chrono::high_resolution_clock::now();
                time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
            }
            cout << "Time taken to erase the tree with " << count << " numbers: " << time_count_tree / 1000 << " seconds" << endl;
            cout << "Time taken to erase the vec with " << count << " numbers: " << time_count_vec / 1000 << " seconds" << endl;
        }
    };
    template <typename T>
    vector<int> findDuplicates(const vector<int>& vec) {
        vector<int> duplicates;
        MySet<int> temp(vec.data());
        for (size_t i = 0; i < vec.size(); ++i) {
            if (temp.contains(vec[i])) {
                temp.erase(vec[i]);
            }
            else if (!(count(duplicates.begin(), duplicates.end(), vec[i])))
                duplicates.push_back(vec[i]);
        }
        return duplicates;
    }
        
}

