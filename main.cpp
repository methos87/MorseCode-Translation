#include <iostream>
#include <map>
#include <bits/stdc++.h>


std::map <char, std::string> morseTable{{'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
                                        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
                                        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
                                        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
                                        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
                                        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
                                        {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, 
                                        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
                                        {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {'@', ".--.-."},
                                        {'!', "-.-.--"}, {'?', "..--.."}, {'/', "-...-"}, {'=', "-...-"}, {'.', ".-.-.-"}, {',', "--..--"}
                                        };

void seperateString(std::string str, std::vector<std::string>& temp){
    
    std::istringstream ss(str);
    std::string word;
    
    while (getline(ss, word, ' ')){
        temp.push_back(word.c_str());
        //printf("%s\n", word.c_str());       
    }    
}

void print(std::vector<std::string> out){
    
    for(auto i : out){
        std::cout << i << std::endl;
    }
}


std::string decodeMorse(std::string morseCode) {

    //std::cout << morseCode << std::endl;
    std::vector<std::string>temp;  
    std::string decoded = "";
    int count = 0;
     
    seperateString(morseCode, temp);
    
    for (unsigned n = 0; n < temp.size(); n++)
        for (auto& it : morseTable){
            if(it.second == temp[n]){
                decoded = decoded + it.first;
                count = 0;
            }
            else if(temp[n].empty() && temp[n+1].empty() && count < 1){
                decoded = decoded + " ";
                count++;         
            }
            else if(temp[n] == "...---..."){
                decoded = "SOS";
            }
    }

    if(decoded.at(0) == ' '){ 
        decoded.erase(decoded.begin()+0); 
    }
    if(decoded.back() == ' '){ 
        decoded.pop_back(); 
    } 
    
    std::cout << decoded << std::endl;
    return decoded;
}


int main(){

    decodeMorse(".... . -.--   .--- ..- -.. ."); //"HEY JUDE"
    decodeMorse("...---..."); //"SOS"
    decodeMorse(" . "); //"E"
    decodeMorse("       ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.- ");
    //"SOS! THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."
    decodeMorse("   .   .   "); //E E


    return 0;
    
}



