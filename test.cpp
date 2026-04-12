#include <iostream>
#include <iomanip>
using namespace std;

class SavingsAccount
{
    private:
  		static double annualInterestRate;
  		double savingsBalance;
  	public:
  		static void modifyInterestRate(double r)
        {
          	annualInterestRate = r;
        }
  		SavingsAccount(double s = 0): savingsBalance(s) {};
  		//
  		void calculateMonthlyInterest()
        {
          	savingsBalance += savingsBalance * annualInterestRate / 100 / 12;
        }
  		friend ostream &operator<<(ostream &out, const SavingsAccount &c)
        {
          	out << fixed << setprecision(2) << c.savingsBalance << "\n";
          	return out;
        }
};
double SavingsAccount::annualInterestRate;

int main()
{
    double balance1, balance2, rate1, rate2;
    cin >> balance1 >> balance2 >> rate1 >> rate2;
  	SavingsAccount saver1(balance1), saver2(balance2);
  	saver1.modifyInterestRate(rate1);
  	saver1.calculateMonthlyInterest();
  	saver2.calculateMonthlyInterest();
  	cout << "Month 1:\n";
  	cout << "saver1: " << saver1;
  	cout << "saver2: " << saver2;
  	saver1.modifyInterestRate(rate2);
  	saver1.calculateMonthlyInterest();
  	saver2.calculateMonthlyInterest();
  	cout << "Month 2:\n";
  	cout << "saver1: " << saver1;
  	cout << "saver2: " << saver2;
    return 0;
}