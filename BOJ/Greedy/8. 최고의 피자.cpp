#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 1원당 열량이 가장 높은 피자 == 최고의 피자

	int n; cin >> n;		// 토핑의 종류 수
	int A; int B;			// dow, topping의 가격
	int dow_cal; 
	int total_cal = 0; int price = 0;		// 총 열량, 총 가격
	vector<int> topping_cal(n);	// 각 토핑들의 열량
	cin >> A >> B;
	cin >> dow_cal;			// 도우의 열량
	for (int i = 0; i < n; i++)
	{
		cin >> topping_cal[i];
	}

	total_cal = dow_cal;
	price = A;
	sort(topping_cal.begin(), topping_cal.end());
	reverse(topping_cal.begin(), topping_cal.end());
	// 가장 열량이 높은 칼로리부터 순서대로 선택해보자
	for (int i = 0; i < n; i++)
	{
		// 1원당 열량이 더 높아지면 토핑 선택
		if ((total_cal + topping_cal[i]) / (price + B) >= total_cal / price)
		{
			price += B;
			total_cal += topping_cal[i];
		}
		else {
			break;
		}
	}

	// 위 조건 중 토핑을 선택해도되고 안해도된다.
	cout << total_cal/price;
	
	return 0;
}