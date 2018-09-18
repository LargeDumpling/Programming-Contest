/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int C[138][138];
int main()
{
	freopen("bitch2.txt","w",stdout);
	int cnt=0;
	for(int i=1;i<=130;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		for(int j=0;j<=i;j++) if((C[i][j]&1)==0)
			cnt++;
		printf("%d:%d\n",i,cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

