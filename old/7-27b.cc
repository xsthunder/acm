#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
using namespace std;
const int inf=0x7fffffff;
const int N=50+5;
string s[N];
bool cmp(string a,string b){
	//cout<<a+b<<endl;
	//cout<<b+a<<endl;
	return a+b<b+a;
}
int main()

{
#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	while(scanf("%d", &n)&&n){
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		sort(s,s+n,cmp);
		for(int i=n-1;i>=0;i--){
			cout<<s[i];
		}
		cout<<endl;
	}
	

	
	//insert code
	return 0;
}
//7-27b.cc

