#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 150;
int arr[MAX][MAX];
int check[MAX][MAX];
int n;

void search(int x, int y, int h){
    //하
    if(arr[x+1][y]-h>0 && check[x+1][y]==0 && x+1<=n){
        check[x+1][y]=1;
        search(x+1, y,h);
    }    

    //우
    if(arr[x][y+1]-h>0 && check[x][y+1]==0 && y+1 <=n){
        check[x][y+1]=1;
        search(x, y+1,h);
    }   

    //상
    if(arr[x-1][y]-h>0 && check[x-1][y]==0 && x-1>0){
        check[x-1][y]=1;
        search(x-1, y,h);
    }   

    //좌
    if(arr[x][y-1]-h>0 && check[x][y-1]==0 && y-1>0){
        check[x][y-1]=1;
        search(x, y-1,h);
    }
    //섬
    if(arr[x][y-1]-h<=0 && arr[x][y+1]-h<=0 && arr[x-1][y]-h<=0 && arr[x+1][y]-h<=0){
        return;
    }
    
    return;
}

int main(void){
    int h ;
    int i,j;  
    cin>>n;
    int h_max=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
            if(h_max<arr[i][j]){
                h_max=arr[i][j];
            }
        }
    }
    int q=0;
    int maxans=0;
    int tmp;
    for(h=h_max-1;h>=0;h--){
        tmp=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                check[i][j]=0;
            }
        }

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(check[i][j]!=0 || arr[i][j]-h<=0){
                    check[i][j]=1;
                    continue;
                }
                check[i][j]=1;
                search(i,j,h);
                tmp++;
            }
        }
        if(maxans<tmp){
            maxans=tmp;
        }
    }
    cout<<maxans<<'\n';
    return 0;
}