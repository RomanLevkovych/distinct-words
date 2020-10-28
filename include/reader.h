#ifndef READER_H
#define READER_H

#include <istream>
#include <memory>

#include "ireader_delegate.h"

class Reader {
   public:
    explicit Reader(std::istream& is, std::weak_ptr<IReaderDelegate> delegate);
    void exec();

   private:
    std::istream& stream_;
    std::weak_ptr<IReaderDelegate> delegate_;
};

#endif  // READER_H