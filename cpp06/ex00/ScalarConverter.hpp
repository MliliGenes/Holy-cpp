#pragma once

#include <string>

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    INVALID
};

enum SpecialType {
    NOT_SPECIAL,
    NAN_F,
    POS_INF_F,
    NEG_INF_F,
    NAN_D,
    POS_INF_D,
    NEG_INF_D
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