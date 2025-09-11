#include <bits/stdc++.h>

using namespace std;


int n,s;
int main(void){
    
    cin>>n>>s;
    vector<int> v;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(t);
;
    }
    int start =0;
    int end =0;
    int h = 0;
    int answer=INT_MAX, tmp=0;
    if(s==0){
        cout<<1;
        return 0;
    }
    while(start<=n&&end<=n){
        if(s<=h&&answer>end-start){
            answer=end-start;
        

        }
        if(s<=h){
            if(start<n)
                h=h-v[start];
            start++;
            
            
        }
        else{
            if(end<n)                                  
                h += v[end];
            end++;
            
        }
    }
    if(answer==INT_MAX){
        cout<<0;
        return 0;
    }
    cout<<answer;
   
    return 0;
}