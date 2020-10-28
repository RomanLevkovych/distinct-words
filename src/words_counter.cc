#include "words_counter.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>

WordsCounter::WordsCounter() {
    is_alive_ = true;
    worker_ = std::thread(&WordsCounter::dataHandler, this);
}

void WordsCounter::dataHandler() {
    static std::string word;
    static std::string buffer;
    do {
        buffer = queue_.pop();
        container_ = container_.append(buffer);
        size_t pos;
        while ((pos = container_.find(" ")) != std::string::npos) {
            word = container_.substr(0, pos);
            dictionary_.insert(word);
            container_.erase(0, pos + 1);
        }
    } while (is_alive_);
}

void WordsCounter::addBuffer(std::string_view buffer) {
    queue_.push(buffer);
}

void WordsCounter::readingFinished() {
    static std::string word;
    static size_t pos;
    is_alive_ = false;
    worker_.join();
    while ((pos = container_.find(" ")) != std::string::npos) {
        word = container_.substr(0, pos);
        dictionary_.insert(word);
        container_.erase(0, pos + 1);
    }
    if (!container_.empty()) {
        container_.erase(std::remove(container_.begin(), container_.end(), 0), container_.end());
        dictionary_.insert(container_);
    }
    count_.set_value(dictionary_.size());
}

size_t WordsCounter::uniqueWordsCount() {
    auto future = count_.get_future();
    return future.get();
}