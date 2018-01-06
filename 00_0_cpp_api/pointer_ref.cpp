#include <iostream>
#include <vector>


using namespace std;

class Test{

    public:
        int a;
        Test(){
            a = 1;
        }
};


void test1() {
    cout << "*****class Pointer*****" << endl;
    Test* t1 = new Test();
    t1->a = 10;
    
    Test* t2 = new Test();
    t2->a = 5;
    
    cout << "&t1:" << t1 << " a = " << t1->a << endl;
    cout << "&t2:" << t2 <<  " a = " << t2->a <<endl;
    
    cout << "-------------t2=t1-----------------" << endl;
    t2 = t1;
    cout << "&t1:" << t1 << " a = " << t1->a << endl;
    cout << "&t2:" << t2 <<  " a = " << t2->a <<endl;
    
    cout << "--------------update a----------------" << endl;
    
    t1->a = 111;
    t2->a = 222;
    cout << "&t1:" << t1 << " a = " << t1->a << endl;
    cout << "&t2:" << t2 <<  " a = " << t2->a <<endl;
}


void test2() {
    cout << "*****class object*****" << endl;
    Test t1;
    t1.a = 10;
    
    Test t2;
    t2.a = 5;
    
    cout << "&t1:" << &t1 << " a = " << t1.a << endl;
    cout << "&t2:" << &t2 <<  " a = " << t2.a <<endl;
    
    cout << "-------------t2=t1-----------------" << endl;
    t2 = t1;
    cout << "&t1:" << &t1 << " a = " << t1.a << endl;
    cout << "&t2:" << &t2 <<  " a = " << t2.a <<endl;
    
    cout << "--------------update a----------------" << endl;
    
    t1.a = 111;
    t2.a = 222;
    cout << "&t1:" << &t1 << " a = " << t1.a << endl;
    cout << "&t2:" << &t2 <<  " a = " << t2.a <<endl;

}

int main() {
    test1();
    test2();
    return 0;
}
