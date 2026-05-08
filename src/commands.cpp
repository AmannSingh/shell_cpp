#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <shell_cpp/command_map.hpp> 
#include <shell_cpp/utility.hpp>


int cmd_exit(std::vector<std::string> args)
{
  exit(0);
}

int cmd_echo(std::vector<std::string> args)
{
  if(args.empty())
  {
    std::cout << std::endl;
    return 0;
  }

  std::string str = args[0];

  for(int i = 1; i< args.size(); i++)
  {
    str += " " + args[i];
  }

  std::cout<< str << std::endl;

  return 0;
}

int cmd_type(std::vector<std::string> args)
{
  if(args.size()<1)
  {
    std::cerr << "type: missing arguments" << std::endl;
    return 0;
  }

  auto it = command_map.find(args [0]);

  //check if command is in command map

  if(it != command_map.end())
  {
    std::cout<<args[0]<<" is a shell built-in"<<std::endl;
    return 0;
  }
  else
  {
    const char* env_p = getenv("PATH");

    return 0;
  }
  
  std::cout<<args[0]<<": not found"<<std::endl;
  return 1;

}