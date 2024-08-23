#include "CommandRunner.hpp"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>

extern std::string ExecuteCommand(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw IOException("popen() failed!");
    }
    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}