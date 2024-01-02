#include<stdio.h>
#include<stdlib.h>
int** input(int m, int N)
{
	int** aray;
	aray = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		aray[i] = (int*)malloc(N * sizeof(int));
	}
	return aray;
}
void sort(int** aray1,int N,int m)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = j; k < m; k++)
			{
				if (aray1[i][j] > aray1[i][k])
				{
					int t = aray1[i][j];
					aray1[i][j] = aray1[i][k];
					aray1[i][k] = t;
				}
			}
		}
	}
}
int answer(int** aray1, int** aray2,int **aray3,int N,int m)
{
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int w = aray1[i][j];
			int k = aray2[j][i];
			aray3[i][j]= aray1[i][j] * aray2[j][i];
			printf("%5d", aray3[i][j]);
		}
		printf("\n");
	}
	return ans;
}
int main()
{
	int N, m, ans,**aray1,**aray2,**aray3;
	printf("请输入m\n");
	scanf("%d", &m);
	printf("请输入N\n");
	scanf("%d", &N);
	aray1=input(m, N);
	aray2=input(N, m);
	aray3 = input(m, N);
	printf("请输入数组1的元素：\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &aray1[i][j]);
		}
	}
	printf("请输入数组2的元素：\n");
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &aray2[i][j]);
		}
	}
	sort(aray1, m, N);
	sort(aray2, N, m);
	ans = answer(aray1, aray2,aray3, N, m);
	for (int i = 0; i < N; ++i) {
		free(aray1[i]);
	}
	free(aray1);
	for (int i = 0; i < m; ++i) {
		free(aray2[i]);
	}
	free(aray2);
}