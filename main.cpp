#include <iostream>
#include<vector>
#include <string>
using namespace std;
bool isValidId(string id){
    return id.size() == 10;
}
bool isValidPin(string pin ){
    if (pin.size() != 6) {
        return false; // PIN must be exactly 6 digits
    }

    for (char c : pin) {
        if (!isdigit(c)) {
            return false; // Non-digit character found
        }
    }

    return true;

}
class Account {
private:
    string id;
    int pin;
    long amount;
    std::vector<std::string> friendsList;

public:
    Account(int pin,string id) {
        this->id = id;
        this->pin = pin;
        this->amount = 0;
    }
    string getId(){
        return this->id;
    }
    int getPin() {
        return this->pin;
    }

    void setPin(int pin) {
        this->pin = pin;
    }

    long getAmount() {
        return this->amount;
    }

    void setAmount(long amount) {
        this->amount = amount;
    }

    void addFriendlyAcc(const std::string& acc) {
        friendsList.push_back(acc);
    }
    void getInfo(){

    };
};
class ATM{
    private: 
        vector<Account> userAcounts;
        Account currentUser;
    public:
        bool Login(string id, string pin){
            if (!isValidId(id)|| !isValidPin(pin)){
                cout<<"id or pin wrong\n";
                return false;
            }
            int pinNumber = stoi(pin);
            Account tempAccount(pinNumber,id);
            for (Account a : userAcounts){
                if (a.getId() == id && a.getPin() == pinNumber){
                    this->currentUser = a;
                    cout<<"Login successful!\n";
                    return true;
                }
            }
        }
        void getAccountInfo(){
            currentUser.getInfo();
        }
        void withdrawMoney(){

        }
        void depositMoney(){

        }
        void transferMoney(){

        }
        void saveCurrentUser(){

        }
};
int main(){
    Account acc(10200,"12021012012");
    cout<<acc.getPin();
}