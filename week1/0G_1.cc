#include<cstdio>
#include<cstring>
using namespace std;
char s[100];
const int N=1e6+100;
double p[N];
void pre(){
	for(long long int i=1;i<N;i++){
		p[i]=p[i-1]+double (1)/(double (i)*double(i));
	}
}
int main(){
	pre();
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		if(len>=7){
			printf("1.64493\n");
			continue;}
		int n=0;
		for(int i=0;i<len;i++){
			n*=10;
			n+=s[i]-'0';
		}
		printf("%.5lf\n",p[n]);
	}
	return 0;
}
