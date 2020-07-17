#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
class Circle
{
private:
	float values[50] = { 0, };
	int top = 0;
	int max_cnt = 0;
public:
	void setTop(int value)
	{
		top = value;
	}
	void setValues(float _values[], int cnt)
	{
		max_cnt = cnt;
		for (int i = 0; i < 50; i++)
		{
			values[i] = _values[i];
		}
	}
	void setValue(int idx, float value)
	{
		values[idx] = value;
	}
	void turn(int value, int dir)
	{
		for (int qwe = 0; qwe < value; qwe++) {
			if (dir == 1) //반시계방향
			{
				top = top + value;
				if (top >= max_cnt) top = top - max_cnt;
				int temp = values[0];
				for (int i = 1; i < max_cnt; i++)
				{
					values[i - 1] = values[i];
				}
				values[max_cnt - 1] = temp;
			}
			else if (dir == 0)  //시계방향
			{
				top = top - value;
				if (top < 0) top = top + max_cnt;
				int temp = values[max_cnt - 1];
				for (int i = max_cnt - 1; i > 0; i--)
				{
					values[i] = values[i - 1];
				}
				values[0] = temp;
			}
		}
	}
	float getValue(int idx)
	{
		return values[idx];
	}
	float getTotal()
	{
		float sum = 0;
		for (int i = 0; i < max_cnt; i++)
		{
			sum += values[i];
		}
		return sum;
	}
	void deleteValue(int idx)
	{
		values[idx] = 0;
	}
	void avrMinus()
	{
		float sum = 0;
		float avr = 0;
		for (int i = 0; i < max_cnt; i++)
		{
			sum += values[i];
		}
		for (int i = 0; i < max_cnt; i++)
		{
			if (values[i] < avr)
			{
				values[i]++;
			}
			else if (values[i] > avr)
			{
				values[i]--;
			}
		}
	}
	int getCnt()
	{
		int cnt = 0;
		for (int i = 0; i < max_cnt; i++)
		{
			if ((int)values[i] != int(0.0))
			{
				cnt++;
			}
		}
		return cnt;
	}
};

int main()
{
	Circle circle[52];
	int N = 0;		//원판수
	int M = 0;		//숫자갯수
	int T = 0;		//회전수
	scanf("%d %d %d", &N, &M, &T);
	//read Data
	for (int qwe = 1; qwe < N + 1; qwe++)
	{
		float temp_values[50] = { 0, };
		for (int wer = 0; wer < M; wer++)
		{
			scanf("%f", &temp_values[wer]);
		}
		circle[qwe].setValues(temp_values, M);			// m 개만큼 배열에 담음
	}
	printf("\n입력 후\n");
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%f ", circle[i].getValue(j));
		}
		printf("\n");
	}

	int xi = 0;		//xi의 배수
	int di = 0;		//di 방향, 0 : 시계, 1: 반시계
	int ki = 0;		//ki 칸수 회전
	//회전하고 지우고
	for (int dfg = 0; dfg < T; dfg++)
	{	//회전
		scanf("%d %d %d", &xi, &di, &ki);
		for (int wer = xi; wer <= N; wer = wer + xi)			// xi 배수만큼
		{
			circle[wer].turn(ki, di);							// 회전
		}
		printf("\n회전 후\n");
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%f ", circle[i].getValue(j));
			}
			printf("\n");
		}
		//지우기
		int del_cnt = 0;
		for (int wer = 1; wer <= N; wer++)
		{
			for (int ert = 0; ert < M; ert++)
			{
				int comp = circle[wer].getValue(ert);
				if (comp == 0) continue;
				int left = ert - 1;
				if (left < 0) left = M - 1;
				int right = ert + 1;
				if (right > M - 1) right = 0;
				if (circle[wer].getValue(left) == comp)
				{
					circle[wer].deleteValue(left);
					circle[wer].deleteValue(ert);
					del_cnt++;
				}
				if (circle[wer].getValue(right) == comp)
				{
					circle[wer].deleteValue(right);
					circle[wer].deleteValue(ert);
					del_cnt++;
				}
				if (circle[wer - 1].getValue(ert) == comp)
				{
					circle[wer - 1].deleteValue(ert);
					circle[wer].deleteValue(ert);
					del_cnt++;
				}
				if (circle[wer + 1].getValue(ert) == comp)
				{
					circle[wer + 1].deleteValue(ert);
					circle[wer].deleteValue(ert);
					del_cnt++;
				}
			}
		}
		// 같은게 있으면 지우고 없으면 아래 조건
		printf("del count = %d\n", del_cnt);
		if (del_cnt == 0)
		{
			float sum = 0;
			float avr = 0;
			float ValCnt = 0;
			for (int asd = 1; asd < N; asd++)
			{
				sum += circle[asd].getTotal();
				ValCnt += circle[asd].getCnt();
				printf("avr = %f\n", avr);
				printf("sum = %f\n", sum);
				printf("valcnt = %f\n", ValCnt);
			}
			avr = sum / ValCnt;
			printf("avr = %f\n", avr);
			printf("sum = %f\n", sum);
			printf("valcnt = %f\n", ValCnt);
			///////+1 -1
			for (int asd = 1; asd <= N; asd++)
			{
				for (int qwe = 0; qwe < M; qwe++)
				{
					if (circle[asd].getValue(qwe) != 0)
					{
						if (circle[asd].getValue(qwe) < avr)
						{
							circle[asd].setValue(qwe, circle[asd].getValue(qwe) + 1.0);
						}
						else if (circle[asd].getValue(qwe) > avr)
						{
							circle[asd].setValue(qwe, circle[asd].getValue(qwe) - 1.0);
						}
					}
				}
			}
		}
		printf("\n삭제 후\n");
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%f ", circle[i].getValue(j));
			}
			printf("\n");
		}
	}
	float sum = 0;
	//전체원판토탈
	for (int asd = 1; asd <= N; asd++)
	{
		sum += circle[asd].getTotal();
	}
	printf("%f", sum);
	return 0;
}