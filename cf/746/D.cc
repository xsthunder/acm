const bool test=0;
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
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
const int N=1e5+1000;
char s[N];
char A,B;
void check(int &a,int &b){
	if(a<b){
		swap(a,b);
		swap(A,B);
	}
}
void sol(){
	A='G',B='B';
	int n,k,a,b;
	cin>>n>>k>>a>>b;
	int cur=0;
	bool flag=1;
	while(1){
	check(a,b);
		if(b==0&&a>k){
			flag=0;
			break;
		}
		else if(b==0&&a<=k){
			for(;cur<n;){
				s[cur++]=A;
			}
			break;
		}
		if(a==0&&b==0)break;
		
		int r=a-b;
		IF cout<<a<<' '<<b<<' '<<k<<' '<<r<<endl;
		if(r>0&&r<=k){
			for(int i=0;i<r;i++){
				s[cur++]=A;
			}
			s[cur++]=B;
			a-=r;
			b--;
		}
		else if(r>k){
			for(int i=0;i<k;i++){
				s[cur++]=A;
			}
			s[cur++]=B;
			a-=k;
			b--;
		}
		if(b==0&&a<=k){
			for(;cur<n;){
				s[cur++]=A;
			}
			a=b=0;
			break;
		}
		if(r==0){
			for(;cur<n;){
				s[cur++]=A;
				s[cur++]=B;
			}
			a=b=0;
			break;
		}
	}
	if(flag){
		s[n]='\0';
		printf("%s\n",s);
	}
	else printf("NO\n");
}
int main()
{
	IF while(!cin.eof()){
		sol();
	}
	sol();
	return 0;
}
//D.cc
//generated automatically at Sun Dec 18 20:15:52 2016
//by xsthunder

