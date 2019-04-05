#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N = 2e5;
int Sa[N];
int Sc[N];
int main(){
    int n,q;
    string s;
    while(cin>>n>>q>>s){
        Sa[0]=Sc[0] = 0;
        Sa[1]=Sc[1] = 0;
        for(int j=1 ;j<(int)s.size(); j++){
            char c = s[j];
            char bc = s[j-1];
            int i = j + 1;
            if(bc == 'A'&& c == 'C'){
                Sa[i] = Sa[i-1]+1;
            }
            else {
                Sa[i] = Sa[i-1];
            }
        }
        for(int j = 2 ;j<=(int)s.size(); j++){
            //cout<<j<<" "<<Sa[j]<<endl;
        }
        while(q--){
            int l,r;cin>>l>>r;
            int ans = Sa[r] - Sa[l-1];
            l --;
            if(l >=1){
                if(s[l] == 'C'&& s[l-1] == 'A'){
                    ans --;
                }
            }
            if(r - l + 1<=1){
                cout<<0<<endl;
            }
            else {
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
