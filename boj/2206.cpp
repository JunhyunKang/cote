#include <bits/stdc++.h>

using namespace std;
typedef struct pos{
    int x;
    int y;
    int chance;
} pos;
int check[1001][1001][2];
int main(void){
    check[0][0][0] =1;
    check[0][0][1] =1;
    int n, m;
    cin>>n>>m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    queue<pos> Q;
    for(int i =0 ; i<n ; i++){
        for(int j =0 ;j<m ; j++){
            scanf("%1d", &map[i][j]);        
        }
    }

    int c = 0;
    
    int answer = -1;
    
    Q.push({0,0,0});
    check[0][0][0]=1;
    while(!Q.empty()){
        int curx = Q.front().x;
        int cury = Q.front().y;
        int chance = Q.front().chance;
        Q.pop();
        if(curx==n-1 && cury==m-1 && chance<=1){
            cout<<check[curx][cury][chance];
            return 0;
        }
        for(int i =0 ;i<4 ;i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m || check[nx][ny][chance]>=1 ){
                continue;
            }
            
            
            
            if(map[nx][ny] ==1 && chance ==0){
                check[nx][ny][1]=check[curx][cury][0] + 1;
                Q.push({nx,ny,chance+1});

            }
            else if(map[nx][ny] ==0 && chance<=1){
                
                check[nx][ny][chance]=check[curx][cury][chance] + 1;
                
                Q.push({nx,ny,chance});
            }
        }

    }
    
    cout<<-1;
    
    return 0;
}