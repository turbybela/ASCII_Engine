#include <iostream>
#include <thread>
#include <chrono>

#include "ConsoleHandle.hpp"

int main(int argc, char const *argv[])
{
    try{
    ConsoleHandle handle = ConsoleHandle::GetHandle();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        handle.ClearScreen();
        auto size = handle.GetSize();
        std::cout << "Size: (" << size.X << ", " << size.Y << ")" << std::endl;
        auto pos = handle.GetCursorPosition();
        std::cout << "Pos: (" << pos.X << ", " << pos.Y << ")" << std::endl;
         
    }
    
    }
    catch (const Exception& ex)
    {
        ex.Print(std::cout);
        std::cout << std::endl;
    }
    return 0;
}
