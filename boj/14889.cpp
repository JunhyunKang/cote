#include <iostream>
#include <algorithm>


using namespace std;

const int MAX = 25;
int n;
int arr[MAX][MAX];


int main(void){
    
    int i,j;
    
    cin>>n;
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    

    return 0;
}