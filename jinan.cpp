//2016-编写算法，分成左右两部分，左全小于ki，右全大于ki
void findPosition(elemType a[],int i,int n){
  //从a[0]开始存储数据，则Ki的位置在a[i-1]
  i=i-1;
  int temp=a[i];//将Ki与K1交换位置
  a[i]=a[0];
  a[0]=temp;
  int p1=0,p2=n-1;
  while(p1<p2){
    while(p1<p2&&a[p2]>temp) p2--;//从后往前找到比Ki小的数
    a[p2]=a[p1];
    while(p1<p2&&a[p1]<temp) p1++;
    a[p1]=a[p2];
  }
  a[p2]=temp;
}

//2016-构造哈夫曼树
//思想：每次从数组中找到最小的两个数a、b，然后令a=a+b，b=-1表示不用改位置，并且将a与b指向a+b
typedef TNode{
  int w;//权值
  int parent,lchild,rchild;
}TNode;

int findMin(TNode a[],int n){
  int minIdx=0x7fffffff;
  for(int i=0;i<n;i++){
    if(a[i].parent==NULL && a[i]<a[minIdx]) minIdx=i;
  }
  return minIdx;
}

TNode* buildTree(int a[],int n){
  TNode T[2*n];
  for(int i=0;i<2*n;i++){
    T[i].w=-1;
    T[i].parent=-1;
    T[i].lchild=-1;
    T[i].rchild=-1;
  }
  for(int i=0;i<n;i++) T[i].w=a[i];
  int p1=n;//非叶子节点指针
  while(1){
    int minIdx1,minIdx2;
    minIdx1=findMin(T,2*n);
    T[minIdx1].parent=p1;
    minIdx2=findMin(T,2*n);
    if(minIdx2==0x7fffffff) break;//表示树构建完成
    T[minidx2].parent=p1;
    T[p1].w=T[minIdx1].w+T[minIdx2].w;
    T[p1].lchild=minIdx1;
    T[p1].rchild=minIdx2;
    p1++;
  }
  return T;
} 

void print(TNode T[],int k){//求a[k]的哈夫曼编码
  int stack[100]={0};
  int top=-1;
  int p1=k;//指针
  while(T[p1].parent!=NULL){
    if(T[T[T[p1].parent].lchild].w==T[p1].w)//p1为p1父亲的左孩子
      stack[++top]=0;
    else{stack[++top]=1}
    p1=T[p1].parent;
  }
  while(top!=-1){
    printf("%d ",stack[top--]);
  }
}

//2014-408,求二叉树带权路径长度
int getWPL(TNode *T){
  int sum=0,deep=1;
  queue<TNode *> q;
  TNode *p;
  q.push(T);
  while(!q.empty()){
    int size=q.size();
    for(int i=0;i<size;i++){
      p=q.front();
      q.pop();
      sum+=p->weight*deep;
      if(p->left) q.push(p->left);
      if(p->right) q.push(p->right);
    }
    deep+=1;
  }
}

//暨南484-2021
//孩子兄弟表示法，输出所有从根到叶子的路径
typedef TNode{
  elemType value;
  TNode *child;
  TNode *brother;
}TNode;


void printPath(TNode *T,TNode **stack,int top){
  if(!T){//T为NULL,即已经访问完叶子节点
    for(int i=0;i<=top;i++){
      cout<<stack[i].value<<" ";
    }
    cout<<endl;
    return;
  }
  else{
    stack[++top]=T; 
    printPath(T->child,stack,top);
    top--;
  }
  if(T->brother){
    q.push(T->brother,stack,top);
  }
}

void fun(TNode *T){
  TNode *stack[500];
  int top=-1;
  printPath(T,stack,top)
}