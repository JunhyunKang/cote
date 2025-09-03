#include <bits/stdc++.h>

using namespace std;

vector<int> zeros;
vector<int> negative;
vector<int> positive;

int main(void){
    int n,answer=0;
    
    cin>>n;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp>0){
            positive.push_back(tmp);
        }
        else if(tmp<0){
            negative.push_back(tmp);
        }
        else{
            zeros.push_back(tmp);
        }
    }

    sort(positive.begin(), positive.end(), greater<>());
    sort(negative.begin(),negative.end());

    // 음수 음수 곱
    // 음수와 0있으면 두개곱
    // 옴수 한개 남으면 가장 큰 음수 만 더하고 나머지곱
    // 음수 없고 0만 있을때는 그냥 더하기
    int psize = positive.size();
    for(int i =0; i<psize ;i=i+2){
        if(psize%2==0){
            if(positive[i]==1){
                answer += 2;
            }
            else{
                if(positive[i+1]==1){
                    answer = answer+positive[i]+positive[i+1];

                }
                else{
                    answer = answer+positive[i]*positive[i+1];
                }
            }
        }
        else{
            if(i==psize-1){
                answer = answer+positive[i];

            }
            else{
                if(positive[i]==1){
                    answer += 2;
                }
                else{
                    if(positive[i+1]==1){
                        answer = answer+positive[i]+positive[i+1];

                    }
                    else{
                        answer = answer+positive[i]*positive[i+1];
                    }
                }            
            }
        }
    }
    
    int nsize = negative.size();

    for(int i =0; i<nsize ;i=i+2){
        if(nsize%2==0){
            answer = answer+negative[i]*negative[i+1];
        }
        else{
            if(i==nsize-1){
                if(zeros.size()==0){
                    answer = answer+negative[i];
                }
            }
            else{
                answer = answer+negative[i]*negative[i+1];
            }
        }
    }

    cout<<answer;

    return 0;
}