///*
//476������ƥ�䡢�����е� K ������е���Сֵ
//��Ŀ������
//��һ��N*M��N<=M)�ľ�����ѡ��N�����������������ֲ�����ͬһ�л�ͬһ�У���ѡ������N�����е�K������ֵ���Сֵ�Ƕ��١�
//
//����������
//�������Ҫ��1<=K<=N<=M<=150
//
//�����ʽ��
//N M K
//N*M����
//
//���������
//N*M�ľ����п���ѡ��M!/N!��������飬ÿ����������е�K������е���Сֵ�����迼���ظ����֣�ֱ��ȡ�ֵ����������ɡ�
//
//����˵����ע�⣺����ǵ�K������ֵ���Сֵ
//ʾ��1
//���룺
//3 4 2
//1 5 6 6
//8 3 4 3
//6 8 6 3
//�����3
//˵����N*M�ľ����п���ѡ��M!/N!��������飬ÿ����������е�K������е���Сֵ������������ѡ�����������Ϊ1,3,6; 1,3,3; 1,4,8; 1,4,3;......��������������ѡ�������������24�֣���С����Ϊ1,3,3����2�����СֵΪ3
//
//��⣺ÿ��ѡһ�������в���ͻ
//
//*/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, M, K;	// N*M���� ��K��
//vector<int> nums;
//int res = INT_MAX;
//vector<bool> vis;
//vector<vector<int>> vec;
//
//void dfs(int row)
//{
//	if (nums.size() == N)
//	{
//		vector<int> sort_nums(nums);
//		sort(sort_nums.begin(), sort_nums.end(), greater<int>());
//		res = min(res, sort_nums[K-1]);	// ��K���������еĵ�k-1λ
//		return;
//	}
//	for (int j = 0; j < M; j++)
//	{
//		if (vis[j] == true) continue;
//		vis[j] == true;
//		nums.push_back(vec[row][j]);
//		dfs(row + 1);
//		vis[j] == false;
//		nums.pop_back();
//	}
//}
//
//int main()
//{
//	cin >> N >> M >> K;
//	vec.resize(N, vector<int>(M, 0));
//	vis.resize(M,false); // ����������Ƿ�ʹ��
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> vec[i][j];
//		}
//	}
//
//	// ����
//	dfs(0);
//	cout << res;
//}