#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const char A = 'A';
const char T = 'T';
const char C = 'C';
const char G = 'G';
int main(){
    string s;
    while(cin>>s){
        int ans = 0;
        int last = -1;
        for(int i =0 ;i<(int)s.size(); i++){
            char c = s[i];
            if(c == A || c == T ||  c == C || c == G){
                if(last < 0){
                    ans = max(ans, 1);
                    last = i;
                }
                else {
                    int tmp = i - last + 1;
                    ans = max(ans, tmp);
                }
            }
            else last = -1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
