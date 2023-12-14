#include<iostream>
#include <cassert>
using namespace std;
class Node{
   public:
       int val;
       Node* next;
   Node(int data){
       val=data;
       next=NULL;
   }
};
void insertAtHead(Node* &head, int val ){///taking head as pass by reference coz we have to change or edit the linked list/head reference
   ///allocating new node
   Node* new_node = new Node(val);
   ///pointing the new node to the 1st node of current linked list
   new_node->next = head;
   ///changing head pointer. It is now pointing to the new node now.
   head = new_node;
}

void insertAfter(Node* prev_node, int val) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";///as we have to insert after previous node
        return;
    }

    Node* new_node = new Node(val);
    ///new_node->data = val;//Constructor
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    ///temp has reached the last node
    temp->next = new_node;
}

void deleteNode(Node* &head, int key){
      Node* temp = head; ///to store the head node
      Node* prev = NULL; ///to keep tracking the previous node while the value isn't in the head node

      ///if the value is in the head node aka temp
      if(temp != NULL && temp->val == key){
         //transferring the head reference to the next node as going to delete the 1st node
         head = temp->next;
         delete temp;
         return;
      }
      ///if the value isn't found in the 1st node aka head
      else{
        while(temp != NULL && temp->val != key){
            ///shifting to next node
            prev = temp;
            temp = temp->next;
        }
        ///if the need to be checked node is null as there is nd operator.
        if(temp == NULL){
          return;
        }
        ///if the node is found
        prev->next = temp->next;
        delete temp;
        return;
      }
}

int GetNth(Node* head, int index) {
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (count == index){
            return (current->val);
        }
        else{
        count++;
        current = current->next;
        }
    }
    ///the caller was asking for a non-existent element,so assert fail
    assert(0);
}
void display(Node* head){///not needed to pass by reference coz we are not going to change the linked list

     Node* temp = head;///temporary pointer to traverse the whole linked list

     while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
        }
       //cout<<"NULL"<<endl;
       cout<<endl;
}

int main(){
   //Node* n = new Node(1);
   //cout<<n->val<<" "<<n->next<<endl;
   Node* head = NULL;
   insertAtHead(head,5);
   //display(head);
   insertAtHead(head,2);
   //display(head);
   insertAtHead(head,1);
   //display(head); ///(1,2,5)

   Node* node_before = head->next;
   insertAfter(node_before, 3);
   cout<<"After using insertAfter function: "<<endl;
   display(head); ///(1,2,3,5)

   Node* n = node_before->next;
   insertAfter(n,4);
   insertAtTail(head,7);
   insertAtTail(head,6);
   cout<<"After adding value at the end of the Linked List: "<<endl;
   display(head); ///(1-7,6)

   deleteNode(head, 7);
   cout<<"After deleting the node containing value 7: "<<endl;
   display(head);

   int dataATIndex = GetNth(head,2);
   cout<<"Data at Index 3 is: "<<dataATIndex;


 return 0;
}
