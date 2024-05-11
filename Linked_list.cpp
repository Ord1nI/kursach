#include "Linked_list.h"
#include <string>
#include <iostream>
Node::Node(std::string name, std::string auther, std::string date, std::string pages){
    this->name = name;
    this->auther = auther;
    this->date = date;
    this->pages = pages;
    this->next = nullptr;
    this->prev = nullptr;
}
LinkedList::LinkedList(){
    this->head = nullptr;
    this->sort_by = 0;
    this->size = 0;
}
int LinkedList::compare(Node* item1,Node* item2,int sort_by) {
    std::string *val_item1;
    std::string *val_item2;
    switch(sort_by){
        case 0:
            val_item1 = &item1->name;
            val_item2 = &item2->name;
            break;
        case 1:
            val_item1 = &item1->auther;
            val_item2 = &item2->auther;
            break;
        case 2:
            val_item1 = &item1->date;
            val_item2 = &item2->date;
            break;
        case 3:
            val_item1 = &item1->pages;
            val_item2 = &item2->pages;
            break;
        default:
            val_item1 = &item1->name;
            val_item2 = &item2->name;
    }
    if (*val_item1 > *val_item2)
        return 1;
    if (*val_item1 < *val_item2)
        return -1;
    return 0;
}
Node* LinkedList::End() {
    return this->end;
}
Node* LinkedList::Begin() {
    return this->head;
};
int LinkedList::GetSort_by() {
    return this->sort_by;
}
void LinkedList::insert(std::string name,std::string auther,std::string date,std::string pages) {
    size += 1;
    Node* newNode = new Node(name,auther,date,pages);
    if(head == nullptr ||  (compare(head,newNode,sort_by) != -1  ))  {
        if (head!=nullptr)
            head->prev = newNode;
        else
            end = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while(current->next != nullptr && compare(current->next,newNode,sort_by) != 1) {
            current = current->next;
        }
        if (current->next == nullptr) {
            end = newNode;
        }
        else
            current->next->prev = newNode;
        newNode->next = current -> next;
        newNode->prev = current;
        current->next = newNode;

    }
}
void LinkedList::remove(long index) {
    if (index>size-1)
        return;
    Node* current = head;
    Node* prev = nullptr;
    for (long i = 0; i<index; i++){
        prev = current;
        current = current->next;
    }
    if (prev != nullptr){
        if (current->next !=nullptr){
            prev->next = current->next;
            prev->next->prev = prev;
        }
        else {
            end = prev;
            prev->next = nullptr;
        }
    } else {
        if (current->next !=nullptr){
            head = current->next;
            head->prev = nullptr;
        } else {
            end = nullptr;
            head = nullptr;
        }

    }

    size -=1;
    delete current;
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
            if(compare(current->next,current,n) == -1) {
                std::swap(current->next->name,current->name);
                std::swap(current->next->auther,current->auther);
                std::swap(current->next->date,current->date);
                std::swap(current->next->pages,current->pages);
            swapped = true;
            }
            current = current->next;
        }
        if (current->next == nullptr)
        {
            end = current;
        }
        tmp = current;
    } while(swapped);
}
void LinkedList::display() {
    Node* temp = head;
    while(temp != nullptr) {
        std::cout << *(&(temp->name)) << " - ";
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
    temp = head;
    while(temp != nullptr) {
        std::cout << temp->pages << " - ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
void LinkedList::display_back() {
    Node* temp = end;
    while(temp != nullptr) {
        std::cout << *(&(temp->name)) << " - ";
        temp = temp->prev;
    }
    std::cout << std::endl;
    temp = end;
    while(temp != nullptr) {
        std::cout << *(&(temp->name)+1) << " - ";
        temp = temp->prev;
    }
    std::cout << std::endl;
    temp = end;
    while(temp != nullptr) {
        std::cout << *(&(temp->name)+2) << " - ";
        temp = temp->prev;
    }
    std::cout << std::endl;
    temp = end;
    while(temp != nullptr) {
        std::cout << temp->pages << " - ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}
Node* LinkedList::GetByPos(unsigned int pos, bool reverse) {
    if (pos > size-1)
        return nullptr;
    if(not(reverse)) {
        Node* current = head;
        for(unsigned int i = 0; i != pos; ++i) {
            current = current->next;
        }
        return current;
    } else {
        Node* current = end;
        for(unsigned int i = 0; i != pos; ++i) {
            current = current->prev;
        }
        return current;
    }
    return nullptr;
}
LinkedList::~LinkedList() {
    Node* temp;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
