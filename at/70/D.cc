const bool TEST=1;
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
#include<sstream>
#include<stack>
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
ostream&  operator << (ostream &out,const Point &a){ out<<'('<<a.first<<','<<a.second<<')'; return out; }
void inp();
int n,k;
const int N = 5e5+100;
int A[N];
bool B[N];
void sol(){
	inp();
	sort(A,A+n);
	int *begin=A;
	int *end=A+n;
	int *f =begin;
	int *b=f+1;
	int nN=0;
	LL sum = *f  ;
	//int *fb=0;
	IF cout<<"begin"<<begin<<endl<<"end"<<end<<endl<<"f"<<f<<endl<<"b"<<b<<endl;
	IF cout<<"---"<<endl;
	IF pA(A,3);
	while(b!=end+1){
		IF cout<<"f"<<f<<endl<<"b"<<b<<endl;
		IF cout<<"sum"<<sum<<endl;
		if(sum>k){
			IF cout<<"sum<k"<<sum<<endl;
			int *lb=upper_bound(f,b,sum-k);
			for(int i = lb-begin;i<n;i++){
				if(!B[i])nN+=B[i]=1;
			}
			if(f+1==end)break;
			sum-=*f;
			f++;
//			IF cout<<"end if sum"<<sum<<endl;
			IF cout<<"end if f"<<f<<endl<<"b"<<b<<endl;
		}
		else {
			if(b!=end){
				sum +=*b;
			}
			b++;
		}
		IF cout<<"end sum"<<sum<<endl;
	}
	printf("%d\n", n-nN);
}
void inp(){
	cin>>n>>k;
	for(int i = 0 ;i< n;i++){
		scanf("%d", A+i);
	}
}
int main()
{
	sol();
	return 0;
}
//D.cc
//generated automatically at Sat Mar 18 20:45:56 2017
//by xsthunder

