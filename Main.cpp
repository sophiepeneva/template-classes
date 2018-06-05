# template-classes

#include<iostream>
#include "Pair.h"
#include "Settings.h"

using namespace std;

int main() 
{
	typedef Pair<int> intPair;
	intPair pair1("0xGEJB32NFEL",54);
	intPair pair2("0xGDIOGI78FE", 44);

	intPair* container = new intPair[2];
	container[0] = pair1;
	container[1] = pair2;

	typedef Settings<int> intSettings;
	intSettings settings(container, 2);
	settings.set("0xGDIOGI78FE", 45);
	settings.set("0xGDIOGIE", 45);
	cout << settings.count() << endl;
	int value;
	cout << settings.get("0xGDIOGIE", value) << endl;
	cout << value << endl;
	system("pause");
}
