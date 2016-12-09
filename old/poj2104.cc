#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int B=2;
const int MAXN=1e5+1000;
int A[MAXN];
int nums[MAXN];
int M,N;
const int MAXM=10000;
vector<int > buckets[B+100];
int I[MAXM],J[MAXM],K[MAXN];
void init(){
	for(int i=0;i<B+100;i++){
		buckets[i].clear();
	}
}
void solve(){
	init();
	for(int i=0;i<N;i++){
		buckets[i/B].push_back(A[i]);
	}
	for(int i=0;i<N/B;i++){
		sort(buckets[i].begin(),buckets[i].end());
	}
	for(int m=0;m<M;m++){
		int lb=-1,ub=N;
		int l=I[m]-1,r=J[m],k=K[m];
		if(r==l){
			printf("%d\n", A[r]);
			continue;
		}
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			int c=0;
			int tl=l,tr=r;
			int x=nums[mid];
			//printf("tl,tr,x %d %d %d \n",tl,tr,x);
			//outside the buckets
			for(;tl<tr&&tl%B!=0;)if(A[tl++]<=x) c++;
			//printf("tl c :%d \n",c);
			for(;tl<tr&&tr%B!=0;)if(A[--tr]<=x)c++;
			//printf("tr c :%d \n",c);

			while(tl<tr){
				c+=upper_bound(buckets[tl/B].begin(),buckets[tl/B].end(),x)-buckets[tl/B].begin();
				tl+=B;
			}
			//printf("buckets c :%d \n",c);
			if(c>=k)ub=mid;
			else lb=mid;
			//printf("%d %d %d : %d %d %d :%d c:%d\n",l,r,k,ub,lb,mid,nums[mid],c);
		}
		printf("%d\n",nums[ub]);
		//break;
	}
}
int main(){ 
	//printf("hello world");
	while(scanf("%d%d",&N,&M)!=	EOF){
		//printf("%d %d \n",N, M);
			for(int i=0;i<N;i++){
				scanf("%d",&A[i]);
			nums[i]=A[i];
		}
		sort(nums,nums+N);
		for(int i=0;i<M;i++){
			scanf("%d%d%d", &I[i],&J[i],&K[i]);
			
		}
		solve();
	}
	return 0;
}
