///*
//436��5G���罨��
//��Ŀ������
//����Ҫ��ĳ���н���5G���罨�裬�Ѿ�ѡȡN���ص�����5G��վ����Ź̶�Ϊ1��N����������Ҫ������վ֮��ʹ�ù��˽���������ȷ����վ�ܻ�����ͨ����ͬ��վ֮�������˵ĳɱ�������ͬ������Щ�ڵ�֮���Ѿ����ڹ�����������������㷨�����������ͨ��Щ��վ����С�ɱ��Ƕ��١�
//ע�⣺��վ����ͨ���д����ԣ����վA���վB�����˹��ˣ���վB���վCҲ�����˹��ˣ����վA���վC��Ϊ���Ի�����ͨ
//����������
//��һ�������ʾ��վ�ĸ���N������0<N<=20
//�ڶ��������ʾ�߱�����ֱ�������Ļ�վ�Ե���ĿM������0<M<N*(N-1)/2
//�ӵ����п�ʼ��������M�����ݣ���ʽΪ X Y Z P������X Y��ʾ��վ�ı�ţ�0<X<=N��0<Y<=N��x������y��Z��ʾ��X Y֮�������˵ĳɱ�������0<Z<100��P��ʾ�Ƿ��Ѵ��ڹ������ӣ�0��ʾδ���ӣ�1��ʾ������
//���������
//����������������Խ���ɹ�������ͨ��5G���磬�������С�Ľ���ɱ���
//��������������޷�����ɹ�������ͨ��5G���磬�����-1
//
//ʾ��
//ʾ��1
//���룺
//3
//3
//1 2 3 0
//1 3 1 0
//2 3 5 0
//�����
//4
//˵����ֻ��Ҫ��1,2�Լ�2,3��վ֮��������ˣ���ɱ�Ϊ3+1=4
//
//ʾ��2
//���룺
//3
//1
//1 2 5 0
//�����
//-1
//˵����3��վ�޷���������վ���ӣ����-1
//
//ʾ��3
//���룺
//3
//3
//1 2 3 0
//1 3 1 0
//2 3 5 1
//�����
//1
//˵����2,3��վ���й���������ֻ��Ҫ��1,3վ��֮��������ˣ���ɱ�Ϊ1
//
//�ҵ���С������
//�����ص㣺ĳЩ·���Ѿ����ɣ������ҪԤ����
//
//*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//struct Edge
//{
//	int x, y, z; // ����u��v Ȩֵw
//	// Edge(int x, int y, int z) : x(x), y(y), z(z) {}
//	bool operator<(const Edge& other) const
//	{
//		return this->z < other.z;
//	}
//};
//
//class DisjointSets
//{
//public:
//	DisjointSets(int n) : root(n), rank(n, 0)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			root[i] = i;
//		}
//	}
//
//	int unionFind(int x)	// ����
//	{
//		if (x != root[x])
//		{
//			root[x] = unionFind(root[x]);
//		}
//		return root[x];
//	}
//
//	void unionMerge(int x, int y)	// �ϲ�
//	{
//		int rX = unionFind(x);
//		int rY = unionFind(y);
//		if (rX != rY)
//		{
//			if (rank[rX] < rank[rY])
//			{
//				swap(rX, rY);
//			}
//			root[rY] = rX;
//			rank[rX]++;
//		}
//	}
//
//private:
//	vector<int> root;
//	vector<int> rank;
//};
//
//
//int main()
//{
//	int n; // ��վ�ĸ���N
//	int m; // ��ʾ�߱�����ֱ�������Ļ�վ�Ե���ĿM
//	cin >> n >> m;
//
//	// ��ʼ�����鼯
//	DisjointSets dset(n+1);
//	vector<Edge> Edges;
//	// ����M������, X Y Z P������X Y��ʾ��վ�ı�� Z��ʾ��X Y֮�������˵ĳɱ� P��ʾ�Ƿ��Ѵ��ڹ������� 0��ʾδ���ӣ�1��ʾ������
//	for (int i = 0; i < m; i++)
//	{
//		int x, y, z, p;
//		cin >> x >> y >> z >> p;
//		if (p == 1)
//		{
//			dset.unionMerge(x, y);
//		}
//		else {
//			Edges.push_back({x, y, z});
//		}
//	}
//	// ���ߵ�Ȩ������
//	sort(Edges.begin(), Edges.end());
//	
//	int res = 0; // ��Ҫ�Ļ���
//	// ��³˹�����㷨
//	for (auto& edge : Edges)
//	{
//		int x = edge.x;
//		int y = edge.y;
//		int set_x = dset.unionFind(x);
//		int set_y = dset.unionFind(y);
//		if (set_x != set_y)
//		{
//			dset.unionMerge(x, y);
//			res += edge.z;
//		}
//	}
//	
//	bool ok = true;
//	for (int i = 1; i <= n; i++)
//	{
//		if (dset.unionFind(1) != dset.unionFind(i))
//		{
//			ok = false;
//		}
//	}
//	if (ok)
//	{
//		cout << res;
//	}
//	else {
//		cout << -1;
//	}
//}
