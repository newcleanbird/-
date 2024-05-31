/*
����һ���������飬���������������Ӵ���

���룺1 2 3 -5 -5

ʱ�临�Ӷȣ�
O(n^2)
O(n)
*/

#include<iostream>
#include<vector>

using namespace std;

// ʵ��һ��O(n)ʱ�临�Ӷȵ��㷨

/*
�������ĺ�Ϊ�����������ӳɣ�����ѡ������ִ�

*/
int get_max_count(const vector<int> &nums)
{
	int res = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (sum + nums[i] >= 0)
		{
			sum += nums[i];
			res = max(sum, res);
		}
		else {
			sum = 0;
		}
	}
	return res;
}

int main()
{
	// vector<int> nums = { -3, -4, 1, 2, 3, -5, 6, -5 };
	vector<int> nums = {1, 2, 3, -5, 6, -5 };
	cout << get_max_count(nums);

}

