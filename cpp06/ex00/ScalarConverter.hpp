#pragma once

#include <string>

enum LiteralType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO,
    TYPE_INVALID
};

class ScalarConverter;

typedef ScalarConverter Scalar;
typedef std::string string;

typedef struct scalar_s {
    string _char;
    string _int;
    string _float;
    string _double;
} scalar_t;

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