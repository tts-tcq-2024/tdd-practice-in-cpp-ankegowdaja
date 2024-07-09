#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator {
public:
    int addnum(const std::string& input);
    int sumOfNumbers(const std::string& input);
    void verifiy_negative_numbers(const std::string& input);
    std::string Delimeterseperation(const std::string& input);
    std::string newlinecheck(const std::string& input);   
 };

#endif 
