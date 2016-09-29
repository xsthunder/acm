#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<utility>

using namespace std;
struct red
{
	int x;
	int y;
	char type;
}r[10],b[5],h[5];
int borad[12][12]={0};
int blackborad[5][5]={0,0,0,0,0,
	0,1,1,1,0,
	0,1,1,1,0,
	0,1,1,1,0,
	0,0,0,0,0,};
void tryblack(const int b1,const int b2)
{
	b[0].type=1;
	b[0].x=b1;
	b[0].y=b2;
	b[1].x=b1-1;b[1].y=b2;if(blackborad[b[1].x,b[1].y])b[1].type=1;
	b[2].x=b1;b[2].y=b2-1;if(blackborad[b[2].x,b[2].y])b[2].type=1;
	b[3].x=b1+1;b[3].y=b2;if(blackborad[b[3].x,b[3].y])b[3].type=1;
	b[4].x=b1;b[4].y=b2+1;if(blackborad[b[4].x,b[4].y])b[4].type=1;
}
void tryhorse(const int b1,const int b2)
{
	h[0].type=1;
	h[0].x=b1;
	h[0].y=b2;
	h[1].x=b1-1;h[1].y=b2;if(borad[h[1].x,h[1].y])h[1].type=1;
	h[2].x=b1;h[2].y=b2-1;if(borad[h[2].x,h[2].y])h[2].type=1;
	h[3].x=b1+1;h[3].y=b2;if(borad[h[3].x,h[3].y])h[3].type=1;
	h[4].x=b1;h[4].y=b2+1;if(borad[h[4].x,h[4].y])h[4].type=1;
}//1表示翘马脚kk

bool trylive(int i,int x,int y)
{
	int rx=r[i].x,ry=r[i].y;
	int flag=0;
	switch(r[i].type)
	{
	case 'G':
		if(rx==x)
		{
			for(int j=y;j<ry;j++)
			{
				if(borad[x][j]==1){flag=1;break;}
			}
			if(flag==0)return 0;//无阻挡
		}
		break;
	case 'R':
		if(rx==x&&ry==y)break;//被吃
		if(rx==x)
		{
			if(y>ry)swap(y,ry);
		}
		if(ry==y)
		{
			ry=max(rx,x);
			y=min(rx,x);
		}
		for(int j=y;j<ry;j++)
		{
			if(borad[x][j]==1){flag=1;break;}
		}
		if(flag==0)return 0;//无阻挡
		break;
	case 'C':
		if(rx==x&&ry==y)break;//被吃
		if(rx==x)
		{
			if(y>ry)swap(y,ry);
		}
		if(ry==y)
		{
			ry=max(rx,x);
			y=min(rx,x);
		}
		for(int j=y;j<ry;j++)
		{
			if(borad[x][j]==1)flag++;
		}
		if(flag==1)return 0;//炮台一个

		break;
	case 'H':
		tryhorse(rx,ry);
		for(int i=1;i<=4&&h[i].type!=1;i++)
		{
			int xdistance=h[i].x-rx;
			int ydistance=h[i].y-ry;
			if(xdistance==0&&ydistance>0)	
			{
				ry=ry+2;
				if(ry==y)
				{
					if(x==rx+1||x==rx-1)return 0;
				}
			}
			if(xdistance==0&&ydistance<0)	
			{
				ry=ry-2;
				if(ry==y)
				{
					if(x==rx+1||x==rx-1)return 0;
				}

			}
			if(ydistance==0&&xdistance<0)	
			{
				rx=rx-2;
				if(rx==x)
				{
					if(y==ry+1||y==ry-1)return 0;
				}
			}
			if(ydistance==0&&xdistance>0)	
			{
				rx=rx+2;
				if(rx==x)
				{
					if(y==ry+1||y==ry-1)return 0;
				}
			}
		}


	}
	return 1;
}

bool solve(int n)
{	
	for(int i=1;i<5&&b[i].type;i++)
 	{
		int x=b[i].x,y=b[i].y;
		for(int j=0;i<n;j++)
		{
			if(trylive(i,x,y))return 0;
		}
 	}
	return true;
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif

	int n,b1,b2;
	while(scanf("%d%d%d", &n,&b1,&b2)==3&&n!=0&&b1!=0&&b2!=0)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%c%d%d", &r[i].type,&r[i].x,&r[i].y);
			borad[r[i].x][r[i].y]=1;
		}
		tryblack(b1,b2);
		printf("%s\n",solve(n)?"YES":"NO");
	}

	return 0;
}
