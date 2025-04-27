//Header inclusion
#include <iostream>
#include <string>
using namespace std;

//Car class
class Car{
    /*As the following classes are children of Car, the following members are protected
    for easy access*/
    protected:
    string model;
    int year;
    float price;

    public:
    /*Default constructor initializes members to 0 or empty string when no other values
    are present*/
    Car() : model(""), year(0), price(0.0){}

    //Destructor is virtual as this is the base class
    virtual ~Car(){}

    //Inputs for the user
    void inputBasic(){
        cout<<"Enter model: ";
        getline(cin, model);
        cout<<"Enter year: ";
        cin>>year;
        cout<<"Enter price: ";
        cin>>price;
    }

    //Basic display
    void displayBasic() const{
        cout<<"Model: "<<model<<", Year: "<<year<<", Price: $"<<price;
    }
};

//Derived ElectricCar class
class ElectricCar : public Car{
    //Specific member for ElectricCar
    private:
    float batterySize;

    //Public members - default constructor, and input and display functions
    public:
    ElectricCar() : batterySize(0.0){}

    void input(){
        inputBasic();
        cout<<"Enter battery size (kWh): ";
        cin>>batterySize;
    }

    void display() const{
        displayBasic();
        cout<<", Battery: "<<batterySize<<" kWh"<<endl;
    }

    //Destructor for ElectricCar
    ~ElectricCar(){
        cout<<"Destroying Electric Car "<<model<<endl;
    }
};

//Derived GasCar class
class GasCar : public Car{
    //Specific member for GasCar
    private:
    float fuelCapacity;

    //Public members - default constructor, and input and display functions
    public:
    GasCar() : fuelCapacity(0.0){}

    void input(){
        inputBasic();
        cout<<"Enter fuel capacity (L): ";
        cin>>fuelCapacity;
    }

    void display() const{
        displayBasic();
        cout<<", Fuel: "<<fuelCapacity<<" L"<<endl;
    }

    //Destructor
    ~GasCar(){
        cout<<"Destroying Gas Car "<<model<<endl;
    }
};

//Derived HybridCar class
class HybridCar : public Car{
    //Specific members for HybridCar
    private:
    float batterySize, fuelCapacity;

    //Public members - default constructor, and input and display functions
    public:
    HybridCar() : batterySize(0.0), fuelCapacity(0.0){}

    void input(){
        inputBasic();
        cout<<"Enter battery size (kWh): ";
        cin>>batterySize;
        cout<<"Enter fuel capacity (L): ";
        cin>>fuelCapacity;
    }

    void display() const{
        displayBasic();
        cout<<", Battery: "<<batterySize<<" kWh, Fuel: "<<fuelCapacity<<" L"<<endl;
    }

    //Destructor
    ~HybridCar(){
        cout<<"Destroying Hybrid Car "<<model<<endl;
    }
};

int main(){
    int n;

    //User input required to start
    cout<<"Enter total number of cars: ";
    cin>>n;

    /*Creates a new array of n Car pointers and an array of integers to store
    car types*/
    Car** fleet = new Car*[n];
    int* type = new int[n];

    //In the loop, user is asked to choose the type of car
    for(int i=0; i<n; i++){
        cout<<"\nCar "<<i+1<<" type: \n";
        cout<<"[1] Electric\n[2] Gasoline\n[3] Hybrid"<<endl;
        cout<<"Enter choice: ";
        cin>>type[i]; //Car choices are stored in type array
        cin.ignore();

        /*Depending on the car chosen, a new object is created in the
        proper type; <static_cast is used to direct the array to the desired
        car type and the specific input function is called*/
        if(type[i]==1){
            fleet[i] = new ElectricCar();
            static_cast<ElectricCar*>(fleet[i])->input();
        }
        else if(type[i]==2){
            fleet[i] = new GasCar();
            static_cast<GasCar*>(fleet[i])->input();
        }
        else if(type[i]==3){
            fleet[i] = new HybridCar();
            static_cast<HybridCar*>(fleet[i])->input();
        }
    }

    cout<<"\n--- Fleet Information ---"<<endl;

    /*static_cast is again used to call the appropriate display
    function depending on car type*/
    for(int i=0; i<n; i++){
        if(type[i]==1){
            static_cast<ElectricCar*>(fleet[i])->display();
        }
        else if(type[i]==2){
            static_cast<GasCar*>(fleet[i])->display();
        }
        else if(type[i]==3){
            static_cast<HybridCar*>(fleet[i])->display();
        }
    }

    cout<<"\n--- Cleaning up fleet ---"<<endl;
    
    //Element deletion
    for(int i=0; i<n; i++){
        delete fleet[i];
    }

    delete[] fleet;
    delete[] type;
    
    return 0;
}