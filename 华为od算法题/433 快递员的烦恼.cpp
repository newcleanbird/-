///*
//433、 快递员的烦恼
//题目描述：
//快递公司每日早晨，给每位快递员推送需要送到客户手中的快递以及路线信息，快递员自己又查找了一些客户与客户之间的路线距离信息，请你依据这些信息，给快递员设计一条最短路径，告诉他最短路径的距离。
//注意：
//1. 不限制快递包裹送到客户手中的顺序，但必须保证都送到客户手中
//2. 用例保证一定存在投递站到每位客户之间的路线，但不保证客户与客户之间有路线，客户位置及投递站均允许多次经过
//3. 所有快递送完后，快递员需回到投递站
//
//输入描述：首行输入两个正整数n、m
//接下来n行，输入快递公司发布的客户快递信息，格式为：客户id 投递站到客户之间的距离distance
//再接下来的m行，是快递员自行查找的客户与客户之间的距离信息，格式为：客户1id 客户2id distance
//在每行数据中，数据与数据之间均以单个空格分割
//
//规格：
//0 < n <= 10
//0 <= m <= 10
//0 < 客户id <= 1000
//0 < distance <= 10000
//
//输出描述：最短路径距离，如无法找到，请输出-1
//
//示例
//示例1
//输入：
//2 1
//1 1000
//2 1200
//1 2 300
//输出：
//2500
//说明：路径1：快递员先把快递送到客户1手中，接下来直接走客户1到客户2之间的直通线路，最后走投递站和客户2之间的路，回到投递站，距离为1000 + 300 + 1200 =2500
//路径2：快递员先把快递送到客户1手中，接下来回到快递站，再出发把客户2的快递送过去，再回到投递站，距离为1000 + 1000 + 1200 + 1200 = 4400
//路径3：快递员先把快递送到客户2手中，接下来直接走客户2到客户1之间的直通线路，最后走投递站和客户1之间的路，回到投递站，距离为1200 + 300 + 1000 =2500
//其他路径……
//所有路径中，最短路径距离为2500
//
//示例2
//输入：
//5  1
//5 1000
//9 1200
//17 300
//132 700
//500 2300
//5 9 400
//输出：9200
//说明：在所有可行的路径中，最短路径长度为1000 + 400 + 1200 + 300 + 300 + 700 + 700 + 2300 + 2300 = 9200
//
//要求：访问每一个节点，节点可以重复访问，寻找最短路径。
//
//变种的旅行商问题（TSP）
//输入：
//n行为初始点到其他点的距离
//m行为其他点之间的距离
//
//思想：
//使用佛洛依德算法求出全源最短路径，然后使用深搜遍历所有路径，找到最短路径的距离。
//*/
//
//#include <iostream>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//#define INF INT_MAX // 定义一个大数作为无穷大，用于初始化路径长度
//
//int n, m;           // n表示客户数量，m表示客户间路线的数量
//vector<vector<int>> path;   // 路径长度矩阵，存储任意两点间的最短路径
//int num = 1;        // num用于记录下一个可用的节点索引
//vector<int> Hash;   // 映射客户id到节点索引
//vector<bool> vist;  // 标记数组，用于DFS中标记哪些节点已访问
//int ans = INF;      // 存储最短路径的结果
//
//// 深度优先搜索函数，用于计算从起点出发访问所有客户并返回的最短路径
//void dfs(int u, int k, int t) { // K：当前已搜索路径长度 t:当前已搜索的节点个数
//    if (k > ans) return;  // 剪枝，如果当前路径长度已超过已知最短路径，则停止搜索
//    if (t == num - 1) { ans = min(ans, k + path[u][0]); return; }  // 所有客户访问完毕，计算回起点的总距离，并更新最短路径
//    for (int i = 1; i < num; i++) {  // 遍历所有客户
//        if (!vist[i]) {  // 如果客户i未被访问
//            vist[i] = true;  // 标记客户i为已访问
//            dfs(i, k + path[u][i], t + 1);  // 递归访问客户i
//            vist[i] = false;  // 回溯，取消标记
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m; 
//    // 初始化path
//    path.resize(n+1, vector<int>(n+1)); // 设置path的大小    初始节点1个，其他节点共n个，所以需要一共n+1个
//    for (auto& i : path)
//    {
//        for (auto& j : i)
//        {
//            j = INF;
//        }
//    }
//    // 初始化Hash
//    Hash.resize(1001);   // 0 < 客户id <= 1000
//    // 初始化标记数组
//    vist.resize(n + 1);
//
//    // 输入快递公司发布的客户快递信息  即输入节点0到其他节点的距离
//    for (int i = 0; i < n; i++) 
//    {
//        int id, distance;
//        cin >> id >> distance;
//        if (!Hash[id])  // 如果id还未映射到索引
//            Hash[id] = num++;  // 分配一个新的索引给这个id
//        id = Hash[id];  // 获取id对应的索引
//        path[0][id] = min(distance, path[0][id]);  // 更新起点到客户id的最短路径
//        path[id][0] = path[0][id];  // 无向图，同步更新客户id到起点的最短路径
//    }
//    // 快递员自行查找的客户与客户之间的距离信息     即输入其他节点之间的距离
//    for (int i = 0; i < m; i++) {
//        int x, y, distance; // x到y的距离
//        cin >> x >> y >> distance;
//        x = Hash[x];    // 获取path中的x坐标
//        y = Hash[y];    // 获取path中的y坐标
//        path[x][y] = min(path[x][y], distance);  // 更新客户x到客户y的最短路径
//        path[y][x] = path[x][y];  // 由于是无向图，所以路径也需要对称更新
//    }
//    // 初始化path矩阵
//    for (int i = 0; i < num; i++)
//        path[i][i] = 0;  // 将自己到自己的距离设为0
//
//    // 使用Floyd-Warshall算法计算所有节点对之间的最短路径
//    for (int k = 0; k < num; k++)
//        for (int i = 0; i < num; i++)
//            for (int j = 0; j < num; j++)
//                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
//
//    // 从起点开始进行深度优先搜索
//    dfs(0, 0, 0);
//    if (ans == INF) ans = -1;
//    cout << ans;  // 输出计算得到的最短路径长度
//}
