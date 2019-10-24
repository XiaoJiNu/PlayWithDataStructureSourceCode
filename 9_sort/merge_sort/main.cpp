//#include <iostream>
//
//#include <iostream>
//using namespace std;
//
//
//// 对数组a中的a[start, middle], a[middle + 1, end]两个数组进行合并。并保存到temp中. start并不一定指数组开头
//void merger(int a[], int temp[], int start, int middle, int end){
//    /*
//    先遍历a[start, middle], a[middle + 1, end]，并将它们的元素从小到在放置在temp相应位置。
//    遍历完成后就将它们剩下的元素复制到temp的后面为止
//    */
//    int startRecord = start, middleTemp = middle + 1;
//    int k = 0 ;
//    while (start <= middle && middleTemp <= end){
//        // 将a[start, middle], a[middle + 1, end]中小的元素依次放置到temp中
//        if (a[start] <= a[middleTemp]){
//            temp[k++] = a[start++];
//        } else{
//            temp[k++] = a[middleTemp++];
//        }
//    }
//
//    // a[start, middle], a[middle + 1, end]遍历完成后将其中一个数组剩余的元素放置到temp中
//    // if (i < middle){
//    if (start <= middle){
//            for (int m = start; m <= middle; m++){
//                temp[k++] = a[m];
//            }
//    }
//    if (middleTemp+1 <= end){
//        for (int m = middleTemp+1; m <= end; m++){
//            temp[k++] = a[m];
//        }
//    }
//
//    for (int i = 0; i < k; i++){
//        a[startRecord] = temp[i]; //
//    }
//}
//
//
//// 对于数组a,对间隔span的相邻两个数组进行两两合并到span
//void merge_method(int a[], int temp[], int span, int array_length){
//    int index = 0 ; // 存储当前下标
//    int j;
//    // 当 index + 2*span <= array_length -1 时，对间隔span的两个数组a[index..index+span-1] 和
//    // a[index+span..index+2span-1]归并此时 index <= array_length - 2*span - 1.
//    while (index <= array_length-2*span+1){
//        // 将a[index..index+span-1] 和 a[index+span..index+2span-1]归并排序，保存到temp中
//        merger(a, temp, index, index + span - 1, index + 2*span -1);
//        // 下一次进行归并排序的两个数组的开始元素位置为 index + 2 * span
//        index += 2 * span;
//    }
//
//    // 如果 array_length -1 - index > span, 证明剩下的元素长度至少比span大，所以依然可以将a[index..index+s-1]和
//    // a[index+s..array_length -1]进行归并。否则证明剩下的元素个数小于或者等于span，不能进行归并，直接将剩下的元素复制给temp即可
//    //    if (index < array_length - 1 - span){
//    if (index < array_length - span - 1){
//            merger(a, temp, index, index + span - 1, array_length - 1);
//    } else{
//        for (int i = index; i < array_length; ++i) {
//            temp[i] = a[i];
//        }
//    }
//}
//
//
//void merge_in(int a[], int array_length){
//    int span = 1;
//    int temp[array_length];
//
//    // 每次循环以间隔span的两个数组进行两两合并到temp中，直到间隔大于或者等于数组长度
//    while(span < array_length){
//        merge_method(a, temp, span, array_length);
//        span *= 2;  // 间隔每次增长2倍
//    }
//}
//
//
////typedef struct{
////    int a[] = {4,23,15,3,52,1,52,3,542,35,42};
////
////
////}SqList;
//
//
//int main() {
//    int a[] = {4,23,15,3,52,1,52,3,542,35,42};
//    int array_length = sizeof(a) / sizeof(*a);
//    merge_in(a, array_length);
//    for (auto ai : a) {
//        cout << ai << ' ' ;
//    }
//    cout << endl;
//    return 0;
//}
//
//
////
////
////
////
////
////
////
////
////
////
////
////
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */

typedef int Status;


#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */
typedef struct
{
    int r[MAXSIZE+1];	/* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
    int length;			/* 用于记录顺序表的长度 */
}SqList;


void print(SqList L)
{
    int i;
    for(i=1;i<L.length;i++)
        printf("%d,",L.r[i]);
    printf("%d",L.r[i]);
    printf("\n");
}

/* 归并排序********************************** */

/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
    int j,k,l;
    for(j=m+1,k=i;i<=m && j<=n;k++)	/* 将SR中记录由小到大地并入TR */
    {
        if (SR[i]<SR[j])
            TR[k]=SR[i++];
        else
            TR[k]=SR[j++];
    }
    if(i<=m)
    {
        for(l=0;l<=m-i;l++)
            TR[k+l]=SR[i+l];		/* 将剩余的SR[i..m]复制到TR */
    }
    if(j<=n)
    {
        for(l=0;l<=n-j;l++)
            TR[k+l]=SR[j+l];		/* 将剩余的SR[j..n]复制到TR */
    }
}


/* 非递归法 */
/* 将SR[]中相邻长度为s的子序列两两归并到TR[] */
void MergePass(int SR[],int TR[],int s,int n)
{
    int i=1;
    int j;
    while(i <= n-2*s+1)
    {/* 两两归并 */
        Merge(SR,TR,i,i+s-1,i+2*s-1);
        i=i+2*s;
    }
    if(i<n-s+1) /* 归并最后两个序列 */
        Merge(SR,TR,i,i+s-1,n);
    else /* 若最后只剩下单个子序列 */
        for(j =i;j <= n;j++)
            TR[j] = SR[j];
}

/* 对顺序表L作归并非递归排序 */
void MergeSort2(SqList *L)
{
    int* TR=(int*)malloc(L->length * sizeof(int));/* 申请额外空间 */
    int k=1;
    while(k<L->length)
    {
        MergePass(L->r,TR,k,L->length);
        k=2*k;/* 子序列长度加倍 */
        MergePass(TR,L->r,k,L->length);
        k=2*k;/* 子序列长度加倍 */
    }
}


/* **************************************** */
#define N 9
int main()
{
    int i;

    /* int d[N]={9,1,5,8,3,7,4,6,2}; */
    int d[N]={50,10,90,30,70,40,80,60,20};
    /* int d[N]={9,8,7,6,5,4,3,2,1}; */

    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;

    for(i=0;i<N;i++)
        l0.r[i+1]=d[i];
    l0.length=N;
    l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;

    printf("归并排序（非递归）:\n");
    MergeSort2(&l8);
    print(l8);

    return 0;
}




