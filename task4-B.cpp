//Task 4 part 2 copied from the PDF - getline() used without cin.ignore()
#include <iostream>
#include <string>
using namespace std;

int main(){
    int age;
    string name;
    
    cout<<"Enter your age: ";
    cin>>age;

    cout<<"Enter your full name: ";
    getline(cin, name);

    cout<<"Age: "<<age<<", Name: "<<name<<endl;

}