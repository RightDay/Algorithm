//https://programmers.co.kr/learn/courses/30/lessons/42862#

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;

	vector <int> students(n, 1);

	for (int i = 0; i < lost.size(); i++)
	{
		students[lost[i] - 1] -= 1;
	}

	for (int i = 0; i < reserve.size(); i++)
	{
		students[reserve[i] - 1] += 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (students[i] == 0)
		{
			if (i - 1 > -1)
			{
				if (students[i - 1] == 2)
				{
					students[i] += 1;
					students[i - 1] -= 1;
				}
			}

			if (i + 1 < n)
			{
				if (students[i + 1] == 2)
				{
					students[i] += 1;
					students[i + 1] -= 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (students[i] > 0)
			answer++;
	}

	return answer;
}


int main()
{
	int n = 6;

	vector<int> lost = { 2, 4, 6 };
	vector<int> reserve = { 1, 3, 5 };

	return solution(n, lost, reserve);
}