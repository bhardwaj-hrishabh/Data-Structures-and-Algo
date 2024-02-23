#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    // Constructor
    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    
    // Destructor
    ~Node(){
        int value = this -> data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<value<<endl;
    }
    
    
};

//-----------------------------------Traversing a linked list or printing-----------------
void print(Node* &head){
    Node* temp = head;
    
    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<endl;
}

//-----------------------------------Find Length of LL--------------------------------
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

// -----------------------------------Insert At Head -----------------------------------
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
    
}

// -----------------------------------Insert At Tail -----------------------------------
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}


//---------------------------------------Insert At Position -------------------------------
void insertAtPosition(Node* &head ,Node* &tail , int position , int data){
    // IF LL is Empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    //Insert At Start
    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }
    
    // Insert At End
    int len = getLength(head);
    if(position > len){
        insertAtTail(head ,tail , data);
        return;
    }
    
    int count = 1;
    Node* prevNode = head;
    
    while(count < position-1){
        prevNode = prevNode -> next;
        count++;
    }
    Node* curr = prevNode -> next;
    
    //creating a node for data
    Node* nodeToInsert = new Node(data);
    
    prevNode ->next = nodeToInsert;
    nodeToInsert -> prev = prevNode;
    curr -> prev = nodeToInsert;
    nodeToInsert -> next = curr;
}

//----------------------------------------------Deletion of Node at any Position -------------------------------------
void deleteNode(Node* &head, Node* &tail, int position){
    if(head == NULL){
        cout<<"LinkedList is Empty"<<endl;
        return;
    }
    
    if(head -> next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }
    
    int len = getLength(head);
    if(position > len){
        cout<<"Please Enter a Valid Position"<<endl;
    }
    
    if(position == len){
        // LAst Node delete
        
        Node* temp = tail;
        tail = tail -> prev;
        temp -> prev = NULL;
        tail -> next = NULL;
        delete temp;
        return;
    }
    
    // Delete from middle of LL
    int count = 1;
    Node* left = head;
    while( count < position - 1){
        left = left -> next;
        count++;
    }
    Node* curr = left -> next;
    Node* right = curr ->next;
    
    left -> next = right;
    right -> prev = left;
    
    curr -> next = NULL;
    curr -> prev = NULL;
    delete curr;
}


int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    first -> next = second;
    second ->prev = first;
    second -> next = third;
    third -> prev = second;
    
    print(first);
    
    insertAtHead(first, third, 50);
    insertAtTail(first, third, 501);
    insertAtPosition(first, third, 5, 400);
    print(first);
    
    deleteNode(first, third, 7);
    print(first);
    
    return 0;
}
