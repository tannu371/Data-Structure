#include <iostream>
#include <list>
#include <string>

void printList (std::list<std::string> l) {
    for(auto s : l) {
        std::cout << s << std::endl;
    }
}

int main() {
    std::list <int> buyingStocks;
    std::list <std::string> output;
    int q;
    std::cout << "q = ";
    std::cin >> q;
    while(q--) {
        char operation;
        std::cin >> operation;
        if (operation == 'B') {
            int price;
            std::cin >> price;
            buyingStocks.emplace_back(price);
            output.emplace_back("Buying Successful");
        } else if (operation == 'S') {
            int X, Y;
            std::cin >> X >> Y;

            bool found = false;
            for(auto it = buyingStocks.begin(); it != buyingStocks.end(); it++) {
                if(*it >= X && *it <= Y) {
                    output.emplace_back(std::to_string(*it));
                    buyingStocks.erase(it);
                    found = true;
                    break;
                }
            }
            if(!found) {
                output.emplace_back("-1");
            }
        }
    }

    printList(output);

    return 0;
}