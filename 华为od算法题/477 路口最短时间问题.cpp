///*
//477��·�����ʱ������
//��Ŀ������
//�ٶ��ֵ��������͵ģ�ÿ�������ȣ�����ͨ��ÿ��ֵ���Ҫʱ���Ϊ timePerRoad;
//�ֵ��Ľֿ�(�����)�н�ͨ�ƣ��Ƶ�����T(=lights[row][col])������ͬ;
//������ֱ�С���ת����ת������ֱ�к���ת��Ҫ����ӦTʱ��Ľ�ͨ�Ʋſ�ͨ�У���ת������̡�
//�ָ��� n*m ���ֿڵĽ�ͨ�����ڣ��Լ���ֹ�ֿڵ����꣬���㳵�����������ֿڵ����ʱ��,����:
//1)�����յ�Ľ�ͨ�Ʋ�����ʱ�䣬�ҿ������ⷽ�򾭹��ֿ�
//2) ���ɳ��� n*m ���ֿڣ�������Ծ��������Ҳ�ǵ�·(�� lights[0][0] -> lights[0]1] ����Ч·��)
//��ں�������:
///**
///* lights: n*m ���ֿ�ÿ����ͨ�Ƶ����ڣ�ֵ��Χ[0,120]��n��m�ķ�ΧΪ[1,9]
//*timePerRoad:���������ֿ�֮��ֵ���ͨ��ʱ�䷶ΧΪ[0,600]
//* rowStart: �����к�
//*colStart: �����к�
//*rowEnd : �յ���к�
//*colEnd : �յ���к�
//*return : lights[rowStart][colStart] �� lights[rowEnd][colEnd] �����ֿ�֮������ͨ��ʱ��
///*
//int calcTime(int[] lights,int timePerRoad,int rowStart,int colStart,int rowEnd,int colEnd)
//
//��������
//��һ������ n �� m���Կո�ָ�
//֮�� n ������ lights���󣬾���ÿ��m���������Կո�ָ�
//֮��һ������ timePerRoad
//֮��һ������ rowStart colStart���Կո�ָ�
//���һ������ rowEnd colEnd���Կո�ָ�
//
//�������
//lights[rowStart][colStart] �� lights[rowEnd][colEnd] �����ֿ�֮������ͨ��ʱ��
//
//ʾ��1
//����:
//3 3
//1 2 3
//4 5 6
//7 8 9
//60
//0 0
//2 2
//���:
//245
//
//˵��:
//����·��Ϊ (0.0) -> (0.1)-> (1,1) -> (1.2) -> 2.2)����4��·��2����ת��1����ת������ʱ 60+0+60+5+60+0+60=245
//
//// ��̬��Ȩ����Ȩͼ
//1. dijkstra: 
//��ΪҪ�漰�����ķ��򣬲�ͬ��·�ߵ�һ����Ե���һ�������Ӱ�죬��˵�ǰ��̲���һ����ȫ����̡�
//
//2.���ȶ���bfs
//
//����˼·��
//������Ҫ�����һ���ֿڣ���㣩����һ���ֿڣ��յ㣩�����ͨ��ʱ�䣬���ǵ�ÿ���ֿڴ��Ľ�ͨ�����ں͵�·֮�����ʻʱ�䡣���������ͼ�����㷨���������Dijkstra�㷨����Ϊ������Ҫ�ҵ�Ȩ�أ�ʱ�䣩��С��·������������ϸ�Ľ���˼·��
// 1. ͼ��������
//   - �ڵ㣺�ֿڣ�����㣩���Ա���Ϊͼ�еĽڵ㡣
//   - �ߣ��������ڽֿڵĵ�·������Ϊͼ�еıߣ��ߵ�Ȩ����ͨ���õ�·��ʱ�䣨�����ȴ���ͨ�Ƶ�ʱ�䣩��
// 2. ����״̬
//   - Ϊ����ͼ�н������������Ƕ���һ��״̬State��������ǰλ�ã��ֿڣ����ۼƵ�ͨ��ʱ��͵�ǰ����ʻ����
//   - ʹ���ĸ����򣨶����ϡ�����������ȷ����һ���ڵ㵽��һ���ڵ���ƶ���
// 3. ʹ�����ȶ���
//   - ʹ�����ȶ��У���С�ѣ����洢���������е�״̬����ȷ�������ȴ��������Сͨ��ʱ���״̬��
//   - ���ȶ��л��ڵ�ǰ�ۼƵ�ͨ��ʱ������
//����ͨ��ʱ��
//   - ����ÿ���ڵ㣬��Ҫ���Ǵ��ĸ��������ýڵ�Ŀ����ԡ�
//   - �����һ���ֿڵ���һ���ֿڵ�ʱ����Ҫ���ڣ�
//	 - ��·ʱ�䣺timePerRoad����ֱ����ʻʱ�䡣
//	 - ��ͨ��ʱ�䣺
//	   - �����ֱ�л���ת����Ҫ���ǽ�ͨ�����ڣ�������Ҫ�ȴ���
//	   - �������ת������ȴ���ͨ�ơ�
//5. ����ʱ���״̬
//   - ����һ���ֿ��ƶ�����һ���ֿ�ʱ�����´ﵽ�ýֿڵ���Сʱ�䣨�����ǰ�����ʱ��С���Ѽ�¼����Сʱ�䣩��
//   - ����״̬�������ȶ��м�������
//6. ����߽�����
//   - ȷ����Խ�磨�����������������з�Χ����
//   - ���������յ�����⴦�����ʱ���迼�ǽ�ͨ��ʱ�䣬�յ�ʱ�ҵ���Сʱ�伴�ɽ�����
//7. �㷨��������
//   - �����ȶ���Ϊ�գ������ҵ������յ�����·��ʱ�����㷨��
//
//
//��ǰ��0 1 2 3
//��ת:��һ
//ָ�򣺲��䣺
//��ת����һ��
//���򣺼�2����ȡ��
//
//
//֮ǰ 0 1 2 3
//����:0 1 2 3
//
//��-�ɣ���������˳ʱ��()��С������ʱ��->ȡģ
//��ֵ+4 mod 4��
//	0:ֱ��
//	1:��ת
//	2:����
//	3:��ת
//*/
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//// ����һ���ṹ��State����ʾÿ��״̬
//struct State {
//    int row, col, time, dir;  // ��ǰλ���кš��кţ���ǰ�ۼ�ʱ�䣬��ǰ����
//    bool operator<(const State& other) const {
//        return time > other.time; // ʹ���ȶ��а�ʱ���������У���Сʱ������
//    }
//};
//
//// ���������������㵽�յ�����ͨ��ʱ��
//int calcTime(vector<vector<int>>& lights, int timePerRoad, int rowStart, int colStart, int rowEnd, int colEnd) {
//    int n = lights.size(), m = lights[0].size(); // ��ȡ�Ƶ�������
//    vector<vector<vector<int>>> minTime(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
//    priority_queue<State> pq;
//
//    // ��ʼ�����������ĸ�����ʱ��Ϊ0�����������ȶ���
//    for (int dir = 0; dir < 4; ++dir) {
//        minTime[rowStart][colStart][dir] = 0;
//    }
//    pq.push({ rowStart, colStart, 0, -1 });
//    vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };  // �����ϡ�������������ƶ�����
//
//    // ʹ�����ȶ��н���Dijkstra�㷨
//    while (!pq.empty()) {
//        State cur = pq.top();
//        pq.pop();
//
//        // ��������յ�,����ִ��
//        if (cur.row == rowEnd && cur.col == colEnd) {
//            return cur.time;
//        }
//
//        // �������п��ܵķ����ƶ�
//        for (int i = 0; i < 4; ++i) {
//            // ������
//            int nextRow = cur.row + directions[i].first;
//            int nextCol = cur.col + directions[i].second;
//
//            // �ǳ�ʼ״̬��ת�� ȷ�����ܵ�ͷ
//            if ((cur.dir != -1) && (cur.dir + 2) % 4 == i) continue;
//            // ȷ����Խ��
//            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m) continue;
//
//            int waitTime = 0;
//            // �����ǰ�ƶ�Ϊ��ת���򲻵ȴ�������ȡ��ǰ��ͨ��������Ϊ�ȴ�ʱ��
//            if (cur.dir == -1 || i == (cur.dir + 1) % 4) { // Ĭ��״̬/��ת
//                waitTime = 0; // ��ת���ȴ�
//            }
//            else { // ��ת��ֱ��
//                waitTime = lights[cur.row][cur.col];
//            }
//
//            // �����µ�ʱ��
//            int nextTime = cur.time + timePerRoad + waitTime;
//            // �����ʱ��С���Ѽ�¼��ʱ�䣬����²��������ȶ���
//            if (nextTime < minTime[nextRow][nextCol][i]) {
//                minTime[nextRow][nextCol][i] = nextTime;
//                pq.push({ nextRow, nextCol, nextTime, i });
//            }
//        }
//    }
//
//    // ���ĸ������ҵ����ʱ�䲢����
//    int ans = INT_MAX;
//    for (int dir = 0; dir < 4; ++dir) {
//        ans = min(ans, minTime[rowEnd][colEnd][dir]);
//    }
//    return ans;
//}
//
//// �����������ڽ������벢������
//int main() {
//    int n, m; // ������
//    cin >> n >> m;
//    int x;
//    vector<vector<int>> lights(n); // �洢ÿ����ͨ������
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++) {
//            cin >> x; // ���뽻ͨ������
//            lights[i].push_back(x);
//        }
//
//    int timePerRoad, rowStart, colStart, rowEnd, colEnd;
//    // ����ÿ���·��ʱ�䣬�����յ�����
//    cin >> timePerRoad >> rowStart >> colStart >> rowEnd >> colEnd;
//    // �����������ͨ��ʱ��
//    cout << calcTime(lights, timePerRoad, rowStart, colStart, rowEnd, colEnd);
//    return 0;
//}