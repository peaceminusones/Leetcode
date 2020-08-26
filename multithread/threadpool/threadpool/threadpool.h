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
	// ��ֹ���ƿ���
	ThreadPool(const ThreadPool&);
	const ThreadPool& operator=(const ThreadPool&);

	void threadLoop();
	Task take();

	using Threads = vector<thread *>;
	using TasksQue = queue<Task>;
	
	int InitThreadsSize;  // ��ʼ����С

	Threads m_threads;  // �߳�����
	TasksQue m_tasks; // ��������

	mutex m_mutex;  // ��
	condition_variable m_cond;  // ��������
	bool m_isStarted; // �Ƿ����̳߳�
};


#endif // !_THREADPOOL_HH
