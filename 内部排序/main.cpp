#include <iostream>
using namespace std;
#include <fstream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define LS(a,b) ((a)<(b)) //define a<b
#define LL(a,b) ((a)>(b)) // define a>b
#define MAXSIZE 10000

typedef int KeyType;
typedef struct {
    KeyType key;
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
    int length;
}SqList;

int compare=0;
int change=0;
int Create_Sq(SqList &L)
{
    int k;
    cout<<"请输入要进行排序的数的个数--排序数由系统随机产生（要求个数不小于100）:";
    cin>>k;
    L.length=k;
    srand(time(NULL));
    for (int x=1; x<=k; x++)
    {
        L.r[x].key= rand() % k;//随机域为0~k
    }
    return 1;
}
void Bubble_sort(SqList &L)//冒泡排序
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int i,j,l,k=L.length,m=0,n=0;
    for(i=1;i<=L.length-1;++i){
        for(j=1;j<=k-1;++j){
            ++m;
            if(LL(L.r[j].key,L.r[j+1].key)){
                l=L.r[j].key;
                L.r[j].key=L.r[j+1].key;
                L.r[j+1].key=l;
                ++n;
            }
        }
        --k;
    }
    cout<<endl<<"-----冒泡排序后的序列-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"冒泡排序的比较次数:";
    cout<<m<<endl;
    cout<<"冒泡排序的交换次数:";
    cout<<n<<endl;
    out<<endl<<"-----冒泡排序后的序列-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"冒泡排序的比较次数:";
    out<<m<<endl;
    out<<"冒泡排序的交换次数:";
    out<<n<<endl;
    out.close();
}

void InsertSort(SqList &L)//插入排序
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int i,j,m=0,n=0;
    cout<<endl;
    for(i=2;i<=L.length;++i)
        if(LS(L.r[i].key,L.r[i-1].key))
        {
            ++m;
            ++n;
            L.r[0]=L.r[i];
            L.r[i]=L.r[i-1];
            for(j=i-2;LS(L.r[0].key,L.r[j].key);--j)
            {
                ++m;
                L.r[j+1]=L.r[j];
            }
            L.r[j+1]=L.r[0];
        }
    cout<<"-----直接插入排序后的序列-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"直接插入排序的比较次数:";
    cout<<m<<endl;
    cout<<"直接插入排序的交换次数:";
    cout<<n<<endl;
    out<<"-----直接插入排序后的序列-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"直接插入排序的比较次数:";
    out<<m<<endl;
    out<<"直接插入排序的交换次数:";
    out<<n<<endl;
    out.close();
}

void SelectSort(SqList &L) //简单选择排序
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int l,i,j,m=0,n=0;
    cout<<endl;
    for(i=1;i<L.length;++i){
        L.r[0]=L.r[i];
        j=i+1;
        l=i;
        for(;j<=L.length;++j){
            ++m;
            if(LL(L.r[0].key,L.r[j].key)){
                l=j;
                L.r[0]=L.r[j];
            }
        }
        if(l!=i){
            ++n;
            L.r[l]=L.r[i];
            L.r[i]=L.r[0];
        }
    }
    cout<<"-----简单选择排序后的序列-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"简单选择排序的比较次数:";
    cout<<m<<endl;
    cout<<"简单选择排序的交换次数:";
    cout<<n<<endl;
    out<<"-----简单选择排序后的序列-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"简单选择排序的比较次数:";
    out<<m<<endl;
    out<<"简单选择排序的交换次数:";
    out<<n<<endl;
    out.close();
}

int Partition(SqList &L,int low,int high){
    int pivotkey;
    L.r[0]=L.r[low];
    pivotkey=L.r[low].key;
    while(low<high){
        while(low<high&&L.r[high].key>=pivotkey){
            ++compare;
            --high;
        }
        ++change;
        L.r[low]=L.r[high];
        while(low<high&&L.r[low].key<=pivotkey){
            ++compare;
            ++low;
        }
        ++change;
        L.r[high]=L.r[low];
    }
    L.r[low]=L.r[0];
    return low;
}

void QSort(SqList &L,int low,int high)//递归形式的快速排序算法
{
    int pivotloc;
    if(low<high){
        pivotloc=Partition(L,low,high);
        QSort(L,low,pivotloc-1);
        QSort(L,pivotloc+1,high);
    }
}

void QuickSort(SqList &L)
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int i;
    QSort(L,1,L.length);
    cout<<"-----快速排序后的序列为-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"快速排序的比较次数:";
    cout<<compare<<endl;
    cout<<"快速排序的交换次数:";
    cout<<change<<endl;
    out<<"-----快速排序后的序列为-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"快速排序的比较次数:";
    out<<compare<<endl;
    out<<"快速排序的交换次数:";
    out<<change<<endl;
    out.close();
    compare=0;
    change=0;
}

void ShellInsert(SqList &L,int dk)//希尔排序
{
    int i;
    int j;
    for(i=dk+1;i<=L.length;++i)
        if(LS(L.r[i].key,L.r[i-dk].key)){
            ++compare;
            L.r[0]=L.r[i];
            for(j=i-dk;j>0&&LS(L.r[0].key,L.r[j].key);j-=dk){
                ++compare;
                ++change;
                L.r[j+dk]=L.r[j];
            }
            L.r[j+dk]=L.r[0];
        }
}
void ShellSort(SqList &L,int dlta[])//希尔排序
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int k,j=L.length/2,t=0;
    while(j>=0){
        ++t;
        j-=2;
    }
    j=L.length/2;
    for(k=0;k<t;++k)//计算每次的增量值
    {
        if(j==0)
            j=1;//定义最后一趟排序的增量
        dlta[k]=j;
        j-=2;
    }
    for(k=0;k<t;++k)
    ShellInsert(L,dlta[k]);
    cout<<"-----希尔排序后的序列为-----"<<endl;
    for(k=1;k<=L.length;k++)
        cout<<" "<<L.r[k].key;
    cout<<endl;
    cout<<"希尔排序的比较次数:";
    cout<<compare<<endl;
    cout<<"希尔排序的交换次数:";
    cout<<change<<endl;
    out<<"-----希尔排序后的序列为-----"<<endl;
    for(k=1;k<=L.length;k++)
        out<<" "<<L.r[k].key;
    out<<endl;
    out<<"希尔排序的比较次数:";
    out<<compare<<endl;
    out<<"希尔排序的交换次数:";
    out<<change<<endl;
    out.close();
    compare=0;
    change=0;
}

int main()
{
    char flag;
    do{
        int i;
        int dlta[MAXSIZE];
        int tem;
        SqList L,a,b,c,d;
        cout<<"-----------------------------------------主菜单-----------------------------------"<<endl;
        cout<<"-----------------------------------内部排序算法的比较-----------------------------"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        for(tem=0;tem<6;tem++)
        {
            ofstream out;
            if(tem==0){
                out.open("sort.txt");
            }else{
                out.open("sort.txt",ios::app);
            }
            cout<<"第"<<tem+1<<"组排序数比较"<<endl;
            out<<"第"<<tem+1<<"组排序数比较"<<endl;
            Create_Sq(L);
            a=b=c=d=L;
            for(i=1;i<=L.length;i++)
            {
                cout<<" "<<L.r[i].key;
                out<<" "<<L.r[i].key;
                if(i%20==0) out<<endl;
            }
            out.close();
            Bubble_sort(L);
            InsertSort(a);
            SelectSort(b);
            QuickSort(c);
            ShellSort(d,dlta);
        }
        cout<<"是否继续第二次测试?";
        cin>>flag;
    }while(flag=='y'||flag=='Y');
    return 0;
}
