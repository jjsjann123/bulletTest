#include <testLib/testLib.h>
#include <iostream>
using namespace std;

class test2 {
public:
	int _y;
	int _x;
	
	void test();
	int _z;
	int xyz;

	int foo;
};

void test2::test()
{
	cout << _z << xyz;
}

int main (void)
{
	testLib q;
	testLib* f;
	f = &q;
	q.setValue(10, 20, 30);
	q.print();
	q.setValue( 30, 40, 50);
	q.print();
	((test2 *) f )->_y = 1;
	((test2 *) f )->xyz = 1;
	//((test2 *) f )->foo = 1;
	((test2 *) f )->test();
	q.print();


}