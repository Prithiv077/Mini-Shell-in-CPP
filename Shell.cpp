#include "Shell.h"

int main() {
    Shell shell;
    shell.run();
    return 0;
}
dellg@PRITHIV:~/project$ cat Shell.h
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

#endif
dellg@PRITHIV:~/project$ cat Shel.cpp
cat: Shel.cpp: No such file or directory
dellg@PRITHIV:~/project$ cat Shell.cpp
#include "Shell.h"
#include "Parser.h"
#include "Builtins.h"
#include "Executor.h"

#include <iostream>

using namespace std;

void Shell::executeCommand(
    const string& command
)
{
    if(command.empty())
        return;

    history.push_back(command);

    vector<string> tokens =
        Parser::tokenize(command);

    bool handled =
        Builtins::execute(
            tokens,
            history,
            this
        );

    if(!handled)
    {
        Executor::execute(tokens);
    }
}

void Shell::run()
{
    while(true)
    {
        cout << "myshell> ";

        string command;

        getline(cin,command);

        executeCommand(command);
    }
}
