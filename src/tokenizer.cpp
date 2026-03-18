#include <iostream>
#include <string>
#include <vector>

using namespace std;

// this tokenizer only handles whitespace at the moment 
// make edits as you go for delimiters. 

void print_tokens(vector<string> tokens)
{
    for(auto i = 0; i < tokens.size(); i++ )
    {
        cout <<"\"" << tokens[i]<< "\"";
    }
    cout<<endl;
}

vector<string> tokenize_args(string& input)
{
    vector<string> tokens;
    string token;
   
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

