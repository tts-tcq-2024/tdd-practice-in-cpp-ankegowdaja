#include "StringCalculator.h"
#include <sstream>

int StringCalculator::add(const std::string& input) {
    // Implementation of add method goes here
    if (input.empty()) {
        return 0;
    }
    if (input == "0") {
        return 0;
    }

    // Split input string by comma
    std::istringstream iss(input);
    std::vector<int> numbers;
    std::string token;

    while (std::getline(iss, token, ',')) {
        numbers.push_back(std::stoi(token));
    }

    // Calculate sum of numbers
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }

    return sum;
    // Placeholder implementation for simplicity
   // return 0;
}
