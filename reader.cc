#include "reader.h"

#include <istream>
#include <memory>
#include <string>

#include "ireader_delegate.h"

constexpr int kBufferSize = 1 << 20;

Reader::Reader(std::istream& is, std::weak_ptr<IReaderDelegate> delegate)
    : stream_(is), delegate_(delegate) {}

void Reader::exec() {
    std::string buffer(kBufferSize, '\0');
    while (true) {
        stream_.get(&buffer[0], kBufferSize);
        if (auto delegate = delegate_.lock()) {
            delegate->addBuffer(buffer);
        }
        if (!stream_.gcount()) {
            if (auto delegate = delegate_.lock()) {
                delegate->readingFinished();
            }
            break;
        }
    }
}