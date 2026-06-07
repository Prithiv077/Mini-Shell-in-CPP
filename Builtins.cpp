#include "Builtins.h"
#include "Shell.h"
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <fstream>

using namespace std;

bool Builtins::execute(
    const vector<string>& tokens,
    vector<string>& history,
    Shell* shell
)
{
    if(tokens.empty())
        return true;

    string cmd = tokens[0];

    //--------------------------------
    // exit
    //--------------------------------

    if(cmd == "exit")
    {
        exit(0);
    }

    //--------------------------------
    // pwd
    //--------------------------------

    if(cmd == "pwd")
    {
        char cwd[PATH_MAX];

        if(getcwd(cwd,sizeof(cwd)))
        {
            cout << cwd << endl;
        }

        return true;
    }

    //--------------------------------
    // cd
    //--------------------------------

    if(cmd == "cd")
    {
        if(tokens.size() < 2)
        {
            cerr << "cd: missing argument\n";
        }
        else
        {
            if(chdir(tokens[1].c_str()) != 0)
            {
                perror("cd");
            }
        }

        return true;
    }

    //--------------------------------
    // history
    //--------------------------------

    if(cmd == "history")
    {
        for(int i=0;i<history.size();i++)
        {
            cout
                << i+1
                << " "
                << history[i]
                << endl;
        }

        return true;
    }

    //--------------------------------
    // source
    //--------------------------------

    //-----------------------------------
// source
//-----------------------------------

if(cmd == "source")
{
    if(tokens.size() < 2)
    {
        cerr << "source: missing filename\n";
        return true;
    }

    ifstream fin(tokens[1]);

    if(!fin)
    {
        cerr << "Cannot open file\n";
        return true;
    }

    string line;

    while(getline(fin,line))
    {
        if(line.empty())
            continue;

        shell->executeCommand(line);
    }

    fin.close();

    return true;
}

    return false;
}
