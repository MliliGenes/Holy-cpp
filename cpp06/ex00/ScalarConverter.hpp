#pragma once

#include <string>

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};


class ScalarConverter;

typedef ScalarConverter Scalar;
typedef std::string string;

class ScalarConverter {

    private:
        // you can not init and instance from this class so the methods are private
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);

    public:
        static void convert(const string &literal);

};