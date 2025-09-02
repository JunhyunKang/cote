#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a[12341234];
int main(void)
{
    int t,i,j;
    cin>>t;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    int q=0;
    int arr[t];
    for(i=0;i<t;i++){
        cin>>arr[i];
    }
    for(i=4;i<12;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }    
    for(i=0;i<t;i++){
        cout<<a[arr[i]]<<'\n';
    }
    return 0;
}