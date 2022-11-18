//
// Created by Htet Aung Khant on 11/9/2022.
//
#include "iostream"
#include "fstream"
using namespace std;
#ifndef UNTITLED_CYCLETICKETFORNCC_H
#define UNTITLED_CYCLETICKETFORNCC_H

namespace CYCLE {
    class CycleTicketForNCC {
    public:
        //loading declare
        int size=1000;
        string lucNum;
        int couponPrice = 10000;
        int luckyNumberIdx=0; // user ထိုးလိုက်တဲ့ နံပါတ်တွေရဲ့ အရေအတွက် ဘနလုံးလဲ ဆိုတာမျိုး
        int tempLuckyNumberIdx=0;
        int _tempAvaNum[1000];
        string _avNum[1000];       // user ထိုးလို့ရနိုင်တဲ့ နံပါတ်တွေ  // what if this array will string array
        string _luckyNum[1000];    // user ထိုးလိုက်တဲ့ နံပါတ်တွ
        string userName;
        string userPhone;
        string userAddress;

        //Method declare
        void welcome();
        void availableNum();
        void luckyNum();
        void paymentFun();
        void showDetail();
        void askFun();
        void dataToFile();
        void allUserInfo();
        void reloadAvaNumber();
    };
}

#endif //UNTITLED_CYCLETICKETFORNCC_H
