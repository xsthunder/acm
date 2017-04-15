#include<cstdio>
#include<algorithm>
using namespace std;
const int Min=1<<31;
void sol();
int dea(int i);
int A[33];
int n,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		sol();
	}
	return 0;
}
int dea(int val){
	int res=1;
	int cnt =0 ;
	for(int i =0;i<n;i++){
		if(val&1){
			res*=A[i];
			cnt++;
		}
		val>>=1;
	}
	if(cnt==m)return res;
	else return Min;;
}
void sol(){
	for(int i =0;i<33;i++){
		A[i]=1;
	}
	scanf("%d%d", &n,&m);
	for(int i =0;i< n;i++){
		scanf("%d" ,&A[i]);
	}
	int _max=Min;
//	printf("1<<m:%d\n", Min);
	for(int i = 0 ;i<1<<n;i++){
		//printf("%d,%d \n",i,dea(i));
		_max=(max(_max,dea(i)));
	}
	printf("%d\n", _max);
}

