#pragma once

#include <string>
#include <ostream>

class Exception{
    private:
    std::string Type;
    std::string Message;
    public:
    Exception(std::string msg, std::string type = "Exception") : Message(msg), Type(type) {} 
    std::ostream& Print(std::ostream& os) const { return os << "Exception: " << Message; }
};

class NotImplementedException : public Exception {
    public:
    NotImplementedException(std::string msg) : Exception(msg, "NotImplementedException") {}
};

class FailedOperationException : public Exception {
    public:
    FailedOperationException(std::string msg) : Exception(msg, "FailedOperationException") {}
};