const double eps=1e-10;
const double Pi=acos(-1.);
int dcmp(const double &x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
typedef struct Poi Vec;
struct Poi
{
	double x,y;
	Poi(const double &a=0,const double &b=0):x(a),y(b) { }
	Poi operator+(const Poi &P)const { return Poi(x+P.x,y+P.y); }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	Poi operator*(const double &P)const { return Poi(x*P,y*P); }
	Poi operator/(const double &P)const { return Poi(x/P,y/P); }
	bool operator<(const Poi &P)const { return !dcmp(x-P.x)?dcmp(y-P.y)<=0:dcmp(x-P.x)<=0; }
};
struct Line
{
	Poi Ps; Vec Dir;
	double ang;
	Line(const Poi &ps=Poi(),const Vec &dir=Vec()):Ps(ps),Dir(dir)
	{ ang=atan2(Dir.y,Dir.x); }
	bool operator<(const Line &L1)const { return ang<L1.ang; }
};
struct Circle
{
	Poi Pc;
	double r;
	Circle(const Poi &P=Poi(),const double &R=0):Pc(P),r(R) { }
	Poi loc(double ang,double offset) { return Poi(Pc.x+cos(ang)*(r+offset),Pc.y+sin(ang)*(r+offset)); }
};
double dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
double cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
double lEnth(const Vec V) { return sqrt(dOt(V,V)); }
Vec rOtate(const Vec &V,const double &P)
{ double cOs=cos(P),sIn=sin(P); return Vec(V.x*cOs-V.y*sIn,V.x*sIn+V.y*cOs); }
double aNgle(const Vec &V1,const Vec &V2) { return acos(dOt(V1,V2)/lEnth(V1)/lEnth(V2)); }
Poi iNtersect(const Poi &P1,const Vec &V1,const Poi &P2,const Vec &V2)
{ return P1+V1*(cRoss(V2,P1-P2)/cRoss(V1,V2)); }
Poi iNtersect(const Line &L1,const Line &L2)
{ return iNtersect(L1.Ps,L1.Dir,L2.Ps,L2.Dir); }
int HPI(Line *L,int N,Poi *Pol)
{
	int l,r,m;
	Poi IP[N+50]; Line q[N+50];
	sort(L,L+N);//按极角排序
	q[l=r=0]=L[0];
	for(int i=1;i<N;i++)
	{
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[r-1]-L[i].Ps))<=0) r--; //新加入的直线可能是尾部的一些交点失效
		while(l<r&&dcmp(cRoss(L[i].Dir,IP[l]-L[i].Ps))<=0) l++; //首部
		q[++r]=L[i]; //加入
		if(!dcmp(cRoss(q[r].Dir,q[r-1].Dir)))
		{ //对于平行直线要取靠左的
			r--;
			if(dcmp(cRoss(q[r+1].Dir,q[r].Ps-q[r+1].Ps))<0) q[r]=q[r+1];
		}
		if(l<r) IP[r-1]=iNtersect(q[r-1],q[r]); //如果队列中有至少两条线，则取交点
	}
	while(l<r&&dcmp(cRoss(q[l].Dir,IP[r-1]-q[l].Ps))<=0) r--; //后面一些交点可能实际上是无用的
	if(r-l<2) return 0; //如果只有不到两条线，则失败了
	IP[r]=iNtersect(q[l],q[r]); //将最后一条线和第一条线交起来
	for(int i=l;i<=r;i++) Pol[m++]=IP[i];
	return m;
}
int Andrew(Poi *A,int N,Poi *B)
{
	int m=0;
	sort(A,A+N);
	for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;
	for(int i=N-2,k=m;i>=0;B[m++]=A[i--])
		while(m>k&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;
	if(N>1) m--;
	B[m]=B[0];
	return m;
}
int ShamoS(int N,Poi *P)
{
	int r=1,ans=0,d;
	if(N==1) return 0;
	else if(N==2) return sQr(P[0]-P[1]);
	for(int l=0;l<N;r=(r+1)%N)
	{
		d=dcmp(cRoss(P[l+1]-P[l],P[r+1]-P[r]));
		if(d>0) continue;
		ans=max(ans,(int)sQr(P[r--]-P[l++]));
		if(!d) ans=max(ans,(int)sQr(P[r+1]-P[l]));
	}
	return ans;
}
bool onseg(const Poi &A,const Poi &B,const Poi &P)
{
	Vec PA=A-P,PB=B-P;
	if(!dcmp(cRoss(PA,PB))&&dcmp(dOt(PA,PB))<=0) return true;
	return false;
}
bool segI(const Poi &A,const Poi &B,const Poi &C,const Poi &D)
{
	if(onseg(A,B,C) ||onseg(A,B,D) ||onseg(C,D,A) ||onseg(C,D,B)) return true;
	if((dcmp(cRoss(B-C,D-C))^dcmp(cRoss(A-C,D-C)))==-2
			&&(dcmp(cRoss(D-B,A-B))^dcmp(cRoss(C-B,A-B)))==-2) return true;
	return false;
}
