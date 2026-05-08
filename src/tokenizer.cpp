#include <iostream>
#include <string>
#include <vector>


// this tokenizer only handles whitespace at the moment 
// make edits as you go for delimiters. 

void print_tokens(std::vector<std::string> tokens)
{
    for(auto i = 0; i < tokens.size(); i++ )
    {
        std::cout <<"\"" << tokens[i]<< "\"";
    }
    std::cout<<std::endl;
}

std::vector<std::string> tokenize_args(std::string& input)
{
    std::vector<std::string> tokens;
    std::string token;
   
    for(size_t i = 0; i < input.size(); i++)
    {
        char c = input[i];

        //skip whitespace
        if(isspace(c))
        {
            if(!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += c;
        }
    }
    
    //check for any trailing token
    if(!token.empty())
    {
        tokens.push_back(token);
    }

    return tokens;
    
}

