#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        int j;
        for(j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<'\n';
    }
    return 0;
}