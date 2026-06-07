#include "Parser.h"
#include <sstream>

using namespace std;

vector<string>
Parser::tokenize(const string& input)
{
    vector<string> tokens;

    stringstream ss(input);

    string token;

    while(ss >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}
