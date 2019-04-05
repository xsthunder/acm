#include<iostream>
#include<string>
using namespace std;
char map[3000];
const char A = 'A';
const char T = 'T';
const char C = 'C';
const char G = 'G';
int main(){
    string s;
    map[A] = T;
    map[T] = A;
    map[C] = G;
    map[G] = C;
    while(cin>>s){
        cout<<map[s[0]]<<endl;;
    }
    return 0;
}
