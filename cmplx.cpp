#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

struct complex_t
{
    float real;
    float imag;
};

bool read(istream& stream, complex_t& complex)
{
    char op;
    bool r = true;
    double r2, i2;
    if (stream >> op && op == '(' && stream >> r2 && stream >> op && op == ',' && stream >> i2
        && stream >> op && op == ')')
    {
        complex.real = r2;
        complex.imag = i2;
    }
    else
    {
        r = false;
        cout << "An error has occured while reading input data";
    }
    return r;
}
ostream& write(ostream& stream, complex_t complex)
{
    (stream << '(' << complex.real << ',' << complex.imag << ')' << endl);
}
complex_t sum(complex_t r1, complex_t i1)
{
    complex_t complex;
    complex.real = r1.real + i1.real;
    complex.imag = r1.imag + i1.imag;
    return complex;
}

complex_t sub(complex_t r1, complex_t i1)
{
    complex_t complex;
    complex.real = r1.real - i1.real;
    complex.imag = r1.imag - i1.imag;
    return complex;
}

complex_t mul(complex_t r1, complex_t i1)
{
    complex_t complex;
    complex.real = r1.real * i1.real - r1.imag * i1.imag;
    complex.imag = r1.imag * i1.real + r1.real * i1.imag;
    return complex;
}

complex_t div(complex_t r1, complex_t i1)
{
    complex_t complex;
    complex.real
        = (r1.real * i1.real + r1.imag * i1.imag) / (i1.real * i1.real + i1.imag * i1.imag);
    complex.imag
        = (r1.imag * i1.real - r1.real * i1.imag) / (i1.real * i1.real + i1.imag * i1.imag);
    return complex;
}

int main()
{
    complex_t r1, i1, res;
    char op;
    string string;
    getline(cin, string);
    istringstream stream(string);
    if (read(stream, r1))
    {
        if (stream >> op)
        {
            if (read(stream, i1))
            {
                switch (op)
                {
                    case '+':
                    {
                        res = sum(r1, i1);
                        break;
                    };
                    case '-':
                    {
                        res = sub(r1, i1);
                        break;
                    };
                    case '*':
                    {
                        res = mul(r1, i1);
                        break;
                    };
                    case '/':
                    {
                        res = div(r1, i1);
                        break;
                    };
                    default:
                    {
                        cout << "Wrong symbol" << endl;
                        break;
                    };
                }
                write(cout, res);
            }
        }
    }
}
