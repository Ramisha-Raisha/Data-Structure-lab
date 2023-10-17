#include<iostream>
#define max 4
using namespace std;

int Stack[max];
int i,top=-1;


bool isFull(){
  if(top== max - 1){
    return true;
}
 else{
    return false;}
}
bool isEmpty(){
 if(top==-1){
    return true;
 }
 else{
    return false;}
}

void Top_Element(){
  cout<<"Top element is: "<<Stack[top]<<endl;
}

void push(int x){
  if(isFull()){
    cout<<"Stack overflowed!"<<endl;
    cout<<"Unable to push any element :("<<endl;
}
  else{
    top++;
    Stack[top]=x;
}
}
void pop(){
  if(isEmpty()){
    cout<<"Stack is empty!"<<endl;
    cout<<"Nothing is to pop out.Sorry :<"<<endl;
}
  else{
    Stack[top];
    top--;
}
}
void Display(){
  if (isEmpty()){
    cout<<"Stack is empty"<<endl;
}
  else{
    cout<<"Stack elements are"<<endl;
   for(i=top;i>=0;i--){
    cout<<Stack[i]<<endl;
   }
}

}
main(){
    int choice,j;
//cout<<"Enter the stack size: ";
//cin>>Maxsize;
   cout<<"Please enter your choice: "<<endl;
   cout<<"1) push element in the Stack"<<endl;
   cout<<"2) Pop element from the stack"<<endl;
   cout<<"3) Display the stack"<<endl;
   cout<<"4) Display the top value"<<endl;
   cout<<"5) Exit"<<endl;

do{
   cout<<"Enter your choice: "<<endl;
   cin>>choice;
  switch(choice){
    case 1:{
     cout<<"Enter your value: ";
     cin>>j;
     push(j);
     break;
 }
    case 2:{
    pop();
    break;
 }
    case 3:{
    Display();
    break;
 }
   case 4:{
   Top_Element();
   break;
 }
   case 5:{
    cout<<"Exit"<<endl;
    break;
 }
   default :{
    cout<<"invalid choice"<<endl;
 }
}
}while(choice!=5);
}
