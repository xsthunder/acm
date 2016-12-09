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
	int t;
	scanf("%d",&t);
	string maxs="00:00:00";
	string mins="99:99:99";
	string maxid;
	string minid;
	while(t--){
		string id,in,out;
		cin>>id>>in>>out;
		if(in<mins){
//			cout<<"update minid :"<<id<<"for "<<in<<"<"<<mins<<endl;
			minid=id;
			mins=in;
		}
		if(out>maxs){
			maxid=id;
//			cout<<"update maxid :"<<id<<"for "<<out<<">"<<maxs<<endl;
			maxs=out;
		}
	}
	cout<<minid<<' '<<maxid<<endl;
}
int main()
{
	sol();
	return 0;
}
//a1006.cc
//generated automatically at Sun Nov 27 22:14:13 2016
//by xsthunder

//AC at Sun Nov 27 22:22:48 2016
 
