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
	vector<int > ans;
	int n;
	cin>>n;
	for(int i=1;;i++){
		ans.push_back(i);
		n-=i;
		if(n<=i){
			n+=ans.back();
			ans.pop_back();
			ans.push_back(n);
			break;
		}
	}
	cout<<ans.size()<<endl;
	for(int x: ans){
		cout<<x<<' ';
	}
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//A.cc
//generated automatically at Sun Jan  1 23:33:06 2017
//by xsthunder

//AC at Sun Jan  1 23:39:50 2017
 
