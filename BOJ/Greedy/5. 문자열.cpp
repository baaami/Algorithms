#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string a, b;
	int i, j;
	cin >> a >> b;
	int index = 0; int min = 50;
	while (1)
	{
		int dif = 0;
		for (i = 0, j = index; j < a.length() + index; (i++, j++))
		{
			if (b[j] != a[i])
			{
				dif++;
			}
		}
		if (min > dif)
		{
			min = dif;
		}
		if (a.length() + index == b.length())
		{
			break;
		}
		index++;
	}
	
	cout << min;
	return 0;
}