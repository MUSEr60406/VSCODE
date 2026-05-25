#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class CarbonFootprint
{
public:
    virtual double getCarbonFootprint() const = 0;
    virtual string getInfo() const = 0;
    virtual ~CarbonFootprint() {} 
};

class Building : public CarbonFootprint
{
private:
    string name;
    double electricityUsage;

public:
    Building(string n, double e) : name(n), electricityUsage(e) {};
    double getCarbonFootprint() const override
    {
        return electricityUsage * 0.5;
    }
    string getInfo() const override
    {
        return "Buliding " + name;
    }
};

class Car : public CarbonFootprint
{
private:
    string brand;
    double fuelUsed;

public:
    Car(string b, double f) : brand(b), fuelUsed(f) {};
    double getCarbonFootprint() const override
    {
        return fuelUsed * 2.3;
    }
    string getInfo() const override
    {
        return "Car " + brand;
    }
};

class Bicycle : public CarbonFootprint
{
private:
    string brand;
    double distance;

public:
    Bicycle(string b, double d) : brand(b), distance(d) {};
    double getCarbonFootprint() const override
    {
        return 0.00;
    }
    string getInfo() const override
    {
        return "Bicycle " + brand;
    }
};

int main()
{
    string buildingName, carBrand, bicycleBrand;
    double electricityUsage, fuelUsed, distance;

    cin >> buildingName >> electricityUsage;
    cin >> carBrand >> fuelUsed;
    cin >> bicycleBrand >> distance;

    Building *b = new Building(buildingName, electricityUsage);
    Car *c = new Car(carBrand, fuelUsed);
    Bicycle *bi = new Bicycle(bicycleBrand, distance);

    vector<CarbonFootprint*> items;

    items.push_back(b);
    items.push_back(c);
    items.push_back(bi);

    for (CarbonFootprint* item : items)
    {
        cout << item->getInfo() << ": "
             << fixed << setprecision(2)
             << item->getCarbonFootprint() << endl;
    }

    return 0;
}