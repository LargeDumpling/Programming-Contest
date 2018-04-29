/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int num[10050],ws;
	jp();
	jp(const int);
	jp(const char*);
	jp(const jp &);
	bool operator<(const jp X)const;
	bool operator==(const jp X)const;
	bool operator!=(const jp X)const;
	jp operator+(const jp)const;
	jp operator-(const jp)const;
	jp operator*(const jp)const;
	jp &operator=(const jp);
	friend istream& operator>>(istream&,jp&);
	friend ostream& operator<<(ostream&,jp&);
};
jp::jp()
{
	memset(num,0,sizeof(num));
	ws=0;
}
jp::jp(const int x)
{//jp X(2147483648);
	memset(num,0,sizeof(num));
	int y=x;
	for(ws=0;y;ws++,y/=10)
		num[ws]=y%10;
}
jp::jp(const char* tex)
{
	memset(num,0,sizeof(num));
	ws=strlen(tex);
	for(int i=0;i<ws;i++)
		num[ws]=tex[ws]-'0';
}
jp::jp(const jp &X):ws(X.ws)
{
	memset(num,0,sizeof(num));
	for(int i=0;i<ws;i++)
		num[i]=X.num[i];
}
bool jp::operator<(const jp X)const
{
	if(ws<X.ws)
		return true;
	else if(ws>X.ws)
		return false;
	for(int i=ws-1;i>=0;i--)
		if(num[i]<X.num[i])
			return true;
		else if(num[i]>X.num[i])
			return false;
	return false;
}
bool jp::operator==(const jp X)const
{
	if(ws!=X.ws) return false;
	for(int i=0;i<ws;i++) if(num[i]!=X.num[i])
		return false;
	return true;
}
bool jp::operator!=(const jp X)const
{
	if(ws!=X.ws) return true;
	for(int i=0;i<ws;i++) if(num[i]!=X.num[i])
		return true;
	return false;
}
jp jp::operator+(const jp X)const
{
	jp C;
	C.ws=ws>X.ws?ws:X.ws;
	for(int i=0;i<C.ws;i++)
	{
		C.num[i]+=num[i]+X.num[i];
		if(C.num[i]>=10)
		{
			C.num[i+1]++;
			C.num[i]-=10;
			if(i==C.ws-1)
				C.ws++;
		}
	}
	return C;
}
jp jp::operator-(const jp X)const
{
	jp C;
	C.ws=ws>X.ws?ws:X.ws;
	for(int i=0;i<C.ws;i++)
	{
		C.num[i]+=(num[i]-X.num[i]);
		if(C.num[i]<0)
		{
			C.num[i+1]--;
			C.num[i]+=10;
		}
	}
	while(C.num[C.ws-1]==0&&C.ws)C.ws--;
	return C;
}
jp jp::operator*(const jp X)const
{
	jp C;
	C.ws=ws+X.ws+2;
	for(int i=0;i<C.ws;i++)
		for(int j=0;j<ws&&j<=i;j++)
			C.num[i]+=num[j]*X.num[i-j];
	for(int i=0;i<C.ws;i++)
		if(C.num[i]>=10)
		{
			C.num[i+1]+=C.num[i]/10;
			C.num[i]=C.num[i]%10;
			if(i==C.ws-1)
				C.ws++;
		}
	while(C.num[C.ws-1]==0&&C.ws)C.ws--;
	return C;
}
jp& jp::operator=(const jp X)
{
	ws=X.ws;
	memset(num,0,sizeof(num));
	for(int i=0;i<ws;i++)
		num[i]=X.num[i];
	return *this;
}
void read1n(jp& X)
{
	char tex[10050];
	scanf("%s",tex);
	X.ws=strlen(tex);
	for(int i=0;i<X.ws;i++)
		X.num[i]=tex[X.ws-i-1]-'0';
	return;
}
jp x[4],y[4],X0,X1,Y0,Y1;
jp dOt(jp x0,jp y0,jp x1,jp y1) { return x0*x1+y0*y1; }
jp cRoss(jp x0,jp y0,jp x1,jp y1)
{
	jp n1=x0*y1,n2=x1*y0;
	if(n1<n2) return n2-n1;
	else return n1-n2;
}
jp lEnth2(jp x,jp y) { return x*x+y*y; }
jp get(jp a,jp b)
{
	return a<b?b-a:a-b;
}
bool check1()
{
	jp n;
	for(int i=0;i<3;i++)
	{
		n=dOt(get(x[i],x[3]),get(y[i],y[3]),get(x[(i+2)%3],x[(i+1)%3]),get(y[(i+2)%3],y[(i+1)%3]));
		if(n!=0) return false;
	}
	return true;
}
bool check2()
{
	jp n[2];
	for(int i=0;i<3;i++)
	{
		n[0]=cRoss(get(x[(i+1)%3],x[i]),get(y[(i+1)%3],y[i]),get(x[3],x[i]),get(y[3],y[i]));
		n[1]=cRoss(get(x[(i+2)%3],x[i]),get(y[(i+2)%3],y[i]),get(x[3],x[i]),get(y[3],y[i]));
		if(n[0]!=n[1]) return false;
	}
	return true;
}
bool check3()
{
	jp s[3],l[3];
	for(int i=0;i<3;i++)
	{
		s[i]=cRoss(get(x[i],x[3]),get(y[i],y[3]),get(x[(i+1)%3],x[3]),get(y[(i+1)%3],y[3]));
		l[i]=lEnth2(get(x[(i+1)%3],x[i]),get(y[(i+1)%3],y[i]));
	}
	for(int i=0;i<3;i++)
		if(s[i]*s[i]*l[(i+1)%3]!=s[(i+1)%3]*s[(i+1)%3]*l[i])
			return false;
	return true;
}
bool check4()
{
	jp d[3];
	for(int i=0;i<3;i++)
		d[i]=lEnth2(get(x[i],x[3]),get(y[i],y[3]));
	if(d[0]!=d[1]||d[1]!=d[2]||d[2]!=d[0])
		return false;
	return true;
}
int main()
{
	for(int i=0;i<4;i++)
	{
		read1n(x[i]);
		read1n(y[i]);
	}
		//cin>>x[i]>>y[i];
	if(check1()||check2()||check3()||check4())
		puts("Yes");
	else puts("No");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

