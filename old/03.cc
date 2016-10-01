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
typedef pair<int,int> point;
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%2d",*(begin+i));
	}
	printf("\n");
}
string tmp;
void solve(int a,int b){
	while(tmp[a]==' ')a++;
	while(tmp[b]==' ')b--;
	if(a>=b)return;
	int ai,bi;
	for(int i=a;i<b;i++){
		ai=bi=i;
		if(tmp[i]==' '){
			do{
				if(ai==a)break;
			}while(isalpha(ai--));
			if(ai!=a)ai++;
			
		}
	}
}
int main()
{
	while(1){
	if(cin.eof())break;
	while(getline(cin,tmp)){
		if(tmp[0]=='#')break;
		cout<<tmp<<endl;
		int last=0;;
		for(int i=0;i<tmp.length();i++){
			if(tmp[i]=='.'||tmp[i]==','){
				solve(last,i);
				last=i+1;
			}
		}
		solve(last,tmp.length());
	}
	}
	return 0;
}
//03.cc
//generated automatically at Sat Sep 24 15:41:23 2016
//by xsthunder

