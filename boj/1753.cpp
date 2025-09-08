#include <bits/stdc++.h>

using namespace std;

int v,e,s;



int main(void){
    cin>>v>>e>>s;

    vector<vector<long long>> vec(v+1, vector<long long>(v+1,0));
    vector<vector<int>> check(v+1, vector<int>(v+1,0));
    vector<int> test[10];

    for(long long i=0; i<e;i++){
        long long x,y,va;
        cin>>x>>y>>va;
        if(vec[x][y]==0){
            vec[x][y]=va;
        }
        else{
            if(va<vec[x][y]){
                vec[x][y]=va;
            }
        }
    }
    queue<long long> q;
    queue<long long> q2;
    q.push(s);
    q2.push(0);
    check[s][s]=1;
    while(!q.empty()){
        long long cur = q.front();
        long long dist = q2.front();
        q2.pop();
        q.pop();
        for(long long i=1; i<v+1;i++){
            if(vec[cur][i]!=0 && check[cur][i]==0){
                check[cur][i]=1;
                if(vec[s][i]==0||vec[s][i]>vec[cur][i]+dist){
                    vec[s][i]=vec[cur][i]+dist;
                }
                q.push(i);
                q2.push(vec[s][i]);
            }
        }
    }
    
    for(long long i=1; i<v+1;i++){
        if(i==s){
            cout<<0<<'\n';
        }
        else if(vec[s][i]!=0){
            cout<<vec[s][i]<<'\n';
        }
        else{
            cout<<"INF\n";
        }

    }
    return 0;
}