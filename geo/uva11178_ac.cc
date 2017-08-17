#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<complex>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
namespace geoFuc{
}
namespace scalarCplx{
	//complex,cmath,cstdio
	typedef complex<double > Point;
	typedef Point Vector;
	double Dot(Vector A,Vector B){return real(conj(A)*B);}
	double Cross(Vector A,Vector B){return imag(conj(A)*B);}
	Vector Rotate(Vector A,double rad){return A*exp(Point(0,rad));}
}
namespace scalarFuc{
	//dependencies Point Vector
	using namespace scalarCplx;
	Point read_point(){ double x,y; scanf("%lf%lf",&x,&y); return Point(x,y); }
	double Length(Vector A){return sqrt(Dot(A,A));}
	double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
	double get_x(Point A){return real(A);}
	double get_y(Point A){return imag(A);}
}
namespace lineFuc{
	//dependencies Point Vector
	using namespace scalarCplx;
	Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
		//make sure Cross(v,w)!=0
		Vector u = P-Q;
		double t = Cross(w,u)/Cross(v,w);
		return P+v*t;
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
using namespace lineFuc;
using namespace scalarFuc;
Point getD(Point A,Point B,Point C){
	Vector v=C-B;
	double a=Angle (A-B,v);
	v=Rotate(v,a/3);
	
	Vector w=A-C;
	double b=Angle(B-C,w);
	w=Rotate(w,b-b/3);
	return GetLineIntersection(B,v,C,w);
}
void inp(){
	Point A=read_point(),B=read_point(),C=read_point();
	Point D=getD(A,B,C),E=getD(B,C,A),F=getD(C,A,B);
	printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",get_x(D),get_y(D),get_x(E),get_y(E),get_x(F),get_y(F));
}
//scalarCplx.cc by xsthunder at Wed Aug 16 19:59:38 2017

//AC at Thu Aug 17 09:40:43 2017
 
