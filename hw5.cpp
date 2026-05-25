#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class CarbonFootprint
{
public:
    // write the pure virtual functions getCarbonFootprint, getInfo,
    // and a virtual destructor
    // <<< please write your code in here!
};

class Building : public CarbonFootprint
{
private:
    string name;
    double electricityUsage;

public:
    // <<< please write your code in here!
};

class Car : public CarbonFootprint
{
private:
    string brand;
    double fuelUsed;

public:
    // <<< please write your code in here!
};

class Bicycle : public CarbonFootprint
{
private:
    string brand;
    double distance;

public:
    // <<< please write your code in here!
};

int main()
{
    string buildingName, carBrand, bicycleBrand;
    double electricityUsage, fuelUsed, distance;

    cin >> buildingName >> electricityUsage;
    cin >> carBrand >> fuelUsed;
    cin >> bicycleBrand >> distance;

    // Create objects
    // <<< please write your code in here!

    vector<CarbonFootprint*> items;

    // Add objects into the vector
    // <<< please write your code in here!

    for (CarbonFootprint* item : items)
    {
        cout << item->getInfo() << ": "
             << fixed << setprecision(2)
             << item->getCarbonFootprint() << endl;
    }

    return 0;
}