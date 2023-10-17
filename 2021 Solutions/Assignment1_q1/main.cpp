#include<iostream>
#include<unordered_map>

int main () {
    int arr[1000];
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::cout << "Enter the elements in the array: ";
    for(int i=0; i<n; i++) 
        std::cin >> arr[i];
    
    std::unordered_map<int, int> freqMap;
    for(int i=0; i<n; i++)
        freqMap[arr[i]]++;

    int totalDistinctElements=0;
    int duplicatedCount=0;

    for(auto &pair: freqMap) {
        if (pair.second > 1) 
            duplicatedCount++;
        else
            totalDistinctElements++;
    }

    if(duplicatedCount >= totalDistinctElements/2)
        std::cout << "It's a duplicity-bound array" << std::endl;
    else
        std::cout << "As " << duplicatedCount << " ≱ " << totalDistinctElements << " / 2 " << "So, the O/P is: " << duplicatedCount << std::endl;  

    return 0;
}