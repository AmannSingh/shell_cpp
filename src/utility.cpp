#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <cstdlib>

using namespace std;


filesystem::path find_in_path (string filename)
{

    const char* env_p = getenv("PATH");
    
    if(!env_p){
      return ""; 
    }
   
    string str_env_p(env_p);
    stringstream ss(str_env_p);
   
    #ifdef _WIN32
        char delimiter = ';';
    #else
        char delimiter = ":";
    #endif

    string dir;

    while(getline(ss, dir, delimiter));     //iterate through each directory that is seperated by the delimiter
    {
       for(auto &entry : filesystem::recursive_directory_iterator(dir))
       {
         if(entry.path().filename().stem() == filename)
         {
            return entry.path();
         }
       }
    }
    
    return " ";
    
    
}