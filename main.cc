#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>

#include "reader.h"
#include "words_counter.h"

int main(int argc, char *argv[]) {
    auto counter = std::make_shared<WordsCounter>();
    Reader reader(std::cin, counter);
    reader.exec();
    std::cout << "Size: " << counter->uniqueWordsCount() << std::endl;
    return 0;
}