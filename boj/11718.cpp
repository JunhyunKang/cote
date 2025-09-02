#include <iostream>
#include <algorithm>

using namespace std;
char s[100][100];
int main(void){
    int i=0;

    while(fgets(s[i], 100, stdin)){
        cout<<s[i];
        i++;
    }
   
    
    return 0;
}