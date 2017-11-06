#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
struct gauss_elimation{
	// cmath::fabs,algorithm::swap
	static const int N = 7;
	typedef double M[N][N];
	int n;//param dimension
	M A={//param matrix
		{1,0,0,1},
		{0,1,-1,0},
		{0,1,-1,0},
		{0}
	};
	void show(){
		int i,j;
		for(i = 0;i<n;i++){
			for(j = 0;j<n;j++){
				printf("%5.2f ",A[i][j]);
			}
			printf("|%5.2f\n",A[i][j]);
		}
	}
	void run(){
		int i,j,k,r;
		for(i = 0;i < n;i++){
			//选一行r与第i行交换
			r = i;
			for(j = i+1;j<n;j++){
				if(fabs(A[r][i])<A[j][i])r = j;
			}
			if(r!=i){
				for(j=0;j<=n;j++)swap(A[i][j],A[r][j]);
			}

			//与第i+1~n行进行消元,逆向提高精度
			for(k = i+1;k<n;k++){
				for(j = n;j>=i;j--){
					A[k][j] -= A[k][i]/A[i][i]*A[i][j];
				}
			}
		}
		show();
		//回代消元,答案在A[i][n],i=0:n-1
		for(i = n-1;i>=0;i--){
			for(j = i+1;j<n;j++){
				A[i][n] -= A[j][n]*A[i][j];
			}
			A[i][n] /= A[i][i];
		}
	}
}g;
void inp(){
	g.n=3;
	g.run();
	g.show();

}
//gauss_elimination.cc by xsthunder at Wed Nov  1 08:42:28 2017

