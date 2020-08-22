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
	enum taskPriorityE { level0, level1, level2 };
	using Task = function<void()>;
	using TaskPair = pair<taskPriorityE, Task>;

	ThreadPool(int init_size = 3);
	~ThreadPool();

	void start();
	void stop();
	void addTask(const Task&);
	void addTask(const TaskPair&);

private:
	// ��ֹ���ƿ���
	ThreadPool(const ThreadPool&);
	const ThreadPool& operator=(const ThreadPool&);

	struct TaskPriorityCmp
	{
		bool operator()(const ThreadPool::TaskPair p1, const ThreadPool::TaskPair p2)
		{
			return p1.first > p2.first;  // firstֵС������
		}
	};

	void threadLoop();
	Task take();

	using Threads = vector<thread *>;
	using TasksQue = priority_queue<TaskPair, vector<TaskPair>, TaskPriorityCmp>;
	
	int InitThreadsSize;  // ��ʼ����С

	Threads m_threads;  // �߳�����
	TasksQue m_tasks; // ��������

	mutex m_mutex;  // ��
	condition_variable m_cond;  // ��������
	bool m_isStarted; // �Ƿ����̳߳�
};


#endif // !_THREADPOOL_HH
