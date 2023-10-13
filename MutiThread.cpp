//
// Created by cz241 on 9/28/2023.
//
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

static bool suspend=false;
void (*Callback)();
void A(string spk){
    cout<<"hello! "<<spk<<endl;
    Callback();
    while(suspend){
        this_thread::sleep_for(chrono::seconds(0));
    }
    cout<<"No! all u're gonna do is stay"<<endl;
}
void B(){
    cout<<"goodbye"<<endl;
}
int main() {
    thread t(A,"Twlm");
    Callback=[]{
        suspend=true;
        thread tb([]{
            this_thread::sleep_for(chrono::seconds(1));
            B();
            this_thread::sleep_for(chrono::seconds(1));
            suspend=false;
        });
        tb.join();
    };
    t.join();
    return 0;
}