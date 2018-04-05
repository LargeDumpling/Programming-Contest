#include<cstdio>
char ch;
int num[10];
int main()
{
	for(ch=getchar();ch<='0'||'9'<ch;ch=getchar());
	while('0'<=ch&&ch<='9')
	{
		num[ch-'0']++;
		ch=getchar();
	}
	for(int i=0;i<=9;i++) if(num[i])
		printf("%d:%d\n",i,num[i]);
	return 0;
}
4
