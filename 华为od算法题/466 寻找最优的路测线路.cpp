///*
//466��Ѱ�����ŵ�·����·
//��Ŀ������
//����һ��������ź�����������һ�������ǽ����绮��Ϊդ��Ȼ���ÿ��դ����ź��������㡣·���ʱ��ϣ��ѡ��һ���ź���õ�·�ߣ��˴�������դ�񼯺ϣ�������ʾ���ָ���R��C�е���������Cov��ÿ����Ԫ�����ֵS��Ϊ��դ����ź��������ѹ�һ�����޵�λ��ֵԽ���ź�Խ�ã���
//Ҫ���[0, 0]��[R-1, C-1]���һ������·��·�ߡ����ظ�·�ߵ÷֡�
//����
//1.     ·��·�߿������������ĸ����򣬲��ܶԽǡ�
//2.     ·�ߵ���������·�����ź�����դ��Ϊ׼�ģ�����·��8��4��5��9��ֵΪ 4������·����Ϊ4����·���ű�ʾ������·��������ߡ�
//
//����������
//��һ�б�ʾդ�������R
//�ڶ��б�ʾդ�������C
//��3�п�ʼ��ÿһ�б�ʾդ���ͼһ�е��ź�ֵ����5 4 5
//
//���������
//����·�ߵĵ÷�
//
//����˵����
//1.    1<= R, C <= 20
//2.    0<= S <= 65535
//
//ʾ��1
//���룺
//3
//3
//5 4 5
//1 2 6
//7 4 6
//�����
//4
//˵����
//·��Ϊ��5��4��5��6��6
//
//ʾ��2
//���룺
//6
//5
//3 4 6 3 4
//0 2 1 1 7
//8 8 3 2 7
//3 2 4 9 8
//4 1 2 0 0
//4 6 5 4 3
//�����
//3
//˵����
//·��Ϊ��3��4��6��3��4��7��7��8��9��4��3��8��8��3��4��4��6��5��4��3
//
//dist:·�ɱ�ά��һ����ǰ��֪��Դ�㵽������ľ���
//q:ά��һ����ѡ���δ���ʽڵ�
//
//˼�룺ֻѡ��ǰ�ɴ�����ĵ㼴��
//*/
//
//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int R, C;
//
//struct Point
//{
//	int x;
//	int y;
//	int val;
//	Point(int x, int y, int val) : x(x), y(y), val(val) {}
//};
//
//vector<vector<int>> dis;	// ·�ɱ�
//vector<vector<Point>> parents;	// ǰ���ڵ��
//vector<vector<int>> map;
//
//vector<int> dx = { 0, 1, 0, -1 };
//vector<int> dy = { 1, 0, -1, 0 };
//
//class compare
//{
//public:
//	bool operator()(const Point p1, const Point p2)
//	{
//		return p1.val < p2.val;
//	}
//};
//
//void Dijkstra()
//{
//	// vector<vector<bool>> vis(R, vector<bool>(C, 0));	// ���ʱ�
//	// ��ʼ��
//	Point start = { 0, 0, map[0][0]};
//	dis[0][0] = map[0][0];
//	parents[0][0] = start;
//	priority_queue<Point, vector<Point>, compare> q;
//	q.push(start);
//	while (!q.empty())
//	{
//		// ������ǰ���ʵĽڵ�
//		Point cur = q.top(); q.pop();
//		int x = cur.x;
//		int y = cur.y;
//		int val = cur.val;
//		if (dis[x][y] == INT_MAX) continue;
//		Point parent = parents[x][y];
//		/*if (parent.x == 0 && parent.y == 0)
//		{
//			dis[x][y] = dis[0][0];
//		}
//		else {
//			dis[x][y] = min(map[x][y], dis[parent.x][parent.y]);
//		}*/
//		dis[x][y] = min(map[x][y], dis[parent.x][parent.y]);
//
//		// ����dis��q
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx >= 0 && nx < R && ny >= 0 && ny < C && dis[nx][ny] == INT_MAX)	// ��Խ����δ����
//			{
//				if (parents[nx][ny].x == -1 || dis[parents[nx][ny].x][parents[nx][ny].y] < dis[x][y])	// �״η��� �� ֮ǰ���ڵ�����С�ڵ�ǰ���ڵ�����
//				{
//					parents[nx][ny] = cur;
//					dis[nx][ny] = min(map[nx][ny], dis[parents[nx][ny].x][parents[nx][ny].y]);
//					q.push({ nx, ny, map[nx][ny] });
//					
//				}
//			}
//		}
//	}
//}
//
//void printPath(Point& j) // ��ӡԴ�㵽j��·��
//{
//	if (j.x == 0 && j.y == 0) {
//		std::cout << map[0][0];
//		return;
//	}
//	printPath(parents[j.x][j.y]);
//	std::cout <<"->" << j.val;
//}
//
//int main()
//{
//	cin >> R >> C;
//	dis.resize(R, vector<int>(C, INT_MAX));
//	parents.resize(R, vector<Point>(C, {-1, -1, -1}));
//	map.resize(R, vector<int>(C, 0));
//
//
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	// ̽��·��
//	Dijkstra();
//	Point end{ R - 1, C - 1, map[R - 1][C - 1] };
//	cout << dis[R - 1][C - 1] << endl;
//	// printPath(end);
//}