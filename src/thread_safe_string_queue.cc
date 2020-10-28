#include "thread_safe_string_queue.h"

void ThreadSafeStringQueue::push(std::string_view value)
{
  std::lock_guard<std::mutex> lck{m_mut};
  m_data.push(std::string{value});
  m_condVar.notify_one();
}

std::string ThreadSafeStringQueue::pop()
{
  std::string res;
  {
    std::unique_lock<std::mutex> lck{m_mut};
    m_condVar.wait(lck, [this] { return !m_data.empty(); });
    res = m_data.front();
    m_data.pop();
  }
  return res;
}
