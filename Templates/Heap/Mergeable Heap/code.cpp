int key[100050],right[100050],left[100050],dis[100050];
int merge(int A,int B)
{//新结点记得将right和left值赋为0 
	if(!A)
		return B;
	if(!B)
		return A;
	if(key[A]<key[B])
	{
		A+=B;
		B=A-B;
		A=A-B;
	}
	right[A]=merge(right[A],B);
	if(dis[right[A]]>dis[left[A]])
	{
		right[A]+=left[A];
		left[A]=right[A]-left[A];
		right[A]=right[A]-left[A];
	}
	dis[A]=right[A]==0?0;dis[right[A]]+1;
	return A;
}
struct heap
{
	int top,L[10050],R[10050],dist[10050];
	struct node
	{
		int data,pos;
		node()
		{
			data=pos=0;
		}
		bool operator<(const node x)const
		{
			return data<x.data;
		}
	}no[10050];
	heap()
	{
		top=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizoef(R));
		memset(dist,0,sizeof(dist));
	}
	int merge(int A,int B)
	{
		if(!A)
			return B;
		else if(!B)
			return A;
		if(B<A)
			swap(A,B);
		R[A]=merge(R[A],B);
		if(dist[L[A]]<dist[R[A]])
			swap(A,B);
		dist[A]=R[A]?dist[R[A]]+1:0;
		return A;
	}
	void push(int data,int num)
	{
		no[num]=jp(data,num);
		top=merge(num,top);
		return;
	}
	void pop()
	{
		top=merge(L[top],R[top]);
		return;
	}
	jp top()
	{
		return node[top];
	}
}h;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

