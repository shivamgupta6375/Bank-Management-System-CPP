#include<iostream>
#include<conio.h>
#include<ctime>
#include<string>
using namespace std;

class bank{
    public:
       long long accNo;
       string username, password;
       float balance;
       string mobileNo;
       string address, accType;
};

bank users[10];
int total = 2;

class systemBank: public bank{
    public:
        int userIndex;

        void loginPage(){
            string u, p;
            
				    centerText("Enter username and password for login: ", false);
				    cin>>u>>p;
            
            for(int i=0; i<total; i++){
              if(users[i].username == u && users[i].password == p){
				        centerText("Welcome back User! Login successful!");
                userIndex = i;
                accNo = users[i].accNo;
                username = users[i].username;
                password = users[i].password;
                mobileNo = users[i].mobileNo;
                address = users[i].address;
                accType = users[i].accType;
                balance = users[i].balance;
                    
                showMenu();
                return;
                }
            }
             
				    cout << endl;
            centerText("Invalid username or password!");
            int choice; 
				    cout << endl;
            centerText("Menu: ");
            centerText("1.Re-Login  2.Registration");
            centerText("Enter your choice: ", false);
				    cin>>choice;
            switch(choice){
              case 1:
                loginPage();
                break;
              case 2:
                registration();
                break;
             default:
				        centerText("Invalid number!");
            }
        }

        void registration(){
            string newUser;
				    cout << endl;          
            centerText("----Create Account in Nova Bank----");
				    centerText("Enter Username: ", false);
            cin.ignore();
				    getline(cin, newUser);
            for(int i=0; i<total; i++){
              if(users[i].username == newUser){
				        centerText("Username already exists! Please choose another.");
                return;
              }
            }
              
            users[total].username = newUser;
				      centerText("Enter Password: ", false);
				      cin>>users[total].password;
				      centerText("Enter Mobile No.: ", false);
				      cin>>users[total].mobileNo;
				      centerText("Enter Address: ", false);
				      cin.ignore();
              getline(cin, users[total].address);
				      centerText("Enter Account Type(Saving or Current) : ", false);
              getline(cin, users[total].accType);
              srand(time(0));
              users[total].accNo = 100000000000LL + rand() % 900000000000LL;
              users[total].balance = 500.00; 
				      cout << endl;
              centerText("---Your account has been created successfully!---");
				      centerText("Your Account No.= " + to_string(users[total].accNo));
              total++;
				      cout << endl;
              centerText("Please login again to continue.");
              cout << endl; 
              loginPage();      
        }

        void showMenu(){
				    cout << endl;
            centerText("Menu: ");
            centerText("1.Deposit   2.Withdraw   3.Check Balance   ");
            centerText("4.Change Password   5.Display Account Details   6.Logout ");
            centerText("Enter your choice: ", false);
            int choice;
				    cin>>choice;
            cout << endl;
            switch(choice){
                case 1:
                  deposit();
                  cout << endl;
                  break;
                case 2:
                  withdraw();
                  cout << endl;
                  break;
                case 3:
                  checkBalance();
                  cout << endl;
                  break;
                case 4:
                  changePassword();
                  cout << endl;
                  break;
                case 5:
                  displayAccountDetails();
                  cout << endl;
                  break;
                case 6:
                  logout();
                  cout << endl;
                  break;
                default:
				            centerText("Invalid number!");
                    cout << endl;
            }
        }

        void deposit(){
            float amount;
				    centerText("Enter amount to deposit: ", false);
				    cin>>amount;
            
            if(amount > 0){
              balance += amount;
              users[userIndex].balance = balance;
				      centerText("Amount deposited successfully! Current Balance: " + to_string(balance));
            
            } else {
				      centerText("Invalid amount!");
            }
            
            showMenu();
        }

        void withdraw(){
            float amount;
				    centerText("Enter amount to withdraw: ", false);
				    cin>>amount;
            
            if(amount > 0 && amount <= balance){
              balance -= amount;
              users[userIndex].balance = balance;
				      centerText("Amount withdrawn successfully! Current Balance: " + to_string(balance));
            
            } else {
				      centerText("Invalid amount or insufficient balance!");
            }
            
            showMenu();
        }

        void checkBalance(){
				    centerText("Your current balance is: " + to_string(balance));
            showMenu();
        }

        void changePassword(){
            string oldPassword, newPassword;
				    centerText("Enter old password: ", false);
				    cin>>oldPassword;
            
            if(oldPassword == password){
				      centerText("Enter new password: ", false);
				      cin>>newPassword;
              password = newPassword;
              users[userIndex].password = newPassword;
				      centerText("Password changed successfully!");
            
            } else {
				      centerText("Invalid old password!");
            }
            
            showMenu();
        }

        void displayAccountDetails(){
				  centerText("Account Details:-");
				  centerText("Account Number: " + to_string(accNo));
				  centerText("Username: " + username);
				  centerText("Mobile Number: " + mobileNo);
				  centerText("Address: " + address);
				  centerText("Account Type: " + accType);
				  centerText("Balance: " + to_string(balance));
          showMenu();
        }

        void logout(){
          centerText("You have been logged out. Thank you for using Nova Bank!");
          centerText("Please login again to continue.");
          cout << endl;
          mainMenu();
        }

        void mainMenu(){
          int choice;
			    centerText("----Welcome to Nova Bank----");
			    centerText("Menu: ");
			    centerText("1.Login  2.Registration:  3.Exit");
			    centerText("Enter your choice: ", false);
			    cin>>choice;
          
          switch(choice){
            case 1:
              loginPage();
              break;
            case 2:
              registration();
              break;
            case 3:
              cout << endl;
              centerText("Thank you for banking with Nova Bank.");
              centerText("We look forward to serving you again!");
              cout << endl;
              exit(0);
            default:
			        centerText("Invalid number!");
            }
        }

        void centerText(const string &text, bool nextLine = true) {
          const int width = 140;
          int padding = (width - text.length()) / 2;

          if(padding < 0)
              padding = 0;

          cout << string(padding, ' ') << text;

          if(nextLine)
            cout << "\n";
        }

};



int main(){
    systemBank obj;
    users[0].accNo = 6371234122;
    users[0].username = "adam";
    users[0].password = "12345";
    users[0].mobileNo = "9999999999";
    users[0].address = "Noida, Uttar Pradesh";
    users[0].accType = "Saving";
    users[0].balance = 500.00;

    users[1].accNo = 6371234123;
    users[1].username = "john";
    users[1].password = "678910";
    users[1].mobileNo = "8888888888";
    users[1].address = "Delhi, India";
    users[1].accType = "Current";
    users[1].balance = 1000.00;
    
    obj.mainMenu();

    return 0;
}
