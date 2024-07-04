#include "StringCalculator.h"
#include <sstream>

int StringCalculator::add(const std::string& input) {
    int sum = 0;
    std::istringstream iss(input);
    std::string num;

    while (std::getline(iss, num, ',')) {
        if (!num.empty()) {
            sum += std::stoi(num);
        }
    }

    return sum;
}
