#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
void sWap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
void sOrt(int &a,int &b,int &c)
{
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	return;
}
int x,y,z,Rr,Ry,Rb;
bool check()
{
	int a=abs(Rr-Ry),b=abs(Ry-Rb),c=abs(Rr-Rb);
	sOrt(a,b,c);
	if(a==x&&b==y&&c==z)
		return true;
	return false;
}
int main()
{
	int ans=0;
	char ch;
	scanf("%d%d%d",&x,&y,&z);
	sOrt(x,y,z);
	Rr=Ry=Rb=0;
	getchar();
	while(true)
	{
		ch=getchar();
		if(ch=='R')
			Rr++;
		else if(ch=='Y')
			Ry++;
		else if(ch=='B')
			Rb++;
		else
			break;
		if(Rr+Ry+Rb>ans)
			ans=Rr+Ry+Rb;
		if(check())
			Rr=Ry=Rb=0;
	}
	printf("%d",ans);
	return 0;
}

