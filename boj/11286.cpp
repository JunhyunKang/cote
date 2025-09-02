#include <bits/stdc++.h>

using namespace std;


struct Compare{
    bool operator()(int a, int b){
        if(a==b){
            return false;
        }
        if(abs(a)!=abs(b)){
            return abs(a)>abs(b);
        }
        else{
            return a>b;
        }
    }
};

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    cout.tie(NULL);
    priority_queue<int, vector<int>, Compare> pq;
    int n;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        int a;
        cin>>a;
        if(a!=0){
            pq.push(a);
        }
        else{
            if(!pq.empty()){
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else{
                cout<<0<<'\n';
            }
        }
    }

    return 0;
}