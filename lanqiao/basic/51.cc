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
	string s , s2;
	char s3[100];
	int n;
	scanf("%d", &n);
	while(n--){
		cin>>s;
		while(s.length()%3!=0){
			s="0"+s;
		}
		for(unsigned int i = 0 ; i< s.length();i+=3){
			int x;
			sscanf(s.substr(i,3 ).c_str(), "%x", &x);
			sprintf(s3, "%o",x);
			s2=s3;
			if(i!=0)while(s2.size()!=4)s2="0"+s2;
			cout<<s2;
		}
		printf("\n");
	}
}
int main()
{
	sol();
	return 0;
}
//51.cc
//generated automatically at Tue Jan 17 10:19:25 2017
//by xsthunder

