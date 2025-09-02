#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 200;
int arr[MAX][MAX];
int dis[MAX][MAX];
int check[MAX][MAX];
int n,m;

int main(void){
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    dis[1][1]=1;
    //bfs
    queue<pair<int,int>> q;
    q.push(pair<int, int>(1,1));
    check[1][1]=1;
    while(!q.empty()){    
        int x = q.front().first;
        int y = q.front().second;
        q.pop();    
        // 하
        if(arr[x+1][y]!=0 && x+1<=n){

            if(dis[x+1][y]>dis[x][y]+1 || dis[x+1][y]==0){
                dis[x+1][y]=dis[x][y]+1;
                q.push(pair<int, int>(x+1, y));
            }
        }
        // 우
        if(arr[x][y+1]!=0 && y+1<=m){
            if(dis[x][y+1]>dis[x][y]+1 || dis[x][y+1]==0){
                dis[x][y+1]=dis[x][y]+1;
                q.push(pair<int, int>(x, y+1));
            }
        }
        // 상
        if(arr[x-1][y]!=0 && x-1>0){
            if(dis[x-1][y]>dis[x][y]+1 || dis[x-1][y]==0){
                dis[x-1][y]=dis[x][y]+1;
                q.push(pair<int, int>(x-1, y));
            }
        }
        // 좌
        if(arr[x][y-1]!=0 && y-1>0){
            if(dis[x][y-1]>dis[x][y]+1 || dis[x][y-1]==0){
                dis[x][y-1]=dis[x][y]+1;
                q.push(pair<int, int>(x, y-1));
            }
        }
    }

    cout<<dis[n][m];

    return 0;
}