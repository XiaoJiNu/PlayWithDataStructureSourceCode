//#include <iostream>
//
//#include <iostream>
//using namespace std;
//
//
//// ������a�е�a[start, middle], a[middle + 1, end]����������кϲ��������浽temp��. start����һ��ָ���鿪ͷ
//void merger(int a[], int temp[], int start, int middle, int end){
//    /*
//    �ȱ���a[start, middle], a[middle + 1, end]���������ǵ�Ԫ�ش�С���ڷ�����temp��Ӧλ�á�
//    ������ɺ�ͽ�����ʣ�µ�Ԫ�ظ��Ƶ�temp�ĺ���Ϊֹ
//    */
//    int startRecord = start, middleTemp = middle + 1;
//    int k = 0 ;
//    while (start <= middle && middleTemp <= end){
//        // ��a[start, middle], a[middle + 1, end]��С��Ԫ�����η��õ�temp��
//        if (a[start] <= a[middleTemp]){
//            temp[k++] = a[start++];
//        } else{
//            temp[k++] = a[middleTemp++];
//        }
//    }
//
//    // a[start, middle], a[middle + 1, end]������ɺ�����һ������ʣ���Ԫ�ط��õ�temp��
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
//// ��������a,�Լ��span����������������������ϲ���span
//void merge_method(int a[], int temp[], int span, int array_length){
//    int index = 0 ; // �洢��ǰ�±�
//    int j;
//    // �� index + 2*span <= array_length -1 ʱ���Լ��span����������a[index..index+span-1] ��
//    // a[index+span..index+2span-1]�鲢��ʱ index <= array_length - 2*span - 1.
//    while (index <= array_length-2*span+1){
//        // ��a[index..index+span-1] �� a[index+span..index+2span-1]�鲢���򣬱��浽temp��
//        merger(a, temp, index, index + span - 1, index + 2*span -1);
//        // ��һ�ν��й鲢�������������Ŀ�ʼԪ��λ��Ϊ index + 2 * span
//        index += 2 * span;
//    }
//
//    // ��� array_length -1 - index > span, ֤��ʣ�µ�Ԫ�س������ٱ�span��������Ȼ���Խ�a[index..index+s-1]��
//    // a[index+s..array_length -1]���й鲢������֤��ʣ�µ�Ԫ�ظ���С�ڻ��ߵ���span�����ܽ��й鲢��ֱ�ӽ�ʣ�µ�Ԫ�ظ��Ƹ�temp����
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
//    // ÿ��ѭ���Լ��span������������������ϲ���temp�У�ֱ��������ڻ��ߵ������鳤��
//    while(span < array_length){
//        merge_method(a, temp, span, array_length);
//        span *= 2;  // ���ÿ������2��
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

#define MAX_LENGTH_INSERT_SORT 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */

typedef int Status;


#define MAXSIZE 10000  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
typedef struct
{
    int r[MAXSIZE+1];	/* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
    int length;			/* ���ڼ�¼˳���ĳ��� */
}SqList;


void print(SqList L)
{
    int i;
    for(i=1;i<L.length;i++)
        printf("%d,",L.r[i]);
    printf("%d",L.r[i]);
    printf("\n");
}

/* �鲢����********************************** */

/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
    int j,k,l;
    for(j=m+1,k=i;i<=m && j<=n;k++)	/* ��SR�м�¼��С����ز���TR */
    {
        if (SR[i]<SR[j])
            TR[k]=SR[i++];
        else
            TR[k]=SR[j++];
    }
    if(i<=m)
    {
        for(l=0;l<=m-i;l++)
            TR[k+l]=SR[i+l];		/* ��ʣ���SR[i..m]���Ƶ�TR */
    }
    if(j<=n)
    {
        for(l=0;l<=n-j;l++)
            TR[k+l]=SR[j+l];		/* ��ʣ���SR[j..n]���Ƶ�TR */
    }
}


/* �ǵݹ鷨 */
/* ��SR[]�����ڳ���Ϊs�������������鲢��TR[] */
void MergePass(int SR[],int TR[],int s,int n)
{
    int i=1;
    int j;
    while(i <= n-2*s+1)
    {/* �����鲢 */
        Merge(SR,TR,i,i+s-1,i+2*s-1);
        i=i+2*s;
    }
    if(i<n-s+1) /* �鲢����������� */
        Merge(SR,TR,i,i+s-1,n);
    else /* �����ֻʣ�µ��������� */
        for(j =i;j <= n;j++)
            TR[j] = SR[j];
}

/* ��˳���L���鲢�ǵݹ����� */
void MergeSort2(SqList *L)
{
    int* TR=(int*)malloc(L->length * sizeof(int));/* �������ռ� */
    int k=1;
    while(k<L->length)
    {
        MergePass(L->r,TR,k,L->length);
        k=2*k;/* �����г��ȼӱ� */
        MergePass(TR,L->r,k,L->length);
        k=2*k;/* �����г��ȼӱ� */
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

    printf("�鲢���򣨷ǵݹ飩:\n");
    MergeSort2(&l8);
    print(l8);

    return 0;
}




