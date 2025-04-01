﻿//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//    int n;
//    printf("Please input number: ");
//    scanf("%d", &n);  // 读取 n 的值
//
//    int* a = (int*)malloc(n*sizeof(int));  // 在读取 n 的值之后声明数组（动态内存存储）
//
//    for (int i = 0; i < n; i++)
//    {
//        printf("Input number %d: ", i + 1);
//        scanf("%d", &a[i]);  // 读取数组中的每个元素
//    }
//    for (int i = 0; i < n-1; i++)    //冒泡排序算法
//    {
//        for (int j = 0; j < n-1-i; j++)
//        {
//            if (a[j] > a[j + 1])
//            {
//                int temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        printf("Number %d: %d\n", i + 1, a[i]);  // 输出数组中的每个元素
//    }
//    free(a);
//    return 0;
//}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// //冒泡排序函数
//void bubblesort(int* array, int size) 
// {
//    for (int i = size - 1; i > 0; i--) 
// {
//        for (int j = 0; j < i; j++) 
//      {
//            if (array[j] > array[j + 1]) 
//            {
//                // 交换 array[j] 和 array[j + 1]
//                int temp = array[j];
//                array[j] = array[j + 1];
//                array[j + 1] = temp;
//            }
//        }
//    }
//}


//分间函数
int partition(int* array, int low,int high)
{
    int pivotkey = array[low];
    while (low < high)
    {
        while (low < high && array[high] >= pivotkey)
            --high;
        array[low] = array[high];
        while (low < high && array[low] <= pivotkey)
            ++low;
        array[high] = array[low];
    }
    array[low] = pivotkey;
    return low;
}

//快速排序函数
void quicksort(int* array, int low, int high)
{
    if (low < high)
    {
        int piovt = partition( array,low, high);
        quicksort(array, low, piovt - 1);
        quicksort(array, piovt + 1, high);
    }
}

int main() {
    int n;
    printf("please input number of elements: ");
    scanf("%d", &n);  // 读取元素个数

    int* a = (int*)malloc(n * sizeof(int));  // 分配内存，动态内存分布
    if (a == NULL) //函数合法性
    {
        fprintf(stderr, "memory allocation failed\n");
        return 1;
    }


    // 输入数组元素
    for (int i = 0; i < n; i++) {
        printf("input number %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // 对数组进行冒泡排序
    /*bubblesort(a, n);*/
    //对数组进行快速排序
    quicksort(a, 0, n - 1);

    // 输出排序后的数组元素
    for (int i = 0; i < n; i++) 
    {
        printf("number %d: %d\n", i + 1, a[i]);
    }

    // 释放内存
    free(a);

    return 0;
}