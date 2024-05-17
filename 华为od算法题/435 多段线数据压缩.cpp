///*
//435 多段线数据压缩
//题目描述：
//下图中，每个方块代表一个像素，每个像素用其行号和列号表示。
//为简化处理，多段线的走向只能是水平、竖直、斜向45度。
//上图中的多段线可以用下面的坐标串表示：(2, 8), (3, 7), (3, 6), (3, 5), (4, 4), (5, 3), (6, 2), (7, 3), (8, 4), (7, 5)。
//但可以发现，这种表示不是最简的，其实只需要存储6个蓝色的关键点即可，它们是线段的起点、拐点、终点，而剩下4个点是冗余的。
//现在，请根据输入的包含有冗余数据的多段线坐标列表，输出其最简化的结果。
//
//输入描述：
//2 8 3 7 3 6 3 5 4 4 5 3 6 2 7 3 8 4 7 5
//1、所有数字以空格分隔，每两个数字一组，第一个数字是行号，第二个数字是列号；
//2、行号和列号范围为[0,64)，用例输入保证不会越界，考生不必检查；
//3、输入数据至少包含两个坐标点。
//
//
//输出描述：
//2 8 3 7 3 5 6 2 8 4 7 5
//压缩后的最简化坐标列表，和输入数据的格式相同。
//补充说明：
//输出的坐标相对顺序不能变化。
//
//示例1
//输入：
//2 8 3 7 3 6 3 5 4 4 5 3 6 2 7 3 8 4 7 5
//2 8 3 7 3 5 6 2 8 4 7 5
//
//输出：
//2 8 3 7 3 5 6 2 8 4 7 5
//说明：
//如上图所示，6个蓝色像素的坐标依次是（2,8）、（3,7）、（3,5）、（6,2）、（8,4）、（7,5）。
//将他们按顺序出即可。
//
//核心：判断拐点
//a(x1, y1) b(x2, y2) c(x3, y3)
//k1 = y2 - y1 / x2 - x1
//k2 = y3 - y2 / x3 - x2
//注意到 x2 - x1 和 x3 - x2 可能为0，因此可能改除法为乘法
//*/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//struct point
//{
//	int row;	// 行坐标
//	int col;	// 列坐标
//};
//
//int main()
//{
//	// 输入
//	vector<point> vec;
//	int a, b;
//	while (cin >> a >> b)
//	{
//		vec.push_back({a, b});
//		if (cin.peek() == '\n') break;
//	}
//	for (int i = 2; i < vec.size(); i++)
//	{
//		int r1 = (vec[i - 1].col - vec[i - 2].col) * (vec[i].row - vec[i - 1].row);	// y2 - y1 * x3 - x2
//		int r2 = (vec[i].col - vec[i - 1].col) * (vec[i - 1].row - vec[i - 2].row);	// y3 - y2 * x2 - x1
//		if (r1 == r2)
//		{
//			vec.erase(vec.begin() + i - 1);
//			i--;	// 很重要
//		}
//	}
//	for (auto i : vec)
//	{
//		cout << i.row << " " << i.col << " ";
//	}
//}