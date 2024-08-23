#pragma once

#include "Dimensions.hpp"
#include "Exceptions.hpp"

#include <iostream>

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

    Dim2D<int> SetCursorPosition(Dim2D<int> pos);
    Dim2D<int> SetCursorPosition(int x, int y);

    Dim2D<int> PutChar(char chr);
    Dim2D<int> PutSequence(const char* sequence, int lenght);
    Dim2D<int> PutSequence(const char* str);

};