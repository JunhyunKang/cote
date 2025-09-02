#include <iostream>
// #include <bits.c
using namespace std;

vector<string> split(string s, string d){
    // for(int i=0;i<s.size();i++){

    // }
    vector<string> result;
    int start =0;
    int end = s.find(d);
    while(end<s.length()){
        result.push_back(s.substr(start, end-start));
        start = end+d.length();
        end = s.find(d, start);
    }
    result.push_back(s.substr(start));
    return result;

}

    // int a[10];
int main(){
    string a ="ab->cd->ef";
    vector<string> s = split(a,"->");
    
    for(int i =0 ; i<s.size();i++){
        cout<< s[i];
        cout << '\n';
    }
    return 0;
    // }
    // while(next_permutation(a.begin(), a.end()));
}
