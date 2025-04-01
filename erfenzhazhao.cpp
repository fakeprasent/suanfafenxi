#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//二分查找
int binarysearch(int a[], int left, int right,int x)
{
	while (left<=right)
	{
		int middle = (left + right) / 2;
		if (x == a[middle])
			return middle;//递归调用
		if (x > a[middle])
			return binarysearch(a,middle+1,right,x);
		if (x < a[middle])
			right = middle - 1;
		return binarysearch(a, left, middle - 1, x);
	}
	return -1;
}

int main()
{
	int n;
	printf("请输入数组个数：\n");
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));//分配内存空间
	if (a == NULL)
	{
		fprintf(stderr, "memory allocation failed\n");
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		printf("请输入第%d个数\n", i+1);
		scanf("%d", &a[i]);
	}

	int x;
	printf("请输入要查找的值：\n");
	scanf("%d", &x);

	int result = binarysearch(a, 0, n-1, x);
	if(result != -1)
	{ 
		printf("你要查找值在第%d位\n",result+1);
	}
	else
	{
		printf("not fount\n");
	}
	free(a);
	return 0;
}