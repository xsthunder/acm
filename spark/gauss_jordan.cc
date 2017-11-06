#include<cstdio>
#include<vector>
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
	while(1)inp();
	return 0;
}
static const double eps = 1.0e-8;
struct gauss_jordan{
	// cmath::fabs algorithm::swap
	static const int N = 200;
	typedef double M[N][N];
	M A;//param
	int n;//param dimension [n][n+1]
	//若x[i]解唯一且有限,除A[i][i],A[i][n]外,都为0
	void show(){
		int i ,j;
		for(i = 0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%5.2f",A[i][j]);
			}
			printf("|%5.f\n",A[i][n]);
		}
	}
	void run(){
		int i,j,k,r;
		for(i = 0;i<n;i++){
			r = i;
			for(j =i+1;j<n;j++)
				if(fabs(A[r][i]<fabs(A[j][i])))r = j;
			if(fabs(A[r][i])<eps)continue;//放弃这一行
			if(i!=r)for(j = 0;j<=n;j++)swap(A[i][j],A[r][j]);

			//与除了第i行外进行消元
			for(k = 0;k<n;k++){if(k!=i)
				for(j = n;j>=i;j--){
					A[k][j] -= A[k][i]/A[i][i]*A[i][j];
				}
			}
		}
	}
};
const int V  = 200;
vector<int > v[V];
vector<int >::iterator it;
int inf[V];
int ttt = 0;
void inp(){
	int n;scanf("%d",&n);if(!n)exit(0);
	gauss_jordan G;
	G.n = n;
	for(int i =0 ;i<n;i++){
		v[i].clear();v[i].reserve(100);
		for(int j = 0;j<=n;j++){
			G.A[i][j]=0;
		}
		G.A[i][i] =1.0;
	}
	int a,b;
	while(scanf("%d%d",&a,&b)&&a&&b){
		a--,b--,v[a].push_back(b);
	}
	
	G.A[0][n]=1.0;
	for(int i = 0;i<n;i++){
		for(it = v[i].begin();it!=v[i].end();it++){
			G.A[*it][i]-=1.0/v[i].size();
		}
		//printf("->%d %u\n",i,(U)v[i].size());
		//G.show();
	}
	G.run();
//	G.show();
	MS(inf,0);
	for(int i = n-1;i>=0;i--){
		if(fabs(G.A[i][i])<eps){
			if(fabs(G.A[i][n])<eps){
				continue;
			}
			inf[i] = 1;
			continue;
		}
		for(int j = 0;j<n;j++){
			if(i!=j&&fabs(G.A[i][j])>eps&&inf[j]){
				inf[i] = 1;
				break;
			}
		}
		G.A[i][n] /=G.A[i][i];
	}
//	G.show();
	scanf("%d",&b);
	printf("Case #%d:\n",++ttt);
	while(b--){
		scanf("%d",&a);
		a--;
		if(inf[a])printf("infinity\n");
		else printf("%.3f\n",G.A[a][n]);
	}
}
//gauss_jordan.cc by xsthunder at Wed Nov  1 09:17:59 2017
//UVA    10828 Back to Kernighan-Ritchie

