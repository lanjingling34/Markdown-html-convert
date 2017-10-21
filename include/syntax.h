#pragma once

#include <istream>
#include <memory>
#include <vector>
#include "noncopyable.h"

namespace md {
class Token;
class Syntax : private noncopyable {
   public:
    virtual bool matched(std::string buf) = 0;

    virtual std::shared_ptr<Token> parse(const std::shared_ptr<Token> prev,
                                         std::string buf,
                                         std::istream &stream) = 0;
    virtual std::shared_ptr<Token> parse(std::istream &stream) = 0;
    virtual std::shared_ptr<Token> parse(std::string buf) = 0;

   protected:
    std::vector<std::string> startsWith_;
    std::vector<std::string> endsWith_;

   public:
    virtual ~Syntax(){};
};
}