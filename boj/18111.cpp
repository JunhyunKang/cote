#include <iostream>
#include <algorithm>


using namespace std;


const int MAX = 550;
int arr[MAX][MAX];
int arr_h[260];
int arr_a[260];

int main(void){

    int n,m,b;

    cin>>n>>m>>b;

    int i,j;

    for(i=1;i<=n;i++){

        for(j=1;j<=m;j++){
            cin>>arr[i][j];
            arr_h[arr[i][j]]++;
        }
    }

    for(i=0;i<260;i++){
        if(arr_h[i]==0){
            continue;
        }
    // 블록개수 제한

        // 작은거
        





        // 큰거 제거후 블록 개수++





        if(b<=0){
            continue;
        }

        //arr_a 에 계산값 넣기



    }


    return 0;
}