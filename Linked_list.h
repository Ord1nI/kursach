#pragma once
#include <string>
struct Node {
    public:
        std::string name;
        std::string auther;
        std::string date;
        std::string pages;
        Node* next;

        Node(std::string name, std::string auther, std::string date, unsigned int pages);
};
class LinkedList {
    Node* head;
    int sort_by;
    public:
    unsigned int size;
        LinkedList();
        void insert(std::string name,std::string auther,std::string date,unsigned int pages);

        void remove(std::string name);

        void sort(int n);

        void display();

        Node* GetByPos(unsigned int pos);


        ~LinkedList();
};
