#ifndef COUNTRIES_H
#define COUNTRIES_H

#include <map>
#include <string>

enum Country {
    GR,
    UK
};

inline std::map<Country, std::string> country_codes = {
    {GR, "GR"},
    {UK, "UK"}
};

inline Country get_country_from_string(const std::string& country) {
    for (const auto& [key, value] : country_codes) {
        if (value == country) {
            return key;
        }
    }

    throw std::invalid_argument("Invalid country");
}

#endif //COUNTRIES_H
