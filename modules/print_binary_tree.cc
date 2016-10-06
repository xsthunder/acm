#include<cstdio>
#include<iostream>
using namespace std;
template <typename T>
void pT(T *A, int d){//d for depth
	int sum=0;
	cout<<"------tree starts\n";
	for(int i=0;i<d;i++){
		cout<<i+1<<':';
		for(int j=0;j<1<<i;j++){
			cout<<*(A+sum++)<<' ';
		}
		cout<<endl;
	}
	cout<<"------tree ends\n";
}
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin+i)<<' '; } printf("\n"); }
int main(){
	int A[10]={1,2,3,4,5,6,7,8};
	pT(A,3);
}
