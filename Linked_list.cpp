#include "Linked_list.h"
#include <string>
#include <iostream>
Node::Node(std::string name, std::string auther, std::string date){
    this->name = name;
    this->auther = auther;
    this->date = date;
    this->next = nullptr;
}
LinkedList::LinkedList(){
    this->head = nullptr;
    this->sort_by = 0;
    this->size = 1;
}
void LinkedList::insert(std::string name,std::string auther,std::string date) {
    size += 1;
    Node* newNode = new Node(name,auther,date);
    if(head == nullptr ||  *(&(head->name)+sort_by) >= *(&name + sort_by)) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while(current->next != nullptr && *(&(current->next->name)+sort_by) < *(&name + sort_by)) {
            current = current->next;
        }
        newNode->next = current -> next;
        current->next = newNode;
    }
}
void LinkedList::remove(std::string name) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && current->name.compare(name) != 0) {
        prev = current;
        current = current->next;
    }
    if (current != nullptr) {
        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
    }

}
void LinkedList::sort(int n) {
    sort_by = n;
    if (head == nullptr || head->next == nullptr)
        return;
    Node* current;
    bool swapped;
    do {
        current = head;
        swapped = false;
        Node* tmp = nullptr;

        while (current->next != tmp) {
            if(*(&current->next->name+n) < *(&current->name+n)) {
                std::swap(current->next->name,current->name);
                std::swap(current->next->auther,current->auther);
                std::swap(current->next->date,current->date);
            swapped = true;
            }
            current = current->next;
        }
        tmp = current;
    } while(swapped);
}
void LinkedList::display(int n) {
    Node* temp = head;
    while(temp != nullptr) {
        std::cout << *(&(temp->name)+n) << " - ";
        temp = temp->next;
    }
    std::cout << std::endl;
    temp = head;
    while(temp != nullptr) {
        std::cout << *(&(temp->name)+1) << " - ";
        temp = temp->next;
    }
    std::cout << std::endl;
    temp = head;
    while(temp != nullptr) {
        std::cout << *(&(temp->name)+2) << " - ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
LinkedList::~LinkedList() {
    Node* temp;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
