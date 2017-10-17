#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char in1[10000000],*I1=in1,in2[10000000],*I2=in2;
const int D=10000000;
int readln(char* &tex)
{
	int x=0;
	for(;*tex<'0'||'9'<*tex;tex++);
	for(;'0'<=*tex&&*tex<='9';tex++)x=(x<<3)+(x<<1)+*tex-'0';
	return x;
}
int du1[100000],du2[100000];
int main()
{
	FILE *fin1,*fin2;
	fin1=fopen("code.out","r");
	fin2=fopen("LRJ.out","r");
	freopen("test.out","w",stdout);
	int n1,n2;
	int c1,c2;
	bool flag=false;
	fscanf(fin1,"%d\n",&n1);
	fscanf(fin2,"%d\n",&n2);
	if(n1==n2)
	{
		fread(in1,1,D,fin1);
		fread(in2,1,D,fin2);
		if('0'<=*I1&&*I1<='9')
		{
			for(int i=1;i<=n1;i++)
			{
				c1=readln(I1);
				du1[c1]++;
				c1=readln(I1);
				du1[c1]++;
				c1=readln(I2);
				du2[c1]++;
				c1=readln(I2);
				du2[c1]++;
			}
			for(int i=1;i<=n1;i++)
				if(du1[i]&1)
					flag=true;
			for(int i=1;i<=n2;i++)
				if(du2[i]&1)
					flag=true;
		}
	}
	else
		flag=true;
	if(!flag)
		printf("0");
	else
		printf("1");
	fclose(fin1);
	fclose(fin2);
	fclose(stdout);
	return 0;
}

