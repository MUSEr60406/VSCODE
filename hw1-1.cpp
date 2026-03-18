#include <iostream>
#include <string>
#include <limits> // Included to handle potential input buffer issues

using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    int pricePerItem;

public:
    Invoice(string pNum, string pDesc, int qty, int price) {
        partNumber = pNum;
        partDescription = pDesc;
        setQuantity(qty);
        setPricePerItem(price);
    }
    void setPartNumber(string pNum) 
    {
        partNumber = pNum;
    }
    void setPartDescription(string pDesc) 
    {
        partDescription = pDesc;
    }
    void setQuantity(int qty) 
    {
        quantity = (qty > 0 ? qty : 0);
    }
    void setPricePerItem(int price) 
    {
        pricePerItem = (price > 0 ? price : 0);
    }
    //
    string getPartNumber() const 
    { 
        return partNumber; 
    }
    string getPartDescription() const 
    { 
        return partDescription; 
    }
    int getQuantity() const 
    { 
        return quantity; 
    }
    int getPricePerItem() const 
    { 
        return pricePerItem; 
    }
    int getInvoiceAmount() const 
    {
        return quantity * pricePerItem;
    }
};

int main() {
    string partNumber, partDescription;
    int quantity, pricePerItem;

    getline(cin, partNumber);
    getline(cin, partDescription);
    cin >> quantity >> pricePerItem;

    Invoice invoice(partNumber, partDescription, quantity, pricePerItem);
    cout << "Part Number: " << invoice.getPartNumber() << endl;
    cout << "Part Description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per Item: " << invoice.getPricePerItem() << endl;
    cout << "Invoice Amount: " << invoice.getInvoiceAmount() << endl;

    return 0;
}