
#include "ScalarConverter.hpp"
#include <iostream>

// int main()
// {
// 	std::cout << "=== CHAR ===" << std::endl;
// 	ScalarConverter::convert("'a'");
// 	ScalarConverter::convert("'z'");
// 	ScalarConverter::convert("' '");

// 	std::cout << "=== INTEGER ===" << std::endl;
// 	ScalarConverter::convert("1234");
// 	ScalarConverter::convert("-124");
// 	ScalarConverter::convert("0");
// 	ScalarConverter::convert("123412313123123123123");

// 	std::cout << "=== FLOAT ===" << std::endl;
// 	ScalarConverter::convert("0.5f");
// 	ScalarConverter::convert(".5f");
// 	ScalarConverter::convert("0.512312312f");
// 	ScalarConverter::convert("128319083012983098.5f");
// 	ScalarConverter::convert("-5.5f");
// 	ScalarConverter::convert("-1231231.5f");
// 	ScalarConverter::convert("+inf");

// 	std::cout << "=== DOUBLE ===" << std::endl;
// 	ScalarConverter::convert("0.5");
// 	ScalarConverter::convert("0.59128390123");
// 	ScalarConverter::convert("0.5");
// 	ScalarConverter::convert("12371892379.23");
// 	ScalarConverter::convert("-inf");
// }

int main()
{
    std::cout << "=== CHAR EDGE CASES ===" << std::endl;
    ScalarConverter::convert("'A'");     // Normal
    ScalarConverter::convert("'\\n'");   // Escape char (if supported)
    ScalarConverter::convert("' '");     // Space
    ScalarConverter::convert("'~'");     // Last displayable (126)
    ScalarConverter::convert("'\\x7F'"); // DEL (127) - non-displayable
    
    std::cout << "=== INTEGER BOUNDARIES ===" << std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("-1");
    ScalarConverter::convert("127");     // char boundary
    ScalarConverter::convert("128");     // beyond char
    ScalarConverter::convert("2147483647");  // INT_MAX
    ScalarConverter::convert("-2147483648"); // INT_MIN
    ScalarConverter::convert("2147483648");  // INT_MAX + 1
    ScalarConverter::convert("-2147483649"); // INT_MIN - 1
    
    std::cout << "=== FLOAT PRECISION TESTS ===" << std::endl;
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("0.5f");
    ScalarConverter::convert("0.4999999f");
    ScalarConverter::convert("0.5000001f");
    ScalarConverter::convert("42.0f");   // Whole number as float
    ScalarConverter::convert("42.5f");
    ScalarConverter::convert("3.40282e+38f");  // Near float max
    ScalarConverter::convert("-3.40282e+38f"); // Near float min
    ScalarConverter::convert("1e-45f");        // Near float min positive
    
    std::cout << "=== DOUBLE PRECISION TESTS ===" << std::endl;
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("0.5");
    ScalarConverter::convert("42.0");    // Whole number as double
    ScalarConverter::convert("42.5");
    ScalarConverter::convert("1.79769e+308");   // Near double max
    ScalarConverter::convert("-1.79769e+308");  // Near double min
    
    std::cout << "=== SPECIAL VALUES ===" << std::endl;
    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("-inff");
    
    std::cout << "=== INVALID INPUTS ===" << std::endl;
    ScalarConverter::convert("");           // Empty
    ScalarConverter::convert("hello");      // Random string
    ScalarConverter::convert("123abc");     // Mixed
    ScalarConverter::convert("12.34.56f");  // Multiple dots
    ScalarConverter::convert("--123");      // Double sign
    ScalarConverter::convert("++456");      // Double sign
    ScalarConverter::convert("123f");       // Int with f suffix
    ScalarConverter::convert("123.0");      // Double without f
    
    std::cout << "=== FORMATTING TESTS ===" << std::endl;
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("42.5f");
    ScalarConverter::convert("42.5");
    
    return 0;
}