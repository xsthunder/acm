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
const int inf=1e8;
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
	int miN=0;
	int maX=inf;
	bool flag=0;
	bool flag2=0;
	while(n--){
		int c, d;
		cin>>c>>d;
		if(d==2)flag=1;
		switch(d){
			case 1 :
				miN=max(miN,1900);
				break;
			case 2: 
				maX=min(1899,maX);
				break;
		}
		miN+=c;
		maX+=c;
		miN=max(miN,0);
		if(maX<0)flag2=1;
	}
	if(!flag)cout<<"Infinity";
	else if(flag2||miN>maX)cout<<"Impossible";
	else cout<<maX;
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//A2.cc
//generated automatically at Tue Jan  3 20:50:34 2017
//by xsthunder

