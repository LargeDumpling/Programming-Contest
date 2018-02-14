/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
struct jz
{
	int ip[4];
	jz(const int &A=0,const int &B=0,const int &C=0,const int &D=0)
	{
		ip[0]=A;
		ip[1]=B;
		ip[2]=C;
		ip[3]=D;
	}
	bool operator<(const jz &x)const
	{
		for(int i=0;i<4;i++)
			if(ip[i]<x.ip[i])
				return true;
			else if(x.ip[i]<ip[i])
				return false;
		return false;
	}
	bool operator==(const jz &x)const
	{
		for(int i=0;i<4;i++)
			if(ip[i]!=x.ip[i])
				return false;
		return true;
	}
};
map<jz,string> f;
int main()
{
	string str;
	jz ipa;
	//scanf("%d%d",&n,&m);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		/*for(int j=0;j<4;j++)
			cin>>ipa.ip[i];*/
		scanf("%d.%d.%d.%d",&ipa.ip[0],&ipa.ip[1],&ipa.ip[2],&ipa.ip[3]);
		f[ipa]=str;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>str;
		cout<<str<<" ";
		/*for(int j=0;j<4;j++)
		{
			cin>>ipa.ip[i];
			cout<<ipa.ip[i]<<(j==3?';':'.');
		}*/
		scanf("%d.%d.%d.%d;",&ipa.ip[0],&ipa.ip[1],&ipa.ip[2],&ipa.ip[3]);
		printf("%d.%d.%d.%d;",ipa.ip[0],ipa.ip[1],ipa.ip[2],ipa.ip[3]);
		cout<<" #"<<f[ipa]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

