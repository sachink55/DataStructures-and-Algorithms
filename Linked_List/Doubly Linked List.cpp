#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getLength(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node*& head, int data){
    Node* newNode = new Node(data);
    if(head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int data, int pos){
    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    for(int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    newNode->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtHead(Node*& head){
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    delete temp;
}

void deleteAtTail(Node*& head){
    if(head == NULL) return;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    delete temp;
}

void deleteAtPosition(Node*& head, int pos){
    if(head == NULL || pos <= 0) return;
    if(pos == 1) {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    for(int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtPosition(head, 15, 2);
    print(head);
    deleteAtPosition(head, 2);
    print(head);
    deleteAtHead(head);
    print(head);
    deleteAtTail(head);
    print(head);
    return 0;
}
