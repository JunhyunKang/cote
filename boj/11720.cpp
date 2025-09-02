#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int t;
    cin>>t;
    char arr[200];
    int irr[200];
    for(int i=0 ; i<t ; i++){
        cin>>arr[i];
        irr[i]=atoi(&arr[i]);
    }
    int ans=0;
    for(int i=0 ; i<t;i++){
        ans = ans + irr[i];
        
    }
    cout<<ans;

}