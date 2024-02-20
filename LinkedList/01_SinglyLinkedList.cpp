#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    // Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    // Destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

int findLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail, int data){
    // Check for empty LL
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    //Create Node
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}


// Insert At TAil
void insertAtTail(Node* &head,Node* &tail, int data){
    // Check for empty LL
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    // Step1: Create a Node
    Node* newNode = new Node(data);
    
    // Step2: Connect with tail
    tail->next = newNode;

    // Step3:Update tail
    tail = newNode; //or tail = tail -> next;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    // Check if empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    // Step1: Find position : prev & current
    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    
    while(count < position-1){
        
        temp = temp -> next;
        count++;
        
    }
    
    //inserting at last position
    if(temp -> next == NULL) {
        insertAtTail(head,tail,data);
        return ;
    }
    
    //creating a new node for data d
    Node* nodeToInsert = new Node(data);
    
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


void deleteNode(Node* &head, Node* &tail, int position){
    // If LL is Empty
    if(head == NULL){
        cout<<"Cannot delete, LL is empty"<<endl;
        return;
    }
    
    // IF Deleting the starting node
    else if(position == 1){
        Node* temp = head;
        head = head -> next;
        
        //memory free start node
        temp -> next = NULL;
        delete temp;
        return;
    }
    
    //deleting any middle or last node
    
    else{
        
        Node* current = head;
        Node* previous = NULL;
        
        int count = 1;
        
        while(count<position){
            
            previous=current;
            current= current -> next;
            count++;
        }
        previous->next=current->next;
        current->next=NULL;
        delete current;
        
    }
    
    
}


void print(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main()
{
    Node* node1 = NULL;
    
    //Head pointed to node1
    Node* head = node1;
    //Tail pointed to node1
    Node* tail = node1;
    
    // cout<<"HEAD -> "<<head->data<<endl;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    
    cout<<"HEAD -> "<<head->data<<endl;
    cout<<"TAIL -> "<<tail->data<<endl;
    print(head);
    
    insertAtHead(head,tail,50);
    insertAtTail(head,tail,77);
    
    cout<<"HEAD -> "<<head->data<<endl;
    cout<<"TAIL -> "<<tail->data<<endl;
    print(head);
    
    insertAtPosition(head, tail, 5, 101);
    print(head);
    
    deleteNode(head, tail, 4);
    print(head);
    return 0;
}
