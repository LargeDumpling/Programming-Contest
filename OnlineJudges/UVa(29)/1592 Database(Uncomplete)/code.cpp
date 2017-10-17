#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string word[100050];
int n,m;
bool leter(char x)
{
	return ('a'<=x&&x<='z')||('A'<=x&&x<='Z');
}
void read1n(string &x)
{
	int len=0;char ch;
	for(ch=getchar();!leter(ch);ch=getchar());
	for(;ch!=',';ch=getchar())
		x[len++]=ch;
	x.length=len;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		read1n(word[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

