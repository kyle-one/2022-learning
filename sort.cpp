#include <cstdio>
using namespace std;

//冒泡排序
void bubbleSort(int a[],int len){
  for(int i=0;i<len-1;i++){
    for(int j=0;j<len-1-i;j++){
      if(a[j]>a[j+1]){
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}

//快速排序
int findPosition(int a[],int left,int right){
  int temp=a[left];
  wihle(left<right){
    //从右找小
    while(left<right && a[right]>=temp){ right--;}
    a[left]=a[right];
    //从左找大
    while(left<right && a[left]<=temp){left++;}
    a[right]=a[left]
  }
  
  a[left]=temp;
  return left;
}

void qucikSort(int a[],int left,int right){
  if(left>=right) return;
  int pos=findPosition(a,left,right);
  qucikSort(a,left,pos-1);
  qucikSort(a,pos+1,right);
}

//归并排序
void merge(int a[],int L,int R,int M){
  //数组，数组最左边，数组最右边，分割点
  int lArray[M-L];
  int rArray[R+1-M];
  
  //分为两个数组
  for(int i=0;i<M-L;i++){
    lArray[i]=a[L+i];
  }
  for(int i=0;i<R-M+1;j++){
    rArray[i]=a[M+i];
  }
  int i=j=0,k=L;
  
  //合并数组
  while(i<(M-L) || j<(R-M+1)){
    if(lArray[i]<rArray[j])
      a[k++]=lArray[i++];
    else
      a[k++]=rArray[j++];
  }
}

void mergeSort(int a[],int L,int R){
  if(L==R) return;
  int M=(L+R)/2;
  mergeSort(a,L,M);
  mergeSort(a,M+1,R);
  merge(a,L,M+1,R);
}

//插入排序
void insertSort(int a[],int len){
  for(int i=1;i<len;i++){
    int temp=a[i];
    //找到比a[i]小的值
    while(i>0 && temp<a[i-1]){
      a[i]=a[i-1];
      i--;
    }
    a[i]=temp;
  }
}

//选择排序
void selectSort(int a[],int len){
  for(int i=0;i<len-1;i++){
    int minIndex=i;
    for(int j=i+1;j<len;j++){
      if(a[minIndex]>a[j])
        minIndex=j;
    }
    int temp=a[minIndex];
    a[minIndex]=a[i];
    a[i]=temp;
  }
}

//希尔排序 数组下标从1开始
void shellSort(int a[],int len){
  int i,j,d;//d为步长
  for(d=len/2;d>=1;d/=2){//d 8->4->2->1
    for(i=d+1;i<=len;i++){//插入排序的范围
      if(a[i]<a[i-d]){//插入已排序数组
        int temp=a[i];
        for(j=i-d;j>0 && temp<a[j];j-=d){
          a[j+d]=temp;
        }
      }
    }
  }
}