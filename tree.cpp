#include <cstdio>
#include <queue>
#define ElemType int
using namespace std;

typedef struct TNode{
  struct TNode *lc;
  struct TNode *lr;
  ElemType data;
}TNode,*BiTree;

//先序遍历 递归
void preTrave(BiTree t){
  visit(t);
  preTrave(t->lc);
  preTrave(t->rc);
}

//先序遍历 非递归
void preTrave2(BiTree t){
  if(t==NULL) return;
  
  TNode *stack[100];
  int top=-1;
  TNode *p=t;
  stack[++top]=p;
  while(top!=-1){
    p=stack[top--];
    visit(p);
    if(p->lc) stack[++top]=p->lc;
    if(p->rc) stack[++top]=p->rc;
  }
}

//中序遍历 递归
void inTrave(BiTree t){
  inTrave(t->lc);
  visit(t);
  inTrave(t->rc);
}

//中序遍历 非递归
void inTrave2(BiTree t){
  if(t==NULL) return;
  TNode *stack[100];
  int top=-1;
  TNode *p=t;
  while(p!=NULL || top!=-1){
    if(p){
      stack[++top]=p;
      p=p->lr;
    }
    else{
      p=stack[top--];
      visit(p);
      p=p->rc;
    }
  }
}

//后序遍历 递归
void postTrave(BiTree t){
  if(t){
    postTrave(t->lc);
    postTrave(t->rc);
    visit(t);
  }
}


//后序遍历 非递归
//代码为：执行前序遍历，并且通过进栈反向
void postTrave2(BiTree t){
  if(t==NULL) return;
  TNode *stack1[100];
  TNode *stack2[100];
  TNode *p=t;
  int top1=-1,top2=-1;
  
  stack1[++top1]=p;
  while(top1!=-1){
    p=stack1[top1--];
    stack2[++top2]=p;
    if(p->lc) stack1[top1]=p->lc;
    if(p->rc) stack1[top1]=p->rc;
  }
  
  //stack2全部出栈，完成倒序
  while(top2!=-1){
    visit(stack2[top2--]);
  }
}

//层次遍历
void levelTrave(BiTree t){
  queue<ElemType> q;
  TNode *p=t;
  if(t){
    q.push(p);
    while(!q.empty()){
      p=q.front();
      q.pop();
      visit(p);
      
      if(p->lc) q.push(p->lc);
      if(p->rc) q.push(p->rc);
    }
  }
}

//求二叉树高度 非递归
int heightOfTree(BiTree t){
  if(!t) return 0;
  
  queue<ElemType> q;
  TNode *p=t;
  q.push(p);
  int height=0;
  while(!q.empty()){
    int size=q.size();
    for(int i=0;i<size;i++){
      p=q.front();
      q.pop();
      if(p->lc) q.push(p->lc);
      if(p->rc) q.push(p->rc);
    }
    height++;
  }
  return height;
}

//求二叉树高 递归
int heightOfTree2(BiTree t){
  if(!t) return 0;
  int lheight=heightOfTree2(t->lc);
  int rheight=heightOfTree2(t->rc);
  return lheight>rheight?lheight+1:rheight+1;
}

//判断平衡二叉树 递归 自上而下 开销大
bool isBTS(BiTree t){
  if(t==NULL) return true;
  return(abs(heightOfTree2(t->lc)- heightOfTree2(t->rc))
    && isBTS(t->lc) && isBTS(t->rc));
}