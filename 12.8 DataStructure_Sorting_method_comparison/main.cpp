
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <algorithm>

#define N 3000
using namespace std;
int ascend[N+1],descend[N+1],random[N+1];

//随机数初始化
void Initialization(){
    //初始化升序数组
    for (int i = 0; i < 3000; i++) {
        ascend[i] = i;
    }
    //初始化降序数组
    for (int i = 0; i < 3000; i++) {
        descend[i] = 3000 - i;
    }
    //初始化随机数组
    srand((unsigned)time(0));
    for (int i = 0; i < 3000; i++) {
        random[i] = rand();
    }
}
//数组传参类型
typedef void (*Func)(int num[], int n);

//时间精确测量
void Measure_time(Func func,int num[], int n, int loopcount) {
    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();

    // 循环调用 func 函数 loopcount 次
    for (int i = 0; i < loopcount; ++i) {
        func(num,n);
    }
    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();
    // 计算总时间
    auto duration = end - start;
    // 计算平均时间
    auto avg_duration = duration / loopcount;
    // 输出平均时间，并将其转换为毫秒、微秒和纳秒
    cout << "Average time: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(avg_duration)
            .count() << " ms, "
    << std::chrono::duration_cast<std::chrono::microseconds>(avg_duration)
            .count() << " us, "
    << std::chrono::duration_cast<std::chrono::nanoseconds>(avg_duration)
            .count() << " ns" << endl;
    }

uint64_t millis()
{
    uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    return ms;
}

// Get time stamp in microseconds.
uint64_t micros()
{
    uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    return us;
}

// Get time stamp in nanoseconds.
uint64_t nanos()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    return ns;
}
void InsertSort(int arr[], int len)
{
    // 数值比较次数和移动次数计数器
    int compare_count = 0;
    int move_count = 0;

    // 记录开始时间
    clock_t start_time = micros();

    // 从第2个元素开始插入
    for (int i = 1; i < len; i++)
    {
        // 将第i个元素插入到前面的有序序列中
        for (int j = i; j > 0; j--)
        {
            // 比较第j个元素与前面的元素，并移动次数计数器
            compare_count++;
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                move_count++;
            }
                // 如果比它前面的元素大，就停止比较，跳出循环
            else
            {
                break;
            }
        }
    }

    // 记录结束时间
    clock_t end_time = micros();

    // 输出排序结果
    //cout << "Sorted Array is:";
    //for (int i = 0; i < len; i++)
    // {
    //    cout << arr[i] << " ";
    //  }
    // cout << endl;//
    //cout<<"Data Sorted";

    // 输出数值比较次数、移动次数和运行时间
    cout << "Amount of comparison :  " << compare_count << endl;
    cout << "Amount of movement :  " << move_count << endl;
   // cout << "Time consuming is:" << (end_time - start_time) << " micro seconds" << endl;

}
void BubbleSort(int arr[], int len)
{
    // 数值比较次数和移动次数计数器
    int compare_count = 0;
    int move_count = 0;
    // 记录开始时间
    clock_t start_time = micros();
    for (int i = 0; i < len - 1; i++) {
        // 每次从后往前比较相邻的两个元素，如果顺序错误就交换位置
        for (int j = len - 1; j > i; j--) {
            compare_count++;
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                move_count++;
            }
        }
    }


    // 记录结束时间
    clock_t end_time = micros();

    // 输出数值比较次数、移动次数和运行时间
    cout << "Amount of comparison :  " << compare_count << endl;
    cout << "Amount of movement :  " << move_count << endl;
    // cout << "Time consuming is:" << (end_time - start_time) << " micro seconds" << endl;
}
void subquickSort(int a[], int left, int right,int *compare,int *move);
void QuickSort(int arr[], int len)
{
    // 数值比较次数和移动次数计数器
    int compare_count = 0;
    int move_count = 0;

    subquickSort(arr,0,len,&compare_count,&move_count);

    // 输出数值比较次数、移动次数和运行时间
    cout << "Amount of comparison :  " << compare_count << endl;
    cout << "Amount of movement :  " << move_count << endl;

}
void subquickSort(int a[], int left, int right,int *compare,int *move) {
    // 如果左端点小于右端点，说明还有两个及以上的元素需要排序
    if (left < right) {
        // 选择基准元素
        int pivot = a[left];
        // 定义两个指针，分别指向数组的左端点和右端点
        int i = left;
        int j = right;
        // 开始排序

        while (i < j) {

            // 如果右端点的元素大于基准元素，则右端点指针左移
            while (i < j && a[j] >= pivot) {
                j--;(*compare)++;
            }
            // 如果左端点的元素小于基准元素，则左端点指针右移
            while (i < j && a[i] <= pivot) {
                i++;(*compare)++;
            }
            // 如果两个指针没有相遇，则交换它们所指向的元素
            if (i < j) {
                swap(a[i], a[j]);
                (*move)++;
            }
        }
        // 将基准元素放置到两个指针相遇的位置
        a[left] = a[i];
        a[i] = pivot;
        // 对基准元素的左侧和右侧分别进行快速排序
        subquickSort(a, left, i - 1,compare,move);
        subquickSort(a, i + 1,right , compare,move);
    }
}
void heapify(int arr[], int n, int i,int *compare,int *move);
void HeapSort(int arr[], int n) {
    // 建立堆
    // 数值比较次数和移动次数计数器
    int compare_count = 0;
    int move_count = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i,&compare_count,&move_count);
    }

    // 逐个取出堆顶元素并重构堆
    for (int i = n - 1; i >= 0; i--) {
    // 将堆顶元素与末尾元素交换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
    // 重构堆
        heapify(arr, i, 0,&compare_count,&move_count);
    }
    // 输出数值比较次数、移动次数和运行时间
    cout << "Amount of comparison :  " << compare_count << endl;
    cout << "Amount of movement :  " << move_count << endl;

}

// 堆调整函数
void heapify(int arr[], int n, int i, int *compare,int *move) {
// 左子节点索引
    int left = 2 * i + 1;
// 右子节点索引
    int right = 2 * i + 2;

// 寻找最大值
    int largest = i;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        (*compare)++;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        (*compare)++;
    }

// 如果最大值不是当前节点，交换并递归调整堆
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*move)++;
        heapify(arr, n, largest,compare,move);

    }
}
//在这段代码中，heap_sort 函数是堆排序函数，它接受一个整型数组 arr[] 和数组元素个数 n 作为参数。
// 它首先通过 heapify 函数建立堆，然后逐个取出堆顶元素并重构堆，完成排序。
//heapify 函数是堆调整函数，它接受整型数组 arr[]，数组元素个数 n 和堆的根节点索引 i 作为参数

int Mergecompare=0,Mergemove=0;
void merge(int arr[], int mid, int n,int *compare,int *move);
void MergeSort(int arr[], int n) {
    // 数值比较次数和移动次数计数器
    int compare_count = 0;
    int move_count = 0;

// 递归结束条件：如果待排序数组长度为 1，则无需排序
    if (n == 1) {
        return;
    }
// 计算中点
    int mid = n / 2;
// 分别对左右两部分进行归并排序
    MergeSort(arr, mid);
    MergeSort(arr + mid, n - mid);

// 合并已排序的两部分
    merge(arr, mid, n,&compare_count,&move_count);

}
void merge(int arr[], int mid, int n,int *compare,int *move) {
// 临时数组，用于保存合并的结果
    int *temp = new int[n];

// 左右两部分的指针
    int left = 0, right = mid;

// 指向临时数组的指针
    int p = 0;

// 当左右两部分均有数据时
    while (left < mid && right < n) {
        (Mergecompare)++;
        if (arr[left] <= arr[right]) {
            temp[p++] = arr[left++];
        } else {
            temp[p++] = arr[right++];
        }
    }
// 如果左边部分还有数据，则将剩余的数据拷贝到临时数组
    while (left < mid) {
        (Mergecompare)++;
        (Mergemove)++;
        temp[p++] = arr[left++];
    }
// 如果右边部分还有数据，则将剩余的数据拷贝到临时数组
    while (right < n) {
        (Mergecompare)++;
        (Mergecompare)++;
        temp[p++] = arr[right++];
    }
// 将临时数组中的数据拷贝回原数组
    for (int i = 0; i < n; i++) {
        (Mergecompare)++;
        arr[i] = temp[i];
    }
// 释放临时数组

    delete[] temp;
}

void STLSort(int arr[],int n){

    sort(arr,arr+n);
}
//
int main() {
    Initialization();//初始化数组
    //排序函数，数据，数据量，重复次数
    cout<<"###1 InsertSort###"<<endl;
    cout<<"InsertSort 1.Ascend:"<<endl;
    Measure_time(InsertSort,ascend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"InsertSort 2.Descend:"<<endl;
    Measure_time(InsertSort,descend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"InsertSort 3.Random:"<<endl;
    Measure_time(InsertSort,random,3000,1);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    Initialization();//初始化数组
    cout<<"###2 BubbleSort###"<<endl;
    cout<<"bubbleSort 1.Ascend:"<<endl;
    Measure_time(BubbleSort,ascend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"bubbleSort 2.Descend:"<<endl;
    Measure_time(BubbleSort,descend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"bubbleSort 3.Random:"<<endl;
    Measure_time(BubbleSort,random,3000,1);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    Initialization();//初始化数组
    cout<<"###3 QuickSort###"<<endl;
    cout<<"QuickSort 1.Ascend:"<<endl;
    Measure_time(QuickSort,ascend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"QuickSort 2.Descend:"<<endl;
    Measure_time(QuickSort,descend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"QuickSort 3.Random:"<<endl;
    Measure_time(QuickSort,random,3000,1);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    Initialization();//初始化数组
    cout<<"###4 HeapSort###"<<endl;
    cout<<"HeapSort 1.Ascend:"<<endl;
    Measure_time(HeapSort,ascend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"HeapSort 2.Descend:"<<endl;
    Measure_time(HeapSort,descend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"HeapSort 3.Random:"<<endl;
    Measure_time(HeapSort,random,3000,1);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    Initialization();//初始化数组
    cout<<"###5 MergeSort###"<<endl;
    cout<<"MergeSort 1.Ascend:"<<endl;
    cout << "Amount of comparison :  " << Mergecompare << endl;
    cout << "Amount of movement :  " << Mergemove << endl;
    Mergecompare=0;Mergemove=0;
    Measure_time(MergeSort,ascend,3000,1);

    cout<<"--------------------"<<endl;
    cout<<"MergeSort 2.Descend:"<<endl;
    cout << "Amount of comparison :  " << Mergecompare << endl;
    cout << "Amount of movement :  " << Mergemove << endl;
    Mergecompare=0;Mergemove=0;
    Measure_time(MergeSort,descend,3000,1);

    cout<<"--------------------"<<endl;
    cout<<"MergeSort 3.Random:"<<endl;
    cout << "Amount of comparison :  " << Mergecompare << endl;
    cout << "Amount of movement :  " << Mergemove << endl;
    Mergecompare=0;Mergemove=0;
    Measure_time(MergeSort,random,3000,1);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    Initialization();//初始化数组
    cout<<"###6 Sort with STL###"<<endl;
    cout<<"STLSort 1.Ascend:"<<endl;
    Measure_time(STLSort,ascend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"STLSort 2.Descend:"<<endl;
    Measure_time(STLSort,descend,3000,1);
    cout<<"--------------------"<<endl;
    cout<<"STLSort 3.Random:"<<endl;
    Measure_time(STLSort,random,3000,1);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    return 0;
}
