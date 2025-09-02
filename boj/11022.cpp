#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int a=0;
    int b=0;
    int t=0;
    cin>>t;
    int arr[t];
    for(int i=0 ;i<t;i++){
        cin>>a>>b;
        cout<<"Case #"<<i+1<<": "<<a<<" + "<<b<<" = "<<a+b<<'\n';

    }
    return 0;
}