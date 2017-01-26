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
const int inf=1<<30;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
void sol(){
	int from  = - inf;
	 int to = inf ;
	 int pref =  0  ;
	int n; 
	bool flag=1;
	 cin >>  n;  
	 while(n--){
		 int c, d ; 
		 cin>>c>>d;
		 if( d==1  ){
			 from  =   max (  1900-pref, from );
		 }
		 else {
			 to = min( 1899-pref , to  );
		 }
		 pref += c;  
		 if (to + pref <  0  )flag=0 ;
	 }
	 flag=1;
	 if (to >= inf  ) cout << "Infinity";
	 else if (!flag||to < from) cout<<  "Impossible";
	 else cout<<to  + pref;
	 cout << endl ;
}
int main()
{
	sol();
	return 0;
}
//C3.cc
//generated automatically at Wed Jan  4 15:11:32 2017
//by xsthunder

//AC at Wed Jan  4 15:21:34 2017
 
