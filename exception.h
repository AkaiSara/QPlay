#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
private:
    std::string errorMessage;
public:
    Exception(const std::string &);
    std::string getErrorMessage() const;
};

#endif // EXCEPTION_H
