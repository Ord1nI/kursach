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
    int sort_by;
    public:
        LinkedList(){
            this->head = nullptr;
            this->sort_by = 0;
            this->size = 1;
        }
        void insert(std::string name,std::string auther,std::string date) {
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
        void remove(std::string name) {
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
        void sort(int n) {
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
                        std::swap(*(&current->next->name + n),*(&current->name + n));
                    swapped = true;
                    }
                    current = current->next;
                }
                tmp = current;
            } while(swapped);
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
            std::cout << std::endl;
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
    Head.insert("baa","david","12.42.2005");
    Head.insert("aaa","bord","12.42.2005");
    Head.insert("bba","alex","12.42.2005");
    Head.display(1);
    Head.sort(1);
    Head.insert("aaa","muxamed","12.42.2005");
    Head.insert("abb","bob","21.12.2004");
    Head.display(1);


}
