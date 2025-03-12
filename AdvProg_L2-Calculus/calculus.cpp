#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
const int TERMS = 10; // Số lượng số hạng trong chuỗi Taylor


double myCos(double x) 
{
    double term = 1.0; // Giá trị đầu tiên của chuỗi Taylor
    double sum = term;

    for (int n = 1; n < TERMS; ++n) 
    {
        term *= -x * x / (2 * n * (2 * n - 1));
        sum += term;
    }

    return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x) 
{
    double term = x; // Giá trị đầu tiên của chuỗi Taylor
    double sum = term;

    for (int n = 1; n < TERMS; ++n) 
    {
        term *= -x * x / ((2 * n + 1) * (2 * n)); // Cập nhật số hạng
        sum += term;
    }

    return sum;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    if (x == 0) return 0; // Căn bậc hai của 0 là 0

    double guess = x;
    const double epsilon = 1e-6; // Sai số chấp nhận

    while (fabs(guess * guess - x) > epsilon) {
        guess = (guess + x / guess) / 2;
    }

    return guess;
}
