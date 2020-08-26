#include <assert.h>
#include "threadpool.h"

ThreadPool::ThreadPool(int init_size) :m_mutex(), m_cond(),InitThreadsSize(init_size), m_isStarted(false)
{
	start();
}

ThreadPool::~ThreadPool()
{
	if (m_isStarted)
	{
		stop();
	}
}

void ThreadPool::start()
{
	assert(m_threads.empty());

	m_isStarted = true;
	m_threads.reserve(InitThreadsSize);
	for (int i = 0; i < InitThreadsSize; i++)
	{
		m_threads.push_back(new thread(bind(&ThreadPool::threadLoop, this)));
	}
}

void ThreadPool::stop()
{
	{
		unique_lock<mutex> lock(m_mutex);
		cout << "ThreadPool::stop() stop." << endl;
		m_isStarted = false;
		m_cond.notify_all();
		cout << "ThreadPool::stop() notifyAll()" << endl;
	}
	
	for (Threads::iterator it = m_threads.begin(); it != m_threads.end(); it++)
	{
		(*it)->join();
		delete* it;
	}
	m_threads.clear();
}


void ThreadPool::threadLoop()
{
	cout << "ThreadPool::threadLoop() tid:" << this_thread::get_id() << " start." << endl;
	while (!m_tasks.empty() && m_isStarted)
	{
		Task task = take();
		if (task)
		{
			task();
		}
	}
	cout << "ThreadPool::threadLoop() tid:" << this_thread::get_id() << " exit." << endl;
}

void ThreadPool::addTask(const ThreadPool::Task& task)
{
	unique_lock<mutex> lock(m_mutex);
	m_tasks.push(task);
	m_cond.notify_one();
}

ThreadPool::Task ThreadPool::take()
{
	unique_lock<mutex> lock(m_mutex);
	while (m_tasks.empty() && m_isStarted)
	{
		cout << "ThreadPool::take() tid:" << this_thread::get_id() << " wait" << endl;
		m_cond.wait(lock);
	}
	cout << "ThreadPool::take() tid:" << this_thread::get_id() << " wakeup" << endl;

	Task task;
	TasksQue::size_type size = m_tasks.size();
	if (!m_tasks.empty() && m_isStarted)
	{
		task = m_tasks.front();
		m_tasks.pop();
		assert(size - 1 == m_tasks.size());
	}

	return task;
}