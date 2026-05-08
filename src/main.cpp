#include <iostream>
#include <shell_cpp/command_map.hpp>
#include <shell_cpp/tokenizer.hpp> 
#include <string>
#include <vector>


int execute(std::string& input) 
{

  //tokenizer 
  std::vector<std::string> tokens = tokenize_args(input);
  if (tokens.empty()) return 0; 
  
  std::string command_name = tokens[0];

  auto it = command_map.find(command_name);
  
  std::vector<std::string> args(tokens.begin() + 1, tokens.end());    // retrieves the args after the command

  if(it == command_map.end())
  { 
    std::cerr << input << ": command not found"<< std::endl;
    return 1;
  }
  else
  {
    return it->second(args);
  }

  return 0;
}



int main() 
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;  
  int last_exit_status = 0;

  while(true)
  {
    std::cout << "$ ";
    std::string input; 
    if(!std::getline(std::cin,input)) break;    
    if(input.empty()) continue;       //blank line, re-prompt
    last_exit_status = execute(input);
  }

  return last_exit_status;
}

