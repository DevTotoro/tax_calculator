#ifndef TAX_BRACKETS_H
#define TAX_BRACKETS_H

#include <map>
#include <vector>

#include "countries.h"

struct TaxBracket {
    double lower_bound;
    double upper_bound;
    double tax_rate;
};

inline std::map<Country, std::vector<TaxBracket>> tax_brackets = {
    {GR, {
        {0, 20000, 0.22},
        {20001, 30000, 0.29},
        {30001, 40000, 0.37},
        {40001, std::numeric_limits<double>::max(), 0.45}
    }},
    {UK, {
        {0, 12570, 0},
        {12571, 50270, 0.2},
        {50271, 125140, 0.4},
        {125141, std::numeric_limits<double>::max(), 0.45}
    }}
};

inline double calculate_tax(const Country& country, const double& income) {
    double tax = 0;

    for (const auto& [lower_bound, upper_bound, tax_rate] : tax_brackets.at(country)) {
        if (income > lower_bound) {
            tax += (std::min(upper_bound, income) - lower_bound) * tax_rate;
        }
    }

    return tax;
}

inline void print_tax_brackets_for_income(const Country& country, const double& income) {
    std::cout << "Tax brackets for income " << income << " in " << country_codes.at(country) << ":" << std::endl;

    for (const auto& [lower_bound, upper_bound, tax_rate] : tax_brackets.at(country)) {
        if (income > lower_bound) {
            std::cout << "From " << lower_bound << " to " << upper_bound << ": " << tax_rate * 100 << "%" << std::endl;
        }
    }
}

#endif //TAX_BRACKETS_H
