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
struct Player{
	int empty=0;
	int bulls=0,cows=0;
	void query(string s){
		cout<<s<<endl;
		fflush(stdout);
		cin>>bulls>>cows;
	}
	void getEmpty(){
		for(int i=0;i<10;i++){
			string s;
			for(int c=0;c<4;c++){
				s+=(i+'0');
			}
			query(s);
			if(cows==0&&bulls==0){
				empty=i;
				break;
			}
		}
	}
	void solve(){
		getEmpty();
		int cnt=0;
		int ans[4];
		//init ans
		for(int i=0;i<4;i++){
			ans[i]=empty;
		}
		while(cnt<4){
			//guess pos i , for 0 to 9
			for(int i=0;i<10;i++){
				ans[cnt]=i;
				string s;
				for(int i=0;i<4;i++){
					s+=(ans[i]+'0');
				}
				query(s);
				if(bulls==cnt+1){
					cnt++;
					break;
				}
			}
		}
	}
}player;
void sol(){
	player.solve();
}
int main()
{
	sol();
	return 0;
}
//B.cc
//generated automatically at Mon Jan  2 00:20:53 2017
//by xsthunder

//AC at Mon Jan  2 00:46:38 2017
 
