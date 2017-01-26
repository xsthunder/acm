const bool TEST=0;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
const char cho[4]={
	'R','B','Y','G'
};
vector<U> fAns;
bool flag=0;
bool check(string s,vector<U> ans){
	if(flag)return 0;
	IF cout<<s<<endl;;
	for(int c = 0 ; c < 4;c++){
		int pre=-4;
		for(U i = 0; i< s.size();i++){
			if(s[i]=='!'){
				if(c==3)return 1;
				else continue;
			}
			if(s[i]==cho[c]){
				if(i-pre>=4){
					pre=i;
				}
				else return false;
			}
		}
	}
	fAns=ans;
	flag=1;
	return 0;
}
int cor(char x  ){
	switch(x){
		case 'R':return 0;
		case'B':return 1;
		case'Y':return 2;
		case'G':return 3;
	}
	return 30;
}
void count(string s,vector<U>ans){
	IF cout<<"int count"<<s<<endl;
	int sum = 0; 
	for(U i =0 ;i< 4;i++){
		sum+=cor(s[i]);
	}
	if(sum!=6)return ;
	for(U i = 4;i<s.size();i++){
		if(s[i]=='!'){
			ans[cor(s[i-4])]++;
		}
	}
	fAns=ans;
}
void dfs(U st,U curTol,const string s,vector<U> ans){
		bool val=0;
		val=check(s,ans);
		if(!val) return ;
		if(st==4){
			count(s,ans);
		}
		IF cout<<val<<endl;
		for(U  i = st;i < 4;i++){
			if(s[i]=='!'){
				for(int c=0;c<4;c++){
					string s2= s;
					s2[i]=cho[c];
					ans[c]++;
					dfs(i+1,curTol+1,s2,ans);
					ans[c]--;
				}
				return ;
			}
		}
		count(s,ans);
}
void sol(){
	string s ;
	cin>>s;
	for(int i =0 ;i< 4;i++){
		fAns.push_back(0);
	}
	dfs(0,0,s,fAns);
	for(int i =0 ;i<4;i++){
		if(0!=i)cout<<' ';
		cout<<fAns[i];
	}
	cout<<endl;
}
void sol2(){
	string s ;
	cin>>s;
	for(int i =0 ;i< 4;i++){
		fAns.push_back(0);
	}
	for(int c= 0 ;c< 4;c++){
		char x = cho[c];
		U pos= s.find_first_of(x);
		pos%=4;
		for(U i =pos ;i< s.size();i+=4){
			if('!'==s[i])fAns[cor(x)]++;
		}
	}
	for(int i =0 ;i<4;i++){
		if(0!=i)cout<<' ';
		cout<<fAns[i];
	}
	cout<<endl;
}
int main()
{
	sol2();
	return 0;
}
//B.cc
//generated automatically at Thu Jan 19 23:25:46 2017
//by xsthunder

