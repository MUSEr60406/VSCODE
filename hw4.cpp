#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Package
{
protected:
    string senderName, senderAddress, senderCity, senderState, senderZIP;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZIP;
    double weight;
    double costPerOunce;

public:
    Package(string sName, string sAddress, string sCity, string sState, string sZIP,
            string rName, string rAddress, string rCity, string rState, string rZIP,
            double w, double c)
    {
        senderName = sName;
        senderAddress = sAddress;
        senderCity = sCity;
        senderState = sState;
        senderZIP = sZIP;
        recipientName = rName;
        recipientAddress = rAddress;
        recipientCity = rCity;
        recipientState = rState;
        recipientZIP = rZIP;

        weight = (w > 0.0) ? w : 0.0;
        costPerOunce = (c > 0.0) ? c : 0.0;
    }

    double calculateCost() const
    {
        return weight * costPerOunce;
    }
};

class TwoDayPackage : public Package
{
private:
    double flatFee;

public:
    TwoDayPackage(string sName, string sAddress, string sCity, string sState, string sZIP,
                  string rName, string rAddress, string rCity, string rState, string rZIP,
                  double w, double c, double fee)
    : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, c)
    {
        flatFee = (fee > 0.0) ? fee : 0.0;
    }
    double calculateCost() const
    {
        return Package::calculateCost() + flatFee;
    }
};

class OvernightPackage : public Package
{
private:
    double additionalFeePerOunce;

public:
    OvernightPackage(string sName, string sAddress, string sCity, string sState, string sZIP,
                     string rName, string rAddress, string rCity, string rState, string rZIP,
                     double w, double c, double addFee)
        : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, c)
    {
        additionalFeePerOunce = (addFee > 0.0) ? addFee : 0.0;
    }
    double calculateCost() const
    {
        return weight * (costPerOunce + additionalFeePerOunce);
    }
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int type;
        cin >> type;

        string sName, sAddress, sCity, sState, sZIP;
        string rName, rAddress, rCity, rState, rZIP;
        double weight, costPerOunce;

        cin >> sName >> sAddress >> sCity >> sState >> sZIP;
        cin >> rName >> rAddress >> rCity >> rState >> rZIP;
        cin >> weight >> costPerOunce;

        if (type == 1)
        {
            Package package(sName, sAddress, sCity, sState, sZIP,
                            rName, rAddress, rCity, rState, rZIP,
                            weight, costPerOunce);
            cout << fixed << setprecision(2) << package.calculateCost() << "\n";
        }
        else if (type == 2)
        {
            double flatFee;
            cin >> flatFee;

            TwoDayPackage package(sName, sAddress, sCity, sState, sZIP,
                                  rName, rAddress, rCity, rState, rZIP,
                                  weight, costPerOunce, flatFee);
            cout << fixed << setprecision(2) << package.calculateCost() << "\n";
        }
        else if (type == 3)
        {
            double additionalFeePerOunce;
            cin >> additionalFeePerOunce;

            OvernightPackage package(sName, sAddress, sCity, sState, sZIP,
                                     rName, rAddress, rCity, rState, rZIP,
                                     weight, costPerOunce, additionalFeePerOunce);
            cout << fixed << setprecision(2) << package.calculateCost() << "\n";
        }
    }
    return 0;
}