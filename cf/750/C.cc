const bool test=1;
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
void sol(){
	int n;
	cin>>n;
	bool flag2=0;
	bool flag=1;
	int cur = 20000;
	while(n--){
		int c,d;
		cin>>c>>d;
		if(d==2){
			if(!flag2){
				flag2=1;
				cur =1899;
				cur+=c;
				IF cout<<cur<<' '<<flag<<' '<<flag2<<endl;
				continue;
			}
		}
		switch(d){
			case 1:
				if(cur>=1900){
					cur+=c;
				}
				else flag=0;
				break;
			case 2:
				if(cur<1900){
					cur+=c;
				}
				else {
					if(cur>=1900){
						cur=1899;
					}
					cur+=c;
				}
		}
		if(cur<0)flag=0;
		IF cout<<cur<<' '<<flag<<' '<<flag2<<endl;
	}
	if(!flag2)cout<<"Infinity";
	else if(!flag)cout<<"Impossible";
	else cout<<cur;
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//C.cc
//generated automatically at Tue Jan  3 16:51:20 2017
//by xsthunder

