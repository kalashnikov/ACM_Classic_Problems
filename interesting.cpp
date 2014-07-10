#include<iostream>
using namespace std;

# define __always_inline   inline __attribute__((always_inline))

static __always_inline int middle(int a, int b) {
    return (b-a)/2;
}

int main(){
    int x = 'FOO!';
    short y = 'BO';

    cout << x << " " << y << endl;

#ifdef __clang__
    cout << __LINE__ << " " << __GNUC__  << " " << "YES" << endl;
#endif
    return 0;
}
