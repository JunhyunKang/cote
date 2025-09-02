#include <bits/stdc++.h>

using namespace std;

int t,n;
int main(void){
    cin>>t;
    
    for(int T =0 ; T<t;T++){
        vector<pair<int,int>> v;
        cin>>n;
        for(int i =0;i<n;i++){
            int f,s;
            cin>>f>>s;
            v.push_back({f,s});
        }
        
        int check, count=1;
        sort(v.begin(), v.end());

        check =  v[0].second;

        for(int i =1;i<n;i++){
            int vf = v[i].first;
            int vs = v[i].second;
            if(check<vs){
                continue;
            }
            check = vs;
            count++;
        }
        cout<<count<<'\n';

    }


    

 
    return 0;
}