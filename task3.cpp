//Header inclusions
#include <iostream>
#include <string>
using namespace std;

//Car class creation
class Car{
    //Private members
    private:
    string model;
    int year;
    float price;

    public:
    //Default constructor: if nothing is inputted, values are defaulted
    Car() : model(""), year(0), price(0.0){}

    //Parameterized constructor for Car element presentation
    Car(string m, int y, float p) : model(m), year(y), price(p){
        cout<<"Car Constructor: "<<model<<" ("<<year<<") - $"<<price<<endl;
    }

    //Display function
    void display() const{
        cout<<"Model: "<<model<<", Year: "<<year<<", Price: $"<<price<<endl;
    }

    //Destructor
    ~Car(){
        cout<<"Car Destructor: "<<model<<" destroyed"<<endl;
    }
};

//CarCollection class
class CarCollection{
    //Private members
    private:
    Car* cars; //Pointer to Car class
    int size;

    public:
    CarCollection(){
        //Initial user input
        cout<<"How many cars do you want to enter? ";
        cin>>size;
        cin.ignore();

        /*Three temporary arrays are created here to contain 'size' elements.
        If these are not included, only the last inputted
        element will be displayed when constructors are called*/
        string* models = new string[size];
        int* years = new int[size];
        float* prices = new float[size];

        /*The new arrays also work to avoid having to create a cars array
        with 'size' elements at this point. If the cars array were included, the
        parameterized constructor would be called at each iteration (not the
        desired output)*/
        for(int i=0; i<size; i++){
            cout<<"\nEnter model for car "<<i+1<<": ";
            getline(cin, models[i]);
            cout<<"Enter year: ";
            cin>>years[i];
            cout<<"Enter price: ";
            cin>>prices[i];
            cin.ignore();
        }

        //Cars array created with 'size' elements
        cars = new Car[size];

        cout<<"\n";

        for(int i=0; i<size; i++){
            /*The following reference is necessary to ensure that all
            constructors are called in the correct order, one after the other*/
            new (&cars[i]) Car(models[i], years[i], prices[i]);
        }

        cout<<"CarCollection initialized with "<<size<<" cars\n"<<endl;

        //The three arrays above are deleted
        delete[] models;
        delete[] years;
        delete[] prices;
    }

    //Display function from Car class is called here
    void displayCollection() const{
        cout<<"--- Car Collection ---"<<endl;

        for(int i=0; i<size; i++){
           cars[i].display();
        }

        cout<<"\n";
    }

    //Destructor
    ~CarCollection(){
        /*The Car class destructor needs to be explicitly called here, else
        it will appear after each constructor element, leading to an undesired
        output*/
        for(int i=0; i<size; i++){
        cars[i].~Car();
        }

       cout<<"CarCollection destroyed"<<endl;
    }

};

int main(){
    //collections variable with reference to CarCollection class
    CarCollection* collections = new CarCollection();

    collections ->displayCollection(); //Display function for CarCollection

    delete collections;
    return 0;
}