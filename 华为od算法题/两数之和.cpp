///*
//����֮�ͣ������򷵻��±�
//
//����������
//
//���룺1 2 3 5 6 8 9
//
//Ŀ�꣺ 8
//
//˼·��
//�ҵ�����֮�ͣ�
//1. ������ֱ����λ��������
//
//*/
//
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//
//using namespace std;
//
//// ����
//pair<int, int> find_target(const vector<int>& nums, int target)
//{
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		for (int j = i; j < nums.size(); j++)
//		{
//			if (nums[i] + nums[j] == target)
//			{
//				return { i, j };
//			}
//		}
//	}
//}
//// ��ϣ
//pair<int, int> find_target_1(const vector<int>& nums, int target)
//{
//	unordered_map<int, int> umap;
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (umap.find(target - nums[i]) != umap.end())
//		{
//			int pos1 = umap[target - nums[i]];
//			int pos2 = i;
//			if (pos1 > pos2)
//			{
//				swap(pos1, pos2);
//			}
//			return { pos1, pos2 };
//		}
//		else {
//			umap.insert(pair<int, int>{nums[i], i});
//		}
//	}
//}
//
//
//int main()
//{
//	vector<int> nums = { 1, 3, 5, 7, 9, 10, 11 };	// ������Ҫ��ѯ������
//
//	int target = 6; // ��Ҫ���ҵ�Ŀ������
//
//	pair<int, int> res = find_target(nums, target);
//
//	cout << res.first << " " << res.second << endl;
//
//	pair<int, int> res1 = find_target_1(nums, target);
//
//	cout << res1.first << " " << res1.second << endl;
//
//}