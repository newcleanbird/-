/*
467、运输时间、单行道汽车通行时间
题目描述：
M（1<=M <=20）辆车需要在一条不能超车的单行道到达终点，起点到终点的距离为N（1<=N<=400）。速度快的车追上前车后，只能以前车的速度继续行驶，求最后一车辆到达目的地花费的时间。
注：每辆车固定间隔1小时出发，比如第一辆车0时出发，第二辆车1时出发，依次类推
输入描述：
第一行两个数字：M N分别代表车辆数和到终点的距离，以空格分隔。
接下来M行，每行1个数字 S，代表每辆车的速度。0< S<30
输出描述：
输出：最后一辆车到达目的地花费的时间。
补充说明：
示例1
输入：
2 11
3
2
输出：
5.5
说明：
2辆车，距离11，0时出发的车速度快，1时出发的车，达到目的地花费5.5
*/
#include <iostream>
#include <iomanip> // Include the iomanip header for fixed and setprecision
#include <vector>

using namespace std;

int main() {
    // 读取 m 和 n
    int m, n;
    cin >> m >> n;
    // 初始化最大花费时间 ans 为 0
    double ans = 0.0;
    // 创建数组 w 用于存储每个人的速度
    vector<double> w(m);
    // 读取数组 w 的值，即每个人的速度
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    // 遍历数组计算最大花费时间 ans
    for (int i = 0; i < m; i++) {
        // 计算按照当前速度行驶到达终点所需要的时间
        double t = 1.0 * n / w[i];
        // 如果是第一个人，或者追不上前面一个人，更新最大花费时间 ans
        if (i == 0 || t - ans + 1.0 > 1e-4) {
            ans = t;
        }
        else {
            // 如果追上了前面一个人，更新最大花费时间 ans 为当前时间减一
            ans = ans - 1.0;
        }
    }

    cout << fixed << setprecision(1) << ans << endl;

    return 0;
}