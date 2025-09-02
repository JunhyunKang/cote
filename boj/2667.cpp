#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 30;
int arr[MAX][MAX];
int check[MAX][MAX];
int cnt;
int n;
int ans[MAX*MAX];

void search(int x, int y){
    //하
    if(arr[x+1][y]!=0 && check[x+1][y]==0 &&x+1<=n){
        cnt++;
        check[x+1][y]=1;
        search(x+1, y);
    }    

    //우
    if(arr[x][y+1]!=0 && check[x][y+1]==0 && y+1 <=n){
        cnt++;
        check[x][y+1]=1;
        search(x, y+1);
    }   

    //상
    if(arr[x-1][y]!=0 && check[x-1][y]==0 && x-1>0){
        cnt++;
        check[x-1][y]=1;
        search(x-1, y);
    }   

    //좌
    if(arr[x][y-1]!=0 && check[x][y-1]==0 && y-1>0){
        cnt++;
        check[x][y-1]=1;
        search(x, y-1);
    }
    //섬
    if(arr[x][y-1]==0 && arr[x][y+1]==0 && arr[x-1][y]==0 && arr[x+1][y]==0){
        cnt++;
    }
    
    return;
}

int main(void){
    int i,j;  
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    int tmp=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cnt =0;
            if(check[i][j]!=0 || arr[i][j]==0){
                continue;
            }
            search(i,j);
            ans[tmp] = cnt;
            tmp++;
        }
    }
    sort(ans, ans+tmp);
    cout<<tmp<<'\n';
    for(i=0;i<tmp;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}