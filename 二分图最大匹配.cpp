#include <bits/stdc++.h>
using namespace std;
int idx[510][510],boy[510],vis[510];
int n,m;
int Find(int x)
{
    for( int i=1; i<=m; i++)//遍历所有被选者
    {
        if( idx[x][i] == 1 && vis[i] == 0 )
        {//如果 x对i有好感且在这一个递归选取阶段没有被选取（哪怕是暂时选取，新的递归可能会换）
            vis[i] = 1;//标记被选取
            if(boy[i] == 0 || Find(boy[i]))//如果被选者没有归属或他的归属着可以调换（他的归属者可以选择其它被选者）
            {
                boy[i] = x;//将归属定为 x
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int i,k,x,y,sum;
    while(scanf("%d %d %d",&k,&n,&m) == 3 && k){
        memset(idx,0,sizeof(idx));
        memset(boy,0,sizeof(boy));
        memset(vis,0,sizeof(vis));
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&x,&y);
            idx[x][y]=1; //表示 x希望与 y有关系
        }
        sum = 0; //记录能撮合的情侣对数
        for(i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));//每次都要清 0
            if(Find(i)) sum++;//找到一对就记录
        }
        printf("%d\n",sum);
    }
    return 0;
}

