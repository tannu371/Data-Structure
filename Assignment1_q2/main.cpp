#include<iostream>
#include<map>

int main() {
    std::map<int, int> freqMap {{1,0}, {3,0}, {5,0}, {7,0}, {9,0}};
    int num=0;
    while(true) {
        std::cout << "Enter the elements in the data stream (-1) to end: ";
        std::cin >> num;
        if(num==-1)
            break;

        while(num>0) {
            auto it = freqMap.find(num%10);
            if(it!= freqMap.end())
                freqMap[num%10]++;
            num /= 10;
        }
    }

    std::cout << "Odd digits: 1 3 5 7 9 "<< std::endl;
    std::cout << "Frequency: ";
    for(auto pair:freqMap) 
        std::cout << pair.second << " ";

    return 0;
}