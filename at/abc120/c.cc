#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string str;
    while(cin>>str){
        stack<char> s;
        int ans = 0;
        for(auto c:str){
            const char v = c - '0';
            if(!s.empty()){
                if(s.top()+v == 1){
                    ans ++ ;
                    s.pop();
                    continue;
                }
            }
            s.push(v);
        }
        cout<<ans*2<<endl;
    }
    return 0;
}
