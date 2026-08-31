#include <iostream>
#include<string>
using namespace std;

class payment{
protected:
    double amount;
    string tranid;
public:
    payment(double amount , string tranid){
        this->tranid=tranid;
        this->amount=amount;
    }

    virtual void processpayment()=0;
};

class creditcard:public payment{
public:
    double cardfee=50;
    creditcard(double amount , string tranid): payment(amount ,tranid){};
    void processpayment(){
        cout<< amount +cardfee;
    };

    
};

class jazzcash:public payment{
public:
    double cashback=0;
    jazzcash(double amount , string tranid): payment(amount ,tranid){};
    void processpayment(){
cashback=amount*0.2;
        cout<< amount -cashback;
    }

    
};

int main() {
    creditcard c1(1000.0, "TXN_CC_01");
    jazzcash j1(1000.0, "TXN_JC_02");

    cout << "Credit Card Total: Rs. ";
    c1.processpayment();
    cout << endl;

    cout << "JazzCash Total (after 20% cashback): Rs. ";
    j1.processpayment();
    cout << endl;

    return 0;
}