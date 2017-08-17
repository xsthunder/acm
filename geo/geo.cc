#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<complex>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
namespace EPS{
	const double eps=1e-10;
	bool dcmp(double x){ if(fabs(x)<eps)return 0;else return x<0?-1:1; }
}
namespace ScalarBaseCplx{
	//complex,cmath,cstdio
	typedef complex<double > Point;
	typedef Point Vector;
	double Dot(Vector A,Vector B){return real(conj(A)*B);}
	double Cross(Vector A,Vector B){return imag(conj(A)*B);}
	Vector Rotate(Vector A,double rad){return A*exp(Point(0,rad));}
}
namespace Scalar{
	//dependencies Point Vector
	using namespace ScalarBaseCplx;
	Point read_point(){ double x,y; scanf("%lf%lf",&x,&y); return Point(x,y); }
	double Length(Vector A){return sqrt(Dot(A,A));}
	double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
	double get_x(Point A){return real(A);}
	double get_y(Point A){return imag(A);}
}
namespace Line{
	//dependencies Point Vector EPS cmath
	using namespace ScalarBaseCplx;
	using namespace Scalar;
	using namespace EPS;
	Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
		//make sure Cross(v,w)!=0
		Vector u = P-Q;
		double t = Cross(w,u)/Cross(v,w);
		return P+v*t;
	}
	double DistanceToLine(Point P,Point A,Point B){
		Vector v1=B-A,v2=P-A; return fabs(Cross(v1,v2))/Length(v1);
	}
	double DistanceToSegment(Point P,Point A,Point B){
		if(A==B)return Length(P-A);
		Vector v1=B-A,v2=P-A,v3=P-B;
		if(dcmp(Dot(v1,v2))<0)return Length(v2);
		else if(dcmp(Dot(v1,v3)>0))return Length(v3);
		else return fabs(Cross(v1,v2))/Length(v1);
	}
	bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
		double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
					 c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
		return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
	}
	bool OnSegment(Point p,Point a1,Point a2){
		return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
	}
}
namespace Polygon{
	//dependencies Point Vector
	using namespace ScalarBaseCplx;
	double PolygonArea(Point *p,int n){
		double area=0;
		for(int i = 1;i<n-1;i++){
			area+=Cross(p[i]-p[0],p[i+1]-p[0]);
		}
		return area/2;
	}
}
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
void inp(){
}
//geo.cc by xsthunder at Wed Aug 16 19:59:38 2017

 
