#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> bo;
vector<int> bags;
int main(void){
    cin>>n>>k;
    for(int i =0;i<n;i++){
        int m,v;
        cin>>m>>v;
        bo.push_back({m,v});
    }
    sort(bo.begin(), bo.end());
    for(int i =0;i<k;i++){
        int m;
        cin>>m;
        bags.push_back(m);
    }
    
    sort(bags.begin(), bags.end());
    long long cnt=0;
    int idx = 0;
    priority_queue<int> pq;
    for(int i =0;i<k;i++){
        while(idx<n && bo[idx].first <= bags[i]){

            pq.push(bo[idx].second);
            idx++;
        }
        if(!pq.empty()){
            
            cnt += pq.top();
            pq.pop();
        }
    }
    cout<<cnt;
    return 0;
}