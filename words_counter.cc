#include "words_counter.h"

#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>

void WordsCounter::addBuffer(std::string_view buffer) {
    input_stream_ << buffer;
    if (buffer.find(" ") != std::string::npos) {
        static std::string word;
        input_stream_ >> word;
        dictionary_.insert(word);
    }
}

void WordsCounter::readingFinished() {}

size_t WordsCounter::uniqueWordsCount() const {
    return dictionary_.size();
}