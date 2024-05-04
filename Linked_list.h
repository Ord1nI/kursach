#pragma once
#include <string>
struct Node {
    public:
        std::string name;
        std::string auther;
        std::string date;
        Node* next;

        Node(std::string name, std::string auther, std::string date);
};
class LinkedList {
    Node* head;
    int size;
    int sort_by;
    public:
        LinkedList();
        void insert(std::string name,std::string auther,std::string date);

        void remove(std::string name);

        void sort(int n);

        void display(int n);

        ~LinkedList();
};
