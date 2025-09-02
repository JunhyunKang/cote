#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int a=0;
    int b=0;
    int t=0;
    char c;
    cin>>t;
    int arr[t];
    for(int i=0 ;i<t;i++){
        cin>>a>>c>>b;
        arr[i]=a+b;
    }
    for(int i=0 ;i<t;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}