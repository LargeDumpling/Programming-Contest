#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ans=0;
bool check(char tex[])
{
	int Lenth=strlen(tex);
	if(Lenth&1)
		return false;
	Lenth>>=1;
	for(int i=0;i<Lenth;i++)
		if(tex[i]!=tex[i+Lenth])
			return false;
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int Lenth,temp;
	char tex[25],t[25];
	scanf("%d%s",&Lenth,tex);
	for(int i=0,j,k;i<(1<<Lenth);i++)
	{
		for(j=0,k=0;j<Lenth;j++)
			if((1<<j)&i)
				t[k++]=tex[j];
		t[k]='\0';
		if(check(t))
		{
			for(j=temp=0;j<Lenth;j++)
				if((1<<j)&i)
					temp++;
			if(ans<temp)
				ans=temp;
		}
	}
	printf("%d",Lenth-ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

