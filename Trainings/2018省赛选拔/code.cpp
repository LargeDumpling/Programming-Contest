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
	for(ws=0;x;ws++)
		num[ws]=x%10;
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
	for(int i=0;i<=C.ws;i++)
		for(int j=0;j<ws&&j<=i;j++)
			C.num[i]+=num[j]*X.num[i-j];
	for(int i=0;i<=C.ws;i++)
		if(C.num[i]>=10)
		{
			C.num[i+1]+=C.num[i]/10;
			C.num[i]=C.num[i]%10;
			if(i==C.ws)
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
void readln(jp& X)
{
	char tex[10050];
	scanf("%s",tex);
	X.ws=strlen(tex);
	for(int i=0;i<X.ws;i++)
		X.num[i]=tex[X.ws-i-1]-'0';
	return;
}
void writeln(jp X)
{
	if(!X.ws)
		printf("0");
	else
		for(int i=X.ws-1;i>=0;i--)
			printf("%c",X.num[i]+'0');
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	jp A,B,C,D,E,F;
	readln(A);
	readln(B);
	readln(C);
	readln(D);
	readln(E);
	readln(F);
	if(C<D)
	{
		C=C+D;
		D=C-D;
		C=C-D;
	}
	writeln(A+B);
	printf("\n");
	writeln(C-D);
	printf("\n");
	writeln(E*F);
	fclose(stdin);
	fclose(stdout); 
    return 0;
}

