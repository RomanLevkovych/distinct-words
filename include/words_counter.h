#ifndef WORDS_COUNTER_H
#define WORDS_COUNTER_H

#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <atomic>
#include <future>
#include <unordered_set>

#include "ireader_delegate.h"
#include "thread_safe_string_queue.h"

class WordsCounter : public IReaderDelegate {
   public:
    WordsCounter();
    // IReaderDelegate interface
    void addBuffer(std::string_view buffer) override;
    void readingFinished() override;

    size_t uniqueWordsCount();

   private:
    void dataHandler();

    std::unordered_set<std::string> dictionary_;
    std::string container_;
    std::thread worker_;
    std::atomic<bool> is_alive_;
    std::promise<size_t> count_;
    ThreadSafeStringQueue queue_;
};

#endif  // WORDS_COUNTER_H