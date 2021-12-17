//BFS
#include <cstdio>
#include <queue>

using namespace std;
int G[100][100];
int n;//节点数量
int vis[100]={0};

void BFS(int u){
  queue<int> q;
  q.push(u);
  while(!q.empty()){
    int t=q.front();
    q.pop();
    for(int i=0;i<n;i++){
      if(vis[i]==0 && G[t][i]!=0){
        q.push(i);
        visit(i);
        vis[i]=1;
      }
    }
  }
}
void BFSTrave(){
  for(int i=0;i<n;i++){
    if(vis[i]!=1){
      BFS(i);
    }
  }
}

int DFS(int u,int deep){
  vis[u]=1;
  visit(u);
  for(int i=0;i<n;i++){
    if(vis[i]==0 && G[u][i]!=0){
      DFS(i,deep+1);
    }
  }
}

int DFSTrave(){
  for(int i=0;i<n;i++){
    if(vis[i]==0){
      DFS(i,1);
    }
  }
}

int d[100];//s到每个点的当前最短距离
int dijkstra(s){
  d[s]=0;
  for(int i=0;i<n;i++){
    int u=-1,MIN=99999;
    //找到距离当前顶点最短距离的点
    for(int j=0;j<n;j++){
      if(vis[j]==0 && d[j]<MIN){
        u=j;MIN=d[j];
      }
    }
    if(u==-1) return;//不连通
    vis[u]=1;//每次最近的点加入标记
    
    for(int j=0;j<n;j++){
      if(vis[j]==0 && G[u][j]!=INF && d[u]+G[u][j]<d[u]){
        d[j]=d[u]+G[u][j];
      }
    }
    
  }
}