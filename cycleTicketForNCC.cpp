//
// Created by Htet Aung Khant on 11/9/2022.
//
#include "iostream"
#include "sstream"
#include "cycleTicketForNCC.h"
using namespace std;
using namespace CYCLE;

void CycleTicketForNCC::welcome() {
    cout<<"Welcome from our cycle lucky show"<<endl;
    cout<<"10000mmk per coupon"<<endl;
    reloadAvaNumber();
}
// get available number from file to _avaNum array
void CycleTicketForNCC::reloadAvaNumber() {
    int idx = 0;
    string data;
    string avaNumber = "availableNumber.txt";
    string dataLine;
    ifstream avaNumFile(avaNumber);
    if (avaNumFile.is_open()) {
        while(getline(avaNumFile,dataLine)){
            for(auto &ch: dataLine){
                if(ch==' '){
                    _avNum[idx]= data;
                    idx++;
                    data="";
                } else{
                    string st(1,ch);
                    data += st;
                }
            }
        }
        avaNumFile.close();
        luckyNum();
    } else{
        availableNum();
    }
} // get available number from file to _avaNum array


// array data while running the program and showing available number
void CycleTicketForNCC::availableNum(){
    cout<<endl;
    for(int i=0; i<size; i++){
        _tempAvaNum[i]=i;
    }
    for(int i=0; i<size; i++){
        if(_tempAvaNum[i]>=0 && _tempAvaNum[i]<10) {
            _avNum[i] = "00" + to_string(_tempAvaNum[i]);
        } else if(_tempAvaNum[i]>=10 && _tempAvaNum[i]<100){
            _avNum[i] = "0" + to_string(_tempAvaNum[i]);
        } else{
            _avNum[i]= to_string(_tempAvaNum[i]);
        }
    }
    luckyNum();
} // array data while running the program and showing available number

// lucky Number function
void CycleTicketForNCC::luckyNum(){
    cout<<"Available number are:"<<endl;
    for(int j=0; j<size; j++){
        cout<<" "<<_avNum[j];
    }
    cout<<endl;
    string option;
    while (true) {
        cout << "Enter Your Lucky Number : ";
        cin >> lucNum;
// to check is there user lucky number in available luckyNumber array?
        for (int i = 0; i < size; i++) {
            if (_avNum[i] == lucNum) {
                _luckyNum[luckyNumberIdx] = lucNum;  // need to check again
    // to delete data(lucky number) in (_avNum)array
                for (int j = i; j < size; j++) {
                    _avNum[j] = _avNum[j + 1];
                }
                while (true) {
                    cout << endl << "Enter 1 to add lucky number || Enter 2 to pay for lucky number : ";
                    cin >> option;
                    if (option == "1") {
                        luckyNumberIdx++;
                        tempLuckyNumberIdx++;
                        size--;
                        luckyNum();
                    } else if (option == "2") {
                        dataToFile();
                        paymentFun();
                    } else{
                        cout<<"Please choose option carefully!!!"<<endl;
                    }
                }
            }
        }
        cout << "Your number cannot out of access!" << endl;
    }
} // lucky Number function


// ငွေချေ function
void CycleTicketForNCC::paymentFun(){
    int userPayment=0;
    int userPaid=0;
    cout<<"Enter your name : ";
    cin>>userName;
    cout<<"Enter your phone number : ";
    cin>>userPhone;
    cout<<"Enter your address : ";
    cin>>userAddress;
    int couponAmount=luckyNumberIdx+1;
    userPayment = couponPrice*couponAmount;
    while(true) {
        cout << "Please paid " << userPayment << "mmk " << "for your " << couponAmount << "coupon : ";
        cin >> userPaid;
        if (userPaid == userPayment) {
            cout<<"Your payment success!"<<endl;
            cout<<"Thank you and Good Luck"<<endl;
            showDetail();
            // to add asking function that is play again or want to quit ?
            askFun();
        } else{
            cout<<"Please retype your payment amount correctly!";
        }
    }
} // ငွေချေ function

// show detail about user's lucky number and his info
void CycleTicketForNCC::showDetail(){
    cout<<"Name: "<<userName<<" | Phone: "<<userPhone<<" | Address: "<<userAddress<<endl;
    cout<<"Lucky Number: ";
    for(int i=0; i<=luckyNumberIdx; i++){
        cout<<_luckyNum[i]<<" , ";
    }
    tempLuckyNumberIdx=luckyNumberIdx;
    luckyNumberIdx=0;
    cout<<endl;
} // show detail about user's lucky number and his info

// asking function that is play again or want to quit?
void CycleTicketForNCC::askFun(){
    string askOption;
    while (true) {
        cout << "Enter 1 to quit : enter 2 to choose your lucky number more :";
        cin >> askOption;
        if (askOption == "1") {
            cout << "Good Luck and thanks again!";
            allUserInfo();
            exit(1);
        } else if (askOption == "2") {
            allUserInfo();   // just testing
            size--;
            luckyNum();
        } else {
            cout<<"Please choose carefully!!";
        }
    }
} // asking function that is play again or wanna quit

// array data overwriting to file when close the program
void CycleTicketForNCC::dataToFile(){
    string avaNumber = "availableNumber.txt";
    ofstream avaNumFile(avaNumber);
    if(avaNumFile.is_open()){
       for(int i=0; i<size-1; i++){
           avaNumFile<<_avNum[i]<<" ";
       }
       avaNumFile.close();
    } else{
        cout<<"Error File cannot open!"<<endl;
        exit(1);
    }
} // array data overwriting to file when close the program

// all users info overwriting to file when close the program
void CycleTicketForNCC::allUserInfo(){
    for(int j=0; j<=tempLuckyNumberIdx; j++){
                cout<<_luckyNum[j]<<endl;
    }
    stringstream ss("");
    for (int i = 0; i <= tempLuckyNumberIdx; i++) {
        ss << _luckyNum[i]<<",";
    }
    string userData = "usersInfo.txt";
    ofstream userInfoFile(userData,ios::app);
    if(userInfoFile.is_open()){
            userInfoFile<<userName<<" "<<userPhone<<" "<<userAddress<<" "<<ss.str()<<" "<<endl;
        userInfoFile.close();
    } else{
        cout<<"Error File cannot open!"<<endl;
        exit(1);
    }
} // all users info overwriting to file when close the program
