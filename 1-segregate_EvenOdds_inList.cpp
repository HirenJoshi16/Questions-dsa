// Program to segregate even & odd nodes to list ~ O(n) & O(1) | coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    node* next;
};

// Creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to segregate even & odds to list
node* segregateNodes(node* head){
    // Edge case
    if(head == NULL || head->next == NULL){
        return head;
    }
    // Create two dummy nodes
    node* dummyEven = createNode(0);
    node* dummyOdd = createNode(0);
    // Set even & odds
    node* even = dummyEven;
    node* odd = dummyOdd;

    // Iterate till end
    while(head != NULL){
        if(head->data%2 == 0){
            even->next = head;
            even = even->next;
        }
        else{
            odd->next = head;
            odd = odd->next;
        }
        head = head->next;
    }
    // Link even & odd nodes
    even->next = dummyOdd->next;
    odd->next = NULL;
    // Update head
    head = dummyEven->next;
    
    // Delete dummy nodes
    delete dummyEven;
    delete dummyOdd;
    return head;
}

// Displays elements of list
void Traversel(node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    Traversel(head->next);
}

// Driver code
int main(){
    // List
    node* head = createNode(13);
    head->next = createNode(5);
    head->next->next = createNode(7);
    head->next->next->next = createNode(10);
    Traversel(head);
    cout<<endl;

    // Function call
    head = segregateNodes(head);
    Traversel(head);
    return 0;
}
