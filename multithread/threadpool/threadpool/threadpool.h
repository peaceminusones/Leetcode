#ifndef _THREADPOOL_HH
#define _THREADPOOL_HH
#pragma once

#include <vector>
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class ThreadPool
{
public:
	using Task = function<void()>;

	ThreadPool(int init_size = 3);
	~ThreadPool();

	void start();
	void stop();
	void addTask(const Task&);
	void threadLoop();
	Task take();

private:
	// 禁止复制拷贝
	ThreadPool(const ThreadPool&);
	const ThreadPool& operator=(const ThreadPool&);

	int InitThreadsSize;  // 初始化大小

	vector<thread*> m_threads;  // 线程数量
	queue<Task> m_tasks; // 任务数量

	mutex m_mutex;  // 锁
	condition_variable m_cond;  // 条件变量
	bool m_isStarted; // 是否开启线程池
};


#endif // !_THREADPOOL_HH
