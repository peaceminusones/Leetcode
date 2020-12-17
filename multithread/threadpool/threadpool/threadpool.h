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
	// ��ֹ���ƿ���
	ThreadPool(const ThreadPool&);
	const ThreadPool& operator=(const ThreadPool&);

	int InitThreadsSize;  // ��ʼ����С

	vector<thread*> m_threads;  // �߳�����
	queue<Task> m_tasks; // ��������

	mutex m_mutex;  // ��
	condition_variable m_cond;  // ��������
	bool m_isStarted; // �Ƿ����̳߳�
};


#endif // !_THREADPOOL_HH
