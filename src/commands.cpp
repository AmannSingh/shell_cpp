#include <iostream>
#include <string>
#include <vector>
#include "command_map.h"

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

  if(it != command_map.end())
  {
    cout<<args[0]<<" is a shell built-in"<<endl;
    return 0;
  }
  else
  {
    cout<<args[0]<<": not found"<<endl;
    return 1;
  }

}