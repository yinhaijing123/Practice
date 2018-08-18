/********************************************************************************************************
问题描述：把n升水倒入m个相同的杯子中，计算有多少种分配方式？

思路分析：使用数组arr[n][m] 表示把n升水导入m个杯子的方法个数，则：可分两种情况：
		  1.n>m, 则必定有所有的杯子都有水的情况.  
		  故有几种情况：将n剩水倒入一个杯子中的情况arr[n][1],将n升水倒入两个杯子中的情况arr[n-2][2]...
		  则：arr[n][m]=arr[n][1]+arr[n-2][2]+...+arr[n-m][m] = arr[n][m-1]+arr[n-m][m];	  
		 
		 2.n<m, 则最多有n个杯子内有水。           故，可转化为arr[n][m]=arr[n][n]
*******************************************************************************************************/
#define MaxN 11
#include<iostream>

using namespace std;

//迭代实现
int GetMethod(int n,int m)
{
	int arr[MaxN][MaxN];
	int i,j;
	for(i=1;i<MaxN;++i)
	{
		arr[0][i]=1;                       //表示不剩空桶的情况 
		arr[i][1]=1;
	}
	
	for(i=1;i<=n;++i)
	{
		for(j=2;j<=m;++j)
		{
			if(i>=j)
				arr[i][j]=arr[i][j-1]+arr[i-j][j];
			else
				arr[i][j]=arr[i][i];
		}
	}
	return arr[n][m];
}

//递归实现
int _GetMethod(int n, int m)
{
    if (n == 0 || m == 1)
    {
        return 1;
    }

    if (n < m)
        return _GetMethod(n, n);
    else
        return _GetMethod(n, m-1)+_GetMethod(n-m, m);
}

int main()
{
	int n, m;
    cin >> n >> m;

    cout<< GetMethod(n, m)<<endl;
	
	return 0;
}