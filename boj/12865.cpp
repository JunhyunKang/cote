// #include <bits/stdc++.h>

// using namespace std;
// int n,k;
// int dp[100002];
// vector<pair<int,int>> mulgun;
// map<int,int> mul;
// int main(void){
//     cin>>n>>k;
//     for(int i =0 ;i<n;i++){
//         int w,v;
//         cin>>w>>v;
//         mulgun.push_back({w,v});
//         mul[w]=v;
//     }

//     for(int i=1 ; i<=k ; i++){
//         vector<int> ans;
//         ans.push_back(0);
//         for(int j = i; j>i/2 ; j--){
//             if(mul.find(j) != mul.end()){
//                 int temp = i-j;
//                 int cur = mul[j] + dp[temp];
//                 ans.push_back(cur);
//             }
//         }
//         dp[i] = *max_element(ans.begin(),ans.end());
//     }

//     cout<<dp[k];

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
int n,k;
int dp[102][100002];
map<int, int> mul;
int main(void){
    cin>>n>>k;
    for(int i =0 ;i<n;i++){
        int w,v;
        cin>>w>>v;
        mul[w] = v;
    }

    for(int i=1 ; i<=100 ; i++){
        
        for(int j=1; j<=k+1 ;j++){
            int w=0 ,v=0;
            if(mul[i]!=0){
                w=i;
                v=mul[w];
            }

            if(w==0){
                dp[i][j] = dp[i-1][j];
            }
            else if(j>=w){
                dp[i][j] = max(dp[j-w][j] + v, dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i][j-1];

            }
        }
    }

    cout<<dp[n][k];

    return 0;
}