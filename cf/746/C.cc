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
int echo(int x){
	IF cout<<"int echo "<<x<<endl;
	return x;
}
void sol(){
	int s , x1,x2,t1,t2,p ,d;
	cin>>s>>x1>>x2>>t1>>t2>>p>>d;
	if(x1>x2){
		x1=s-x1;
		x2=s-x2;
		d=-d;
		p=s-p;
	}
	int ans =(x2-x1)*t2;
	IF cout<<"init ans : "<<ans<<endl;
	if(d>0){
		if(p<=x1)ans=min(ans,echo((x2-p)*t1));
		else {
			ans=min(ans,echo((s-p+s+x2)*t1));
		}
	}
	else {
		if(p<=x1)ans=min(ans,echo((p+s+s+x2)*t1));
		else ans=min(ans,echo((p+x2)*t1));
	}
	cout<<ans<<endl;
}
int main()
{
	//while(!cin.eof())
	sol();
	return 0;
}
//C.cc
//generated automatically at Sun Dec 18 19:35:09 2016
//by xsthunder

