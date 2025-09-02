#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 1005;
int arr[MAX][MAX];
int check_b[MAX];
int check_d[MAX];

int n, m, v;

void bfs(int s){
    queue<int> q;
    q.push(s);
    check_b[s]=1;
    while(!q.empty()){
        int i=0;
        int qq=q.front();
        for(i=1;i<=n;i++){
            if(check_b[i]==0 && arr[qq][i]==1){
                q.push(i);
                check_b[i]=1;      
            }
        }
        cout<<qq<<" ";
        q.pop();
    }
}

void dfs(int s){
    
    check_d[s]=1;
    int i = 0;
    cout<<s<<" ";
    for(i=1;i<=n;i++){

        if(arr[s][i]==1){
            if(check_d[i]==0)
                dfs(i);
            else
                continue;
        }
    }
    return;   
}

int main(void){
    cin>>n>>m>>v;

    
    int i=0;

    int a, b;
    for(i=1;i<=m;i++){
        cin>>a>>b;
        arr[b][a]=1;
        arr[a][b]=1;               
    }

    dfs(v);
    cout<<"\n";
    bfs(v);


    return 0;
}
