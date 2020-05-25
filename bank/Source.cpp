#include<iostream>
#include<string>
#include<list>
#include<Windows.h>

using namespace std;



class Account {
public:
    int num;
    float money;
    

    Account() {


    }
    Account(int number, float balance) {
        setnumber(number);
        setbalance(balance);
    }
    void setnumber(int  number) {
        if (number >= 0) {
            this->num = number;
        }
    }
    void setbalance(float  balance) {
        if (balance >= 0) {
            this->money = balance;
        }
    }

    void Add_money() {
        float sum;
        agin:
        cout << "Enter sum->";
        cin >> sum;
        if (sum < 0||sum>money) {
            cout << "Sum entered incorect!" << endl;
            goto agin;
        }
        
        else {
            money += sum;
        }
    }

    void Withdraw_money() {
        float sum;
        int numb;
        agin:
        cout << "Enter sum->";
        cin >> sum;
        if (sum < 0||sum>money) {
            cout << "Sum entered incorect!" << endl;
            goto agin;
        }
        else {
            money -= sum;
        }
        
    }
    void print() {

        cout << "Number acouunt ->" << num << endl;
        cout << "Balance acouunt -> " << money << endl;
        cout << endl;
    }

   

};

class Info {
public:
    list<Account>listaccount;
    void Show() {
        for (auto it = listaccount.begin(); it != listaccount.end(); it++) {

            it->print();
        }
    }
    void NewAcount() {
        int number;
        float money;
        char type;
        cout << "Enter number acouunt->" ;
        cin >> number;
        agin:
        cout << "Enter balance->";
        cin >> money;
        if (money < 0) {
            cout << "Sum entered incorect!" << endl;
            goto agin;
        }
        
        Account* acouunt = new Account(number, money);
        listaccount.push_back(*acouunt);

        delete[] acouunt;
    }
    int Transfer_found() {
        int num1;
        int num2;
        float sum;
        bool found = false;
        bool found2 = false;
        bool nomoney = false;
        cout << "Enter number account from which you want withdraw money->";
        cin >> num1;
        cout << "Enter number account on which you want put money->";
        cin >> num2;
        cout << "Enter sum for withdrow->";
        cin >> sum;
        if (sum < 0) {
            cout << "Sum entered incorect" << endl;
            Sleep(1500);
            system("cls");
            return 0;
        }
        for (auto item = listaccount.begin(); item != listaccount.end(); item++) {
            if (num1 == item->num) {
                if (sum > item->money) {
                    cout << "No enough money" << endl;
                    Sleep(1500);
                    system("cls");
                    found = true;
                    found2 = true;
                    nomoney = false;
                    break;
                }
                else {
                    item->money -= sum;
                    found = true;
                    nomoney = true;
                    break;
                }
            }
        }
        if (nomoney == false) {
            return 0;
        }
        if (found == false) {
            cout << "Account not found" << endl;
            Sleep(1500);
            system("cls");
            return 0;
        }

        for (auto item2 = listaccount.begin(); item2 != listaccount.end(); item2++) {
            if (num2 == item2->num) {
                
                
                item2->money += sum;
                found2 = true;
                cout << "Operation was successesfule" << endl;
                Sleep(1500);
                system("cls");
                break;
            }
        }
        if (found2 == false) {
            for (auto item3 = listaccount.begin(); item3 != listaccount.end(); item3++) {
                if (num1 == item3->num) {
                    item3->money += sum;
                    break;
                }
            }
            cout << "Account not found!" << endl;
            Sleep(1500);
            system("cls");
            return 0;
        }
    }
};
int main() {

    Info bank;
    int action;
   
    do {
        cout << "1.Create acouunt " << endl;
        cout << "2.Show acouunt " << endl;
        cout << "3.Put up balance" << endl;
        cout << "4.Withdrow money" << endl;
        cout << "5.Transfer found" << endl;
        cout << "5.Exit " << endl;

        cin >> action;
        system("cls");
        switch (action) {
        case 1:
            bank.NewAcount();
            break;
        case 2:
            bank.Show();

            break;
        case 3:
            int a;
            cout << "Enter number acouunt->";
            cin >> a;
            system("cls");
            for (auto i = bank.listaccount.begin(); i != bank.listaccount.end(); i++) {
                if (a == i->num) {
                    i->Add_money();
                }


            }
            break;
        case 4:
            int b;
            cout << "Enter number acouunt->";
            cin >> b;
            for (auto i = bank.listaccount.begin(); i != bank.listaccount.end(); i++) {
                if (b == i->num) {
                    i->Withdraw_money();
                }


            }
            break;
        case 5:
            bank.Transfer_found();
            break;
        case 6:
            cout << "Bye" << endl;
            break;
        }



    } while (action != 6);
}