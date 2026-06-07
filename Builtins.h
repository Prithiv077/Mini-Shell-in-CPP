#ifndef BUILTINS_H
#define BUILTINS_H

#include <vector>
#include <string>

class Shell;

class Builtins
{
public:

    static bool execute(
        const std::vector<std::string>& tokens,
        std::vector<std::string>& history,
        Shell* shell
    );
};

#endif
