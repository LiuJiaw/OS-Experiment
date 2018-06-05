/*
 * ProcessInfo.h
 *
 *  Created on: 2018年6月3日
 *      Author: garvin
 */

#ifndef EXP_2_PROCESSINFO_H_
#define EXP_2_PROCESSINFO_H_

#include <iostream>

class process {
private:
	//进程ID
	int ID;
	//进程到达时间点
	int ArriveTime;
	//进程服务时间长度
	int ServiceTime;
	//进程完成时间点
	int FinishTime;
	//进程剩余时间
	int LeftTime;
public:
	process();
	process(int, int, int);
	//模拟进程运行
	void run();
	//设置完成时间
	void setFinishTime(int);
	//获取到达时间
	int getArriveTime();
	//获取服务时长
	int getServiceTime();
	//获取结束时间
	int getFinishTime();
	//获取进程周转时间
	int getTATime();
	//获取平均进程周转时间
	double getATATime();
	//检查进程是否完成
	bool IsFinish();
	//显示该进程信息
	void Show();
};

#endif /* EXP_2_PROCESSINFO_H_ */
