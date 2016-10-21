#include <cstdio>
#include <cstring>
using namespace std;
char ch[30];
double p[1000100];


int main()
{
	p[0]=0.0;  
    for(int i=1;i<=1000000;i++){  
        p[i]=p[i-1]+1.0/(1.0*i*1.0*i);  
    }  
	while(scanf("%s",ch)!=EOF){
		int len=strlen(ch);
		if(len>=7)printf("1.64493\n");
		else{
			int n=0;
			for(int i=0;i<len;i++)n=n*10+ch[i]-'0';
			printf("%.5lf\n",p[n]);
		}
	}
	return 0;
}

