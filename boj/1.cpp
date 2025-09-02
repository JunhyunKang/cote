#include <iostream>

using namespace std;

const int MAX =15;

int arr[MAX];

int main(void){

    int i,j=1;

    for(i=1;i<=9;i++){

        cin>>arr[j];
        if(arr[j]/100>0){
            i=i+3;
        }
           
        j++;   
    }
    if(j==10){
        


    }
    else{

    }
    return 0;
}