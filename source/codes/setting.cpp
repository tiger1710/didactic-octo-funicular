#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <functional>
using namespace std;
typedef pair<int, int> point;

void outFunc(void) {
    cout << "outterFunc called" << endl;
}
class Foo {
private:
    function<void(Foo&)> f1 = func;
    function<void(void)> f2 = outFunc;
public:
    void func(void) {
        cout << "func called" << endl;
    }

};

void func(Foo& f) {
    f.func();
}

int main(void) {
    function<void(Foo&)> f1 = &Foo::func;
    f1 = &Foo::func;
    Foo foo;
    f1(foo);

    return 0;
}