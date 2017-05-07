#include<iostream>
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
int a[100];
int used[100];
bool dfs(int n,int left){
	if(!left)return 1;
	if(n<0)return 0;
	for(int i = n;i>=0;i--){
		if(!used[i]&&a[i]<=left){
			used[i]=1;
			if(dfs(i-1,left-a[i])){
				return 1;
			}
			used[i]=0;
		}
	}
	return 0;
}
void inp(){
	int m = 0;
	int n;
	int sum =0;
	cin>>n;
	MS(a);
	if(!n)exit(0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		m=max(a[i],m);
		sum+=a[i];
	}
	sort(a,a+n);
	while(1){
		int flag=1;
		if(sum%m==0){
			MS(used);
			for(int i =n-1;i>=0;i--){
				if(!used[i]){
					used[i]=1;
					if(!dfs(i-1,m-a[i])){
						flag=0;
						break;
					}
				}
			}
			if(flag){
				cout<<m<<endl;
				return;
			}
		}
		m++;
	}
}
//A.cc by xsthunder at Sat May  6 11:55:38 2017

