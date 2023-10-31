/*Take an array of 10 element as an input and search
the two elements that gives the sum nearest to zero.*/
#include<iostream>
#include<string.h>
#include<math.h>
#include <cstdlib>
using namespace std;
int main(){
    int arr[10];
    int sum_min, sum, left_min, right_min;
    cout<<"Please Enter the elements of the array: "<<endl;
    for(int i = 0; i<10; i++){
        cin>>arr[i];
    }
    left_min = 0;
    right_min = 1;
    sum_min = arr[0] + arr[1];
    for (int i = 0; i < 9; i++){
        for (int j = i + 1; j < 10; j++){
            sum = arr[i] + arr[j];

            if (abs(sum_min) > abs(sum)){
                sum_min = sum;
                left_min = i;
                right_min = j;
            }
        }
    }
   cout << "The two elements that gives the sum nearest to zero are: " << arr[left_min] << " and " << arr[right_min];
}
