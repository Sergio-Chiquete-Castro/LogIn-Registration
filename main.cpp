#include <iostream>
#include <thread>   // For std::this_thread::sleep_for
#include <chrono>   // For std::chrono::seconds
#include <fstream>
#include <filesystem> // C++17 and later for checking file existence
#include<string>
using namespace std;

class user_interface{
private:

int user_choice;
string registered_Name;
string registered_password;
int get_choice;
string check_LogIn_Name;
string check_LogIn_Password;
string login_Name;
string login_Password;
string line;

public:
void main(){
user_Menu();

}
void user_Menu(){
 

cout << "\033[2J\033[1;1H";//ANSI escape code
cout<<"----------------------------"<<endl;
cout << "Welcome!"<<endl;
cout<<"----------------------------"<<endl;
cout << "LOG IN(1) or Register(2) : ";

cin >> user_choice;

switch(user_choice){

    case 1:
    LogIn();
    break;

    case 2:
    registration();
    break;

    default: 
    cout << "Error"<<endl;
    break;
}

}


void registration (){
 

cout << "Enter your name: ";
cin >> registered_Name;


cout << "Enter Password: ";
cin>> registered_password;


cout<<"________________________________"<<endl;
cout<<"Name: "<< registered_Name<<endl;
cout<<"Password: "<<registered_password <<endl;
cout<<"________________________________"<<endl;
cout << "Is this the correct name and password? Yes(1), No(2)"<<endl;
cin>> get_choice;

if (get_choice == 1){

    cout << "Account Created, "<<endl;
    
    store_registration();
}
else if (get_choice == 2){
    cout << "Account could not be created, going back to menu"<<endl;
    this_thread::sleep_for(chrono::seconds(3)); // pauses for 10 seconds

    main();
}

}

void store_registration(){
    string file_name;
    file_name += registered_Name+".txt";
    
    ofstream get_File(file_name, ios::app);
    if(get_File.is_open()){
        get_File <<registered_password<<endl;
        get_File.close();


    }else{
        cout<<"Could not open file, ERROR"<<endl;
        this_thread::sleep_for(chrono::seconds(3)); // pauses for 10 seconds
        main();
    }

    cout << "Back to Menu.."<<endl;
    this_thread::sleep_for(chrono::seconds(3)); // pauses for 10 seconds
    main();
}

 

void LogIn(){ 


cout << "Enter Your name :";
cin >> login_Name;

cout << "Enter your password :";
cin >> login_Password;

check_LogIn_Name = login_Name + ".txt";


ifstream file(check_LogIn_Name);

if(!file){
    cout << "No Account following that name"<<endl;
    this_thread::sleep_for(chrono::seconds(3)); // pauses for 10 seconds
    main();
}
else {

    file >> check_LogIn_Password;
    file.close();

    if(login_Password == check_LogIn_Password){
        cout << "-------------------------"<<endl;
        cout << "Successfully Logged In ... "<<endl;
        this_thread::sleep_for(chrono::seconds(3)); // pauses for 10 seconds

        user_loggedIn_Menu();

    }
    else{

        cout << " Incorrect Password, going back to menu"<<endl;
        this_thread::sleep_for(chrono::seconds(3)); // pauses for 10 seconds
        main();

    }

}

}

void user_loggedIn_Menu(){
    cout << "\033[2J\033[1;1H";//ANSI escape code
    cout << "-------------------------"<<endl;
    cout << "Welcome : "<< login_Name << "!"<<endl;
    cout << "-------------------------"<<endl;
}

};

int main(){
    user_interface start;
    start.main();
}
