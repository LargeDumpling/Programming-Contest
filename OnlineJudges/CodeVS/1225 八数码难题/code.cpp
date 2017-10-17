#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int kor[9]={4,0,1,2,5,8,7,6,3};
int next[9][10];
map<vector<char>,int> dis,h;
map<vector<char>,bool> exist;
//0 1 2
//3 4 5
//6 7 8
//kor[i]表示i这个数正确的位置
int dIs(const vector<char>&);
int H(const vector<char>&);
struct jp
{
	vector<char> sta;
	jp(const vector<char> &STA):sta(STA) { }
	bool operator<(const jp &x)const
	{ return dIs(sta)+H(sta)<dIs(x.sta)+H(x.sta); }
};
int dIs(const vector<char> &s)
{
	if(!dis.count(s))
		return dis[s]=2147483647;
	return dis[s];
}
int H(const vector<char> &s)
{
	if(!h.count(s))
	{
		int cnt=0;
		for(int i=1;i<9;i++)
			if(i!=kor[(int)s[i]])
				cnt++;
		return h[s]=cnt;
	}
	return h[s];
}
int Astar(vector<char> ini)
{
	dis[ini]=0;
	priority_queue<jp> q;
	q.push(jp(ini));
	exist[ini]=true;
	vector<char> T;
	T.push_back(1);
	T.push_back(2);
	T.push_back(3);
	T.push_back(8);
	T.push_back(0);
	T.push_back(4);
	T.push_back(7);
	T.push_back(6);
	T.push_back(5);
	while(q.size())
	{
		vector<char> u=q.top().sta,v; q.pop();
		if(u==T) break;
		exist[u]=false;
		v=u;
		int k=0;
		while(u[k]!=0) k++;
		for(int i=1;i<=next[k][0];i++)
		{
			swap(v[k],v[next[k][i]]);
			if(dIs(u)+1<dIs(v))
			{
				dis[v]=dis[u]+1;
				if(!exist.count(v)||exist[v]==false)
				{
					exist[v]=true;
					q.push(jp(v));
				}
			}
			swap(v[k],v[next[k][i]]);
		}
	}
	return dIs(T);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[10];
	next[0][0]=2; next[0][1]=1; next[0][2]=3;
	next[1][0]=3; next[1][1]=0; next[1][2]=2; next[1][3]=4;
	next[2][0]=2; next[2][1]=1; next[2][2]=5;
	next[3][0]=3; next[3][1]=0; next[3][2]=4; next[3][3]=6;
	next[4][0]=4; next[4][1]=1; next[4][2]=3; next[4][3]=5; next[4][4]=7;
	next[5][0]=3; next[5][1]=2; next[5][2]=4; next[5][3]=8;
	next[6][0]=2; next[6][1]=3; next[6][2]=7;
	next[7][0]=3; next[7][1]=4; next[7][2]=6; next[7][3]=8;
	next[8][0]=2; next[8][1]=5; next[8][2]=7;
	scanf("%s",tex);
	vector<char> ini;
	for(int i=0;i<9;i++)
		ini.push_back(tex[i]-'0');
	printf("%d",Astar(ini));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

