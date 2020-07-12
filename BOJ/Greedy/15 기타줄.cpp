#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 새로운 줄을 사거나 교체해야 한다.
	// 6줄 패키지를 살 수도있고, 1개 또는 그 이상의 줄을 낱개로 살 수도 있다.
	int n;	 cin >> n;		// 끊어진 기타줄의 개수
	int m;	 cin >> m;		// 기타줄 브랜드
	int package, one, a, b, price1(1000), price2(1000), price3(1000);
	vector<int> min_package;
	vector<int> min_one;
	// 굳이 브랜드를 나눌 필요 없다.
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		min_package.push_back(a);
		min_one.push_back(b);
	}
	package = *min_element(min_package.begin(), min_package.end());
	one = *min_element(min_one.begin(), min_one.end());


	// 기타줄이 6개 이하인 경우?
	if (n % 6 != 0)
	{
		// 패키지로만
		price1 = (n / 6 + 1) * package;
		// 패키지 + 낱개
		price2 = ((n / 6) * package) + ((n % 6) * one);
	}
	else
	{
		price1 = (n / 6) * package;
	}
	// 낱개
	price3 = n * one;

//	cout << price1 << " " << price2 << " " << price3 << endl;
	cout << min(price1, min(price2, price3));
	
	return 0;
}