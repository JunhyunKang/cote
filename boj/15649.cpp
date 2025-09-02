#include <iostream>
#include <algorithm>


using namespace std;

int n, m;

int isused[10];
int arr[10];

void find(int k){
    if(k==m){
        for(int i =0; i<m ; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i =1;i<=n;i++){
        if(!isused[i]){
            arr[k]=i;
            isused[i]=1;
            find(k+1);
            isused[i]=0;
        }
    }
}


int main(void){
    
    
    cin>>n>>m;

    find(0);

    return 0;
}