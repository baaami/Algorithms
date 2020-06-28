/*
	이분 탐색
*/
#include <stdio.h>

int main()
{
	int n, result = -1;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	scanf("%d", &n);
	int left = 0, right = 9;			// 가장 왼쪽과 오른쪽 인덱스로 시작
	
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] > n) {
			right = mid - 1;
		}
		else if(arr[mid] < n)
		{
			left = mid + 1;
		}
		else {
			result = mid;
			break;
		}
	}

	printf("%d\n", result);
	return 0;
}