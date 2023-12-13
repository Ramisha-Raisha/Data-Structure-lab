#include<iostream>
#include <cstdlib>
using namespace std;
class Node{
  public:
      int val;
      Node* prev;
      Node* next;

      Node(int data){
        val = data;
        prev = NULL;
        next =  NULL;
      }
};

class DoublyLinkedList{
   public:
   Node* head;
   Node* tail;

   DoublyLinkedList(){
     head = NULL;
     tail = NULL;
   }

   void insertAtStart(int val){

      Node* new_node = new Node(val);
      if(head == NULL){
        head = new_node;
        tail = new_node;
        return;
      }
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
      return;
   }

   void insertAtEnd(int val){
     Node* new_node = new Node(val);
     if(tail == NULL){
        head = new_node;
        tail = new_node;
     }
     tail->next = new_node;
     new_node->prev = tail;
     tail = new_node;
     return;
   }

   void insertAfter(Node* prev_node,int data){
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node(data);
    //new_node->val = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
   }
   void insertAtMiddle(int val){
       Node* temp = head;
       int total = 0, middlenode_num;
       while(temp != NULL){
         temp = temp->next;
         total++;
    }
      if(total%2 != 0){middlenode_num = (total/2)+1;}
      else{middlenode_num = total/2;}
       Node* temp1 = head;
       int sum = 1;
       while(sum<(middlenode_num-1)){
         temp1 = temp1->next;
         sum++;
       }
       ///temp1 will be pointing to the node at (middlenode_num-1) th position
       Node* new_node = new Node(val);
       new_node->next = temp1->next;
       temp1->next = new_node;
       new_node->prev = temp1;
       new_node->next->prev = new_node;
       return;
   }
   void deleteAtStart(){
     if(head == NULL){
        return;
     }
     Node* temp = head;
     head = temp->next;
     if(head != NULL){
        head->prev = NULL;
     }
     else if(head == NULL){///if there is 1  node in the linked list
        tail = NULL;
     }
     delete temp;
   }
   void deleteAtEnd(){
      if(head == NULL){
        return;
     }
     Node* temp = tail;
     tail = tail->prev;
     if(tail == NULL){
        head = NULL;
     }
     else{
        tail->next = NULL;
     }
     free(temp);
   }
   void deleteNode(int key){
     Node* temp = head->next; ///to store the head's next node
     Node* prior = NULL;
     while(temp != NULL && temp->val != key){
            ///shifting to next node
            prior = temp;
            temp = temp->next;
        }
        ///if the need to be checked node is null as there is nd operator.
        if(temp == NULL){
          return;
        }
        ///if the node is found
        prior->next = temp->next;
        temp->next->prev = prior;
        delete temp;
        return;

   }
   void deleteMiddleNode(){
     Node* temp = head;
       int total = 0, middlenode_num;
       while(temp != NULL){
         temp = temp->next;
         total++;
    }
     if(total%2 != 0){middlenode_num = (total/2)+1;}
     else{middlenode_num = total/2;}
     Node* temp1 = head;
     int sum = 1;
     while(sum<middlenode_num){
        temp1 = temp1->next;
        sum++;
     }
     ///now temp1 is on the middlenode position
     temp1->prev->next = temp1->next;
     temp1->next->prev = temp1->prev;
     delete temp1;
     return;
   }


   void display(){
     Node* temp = head;
     while(temp != NULL){
         cout<<temp->val<<" ";
         temp = temp->next;
    } cout<<endl;
  }

};

int main(){

   Node* new_node = new Node(3);
   //cout<<new_node->val<<" "<<new_node->next<<" "<<new_node->prev<<endl;
   DoublyLinkedList dll;
   dll.insertAtStart(3);
   dll.insertAtStart(2);
   dll.insertAtStart(0);
   dll.display();
   dll.insertAtEnd(4);
   dll.insertAtEnd(5);
   dll.insertAtEnd(6);
   dll.display();
   Node* n = dll.head;///dll.head->next..output will be 0213456///
   dll.insertAfter(n,1);
   cout<<"After adding a node after a specific node: "<<endl;
   dll.display();
   dll.insertAtMiddle(8);
   dll.display();
   dll.deleteAtStart();
   cout<<"After deleting the first node: "<<endl;
   dll.display();
   dll.deleteAtEnd();
   cout<<"After deleting the last node: "<<endl;
   dll.display();
   dll.deleteNode(8);
   cout<<"After deleting definite node: "<<endl;
   dll.display();

   cout<<"After deleting middle node: "<<endl;
   dll.deleteMiddleNode();
   dll.display();
}
