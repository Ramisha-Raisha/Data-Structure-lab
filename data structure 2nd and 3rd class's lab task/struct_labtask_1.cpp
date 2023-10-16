/*Write a C++ program with appropriate data structure to keep records of 15 students.
Each student will have the following information:
•	Unique ID (you can use integer for this)
•	Number of semesters completed.
•	Number of credits completed.
•	CGPA
Print all the student’s ID whose CGPA is 3.75 or above. Categorize them as Scholarship students.
Print all the student’s ID who has completed more than 50 credits.
Print all the student’s ID who has completed minimum 2 semesters and minimum 28 credits.*/

#include<iostream>
#include<string.h>
using namespace std;

struct student{
    int id,nos,noc;
    float cg;
};

int main(){

       student st[15];
       cout<<"Enter 15 students details: "<<endl;
       for(int i=0;i<15;i++){
          cout<<"Enter the details of student "<<(i+1)<<endl;
          cout<<"Unique Id: ";
          cin>>st[i].id;
          //cout<<endl;
          cout<<"Number of semesters completed: ";
          cin>>st[i].nos;
          //cout<<endl;
          cout<<"Number of credits completed: ";
          cin>>st[i].noc;
          //cout<<endl;
          cout<<"Cgpa: ";
          cin>>st[i].cg;
          cout<<endl;
       }

       cout<<"Printing all the student's ID whose CGPA is 3.75 or above as scholarship students: "<<endl;
       cout<<"Scholarship Students: "<<endl;
       for(int i=0;i<15;i++){
            if(st[i].cg>=3.75){
                cout<<st[i].id<<endl;
            }
       }

       cout<<"Printing all the student's ID who has completed more than 50 credits: "<<endl;
       for(int i=0;i<15;i++){
            if(st[i].noc>50){
                cout<<st[i].id<<endl;
            }
       }

       cout<<"Printing all the student's ID who has completed minimum 2 semesters and minimum 28 credits: "<<endl;
       for(int i=0;i<15;i++){
            if(st[i].nos>=2 && st[i].noc>=28){
                cout<<st[i].id<<endl;
            }
       }

}
