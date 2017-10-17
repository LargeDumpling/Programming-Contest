#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[10];
int T,d1,d2,m1,m2,year1,y2,ans;
int getmonth()
{
	scanf("%s",tex);
	if(!strcmp(tex,"January"))
		return 1;
	else if(!strcmp(tex,"February"))
		return 2;
	else if(!strcmp(tex,"March"))
		return 3;
	else if(!strcmp(tex,"April"))
		return 4;
	else if(!strcmp(tex,"May"))
		return 5;
	else if(!strcmp(tex,"June"))
		return 6;
	else if(!strcmp(tex,"July"))
		return 7;
	else if(!strcmp(tex,"August"))
		return 8;
	else if(!strcmp(tex,"September"))
		return 9;
	else if(!strcmp(tex,"October"))
		return 10;
	else if(!strcmp(tex,"November"))
		return 11;
	else if(!strcmp(tex,"December"))
		return 12;
	return -1;
}
bool leap_year(int year)
{
	if((!(year%4)&&(year%100))||!(year%400))
		return true;
	return false;
}
int main()
{
	//freopen("code.in","r",stdin);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		ans=0;
		m1=getmonth();
		scanf("%d,%d",&d1,&year1);
		m2=getmonth();
		scanf("%d,%d",&d2,&y2);
		if(leap_year(year1)&&(m1>2))
			ans--;
		if(leap_year(y2)&&(m2<2||(m2==2&&d2<29)))
			ans--;
		ans+=y2/4-y2/100+y2/400-(year1-1)/4+(year1-1)/100-(year1-1)/400;
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}

