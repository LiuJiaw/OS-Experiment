#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cout << "请输入两个数字，空格隔开" << endl;
	cin >> a >> b;
	if (strcmp(argv[0], "min") == 0) {
		int ans = a < b ? a : b;
		cout << "较小的数字为" << ans << endl;
	} else if (strcmp(argv[0], "max") == 0) {
		int ans = a > b ? a : b;
		cout << "较大的数字为" << ans << endl;
	}
	return 0;
}
