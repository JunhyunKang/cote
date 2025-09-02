#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int t;
    cin>>t;
    int arr[t];
    for(int i=0;i<t;i++){
        int a, b=0;
        cin>>a>>b;
        arr[i]=a+b;
    }
    for(int i=0;i<t;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}