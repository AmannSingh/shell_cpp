#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <shell_cpp/command_map.hpp> 
#include <shell_cpp/utility.hpp>

using namespace std;

int cmd_exit(vector<string> args)
{
  exit(0);
}

int cmd_echo(vector<string> args)
{
  string str = args[0];

  for(auto i = 1; i< args.size(); i++)
  {
    str += " " + args[i];
  }

  cout<< str << endl;

  return 0;
}

int cmd_type(vector<string> args)
{
  auto it = command_map.find(args [0]);

  //check if command is in command map

  if(it != command_map.end())
  {
    cout<<args[0]<<" is a shell built-in"<<endl;
    return 0;
  }
  else
  {
    const char* env_p = getenv("PATH");

    return 0;
  }
  
  cout<<args[0]<<": not found"<<endl;
  return 1;

}