#include<iostream>
#include<set>
#include<cstdio>
#include<map>
#define IF if(TEST)
const bool TEST=0;
typedef unsigned int  U ;
using namespace std;
const int K = 7;
const int MOD = 1e9+7;
const int B = 4;
long long a[2][K];
long long sqmod(int n){
	long long ans = 1;
	long long B = 4;
	while(n){
		if(n&1)ans=(B*ans)%MOD;
		B=(B*B);
		n>>1;
	}
	return ans;
}
void pA(long long * begin, int n ){
	while(n--){
		cout<<' '<<*(begin++);
	}
	cout<<endl;
}
int main(){
	int n , m ;
	scanf("%d%d", &n,&m);
	set<int > s[7];
	map<int ,int> numm;
	numm[1]=4;numm[4]=1;
	numm[2]=5;numm[5]=2;
	numm[3]=6;numm[6]=3;
	for(int i = 1; i <=6;i++){
		a[1][i]=4;
		for(int j = 1;j<= 6;j++){
			s[i].insert(j);
		}
	}
	for(int i = 0 ;i < m ;i ++){
		int a , b ;
		//IF cout<<i<<endl;
		scanf("%d%d",&a,&b);
		for(int c= 0 ; c < 2 ;c++){
			swap(a,b);
			if(s[a].count(b))s[a].erase(b);
		}
	}
	int cur=0;
	IF pA(a[0],K);
	for(int i = 2 ; i<= n ;i++){
		cur = i %2;
		for(int j = 1 ; j <= 6;j++){
			long long  &ans = a[cur][j];
			ans=0;
			long long  * pre = a[!cur];
			for(set<int >::iterator it= s[numm[j]].begin();it!=s[numm[j]].end();it++){
				int curk=*it;
				ans=(ans+pre[curk]*4)%MOD;
			}
		}
		IF {
			cout<<"cur:"<<cur<<endl;
			pA(a[cur],K);
			
		}
	}
	
	long long ans = 0 ;
	for(int j = 1; j< K ; j++){
		ans=(a[cur][j]+ans)%MOD;
	}
	cout<<ans<<endl;
}
