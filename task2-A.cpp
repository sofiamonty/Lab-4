//Task 2 example 1. Code copied from the PDF
#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
    string title;
    int pages;

    public:
    Book(string t = "Untitled", int p = 0) : title(t), pages(p){
        cout<<"Constructor: \""<<title<<"\" with "<<pages<<" pages\n";
    }

    ~Book(){
        cout<<"Destructor: \""<<title<<"\" destroyed\n";
    }

    void display() const{
        cout<<"Title: "<<title<<", Pages: "<<pages<<endl;
    }
};

int main(){
    /*A library is declared here (on the stack) with a fixed array.
    In this case, there's no need for manual deletion*/
    Book library[3] = {
        Book("C++ Fundamentals", 300),
        Book("Data Structures", 450),
        Book("Algorithms", 500)
    };

    cout<<"\n--- Library Contents ---\n";
    for(int i=0; i<3; ++i){
        library[i].display();
    }

    cout<<"\n--- End of Program --\n";
    return 0;
}