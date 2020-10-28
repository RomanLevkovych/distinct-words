#ifndef THREAD_SAFE_STRING_QUEUE_H
#define THREAD_SAFE_STRING_QUEUE_H

#include <queue>
#include <string>
#include <condition_variable>
#include <mutex>

class ThreadSafeStringQueue
{
public:
  void push(std::string_view value);
  std::string pop();
private:
  std::queue<std::string> m_data;
  std::mutex m_mut;
  std::condition_variable m_condVar;
};

#endif // THREAD_SAFE_STRING_QUEUE_H