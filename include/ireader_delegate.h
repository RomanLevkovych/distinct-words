#ifndef IREADER_DELEGATE_H
#define IREADER_DELEGATE_H

#include <string_view>

class IReaderDelegate {
public:
    virtual void addBuffer(std::string_view buffer) = 0;
    virtual void readingFinished() = 0;
    virtual ~IReaderDelegate() = default;
};

#endif // IREADER_DELEGATE_H