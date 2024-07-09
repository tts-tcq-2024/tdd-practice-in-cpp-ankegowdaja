#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <vector>

int StringCalculator::add(const std::string& input) {
    // Implementation of add method goes here
    if (input.empty()) {
        return 0;
    }
    if (input == "0") {
        return 0;
    }
    std::istringstream stream(input);
    std::string number;
    int sum = 0;
    while (std::getline(stream, number, ',')) {
        int num = std::stoi(number);
        if (num <=1000) {
         sum += num;
        }
    }
    return sum;

    
}
