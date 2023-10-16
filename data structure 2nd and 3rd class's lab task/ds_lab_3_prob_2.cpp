/*Write a code that will create custom ciphers (encoded words) on strings. Follow this procedure:
1.Write a function named encode that takes TWO parameters, a string s and an integer j.
2.Skip j number of characters in the string and increase the ASCII value of the next character by 3.
3.Print the encoded string.
4.Then write a function named decode which will decode the string from iii.*/

#include<iostream>
#include<string.h>
using namespace std;
string ds;
/*void encode(string s, int m)
{
    string update; //updated string
    int val,c;
    for(int i=0; i<s.length(); i++) //iterate for every character
    {
        //cout<<s[i]<<endl;
        if(i%m==0 && i!=0 && int(s[i])!=32)
        {
            val=int(s[i])+2;
            //cout<<val<<endl;;
            update[i]=val;
        }
        else
        {
            update[i]=s[i];
        }
    }
    for(int i=0; i<s.length(); i++)
    {
        cout<<update[i];
    }
}*/
void encode2(string s, int j)
{
    string update;
    int val,c=j,ai=2;//j=2..c=5,,j=2,,c=8,j=2,i=5,...i=8,c=11,j=2,........
    for(int i=0; i<s.length(); i++)
    {
        // cout<<"c on loop = "<<c<<endl;;
        if( i==j)
        {
            val=int(s[i])+ai;
            c=c+j+1;
            // cout<<"if = "<<i<<"  c= "<<c<<endl;;
            update[i]=val;
        }
        else if(i==c)
        {
            val=int(s[i])+ai;
            c=c+j+1;
            //cout<<val<<endl;;
            update[i]=val;
            //  cout<<"else if = "<<i<<"  c= "<<c<<"s[i] = "<<s[i] <<endl;;
            //  cout<<"else if = "<<i<<"  j= "<<j<<endl;;
        }
        else
        {
            // cout<<"else ="<<i<<endl;;
            update[i]=s[i];
        }

    }
    cout<<"Encoded String: ";
    for(int i=0; i<s.length(); i++)
    {
        cout<<update[i];
    }
    cout<<endl;
}


void decode2(string s, int j)
{
    string update;
    int val,c=j,ai=2;
    for(int i=0; i<s.length(); i++)
    {
        // cout<<"c on loop = "<<c<<endl;;
        if( i==j)
        {
            val=int(s[i])-ai;
            c=c+j+1;
            // cout<<"if = "<<i<<"  c= "<<c<<endl;;
            update[i]=val;
        }
        else if(i==c)
        {
            val=int(s[i])-ai;
            c=c+j+1;
            //cout<<val<<endl;;
            update[i]=val;
            //  cout<<"else if = "<<i<<"  c= "<<c<<"s[i] = "<<s[i] <<endl;;
            //  cout<<"else if = "<<i<<"  j= "<<j<<endl;;
        }
        else
        {
            // cout<<"else ="<<i<<endl;;
            update[i]=s[i];
        }

    }
    cout<<"Decoded String: ";
    for(int i=0; i<s.length(); i++)
    {
        cout<<update[i];
    }

}

// i, ,a,m, ,a, ,s,t,u,d,e,n,t
// 1,2,3,1,2,3,1,2,3,1,2,3,1,2
// i, ,c,m, ,c, ,s,v,u,d,g,n,t
// 0,1,2,3,4,5,6,7,8,9,10,11,12,13


int main()
{
      encode2("I am a student",2);
      decode2("I cm c svudgnt",2);

    return 0;
}

