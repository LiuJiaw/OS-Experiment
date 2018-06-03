#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h>

using namespace std;

int main() {
	string cmd;
	while (true) {
		cmd.clear();
		cout << "garvin @ shell >";
		getline(cin, cmd);
		if (cmd.size() == 0) {
			continue;
		}
		if (fork() == 0) {
			if ("min" == cmd) {
				execl("compare", "min", NULL);
			} else if ("max" == cmd) {
				execl("compare", "max", NULL);
			} else if ("ave" == cmd) {
				execl("average", NULL, NULL);
			} else if ("fork" == cmd) {
				execl("fork", NULL, NULL);
			} else {
				cout << "sorry，您的输入无法识别" << endl;
			}
			exit(0);
		} else {
			wait(NULL);
		}
	}
	return 0;
}
