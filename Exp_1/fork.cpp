//============================================================================
// Name        : fork.cpp
// Author      : garvin
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
	pid_t pid;
	cout << "嗨，大家好，我是父进程，我的pid为:" << getpid() << endl;

	pid = fork();
	if (pid < 0) {
		cout << "啊哦，我在fork出子进程1的时候出错了" << endl;
		return -1;
	}
	//fork返回0，说明该进程为子进程
	else if (0 == pid) {
		cout << "hello，我是子进程1" << endl;
		pid = fork();
		if (pid < 0) {
			cout << "啊哦，我的子进程1在fork出孙进程3的时候出错了" << endl;
			return -1;
		} else if (0 == pid) {
			cout << "Hi,我是孙进程3～" << endl;
		} else {
			cout << "我的孙进程pid为" << pid << endl;
		}
	}
	//该进程为父进程，其返回的pid为子进程pid号
	else {
		cout << "我的子进程1的pid为:" << pid << endl;
		pid = fork();
		if (pid < 0) {
			cout << "啊哦，我在fork出子进程2的时候出错了" << endl;
			return -1;
		} else if (0 == pid) {
			cout << "hello,我是子进程2" << endl;
		} else {
			cout << "我的子进程2的pid为:" << pid << endl;
		}
	}
	return 0;
}
