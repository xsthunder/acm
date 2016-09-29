#include<cstdio>
#include<algorithm>
using namespace std;
const  int N=1e5;
int A[N];
void print_permutation(int n,int *A,int cur){
//generate permutation using number ranged from 1 to n inclusively;
	if(n==cur){
		for(int i=0;i<n;i++){
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	else {
		for(int i=1;i<=n;i++){
			int ok=1;
			for(int j=0;j<cur;j++){
				if(A[j]==i){ok=0;
					break;
				}
			}
			if(ok){
				A[cur]=i;
				print_permutation(n,A,cur+1);

			}
		}
	}
}
void print_permutation_2(int *P,int n,int *A,int cur){
//generate permutation using number ranged from 1 to n inclusively;
	if(n==cur){
		for(int i=0;i<n;i++){
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	else {
		for(int i=0;i<n;i++)if(i==0||P[i]!=P[i-1]){
			int c1=0,c2=0;
			for(int j=0;j<cur;j++)if(P[i]==A[j])c1++;
			for(int j=0;j<n;j++)if(P[i]==P[j])c2++;
			if(c1<c2){
				A[cur]=P[i];
				print_permutation_2(P,n,A,cur+1);
			}
		}
	}
}
int main(){
	int n=2;
	int P[]={1,2};
	sort(P,P+n);//lexigraphical order
	print_permutation_2(P,n,A,0);
	//print_permutation(n,A,0);
}
