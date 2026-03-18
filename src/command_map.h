#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include "commands.h"

using namespace std;

inline unordered_map< string, function<int(vector<string>)>> command_map = 
{

    {"exit", cmd_exit},
    {"echo", cmd_echo}
};