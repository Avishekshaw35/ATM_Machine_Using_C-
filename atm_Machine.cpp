#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/*Mini Project- ATM : Check balance,
 Cash Withdrawal, User Details, Update Mob. No*/

 class atm
 {
     private:
      long int account_No;
      string name;
      int PIN;
      double balance;
      string mobile_no;

    public:
      void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_no_a)
      {
          account_No = account_No_a;
          name = name_a;
          PIN = PIN_a;
          balance = balance_a;
          mobile_no = mobile_no_a;
      }

      long int getAccountNo()
      {
          return account_No;
      }

      string getName(){
          return name;
      }

      int getPIN(){
          return PIN;
      }

      double getBalance(){
          return balance;
      }

      string getMobile(){
          return mobile_no;
      }

      void setMobile(string mob_prev, string mob_new)
      {
          if(mob_prev==mobile_no){
              mobile_no = mob_new;
              cout<<endl<<"Sucessfully updated Mobile no. ";
              _getch();
          }
          else{
              cout<<endl<<"Incorrect !! Old Mobile no";
              _getch();
          }
      }

      void cashWithDraw(int amount_a)
      {
        if(amount_a>0 && amount_a<balance)
        {
            balance -= amount_a;
            cout<<endl<<"Please Collect Your Cash";
            cout<<endl<<"Available Balnc : "<<balance;
            _getch();
        }
        else{
            cout<<endl<<"Invalid input or Insufficient balance";
            _getch();
        }
      } 
 };

 int main()
 {
     int choice = 0, enterPin;
     long int enterAccNo;

     system("cls");
     //created User (Object)
     atm user1;
     user1.setData(12345678, "Avishek", 4321, 50000.85, "0987654321");
     do
     {
       system("cls");

       cout<<endl<<"    ****Welcome to ATM****   "<<endl;
       cout<<endl<<"Enter Your Account No ";
       cin>>enterAccNo;

       cout<<endl<<"Enter PIN ";
       cin>>enterPin;  

       if((enterAccNo == user1.getAccountNo()) && (enterPin == user1.getPIN()))
       {
           do{
               int amount =0;
               string oldMobileNo, newMobileNo;
               system("cls");
               cout<<endl<<"   ****Welcome to ATM****   "<<endl;
               cout<<endl<<"Select Options ";
               cout<<endl<<"1. Check Balance";
               cout<<endl<<"2. Cash Withdraw";
               cout<<endl<<"3. Show user derails";
               cout<<endl<<"4. Update Mobile No";
               cout<<endl<<"5. Exit"<<endl;
               cin>>choice;
               switch(choice)
               {
                   case 1:
                     cout<<endl<<"Your Balance is: "<<user1.getBalance();
                     _getch();
                     break;

                   case 2:
                     cout<<endl<<"Enter the amount: ";
                     cin>>amount;
                     user1.cashWithDraw(amount);
                     break;

                   case 3:
                     cout<<endl<<"***User Details are : ";
                     cout<<endl<<"-> Account No "<<user1.getAccountNo();
                     cout<<endl<<"-> Name    "<<user1.getName();
                     cout<<endl<<"-> Balance     "<<user1.getBalance();
                     cout<<endl<<"-> Mobile No    "<<user1.getMobile();
                     _getch();
                     break;

                  case 4:
                     cout<<endl<<"Enter Old Mobile No. ";
                     cin>>oldMobileNo;

                     cout<<endl<<"Enter New Mobile No. ";
                     cin>>newMobileNo;
                     
                     user1.setMobile(oldMobileNo, newMobileNo);
                     break;

                 case 5:
                     exit(0);
                 default:
                   cout<<endl<<"Enter Valid input!!";

               }

           } while(1);
       }

       else{
           cout<<endl<<"User Details are Invalid!!!";
           _getch();
       }
     }while(1);

     return 0;

 }