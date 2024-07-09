#include "StringCalculator.h"
#include <sstream>
#include <algorithm>

int StringCalculator::add(const std::string& input) {
  if (input.empty()) {
        return 0;
    }
   if (input == "0") {
        return 0;
    }

  std::string processedInput = handleCustomDelimiter(input);
  processedInput = normalizeDelimiters(processedInput);
  checkForNegativeNumbers(processedInput);
  return sumOfNumbers(processedInput);  
    
}

int StringCalculator::sumOfNumbers(const std::string& input) {
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



void StringCalculator::checkForNegativeNumbers(const std::string& input) {
    std::istringstream stream(input);
    std::string number;
    std::vector<int> negativeNumbers;

    while (std::getline(stream, number, ',')) {
        int num = std::stoi(number);
        if (num < 0) {
            negativeNumbers.push_back(num);
        }
    }

    if (!negativeNumbers.empty()) {
        std::ostringstream message;
        message << "Negative numbers not allowed: ";
        for (size_t i = 0; i < negativeNumbers.size(); ++i) {
            if (i > 0) message << ", ";
            message << negativeNumbers[i];
        }
        throw std::runtime_error(message.str());
    }
}

std::string StringCalculator::normalizeDelimiters(const std::string& input) {
    std::string result = input;
    std::replace(result.begin(), result.end(), '\n', ',');
    return result;
}

std::string StringCalculator::handleCustomDelimiter(const std::string& input) {
    if (input.substr(0, 2) == "//") {
        std::string delimiter = input.substr(2, input.find('\n') - 2);
        std::string rest = input.substr(input.find('\n') + 1);
        std::replace(rest.begin(), rest.end(), delimiter[0], ',');
        return rest;
    }
    return input;
}




