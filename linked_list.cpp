#include <string>
#include <iostream>
struct Node {
    std::string name;
    std::string auther;
    std::string date;
    Node* next;

    Node(std::string name, std::string auther, std::string date){
        this->name = name;
        this->auther = auther;
        this->date = date;
        this->next = nullptr;
    }
};
class LinkedList {
    Node* head;
    int size;
    public:
        LinkedList(){
            this->head = nullptr;
        }
        void push(std::string name,std::string auther,std::string date) {
            size += 1;
            Node* newNode = new Node(name,auther,date);
            if(head == nullptr)
                head = newNode;
            else {
                newNode->next = head;
                head = newNode;
            }
        }
        void ddelete(std::string name) {
            Node* temp = head;
            while(temp != nullptr) {
                if (temp->name == name) {

                }
            }

        }
        void display(int n) {
            Node* temp = head;
            while(temp != nullptr) {
                if (n == 0){
                    std::cout << temp->name << " - ";
                }
                if (n == 1){
                    std::cout << temp->auther << " - ";
                }
                if (n == 2){
                    std::cout << temp->date << " - ";
                }
                temp = temp->next;
            }
        }
        ~LinkedList() {
            Node* temp;
            while(head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

};
int main() {
    LinkedList Head;
    Head.push("c++","andrew","21.12.2004");
    Head.push("python","andrew","12.42.2005");
    Head.display(0);
    std::cout << std::endl;
    Head.display(1);
    std::cout << std::endl;
    Head.display(2);
}
