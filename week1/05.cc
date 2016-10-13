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
const int inf=1e9+10000;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
const int N=1e5;
set<int >s ;
int cnt=0;
void gen(){
	ll tmp;
	ll at,bt,ct,dt;
	for(int a=0;a<=30;a++){
		tmp=1;
		at=pow(2,a);
		if(tmp>=inf)break;
		for(int b=0;b<=19;b++){
			bt=pow(3,b);
			tmp=at*bt;
			if(tmp>=inf)break;
			for(int c=0;c<=13;c++){
				ct=pow(5,c);
				tmp=at*bt*ct;
				if(tmp>=inf)break;
				//cout<<c<<' '<<pow(5,c)<<endl;
				//IF cout<<a<<' '<<b<<' '<<c<<' '<<' '<<tmp<<endl;
				for(int d=0;d<=11;d++){
					dt=pow(7,d);
					tmp=at*bt*ct*dt;
					if(tmp>=inf)break;
					s.insert(tmp);
				}
			}
		}
	}
	//IF {for(int x:s)cout<<x<<' ';
	//	cout<<endl<<s.size();
	//	cout<<endl<<inf-*s.rbegin();
	//}

}
void sol(){
	gen();
	int t;
	int q;
	while(scanf("%d",&q)!=EOF){
		while(q--){
			scanf("%d",&t);
			//cout<<t<<' ';
			printf("%d\n",*s.lower_bound(t));
		}
	}
}
int main()
{
	sol();
	return 0;
}
//05.cc
//generated automatically at Wed Oct 12 20:29:10 2016
//by xsthunder

//AC at Wed Oct 12 21:28:38 2016
 
