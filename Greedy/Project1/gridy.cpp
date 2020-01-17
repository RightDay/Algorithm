#include "pch.h"
#include <string>
#include <vector>
//https://programmers.co.kr/learn/courses/30/lessons/42862#

using namespace std;

void LostEqualReserve(vector<int>& lost, vector<int>& reserve)
{
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				i = -1;
				break;
			}
		}
	}
}

void GiveClothes(vector<int>& lost, vector<int>& reserve)
{
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j])
			{
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				i = -1;
				break;
			}
		}
	}
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = n;

	LostEqualReserve(lost, reserve);

	GiveClothes(lost, reserve);

	answer -= lost.size();

	return answer;
}


int main()
{
	int n = 6;
	//vector<int> lost = { 2, 4, 5, 6 };
	//vector<int> reserve = { 1, 3, 6 };

	vector<int> lost = { 2, 4, 6 };
	vector<int> reserve = { 1, 3, 5 };

	//vector<int> lost = { 1, 2, 3, 4, 5, 6 };
	//vector<int> reserve = { 1, 2, 3, 4, 5, 6 };

	return solution(6, lost, reserve);
}