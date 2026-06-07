#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>

class Shell
{
private:

    std::vector<std::string> history;

public:

    void run();

    void executeCommand(
        const std::string& command
    );
};
