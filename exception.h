#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
private:
    std::string errorMessage;
public:
    Exception(const std::string &);
};

#endif // EXCEPTION_H
