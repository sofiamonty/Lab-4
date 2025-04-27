//Task 2 example 2 copied from the PDF
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

//BookShelf class is meant to specifically organize Book elements
class BookShelf{
    private:
    Book* books;
    int size;

    public:
    BookShelf(){
        size = 3;
        //With 'new', objects are created on the heap, making the program scalable and dynamic
        books = new Book[size]{
            Book("C++ Fundamentals", 300),
            Book("Data Structures", 450),
            Book("Algorithms", 500)
        };
        cout<<"BookShelf Constructor: Shelf initialized with: "<<size<<" books\n";
    }

    ~BookShelf(){
        delete[] books;
        cout<<"BookShelf Destructor: Shelf destroyed\n";
    }

    void displayBooks() const{
        cout<<"\nBooks on shelf:\n";
        for(int i=0; i<size; ++i){
            books[i].display();
        }
    }
};

int main(){
    //'new BookShelf' dynamically allocates one BookShelf object on the heap
    BookShelf* shelf = new BookShelf();
    shelf -> displayBooks();

    //In this example, it's necessary to delete any objects before ending the program
    delete shelf;
    cout<<"\n--- End of Program ---\n";
    return 0;
}