#include<iostream>
using namespace std;

enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN};

struct Passenger {
   string name; 
   MealType mealPref ;
   bool  isFreqFlyer;
   string  freqFlyerNo;
};

//operator overloading

bool operator==(Passenger& x, Passenger& y) {
    return x.name == y.name && x.mealPref  == y.mealPref && x.isFreqFlyer == y.isFreqFlyer && x.freqFlyerNo  == y.freqFlyerNo;
}

int main()
{
    Passenger p1 = { "John Smith", VEGETARIAN, true, "293145" };
    Passenger p2 = { "Adam Smith", VEGETARIAN, true, "293146"  };

    cout<<(p1==p2)<<endl;
}