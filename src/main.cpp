#include <iostream>

#include "countries.h"
#include "tax_brackets.h"

Country get_country_from_user() {
    Country country;
    std::string country_str;

    while (true) {
        std::cout << "Please enter your country: ";
        std::cin >> country_str;

        try {
            country = get_country_from_string(country_str);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid country. Please try again." << std::endl;
        }
    }

    return country;
}

double get_income_from_user() {
    double income;

    while (true) {
        std::cout << "Please enter your income: ";
        std::cin >> income;

        if (income < 0) {
            std::cout << "Income cannot be negative. Please try again." << std::endl;
        } else {
            break;
        }
    }

    return income;
}

int main() {
    std::cout << "Welcome to the Tax Calculator!" << std::endl;

    const Country country = get_country_from_user();
    const double income = get_income_from_user();

    const double tax = calculate_tax(country, income);

    std::cout << "Your tax is: " << tax << std::endl;
    std::cout << "Your net income is: " << income - tax << std::endl;

    std::cout << "========================================" << std::endl;
    print_tax_brackets_for_income(country, income);

    std::cout << "Thank you for using the Tax Calculator!" << std::endl;

    return 0;
}
