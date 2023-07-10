#include <iostream>
#include<thread>
using namespace std;
int p = 250;
int a{}, b{}, c{};


void pt1() {
    while(p>1){
        cout << " работа 1 кассира идет " << endl;
        this_thread::sleep_for(chrono::milliseconds(120));
        --p;
        a++;
    } 
    cout << "КОНЕЦ, 1м кассиром обслужено " << a << " покупателей, за " << (a * 120) / 60. << " минут" << endl;;
}
//
void pt2() {
    while (p > 2) {
        cout << " работа 2 кассира идет" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        --p;
        b++;
    }  
    cout << "КОНЕЦ, 2м кассиром обслужено " << b << " покупателей, за " << (b * 150) / 60. << " минут" << endl;;
}

void pt3() {
    while (p >4) {
        cout << " работа 3 кассира идет" << endl;
        this_thread::sleep_for(chrono::milliseconds(168));
        --p;
        c++;
    }  
    cout << "КОНЕЦ, 3м кассиром обслужено " << c<< " покупателей, за " << (c * 168) / 60. << " минут" << endl;;
}



int main()
{
    setlocale(LC_ALL, "RUS");
    thread p1(pt1);
    thread p2(pt2);
    thread p3(pt3);
    p1.join();
    p2.join();
    p3.join();
    int y = ((c * 168) / 60.) + ((b * 150) / 60.) + ((a * 120) / 60.);
    if (y > 45) {
        y = y + ((y / 45.) * 10);
        cout << "рабочий день длился " << y/60. << " часов" << endl;
    }



}
