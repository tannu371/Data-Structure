#include <iostream>
#include <unordered_map>
#include <vector>

const int ARRAY_SIZE = 4;

std::vector <int> findIndices(int array[], int target) {
    std::unordered_map <int, int> numIndices;
    for(int i=0; i<ARRAY_SIZE; i++) {
        int complement = target - array[i];
        if(numIndices.count(complement)) {
            return {numIndices[complement], i};
        }
        numIndices[complement] = i;
    }
    return {-1};
}

int main () {
    int arr[ARRAY_SIZE];
    int target;
    std::cout << "numbers = ";
    for(int i=0; i<ARRAY_SIZE; i++) {
        std::cin >> arr[i];
    }
    std::cout << "T = ";
    std::cin  >> target;
    
    std::vector<int> result = findIndices(arr, target);

    if(result[0]!=-1) {
        std::cout << "Indices of two numbers are : " << result[0] << result[1] << std::endl;
    } else {
        std::cout << "No such pair exists." << std::endl;
    }

    return 0;
}