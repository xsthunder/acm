#include<iostream>
#include<cctype>
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
#include<cmath>
#include<cassert>
const int inf=0x7fffffff;
const bool test=0;
typedef long long int ll;
using namespace std;
struct Node{
	vector<string> v;
	string name;
	int father;
};
Node link[2000];
int cnt=0;
void init(){
	cnt=0;
	memset(link,0,sizeof(link));
}
void pS(const string &tmp,int n){
	for(int i=0;i<n;i++){
		cout<<"    ";
	}
	cout<<tmp;
}
void pN(int d,int n){
	const Node &tmp=link[d];
	if(tmp.v.size()==0){
		pS(tmp.name,n);
		return ;
	}
	sort(tmp.v.begin(),tmp.v.end());
	for(unsigned int i=0;i<tmp.v.size();i++){
		pN(getID(tmp.v[i]),n+1);
	}
}
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%2d",*(begin+i));
	}
	printf("\n");
}
struct cmp{
	operator()(int a,int b){
		if(IDcache[a]>IDcache[b])return 1;
	}
};
int main()
{
	
	return 0;
}
//01_1.cc
//generated automatically at Sat Sep 24 14:31:10 2016
//by xsthunder

