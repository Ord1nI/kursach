#pragma once
#include <string>
struct Node {
    public:
        std::string name;
        std::string auther;
        std::string year;
        std::string pages;
        Node* next;
        Node* prev;

        Node(std::string name, std::string auther, std::string year, std::string pages);
};
class LinkedList {
    private:
        Node* head;
        Node* end;
        int sort_by;

        int compare(Node* item1, Node* item2,int sort_by);
    public:
    unsigned int size;
        LinkedList();
        void pop();
        void append(std::string name, std::string auther,std::string year,std::string pages);
        void insert(std::string name,std::string auther,std::string year,std::string pages);
        void insert(Node *item);

        void remove(long index);
        void remove(Node *item);

        void sort(int n);
        void clear();

        void display();
        void display_back();
        int GetSort_by();
        Node* GetByPos(unsigned int pos,bool reverse);
        Node* Begin();
        Node* End();


        ~LinkedList();
};
