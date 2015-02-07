////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-08-01 21:29:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*��������һ��Ҫע������Խ������⣬�������ǳ��Ͼ����������Խ���������±굽�׺�����Ĳ��������а�ëǮ�Ĺ�ϵ
��ô oj��������һ������WA���������ݲ����ܴﵽ3000�ģ������Ҷ�����һ��prime[3000]�����飬���ѭ���������Խ�絽prime[3000]�Ļ�
��͹ԹԵص���WA��  ������������*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int x,y,flag = 0;
int prime[3000];
int main()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2;i <= 2900;i++){
        if(prime[i]) continue;
        for(int j = i*i,k = i;j <= 2900;j =i*(++k))
            prime[j] = 1;
    }
    while(~scanf("%d%d",&x,&y)&&(x + y)){
    for(int i = x;i <= y;i++){
        if(prime[i*i + i + 41]){
                 flag = 1;break;
        }
    }
    if(flag) {puts("Sorry");flag = 0;}
    else puts("OK");
    }
    return 0;
}
