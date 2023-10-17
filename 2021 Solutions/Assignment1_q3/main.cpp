#include <iostream>
#include <fstream>
#include <map>
#include <cctype>

int main () {
    std::map<char, int> freqMap {{'a',0}, {'e',0}, {'i',0}, {'o',0}, {'u',0}};
    int total=0;
    int rest=0;

    std::ifstream in_file {"./textFile.txt", std::ios::in};
    if(!in_file) {
        std::cerr << "File open error" << std::endl;
        return 1;
    }

    char c;
    while(in_file.get(c)) {
        if(isalpha(c)) {
            total++;
            auto it = freqMap.find(c);
            if (it != freqMap.end()) {
                freqMap[c]++;
            } else {
                rest++;
            }
        }  
    }

    for(auto &pair : freqMap) {
        std::cout << '\''<< pair.first << '\'' << " = " << pair.second << "; ";
    }

    std::cout << "rest: " << rest << std::endl;

    for(auto &pair : freqMap) {
        std::cout << '\''<< pair.first << '\'' << " = " << pair.second/total*100 << "% " << "; ";
    }
    

    in_file.close();
    return 0;
}