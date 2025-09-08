#include <bits/stdc++.h>

using namespace std;


int n, m;

int main(void){

    cin>>n>>m;

    vector <int> result;

    vector <int> vec[32001];
    vector <int> check(n+1, 0);
    for(int i=0;i<m;i++){
        int s1,s2;
        cin>>s1>>s2;
        vec[s1].push_back(s2);
        check[s2]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(check[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int f = q.front();
        result.push_back(f);
        q.pop();
        for(int r : vec[f]){
            check[r]--;
            if(check[r]==0){
                q.push(r);
            }
        }        
    }
    for(int i:result){
        cout<<i<<" ";
    }



    return 0;
}