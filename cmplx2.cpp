#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class complex_t
{
public:
    complex_t()
    {
        real = 0.0f;
        imag = 0.0f;
    }
    complex_t mult(complex_t other) const
    {
        complex_t result;
        result.real = this->real * other.real - this->imag * other.imag;
        result.imag = this->imag * other.real - this->real * other.imag;
        return result;
    }
    complex_t div(complex_t other) const
    {
        complex_t result;
        result.real = (this->real * other.real + this->real * other.imag)
            / (other.real * other.real + other.imag * other.imag);
        result.imag = (this->imag * other.real - this->real * other.imag)
            / (other.real * other.real + other.imag * other.imag);
        return result;
    }
    complex_t sub(complex_t other) const
    {
        complex_t result;
        result.real = this->real - other.real;
        result.imag = this->imag - other.imag;
        return result;
    }
    complex_t add(complex_t other) const
    {
        complex_t result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }
    istream& input(std::istream& stream)
    {
        char op, op1, op2;
        if (stream >> op && op == '(' && stream >> real && stream >> op1 && op1 == ','
            && stream >> imag && stream >> op2 && op2 == ')')
        {
        }
        return stream;
    }
    ostream& output(std::ostream& stream)
    {
        return stream << '(' << real << "," << imag << ')';
    }
    ~complex_t()
    {
    }

private:
    float real;
    float imag;
};

int main()
{
    complex_t cmplx1, cmplx2, result;
    char op;
    string str;
    getline(cin, str);
    istringstream ptk(str);
    if (cmplx1.input(ptk) && ptk >> op && cmplx2.input(ptk))
    {
        switch (op)
        {
            case '+':
            {
                complex_t result = cmplx1.add(cmplx2);
                result.output(cout);
                break;
            }
            case '-':
            {
                result = cmplx1.sub(cmplx2);
                result.output(cout);
                break;
            }
            case '*':
            {
                result = cmplx1.mult(cmplx2);
                result.output(cout);
                break;
            }
            case '/':
            {
                result = cmplx1.div(cmplx2);
                result.output(cout);
                break;
            }
            default:
            {
                cout << "An error has occured while reading input data";
                break;
            }
        }
    }
    else
    {
        cout << "An error has occured while reading input data";
    }
}
