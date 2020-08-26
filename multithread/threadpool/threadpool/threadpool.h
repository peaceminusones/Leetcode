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

private:
	// 禁止复制拷贝
	ThreadPool(const ThreadPool&);
	const ThreadPool& operator=(const ThreadPool&);

	void threadLoop();
	Task take();

	using Threads = vector<thread *>;
	using TasksQue = queue<Task>;
	
	int InitThreadsSize;  // 初始化大小

	Threads m_threads;  // 线程数量
	TasksQue m_tasks; // 任务数量

	mutex m_mutex;  // 锁
	condition_variable m_cond;  // 条件变量
	bool m_isStarted; // 是否开启线程池
};


#endif // !_THREADPOOL_HH
