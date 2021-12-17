//2021.12.12----------------------------------------
//前序遍历树
int preTreeTraverse(BiTree &T){
  if(T){
    visit(T);
    preTreeTraverse(T->lc);
    preTreeTraverse(T->rc);
  }
}

//no recursion 
int preTreeTraverse2(BiTree &T){
  BiNode *stack[100],p;
  int top=-1;
  stack[++top]=T;
  while(top!=-1){
    p=stack[top--];
    visit(p);
    if(p->rc) stack[++top]=p->rc;
    if(p->lc) stack[++top]=p->lc;
  }
}

//中序遍历树
int inTreeTraverse(BiTree &T){
  if(T){
    inTreeTraverse(T->lc);
    visit(T);
    inTreeTraverse(T->rc);
  }
}

//no recursion ***
int inTreeTraverse2(BiTree &T){
  BiNode* stack[100],*p;
  int top=-1;
  stack[++top]=T;
  while(top!=-1 &&p!=NULL){
    if(p){
      stack[++top]=p;
      p=p->lc;
    }
    else{
      p=stack[top--];
      visit(p);
      p=p->rc;
    }
  }
}

//后序遍历 no recursion
int postTreeTraverse(BiTree T){
  BiNode* stack1[100],*stack2[100],*p;
  int top1=-1,top2=-1;
  //stact2 is used to reverse, instand of visit 
  stack1[++top1]=T;
  while(top1!=-1){
    p=stack1[top1--];
    stack2[++top2]=p;
    if(p->lc) stack1[++top1]=p->lc;
    if(p->rc) stack1[++top1]=p->rc;
  }
  while(top2!=-1){
    p=stack2[top2--];
    visit(p);
  }
  return 0;
}

//2021.12.13-----------------------------------------------
//层次遍历
void levelTreeTraverse(BiTree T){
  queue<TNode*> q;
  TNode *p;
  if(T) q.push(T);
  while(!q.empty()){
    p=q.front();
    q.pop();
    visit(p);
    if(p->lc) q.push(p->lc);
    if(p->rc) q.push(->rc);
  }
  return;
}

//get height of tree
int getHigh(BiTree T){
  if(T==NULL) return 0;
  return max(getHigh(T->lc),getHigh(T->rc));
}
//非递归求树高，没做出来---------------------------------
int getHigh(BiTree T){
  queue<TNode *> q;
  int sum=0;
  q.push(T);
  while(!q.empty()){
    
  }
}

//判断平衡二叉树 (可优化剪枝)
int isAVL(BiTree T){
  int t=0;
  if(!T) return 1;
  if(abs(getHigh(T->lc)-getHigh(T->lc))<2) t=1;
  return t&&isAVL(T->lc)&&isAVL(T->rc);
}

// 二分查找递归
int binarySearch(elemType a[],elemType key,int left,int right){
  int mid=(left+right)/2;
  if(left>right) return -1;
  if(a[mid]==key) return mid;
  else if(a[mid<key]) return midSearch(a,key,mid+1,right);
  else return midSearch(a,key,left,mid-1);
  
}

//binarySearch no recursion
int binarySearch2(elemType a[],elemType key,int left,int right){
  while(left<=right){
    int mid=(left+right)/2;
    if(a[mid]==key) return mid;
    if(a[mid]>key){right=mid-1;}
    else {left=mid+1;}
  }
  return -1;
}

// quicksort
int getPosition(int a[],int left,int right){
  int temp=a[left];
  while(right>left){
    while(right>left&&a[right]>temp) right--;
    a[left]=a[right]
    while(right>left&&a[left]<temp) left++;
    a[right]=a[left]  
  }
  a[left]=temp;
  return left;
}

void quickSort(int a[],int left,int right){
  if(left>=right) return;//--------------------别忘了递归出口
  int t=getPosition(a,left,right);
  quickSort(a,left,t-1);
  quickSort(a,t+1,right);
}

//20211214-------------------------------------------
//堆排序
void AdjustDown(int a[],int k,int len){
  int temp=a[k];
  for(int i=k*2;i<=len;i*=2){
    if(i<len&&a[i+1]>a[i]) i++;//选出两个左右孩子中大的
    if(a[0]>=a[i]) break;//根比左右大，结束
    else{
      a[k]=a[i];
      k=i;//不断下坠
      }
  }
  a[k]=temp;
}

void buildHeap(int a[],int len){
  for(int i=len/2;i>0;i--){
    AdjustDown(a,i,len);
  }
}

void heapSort(int a[],int len){
  buildHeap(a,len);
  for(int i=len;i>1;i--){
    swap(&a[1],&a[i]);//交换首尾
    AdjustDown(a,1,i-1);//调整堆
  }
}

//归并排序
void merge(int a[],int left,int mid,int right){
  int leftArr[mid-left];
  int rightArr[right-mid+1];
  for(int i=left;i<mid;i++){
    leftArr[i-left]=a[i];
  }
  for(int i=mid;i<=right;i++){
    rightArr[i-mid]=a[i];
  }
  int p1=0,p2=0,p3=0;
  while(p1<mid-left&&p2<right-mid+1){
    if(leftArr[p1]>rightArr[p2]){
      a[p3++]=rightArr[p2++];
    }
    else{
      a[p3++]=leftArr[p1++];
    }
  }
  return;
}

void mergeSort()


//2021.12.16-----------------------------------
//深度优先遍历一张图是否存在从i到j的路径
bool existPathDfs(ALGraph G,int i,int j){
  if(i==j) return true;
  else{
    visited[i]=true;
    ArcNode *p=G.vertices[i].first;
    while(p){
      if(!visited[i]&&existPathDfs(G,p->adjvex,j){
        return true;
      }
    return false;
    }
  }
}

//广度有限遍历，一张图是否存在从i到j的路径？
bool existPathBfs(ALGraph G,int i,int j){
  if(i==j) return true;
  else{
    queue<int > q;
    while(!q.empty()){
      visited[q.front()]=ture;
      ArcNode *p=G.vertices[q.front()];
      q.pop();
      while(p){
        if(p->adjvex==j) return true;
        if(!visited[p->adjvex])
          q.push(p->adjvex);
        p=p->next;
      }
    }
  }
  return false;
}

