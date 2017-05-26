const bool longtest=1;
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
#define IF if(longtest)
#define FI if(!longtest)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
vector<point> vp;
map<int ,int > mii;
bool ask= 0;
bool got(int x){
	if(!mii.count(x))return 0;
	if(mii[x]==0)return 0;
	return 1;
}
bool test(int x){
	if(ask==0){
		if(x%2==0)return 1;
		else return 0;
	}
	else {
		if(x%2==1)return 1;
		else return 0;
	}
}
bool cmp(point a,point b){
	if(a.second<b.second)return 1;
	else if(a.second==b.second){
		if(a.first<b.first)return 1;
	}
	return 0;
}
void sol(){
	int n,m;
	cin>>n>>m;
	int odd,even;
	odd=even=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		vp.push_back(make_pair(x,i));
		mii[x]=1;
		if(x%2)odd++;
		else even++;
	}
	int r;
	if(odd==even){
		bool flag=0;
		for(point x:vp){
			if(flag)cout<<' ';
			flag=1;
			cout<<x.first;
		}
		cout<<endl;
		return ;
	}
	else if(odd>even){
		ask=1;
	}
	else {
		ask=0;
	}
	r=abs(odd-even);
	sort(vp.begin(),vp.end());
	int cur=0;
	int curm=0;
	while(r--){
		while(cur<n&&!test(vp[cur].first))cur++;
		if(cur==n)break;
		while(curm<=m&&test(curm)&&!got(curm)){
			curm++;
		}
		if(curm>m)break;
		mii[vp[cur].first]=0;
		mii[curm]=1;
		vp[cur].first=curm;
	}
	if(r)cout<<"-1\n";
	else {
		sort(vp.begin(),vp.end(),cmp);
		printf("%d\n",abs(odd-even)); 
		bool flag=0;
		for(point x:vp){
			if(flag)printf(" ");
			flag=1;
			printf("%d",x.first);
		}
		printf("\n");
	}

}
int main()
{
	IF while(!cin.eof()){
		sol();
	}
	sol();
	return 0;
}
//E.cc
//generated automatically at Sun Dec 18 21:01:01 2016
//by xsthunder

