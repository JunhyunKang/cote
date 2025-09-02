#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

int main(void){

    cin>>n;
    for(int i =0;i<n;i++){
        int s,e;
        cin>>s>>e;
        v.push_back({e,s});
    }
    sort(v.begin(), v.end());
    int end = v[0].first;
    int count=1;
    for(int i=1;i<n;i++){
        if(end<=v[i].second){
            end = v[i].first;
            count++;
        }
    }
    
    cout<<count;
    return 0;
}