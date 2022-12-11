# Sorting_method_comparison
compare different sort method, like bubblesort and quicksort, calculate their time complexity

对常见排序算法的时间复杂度比较，使用真实的计时函数

大二上 数据结构作业实验设计代码



![image](https://user-images.githubusercontent.com/92865821/206882878-95d9eae8-7033-474c-8f8c-fdafa8fa7c21.png)


1.生成三组数据，包括从小到大的N个整数(N>=3000)，从大到小的N的整数
(N=3000)和利用随机函数产生N个随机整数(N>=3000)。

2.对每一组数据分别采用五种排序方法进行排序，并记录每种方法的比较次数、移动次数和运行时间。

3．找出其中两种较快的排序方法，并分别比较它们在最好情况、最坏情况和平均情况下的性能。

4．根据实验数据分析各种排序方法的时空性能及适用场合，并给出结论。

## 在进行实验时，注意了以下几点 

1为了获得更精确的性能数据，应尽可能多地重复实验，并取平均值。

2在比较各种排序方法的性能时，应同时考虑时间复杂度和空间复杂度

3 一些算法在最好情况下，对3000个数据的排序时间不足1毫秒，这个时候应该增加精度，计算微秒和纳秒，使用#include <chrono>库函数调用std::chrono::high_resolution_clock::now()来实现。

4为提高编程效率，使用函数指针来将函数作为参数传入计时函数

typedef void (*Func)(int num[], int n);	
//排序函数，数据，数据量，重复次数
void Measure_time(Func func,int num[], int n, int loopcount) 

 ![image](https://user-images.githubusercontent.com/92865821/206883036-e7f4a46d-d4e3-4520-baad-25322445da32.png)


5使用 clock() 函数来计算函数的运行时间是不准确的，因为该函数的精度只能达到毫秒级别，而不能达到微妙或纳秒级别。其次，该函数还受到操作系统的时钟滴答频率的限制，导致其精度还不够高。

  
  
  # Conclusion: 
  
  直接插入排序
时间复杂度：O(n^2)
空间复杂度：O(1)
适用场合：输入的数据较有序时

起泡排序
时间复杂度：O(n^2)
空间复杂度：O(1)
适用场合：输入的数据较有序时

快速排序
时间复杂度：O(nlogn)，最坏情况下为O(n^2)
空间复杂度：O(logn)
适用场合：一般情况

堆排序
时间复杂度：O(nlogn)
空间复杂度：O(1)
适用场合：不要求稳定性的排序

归并排序
时间复杂度：O(nlogn)
空间复杂度：O(n)
适用场合：需要稳定性的排序

使用STL中algorithm的sort函数
时间复杂度：O(nlogn)，最坏情况下为O(n^2)
空间复杂度：O(logn)
适用场合：一般情况

![image](https://user-images.githubusercontent.com/92865821/206883087-29ace9dd-f1ee-4e53-b9c8-59f89efcd641.png)
![image](https://user-images.githubusercontent.com/92865821/206883088-42eda522-0dd0-415d-b5e2-0487533776e3.png)
![image](https://user-images.githubusercontent.com/92865821/206883090-923d454b-12e1-4467-b626-b9e5c173bfcc.png)
![image](https://user-images.githubusercontent.com/92865821/206883091-168fa0b5-2905-4216-b1b4-a7830a60f798.png)



需要注意的是，上述时间和空间复杂度都是理论值，实际使用中会受到很多因素的影响，例如数据集的状态、硬件环境等。
