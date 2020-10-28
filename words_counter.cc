#include "words_counter.h"

#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <iostream>
#include <algorithm>

void WordsCounter::addBuffer(std::string_view buffer) {
    static std::string word;
    container_ = container_.append(buffer);
    size_t pos;
    while ((pos = container_.find(" ")) != std::string::npos) {
        word = container_.substr(0, pos);
        dictionary_.insert(word);
        container_.erase(0, pos + 1);
    }
}

void WordsCounter::readingFinished() {
    static std::string word;
    size_t pos;
    while ((pos = container_.find(" ")) != std::string::npos) {
        word = container_.substr(0, pos);
        dictionary_.insert(word);
        container_.erase(0, pos + 1);
    }
    if (!container_.empty()) {
        container_.erase(std::remove(container_.begin(), container_.end(), 0), container_.end());
        dictionary_.insert(container_);
    }
}

size_t WordsCounter::uniqueWordsCount() const {
    return dictionary_.size();
}