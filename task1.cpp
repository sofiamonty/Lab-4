//Header inclusion
#include <iostream>
using namespace std;

//Complex class
class Complex{
    //Private members
    private:
    double real;
    double imag;

    public:
    //Constructor and destructor
    Complex(double r=0, double i=0) : real(r), imag(i){}

    ~Complex(){}

    //Overloading + operator to sum two complex numbers
    Complex operator +(const Complex& other) const{
        return Complex(real + other.real, imag + other.imag);
    }

    //Overloading - operator to subtract two complex numbers
    Complex operator -(const Complex& other) const{
        return Complex(real - other.real, imag - other.imag);
    }

    //Overloading / operator to divide two complex numbers
    Complex operator /(const Complex& other) const{
        Complex result;
        double den = other.real*other.real+other.imag*other.imag;
        result.real = (real*other.real+imag*other.imag)/den;
        result.imag = (imag*other.real-real*other.imag)/den;
        return result;
    }

    //Overloading << operator via friend function
    friend ostream& operator<<(ostream& out, const Complex& obj);
};

//Defining the friend function
ostream& operator<<(ostream& out, const Complex& obj){
    out<<obj.real;
    if(obj.imag<0){out<<" - "<<-obj.imag<<"i";}
    else{out<<" + "<<obj.imag<<"i";}
    return out;
}

int main(){
    Complex c1(4,5), c2(2,-3); //Defining the two complex numbers

    cout<<"c1 = "<<c1<<endl; //Outputs c1
    cout<<"c2 = "<<c2<<endl; //Outputs c2
    cout<<"Sum = "<<c1+c2<<endl; //Outputs sum
    cout<<"Difference = "<<c1-c2<<endl; //Outputs difference
    cout<<"Quotient = "<<c1/c2<<endl; //Outputs quotient

    return 0;
}