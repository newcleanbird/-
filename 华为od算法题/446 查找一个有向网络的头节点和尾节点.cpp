///*
//446������һ�����������ͷ�ڵ��β�ڵ�
//��Ŀ������
//����һ������ͼ��ͼ�п��ܰ����л���ͼʹ�ö�ά�����ʾ��ÿһ�еĵ�һ�б�ʾ��ʼ�ڵ㣬�ڶ��б�ʾ��ֹ�ڵ㣬��[0, 1]��ʾ��0��1��·����ÿ���ڵ�����������ʾ����������ݵ��׽ڵ���β�ڵ㣬��Ŀ������������һ���׽ڵ㣬�����ܴ��ڶ��β�ڵ㡣ͬʱ��ͼ�п��ܺ��л������ͼ�к��л�������[-1]��
//
//˵�������Ϊ0���׽ڵ㣬����Ϊ0��β�ڵ㡣
//
//����������
//��һ��Ϊ��������ļ�ֵ������N>=0���ڶ���Ϊ2N�����֡�ÿ����Ϊһ����㣬һ���յ㡣�磺
//
//���������
//���һ��ͷ�ڵ��β�ڵ㡣����ж��β�ڵ㣬���Ӵ�С��˳�������
//
//����˵����
//���ͼ�л������Ϊ-1.
//����������Ϸ���������ֲ���Ե�����
//
//ʾ��1
//���룺
//4
//0 1 0 2 1 2 2 3
//�����
//0 3
//˵����
//
//ʾ��2
//���룺
//2
//0 1 0 2
//�����
//0 1 2
//˵����
//*/
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//class Graph
//{
//private:
//	vector<vector<int>> m;	// (adjMatrix)�ڽӾ��󣬴洢Ȩֵ
//	int v; // numVertices ������
//	vector<int> topologicalOrder; // �洢�����������
//public:
//	Graph(int v) : v(v)
//	{
//		m.resize(v, vector<int>(v, 0));
//	}
//
//	void addEdge(int x, int y)
//	{
//		m[x][y] = 1;
//	}
//
//	void kahn()
//	{
//		// ��ʼ���������:
//		vector<int> in_degree(v, 0);
//		// ����ÿ����������:
//		for (int i = 0; i < v; i++)
//		{
//			for (int j = 0; j < v; j++)
//			{
//				if (m[j][i] != 0)
//				{
//					in_degree[i]++;
//				}
//			}
//		}
//
//		// �����Ϊ0�Ķ�����뵽q
//		queue<int> q; // �洢�������Ϊ0�Ķ���
//		for (int i = 0; i < v; i++)
//		{
//			if (in_degree[i] == 0) q.push(i);
//		}
//
//		// ��������
//		while (!q.empty())
//		{
//			int cur = q.front(); q.pop();// �������׶��� cur�����������ʾ���� cur �����������е�λ�á�
//			topologicalOrder.push_back(cur);
//
//			// ���������
//			for (int i = 0; i < v; i++)
//			{
//				if (m[cur][i] != 0)	// �ҵ��ڽӵ�
//				{
//					in_degree[i]--;
//					if (in_degree[i] == 0) q.push(i);
//				}
//			}
//		}
//	}
//
//	void print_topologicalOrder()
//	{
//		for (auto i : topologicalOrder)
//		{
//			cout << i << " ";
//		}
//	}
//
//	int size_topologicalOrder()
//	{
//		return topologicalOrder.size();
//	}
//
//	void get_result()
//	{
//		vector<int> res;
//		res.push_back(topologicalOrder[0]);
//
//		// �ҵ����г���Ϊ0�ĵ�
//		vector<int> out_degree(v);
//		for (int i = 0; i < v; i++)
//		{
//			for (int j = 0; j < v; j++)
//			{
//				if (m[i][j] != 0) out_degree[i]++;
//			}
//		}
//		for (int i = 0; i < v; i++)
//		{
//			if (out_degree[i] == 0)
//			{
//				res.push_back(i);
//			}
//		}
//		
//		// ������
//		for (auto i : res)
//		{
//			cout << i << " ";
//		}
//	}
//};
//
//
//int main()
//{
//	int n;// һ��n������,��ʵû����
//	cin >> n;
//	vector<int> nums;	// �洢�������������
//	int tmp;
//	while (cin >> tmp)
//	{
//		nums.push_back(tmp);
//		if (cin.get() == '\n') break;
//	}
//	int v = 0;
//	for (auto i : nums) v = max(v, i);
//	v++;	// ʵ�ʽڵ���Ŀ��������+1
//	Graph g(v);
//	for (int i = 0; i < nums.size(); i = i + 2)
//	{
//		g.addEdge(nums[i], nums[i + 1]);
//	}
//	g.kahn();
//	if (g.size_topologicalOrder() != v)
//	{
//		cout << -1;
//	}
//	else {
//		g.get_result();
//	}
//}