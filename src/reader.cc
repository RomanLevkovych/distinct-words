#include "reader.h"

#include <iostream>
#include <istream>
#include <memory>
#include <string>

#include "ireader_delegate.h"

constexpr int kBufferSize = 1 << 10;

Reader::Reader(std::istream& is, std::weak_ptr<IReaderDelegate> delegate)
    : stream_(is), delegate_(delegate) {}

void Reader::exec() {
    char buffer[kBufferSize];
    while (true) {
        bzero(buffer, kBufferSize);
        stream_.get(buffer, kBufferSize);
        if (auto delegate = delegate_.lock()) {
            delegate->addBuffer(buffer);
        }
        if (!stream_) {
            if (auto delegate = delegate_.lock()) {
                delegate->readingFinished();
            }
            break;
        }
    }
}