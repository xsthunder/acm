#include<utility>
#include<cstdio>

using namespace std;
int main(){
	float x[5],y[5];
	pair<float ,float > P[3][5];
	for(int i=1;i<=2;i++){
		scanf("%f%f",&x[i],&y[i]);
		P[1][i]=make_pair(x[i],y[i]);
	}
	for(int i=3;i<=4;i++){
		scanf("%f%f",&x[i],&y[i]);
		P[2][i]=make_pair(x[i],y[i]);
	}
	for(int i=1;i<=2;i++){
		P[i][3]=make_pair(P[i][1].first,P[i][2].second);
		P[i][4]=make_pair(P[i][2].first,P[i][1].second);
	}
	float area=0;;
	for(int i=1;i<=4;i++){
		for(int j=1;j<4;j++){
			auto p1=P[1][i];
			auto p2=P[2][j];
			area=
		}
	}
	return 0;
}
