#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int a, b;
	cout << "请输入两个数字，空格隔开" << endl;
	cin >> a >> b;
	float ans = (1.0 * a + b) / 2;
	cout << "两数字平均值为" << ans << endl;
	return 0;
}
