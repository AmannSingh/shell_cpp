#include <iostream>
#include <string>
#include <vector>

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