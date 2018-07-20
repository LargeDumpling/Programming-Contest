//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<map> 
#include<algorithm>
using namespace std;
string sen[25];
map<string,unsigned long long> c,a;
map<string,string> f;
int n,m;
unsigned long long cn,icn;
int main()
{
	string D,E,R;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>sen[i];
		c[sen[i]]=0;
		a[sen[i]]=0;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>D>>E>>R;
		f[D]=E;
		a[D]++;
		if(R[0]=='c')
			c[D]++;
	}
	cn=icn=1;
	for(int i=0;i<n;i++)
	{
		icn*=a[sen[i]];
		cn*=c[sen[i]];
	}
	if(icn==1)
	{
		for(int i=0;i<n;i++)
			cout<<f[sen[i]]<<" ";
		if(cn==1)
			cout<<"\ncorrect";
		else
			cout<<"\nincorrect";
	}
	else cout<<cn<<" correct\n"<<icn-cn<<" incorrect";
	return 0;
}


