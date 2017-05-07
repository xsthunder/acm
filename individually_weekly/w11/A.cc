#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
int flag=0;
int a[100];
int used[100];
int vis[70][60*80];
bool dfs(int n,int left,string s){
	if(flag)return 1;
	if(!left){
		cout<<1<<' '<<s<<endl;
		return 1;
	}
	if(n<0){
		cout<<0<<' '<<s<<endl;
		return 0;
	}
	for(int i = n;i>=0;i--){
		if(!used[i]&&a[i]<=left){
			stringstream ss;
			used[i]=1;
			if(dfs(i-1,left-a[i],ss.str())){
			}
			used[i]=0;
		}
	}
//	iF cout<<0<<' '<<s<<endl;;
	return 0;
}
void inp(){
	int m = 0;
	int n;
	int sum =0;
	cin>>n;
	MS(a);
	if(!n)exit(0);
	flag=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m=max(a[i],m);
		sum+=a[i];
	}
	sort(a,a+n);
	cout<<sum<<endl;
	while(1){
		if(sum%m==0){
			MS(used);
			iF m=114;
			for(int i =n-1;i>=0;i--){
				if(!used[i]){
					used[i]=1;
					stringstream ss;
					ss<<a[i];
					if(!dfs(i-1,m-a[i],ss.str())){
						break;
					}
					else {
						pA(a,16,3);
						pA(used,n,3);
					}
				}
			}
		}
		if(flag){
			cout<<m<<endl;
			return ;
		}
		m++;
	}
}
//A.cc by xsthunder at Sat May  6 11:55:38 2017

