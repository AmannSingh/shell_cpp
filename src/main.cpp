#include <iostream>
#include "command_map.h"
#include "tokenizer.h"
#include <string>
#include <vector>
using namespace std;


int execute(string& input) 
{

  //tokenizer 
  vector<string> tokens = tokenize_args(input);
  if (tokens.empty()) return 0; 
  
  string command_name = tokens[0];

  auto it = command_map.find(command_name);
  vector<string> args(tokens.begin() + 1, tokens.end());

  if(it == command_map.end())
  { 
    cerr << input << ": command not found"<<endl;
    return 1;
  }
  else
  {
    return it->second(args);
  }

  return 0;
}
// create shell command functions and add them to dictionary 
//exit
//echo


int main() 
{
  // Flush after every std::cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;  
  int last_exit_status = 0;

  while(true)
  {
    cout << "$ ";
    string input; 
    if(!getline(cin,input)) break;    // ctrl + D exit
    if(input.empty()) continue;       //blank line, re-prompt
    last_exit_status = execute(input);
  }

  return last_exit_status;
}

