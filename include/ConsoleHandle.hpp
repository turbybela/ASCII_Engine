#pragma once

#include "Dimensions.hpp"
#include "Exceptions.hpp"

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__linux__)
#define LINUX
#endif

class ConsoleHandle {
    private:
    static ConsoleHandle Singleton;
    ConsoleHandle();

    
    public:
    static ConsoleHandle& GetHandle() { return Singleton; }
    ConsoleHandle(const ConsoleHandle& clone) = default;
    ~ConsoleHandle() = default;

    Dim2D<int> GetSize();
    Dim2D<int> GetCursorPosition();
    void ClearScreen();
};