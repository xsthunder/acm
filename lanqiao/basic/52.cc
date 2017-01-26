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
	vector<int  >  vi;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		vi.push_back(a);
	}
	sort(vi.begin(),vi.end());
	for(unsigned int i =0 ; i < vi.size();i++){
		cout<<vi[i]<<' ';
	}
}
int main()
{
	sol();
	return 0;
}
//52.cc
//generated automatically at Sun Jan 15 22:43:10 2017
//by xsthunder

