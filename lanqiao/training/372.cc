const bool TEST=1;
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
#include<sstream>
#include<stack>
#include<complex>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
void sol(){

}
int main()
{
	double a1,b1,a2,b2;
	char x;
	cin>>x;
	cin>>a1>>b1>>a2>>b2;
	complex<double> c,a(a1,b1),b(a2,b2);
	switch(x){
		case'+':c=a+b;break;
		case'-':c=a-b;break;
		case'*':c=a*b;break;
		case'/':c=a/b;break;
	}
	printf("%.2lf+%.2lfi",c.real(),c.imag());
	return 0;
}
//372.cc
//generated automatically at Fri Feb 10 21:04:58 2017
//by xsthunder

