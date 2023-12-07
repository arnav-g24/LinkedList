#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(): head(nullptr), tail(nullptr), length(0){
    // nothing to implement here as it is default constructor
    // head and tail get set to nullptr in the header of the function
}

LinkedList::LinkedList(const LinkedList &src): head(nullptr), tail(nullptr), length(0){
    // implement
    Node* temp = src.head;
    while(temp != nullptr){
        this->insert(temp->value);
        temp = temp->next;
    }
}

LinkedList::~LinkedList(){
    // calls clear()
    // clear() as a function is not needed
    // can be directly implemented here
    // destructor deletes all allocated memory
    clear();
}

LinkedList& LinkedList::operator=(const LinkedList &src){
    // implement
    if(this != &src){
        clear();
        Node* temp = src.head;
        while(temp != nullptr){
            this->insert(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

void LinkedList::insert(int val){
    Node* toAdd = new Node(val);

    if(head == nullptr){
        head = toAdd;
        head->next = tail;
        length++;
        return;
    }

    if(*toAdd < *head){
        toAdd->next = head;
        head = toAdd;
        head->next = tail;
        length++;
        return;
    }else{
        Node* tempHead = head;
        while(tempHead->next != nullptr){
            Node* tempNext = tempHead->next;
            if(*toAdd < *tempNext){
                tempHead->next = toAdd;
                toAdd->next = tempNext;
                length++;
                return;
            }
            tempHead = tempHead->next;
        }
        tempHead->next = toAdd;
        tail = toAdd;
        length++;
    }
}

void LinkedList::clear(){
    // helper function for the destructor
    while(head != nullptr){               // (temp->next != nullptr) because if temp itself is nullptr (temp != nullptr): overflow
        Node* temp = head;                // temp node to store the current value
        head = head->next;                 // set head to next
        delete temp;                      // delete temp (old head)
    }
    tail = nullptr;                       // set tail to nullptr as head is already nullptr
    length = 0;                           // reset length
}

void LinkedList::print(){
    cout << "\n";2
    Node* temp = head;
    int i = 1;
    while(temp != nullptr){
        cout << "Node " << i << ": " << temp->value << ", Memory Address: " << temp << endl; 
        temp = temp->next;
        i++;
    }
    cout << "Length: " << this->length << endl;
}
