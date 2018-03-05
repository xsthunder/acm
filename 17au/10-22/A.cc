#include<cstdio>
#include<cctype>
#include<list>
#include<map>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	freopen("A.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 2e4+100;
char ss[N][2][200];
char s[2][200];
list<int>l[N];
list<int>::iterator it  ;
map<string ,int> amp;
map<string ,int> bmp;
int lcnt=0;
const char bmail[20] = "bmail.com";
char tmp[200];
void inp(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",ss[i][0]);
		int p = (strchr(ss[i][0],(int)'@') - ss[i][0]);
		ss[i][0][p]='\0';
		strcpy(ss[i][1],ss[i][0]+p+1);
//		printf("%d ss %s %s\n",i,ss[i][0],ss[i][1]);
		for(int c = 0,j;c<2;c++){
			for(j = 0;ss[i][c][j]!='\0';j++){
				s[c][j] = tolower(ss[i][c][j]);
			}
			s[c][j]='\0';
		}
//		printf("%d s %s %s\n",i,s[0],s[1]);
		if(!strcmp(bmail,s[1])){
			int j,cnt;
			for(j =cnt= 0;s[0][j]!='+'&&s[0][j]!='@'&&s[0][j];j++){
				if(s[0][j]=='.')continue;
				tmp[cnt++]=s[0][j];
			}
			tmp[cnt++] = '\0';
			string str(tmp);
			if(bmp.count(str)){ l[bmp[str]].push_back(i); }
			else {
				bmp[str] = lcnt;
				l[lcnt].push_back(i);
				lcnt++;
			}
//			printf("%d s %s \n",i,tmp);
		}
		else {
			string str(s[0]);
			str.append("@");
			str.append(s[1]);
			if(amp.count(str)){ l[amp[str]].push_back(i); }
			else {
				amp[str]=lcnt;
				l[lcnt].push_back(i);
				lcnt++;
			}
		}
	}
	printf("%d\n",lcnt);
	for(int i=0;i<lcnt;i++){
		printf("%d ",(int)l[i].size());
		for(it = l[i].begin();it!=l[i].end();it++){
			printf("%s@%s",ss[*it][0],ss[*it][1]);
			putchar(' ');
		}
		putchar('\n');
	}
}
//A.cc by xsthunder at Sun Oct 22 12:27:41 2017

