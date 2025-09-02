#include <bits/stdc++.h>

using namespace std;

int main(void){
    int m, n;
    cin>>m>>n;

    vector<vector<int>> box(n, vector<int>(m,-1));
    vector<vector<int>> check(n, vector<int>(m,0));

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    queue<pair<int,int>> Q;

    for(int i = 0 ; i<n ; i++){
        for(int j =0; j<m;j++){
            cin>>box[i][j];
            if(box[i][j]==1){
                Q.push({i,j});
            }
            if(box[i][j]==-1){
                check[i][j] = -1;
            }
        }
    }
    int answer = -1;
    while(!Q.empty()){
        vector<pair<int, int>> curs;
        while(!Q.empty()){
            curs.push_back(Q.front());
            check[Q.front().first][Q.front().second] = 1;
            Q.pop();
        }
        for(int i =0; i<curs.size();i++){
            for(int j = 0 ;j<4;j++){
                int nx = curs[i].first+dx[j];
                int ny = curs[i].second+dy[j];
                if(nx<0 || nx>=n ||ny<0 ||ny>=m || check[nx][ny]!=0)
                    continue;
                check[nx][ny]=1;
                if(box[nx][ny]==-1){
                    continue;
                }
                box[nx][ny] = 1;
                Q.push({nx,ny});
            }
        }
        answer++;

    }
    for(int i =0; i<check.size();i++){
        if(count(check[i].begin(), check[i].end(), 0)){
            cout<<-1;
            return 0;
        }
    }
    cout<<answer;
    return 0;
}