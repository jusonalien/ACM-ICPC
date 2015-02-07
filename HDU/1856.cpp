////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-23 15:57:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1856
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

struct node
{
    int x,y;
    node(int a,int b):x(a),y(b) {}
    //��ֵ����
};

int father[10000002],rank[10000002];

void set(int x)
{
    father[x]=x;
    rank[x]=1;
    //��ʼ��Ϊ1����¼��ǰ�ڵ�Ӻ��ӵĸ�����
}

int find(int x)
{
    if(father[x]!=x)
        father[x]= find(father[x]);
    return father[x];
}

bool Union(int x,int y)
{
    int root1=find(x);
    int root2=find(y);
    if(root1!=root2)
    {
        //rank����������Ҹ���rankֵ����С��rankֵ��
        if(rank[root1]<rank[root2])
        {
            father[root1]=root2;
            rank[root2]+=rank[root1];
        }
        else
        {
            rank[root1]+=rank[root2];
            father[root2]=root1;
        }
        return true;
    }
    return false;
}



int main()
{
    //freopen("in.txt","r",stdin);
    int pair;
    vector<node>vect;
    while(scanf("%d",&pair)!=EOF)
    {
        if(pair==0)
        {//������Ϊ0���ʱ��Ҫ���1��
            printf("1\n");
            continue;
        }
        vect.clear();
        int max=0;
        while(pair--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            set(u),set(v);//���ʼֵ
            vect.push_back(node(u,v));//��¼�����ֵ
        }
        for(int i=0; i<vect.size(); i++)
        {
            //һ��һ�Եغϲ�
            Union(vect[i].x,vect[i].y);
        }
        for(int i=0; i<vect.size(); i++)
        {
            //�ҳ�rankֵ����
            if(max<rank[vect[i].x])
                max=rank[vect[i].x];
            if(max<rank[vect[i].y])
                max=rank[vect[i].y];
        }
        printf("%d\n",max);
    }
    return 0;
}
