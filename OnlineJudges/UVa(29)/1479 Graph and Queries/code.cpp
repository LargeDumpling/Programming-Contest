/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*struct jp *null;
struct jp
{
    int key,num,size,v;
    jp *son[2];
    jp(const int &x=0):key(x) { v=rand(); num=size=1; son[0]=son[1]=null; }
    int cmp(const int &x) { return x==key?-1:(x<key?0:1); }
    void updata() { size=son[0]->size+son[1]->size+num; }
}*root[20050];
void adjust(jp* &r,int d)
{//把r结点的d儿子旋转上来
    jp *node=r->son[d];
    r->son[d]=node->son[d^1];
    node->son[d^1]=r;
    r->updata();
    node->updata();
    r=node;
    return;
}
void insert(jp* &r,int x)
{//在r子树中插入一个键值为x的结点
    if(r==null)
    {
        r=new jp(x);
        return;
    }
    r->size++;
    int d=r->cmp(x);
    if(d==-1) r->num++;
    else
    {
        insert(r->son[d],x);
        if(r->son[d]->v > r->v) adjust(r,d);
    }
	r->updata();
    return;
}
bool del(jp* &r,int x)
{//在r子树中删除键值为x的结点
    if(r==null) return false;
    int d= r->cmp(x);
    if(d==-1)
    {
        if(r->num > 1) r->num--;
        else
        {
            if(r->son[0]==null||r->son[1]==null)
            {
                jp *temp=r;
                r=(r->son[0]==null)?r->son[1]:r->son[0];
                delete temp;
            }
            else
            {
                d=r->son[0] < r->son[1];
                adjust(r,d);
                r->size--;
                del(r->son[d^1],x);
            }
        }
        r->updata();
        return true;
    }
    bool flag=del(r->son[d],x);
    r->updata();
    return flag;
}
int kth(jp* &r,int rk)
{
    if(r==null) return 0;
    if(rk<=r->son[1]->size) return kth(r->son[1],rk);
    else if(rk>r->son[1]->size+r->num)
        return kth(r->son[0],rk - r->son[1]->size - r->num);
    return r->key;
}*/
#define jp Node
#define son ch
#define null NULL
struct Node {
  Node *ch[2]; // 左右子树
  int r; // 随机优先级
  int v; // 值
  int s; // 结点总数
  Node(const int &v=0):v(v) { ch[0] = ch[1] = NULL; r = rand(); s = 1; }
  int cmp(int x) const {
    if (x == v) return -1;
    return x < v ? 0 : 1;
  }
  void maintain() {
    s = 1;
    if(ch[0] != NULL) s += ch[0]->s;
    if(ch[1] != NULL) s += ch[1]->s;
  }
}*root[20050];

void rotate(Node* &o, int d) {
  Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o; 
  o->maintain(); k->maintain(); o = k;
}

void insert(Node* &o, int x) {
  if(o == NULL) o = new Node(x);
  else {
    int d = (x < o->v ? 0 : 1); // 不要用cmp函数，因为可能会有相同结点
    insert(o->ch[d], x);
    if(o->ch[d]->r > o->r) rotate(o, d^1);
  }
  o->maintain();
}

void del(Node* &o, int x) {
  int d = o->cmp(x);
  if(d == -1) {
    Node* u = o;
    if(o->ch[0] != NULL && o->ch[1] != NULL) {
      int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
      rotate(o, d2); del(o->ch[d2], x);
    } else {
      if(o->ch[0] == NULL) o = o->ch[1]; else o = o->ch[0];
      delete u;
    }
  } else
    del(o->ch[d], x);
  if(o != NULL) o->maintain();
}
struct Com
{
	int type,a,b;
}C[500050];
int n,m,WEI[20050],from[60050],to[60050],fa[20050];
int find(int x)
{
	while(fa[x]!=fa[fa[x]]) fa[x]=fa[fa[x]];
	return fa[x];
}
void remove_tree(jp* &r)
{
	if(r==NULL) r=null;
	if(r==null) return;
	remove_tree(r->son[0]); remove_tree(r->son[1]);
	delete r; r=null;
	return;
}
void mErgeto(jp* &r,jp* &ss)
{
	if(r==null) return;
	mErgeto(r->son[0],ss); mErgeto(r->son[1],ss);
	insert(ss,r->v); delete r; r=null;
	return;
}
void addedge(int x)
{
	int a=find(from[x]),b=find(to[x]);
	if(a==b) return;
	if(root[a]->s > root[b]->s) swap(a,b);
	mErgeto(root[a],root[b]);
	fa[a]=b;
	return;
}
void change_wei(int a,int b)
{
	int u=find(a);
	del(root[u],WEI[a]);
	insert(root[u],WEI[a]=b);
	return;
}
int kth(Node* o, int k) { // 第k大的值
  if(o == NULL || k <= 0 || k > o->s) return 0;
  int s = (o->ch[1] == NULL ? 0 : o->ch[1]->s);
  if(k == s+1) return o->v;
  else if(k <= s) return kth(o->ch[1], k);
  else return kth(o->ch[0], k-s-1);
}
long long ans;
int qn;
void query(int a,int k)
{
	qn++;
	ans+=kth(root[find(a)],k);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	/*null=new jp();
	null->son[0]=null->son[1]=null;
	null->size=null->num=0;*/
	int T_T,comn;
	char ord[5];
	bool useable[60050];
	for(T_T=1;scanf("%d%d",&n,&m)==2&&n;T_T++)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&WEI[i]);
			fa[i]=i;
			if(root[i]!=null) remove_tree(root[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&from[i],&to[i]);
			useable[i]=true;
		}
		comn=qn=ans=0;
		while(true)
		{
			scanf(" %c",&ord[0]);
			if(ord[0]=='E') break;
			comn++;
			if(ord[0]=='D')
			{
				C[comn].type=0;
				scanf("%d",&C[comn].a);
				useable[C[comn].a]=false;
			}
			else if(ord[0]=='Q')
			{
				C[comn].type=1;
				scanf("%d%d",&C[comn].a,&C[comn].b);
			}
			else if(ord[0]=='C')
			{
				C[comn].type=2;
				scanf("%d%d",&C[comn].a,&C[comn].b);
				swap(C[comn].b,WEI[C[comn].a]);
			}
		}
		for(int i=1;i<=n;i++)
			root[i]=new jp(WEI[i]);
		for(int i=1;i<=m;i++)
			if(useable[i]) addedge(i);
		for(int i=comn;i;i--)
		{
			switch(C[i].type)
			{
				case 0: addedge(C[i].a); break;
				case 1: query(C[i].a,C[i].b); break;
				case 2: change_wei(C[i].a,C[i].b); break;
				default: break;
			}
		}
		printf("Case %d: %.6lf\n",T_T,(double)ans/qn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

