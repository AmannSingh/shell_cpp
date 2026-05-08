#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <cstdlib>


namespace fs = std::filesystem;

fs::path find_in_path (std::string filename)
{

    const char* env_p = getenv("PATH");
    
    if(!env_p){
      return ""; 
    }
   
    std::string str_env_p(env_p);
    std::stringstream ss(str_env_p);
   
    #ifdef _WIN32
        char delimiter = ';';
    #else
        char delimiter = ":";
    #endif

    std::string dir;

    while(getline(ss, dir, delimiter))    //iterate through each directory that is seperated by the delimiter
    {
       for(auto &entry : fs::recursive_directory_iterator(dir))
       {
         if(entry.path().filename().stem() == filename)
         {
            return entry.path();
         }
       }
    }
    
    return " ";
    
    
}