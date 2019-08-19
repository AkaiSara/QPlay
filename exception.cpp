#include "exception.h"

Exception::Exception(const std::string & ER): errorMessage(ER) {}

std::string Exception::getErrorMessage() const{
    return errorMessage;
}
