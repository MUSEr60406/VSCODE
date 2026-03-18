#include <iostream>
#include <string>
using namespace std;

class Invoice
{
    private:
        string partNumber;
        string partDescription;
        int quantity;
        int pricePerItem;
    
    Invoice(string partN, string partD, int q, int ppi)
    {
            partNumber = partN;
            partDescription = partD;
    }
};

int main()
{
    string partNumber, partDescription;
    int quantity, pricePerItem;

    getline(cin, partNumber);
    getline(cin, partDescription);
    cin >> quantity >> pricePerItem;

    // Create Invoice object
    Invoice invoice(partNumber, partDescription, quantity, pricePerItem);
    cout << "Part Number: " << invoice.getPartNumber() << endl;
    cout << "Part Description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per Item: " << invoice.getPricePerItem() << endl;
    cout << "Invoice Amount: " << invoice.getInvoiceAmount() << endl;

    return 0;
}