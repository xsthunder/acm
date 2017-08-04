#include<cstdio>
#include<cstring>

#include<algorithm>
#include<complex>
using namespace std;
typedef complex<double> cplx;

const int N  =50000 + 1000; 
const double pi = acos(-1.0);
char s1[2*N], s2[2*N];
cplx x1[4*N], x2[4*N];
int sum[4*N];
void change(cplx y[],int len){
	int i,j,k;
	for( i = 1,j = len/2;i<len-1;i++){
		if(i < j)swap(y[i],y[j]);
		k = len/2;
		while(j>=k){
			j -=k;
			k /=2;
		}
		if(j<k)j+=k;//is j
	}
}
void fft(cplx y[], int len,int on){
	int h,j,k,i;
	change(y,len);
	for(h=2;h<=len;h<<=1){
		cplx wn(cos(-on*2*pi/h),sin(-on*2*pi/h));
		for(j = 0;j<len;j+=h){
			cplx w(1,0);
			for(k = j;k<j+h/2;k++){
				cplx u = y[k];
				cplx t = w*y[k+h/2];
				y[k] = u+t;
				y[k+h/2] = u-t;
				w = w*wn;
			}
		}
	}
	if(on == -1)for(i = 0;i<len;i++)y[i].real(y[i].real()/len);
}
int main(){
#ifdef XS
	freopen("hdu1402.in","r",stdin);
#endif
#define de(x) (x)-'0'
#define en(x) (x)+'0'
#define MS(x) memset(x,0,sizeof(x))
	int len1,len2,len,i;
	while(scanf("%s%s",s1,s2)!=EOF){
		len1 = strlen(s1),len2 = strlen(s2);
		MS(x1);MS(x2);MS(sum);
		len = 1;while(len<len1*2||len<len2*2)len<<=1;
		for( i = 0;i<len1;i++)x1[i] = cplx(de(s1[len1-i-1]),0);
		for( i = 0;i<len2;i++)x2[i] = cplx(de(s2[len2-i-1]),0);
		fft(x1,len,1),fft(x2,len,1);
		for(i = 0;i<len;i++)x1[i] = x1[i]*x2[i];
		fft(x1,len,-1);
		for(i = 0;i<len;i++)sum[i] = (int)(x1[i].real()+0.5);
		for(i = 0;i<len;i++){
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
		}
		len = len1+len2-1;
		while(sum[len]<=0&&len>0)len--;
		for(i = len;i>=0;i--)printf("%c",en(sum[i]));
		printf("\n");
	}
	return 0;
}

//AC at Wed Aug  2 16:10:58 2017
 
//AC at Wed Aug  2 16:11:53 2017
 
