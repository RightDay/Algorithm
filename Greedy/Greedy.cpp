//https://programmers.co.kr/learn/courses/30/lessons/42862#

#include <string>
#include <vector>

using namespace std;
void InitializeStudents(vector<int>& allStudents, vector<int>& specificStudents, bool isLost)
{
	if (isLost)
	{
		for (int i = 0; i < specificStudents.size(); i++)
		{
			allStudents[specificStudents[i] - 1] -= 1;
		}
	}
	else
	{
		for (int i = 0; i < specificStudents.size(); i++)
		{
			allStudents[specificStudents[i] - 1] += 1;
		}
	}	
}

void ReserveToLost(int num, vector<int>& allStudents, bool isFront)
{
	if (isFront)
	{
		if (allStudents[num - 1] == 2)
		{
			allStudents[num] += 1;
			allStudents[num - 1] -= 1;
		}
	}
	else
	{
		if (allStudents[num + 1] == 2)
		{
			allStudents[num] += 1;
			allStudents[num + 1] -= 1;
		}
	}
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;

	vector <int> students(n, 1);

	InitializeStudents(students, lost, true);
	InitializeStudents(students, reserve, false);

	for (int i = 0; i < n; i++)
	{
		if (students[i] == 0)
		{
			if (i - 1 > -1)
			{
				ReserveToLost(i, students, true);
			}

			if (i + 1 < n)
			{
				ReserveToLost(i, students, false);
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