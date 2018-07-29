/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
int num[MAXN],tem[MAXN];
void shuffle(int n)
{
	int cnt=0;
	for(int i=0;i<n;i+=2)
		tem[cnt++]=num[i];
	for(int i=1;i<n;i+=2)
		tem[cnt++]=num[i];
	memcpy(num,tem,sizeof(tem));
	return;
}
bool check(int n)
{
	for(int i=0;i<n;i++)
		if(num[i]!=i+1)
			 return false;
	return true;
}
void print(int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",num[i]);
	putchar('\n');
	return;
}
int main()
{
	int cnt;
	for(int i=2;i<=40;i+=2)
	{
		for(int j=0;j<i;j++)
			num[j]=j+1;
		//print(i);
		cnt=0;
		do
		{
			shuffle(i);
			cnt++;
			//print(i);
		}while(!check(i));
		printf("%d\n\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

