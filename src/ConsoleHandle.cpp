#include "ConsoleHandle.hpp"

#ifdef WINDOWS
    #include <Windows.h>

    HANDLE hConsoleOutput;
#endif
ConsoleHandle ConsoleHandle::Singleton = ConsoleHandle();

ConsoleHandle::ConsoleHandle(){
    #ifdef WINDOWS
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsoleOutput == INVALID_HANDLE_VALUE)
            throw FailedOperationException("_WINDOWS_ GetStdHandle failed.");
    #endif
}

#ifdef LINUX

Dim2D<int> ConsoleHandle::GetSize(){
    throw NotImplementedException("LINUX_GetSize");
}

Dim2D<int> ConsoleHandle::GetCursorPosition(){
    throw NotImplementedException("LINUX_GetCursorPosition");
}

void ConsoleHandle::ClearScreen(){
    throw NotImplementedException("LINUX_ClearScreen");
}

Dim2D<int> SetCursorPosition(Dim2D<int> pos){
    throw NotImplementedException("LINUX_SetCursorPos DIM");
}
Dim2D<int> SetCursorPosition(int x, int y){
    throw NotImplementedException("LINUX_SetCursorPos XY");
}

Dim2D<int> PutChar(char chr){
    throw NotImplementedException("LINUX_PutChar");
}
Dim2D<int> PutSequence(const char* sequence, int lenght){
    throw NotImplementedException("LINUX_PutSequence");
}
Dim2D<int> PutSequence(const char* str){
    throw NotImplementedException("LINUX_PutSequence STR");
}
#endif

// --------------------------------------------------------------------------------

#ifdef WINDOWS

CONSOLE_SCREEN_BUFFER_INFO CH_GetCSBI(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    return csbi;
}

Dim2D<int> ConsoleHandle::GetSize(){
    CONSOLE_SCREEN_BUFFER_INFO csbi = CH_GetCSBI();

    int columns, rows;
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return Dim2D(columns, rows);
}

Dim2D<int> ConsoleHandle::GetCursorPosition(){
    CONSOLE_SCREEN_BUFFER_INFO csbi = CH_GetCSBI();

    int x,y;
    x = csbi.dwCursorPosition.X;
    y = csbi.dwCursorPosition.Y;
    return Dim2D(x, y);
}

void ConsoleHandle::ClearScreen(){
    system("cls");
}

Dim2D<int> ConsoleHandle::SetCursorPosition(Dim2D<int> pos){

}
Dim2D<int> ConsoleHandle::SetCursorPosition(int x, int y){
    
}

Dim2D<int> ConsoleHandle::PutChar(char chr){
    std::cout << chr;
    return GetCursorPosition();
}
Dim2D<int> ConsoleHandle::PutSequence(const char* sequence, int lenght){
    std::cout.write(sequence, lenght);
    return GetCursorPosition();
}
Dim2D<int> ConsoleHandle::PutSequence(const char* str){
    std::cout << str;
    return GetCursorPosition();
    
}
#endif