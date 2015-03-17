// cent:
//

#include <iostream>

using namespace std;

//
void printBinary(const unsigned char val);
unsigned char rol(const unsigned char val);
unsigned char ror(const unsigned char val);

int main()
{
    cout<<"test printBinary:"<<endl;
	cout<<"0: ";
	printBinary(0);
	cout<<endl;

	cout<<"3: ";
    printBinary(3);
	cout<<endl;

	cout<<"10: ";
	printBinary(10);
	cout<<endl<<endl;
	
	cout<<"test rol & ror:"<<endl;
	cout<<"200: ";
	printBinary(200);
	cout<<endl;
	cout<<"rol: ";
	printBinary(rol(200));
	cout<<endl;
	cout<<"ror: ";
	printBinary(ror(200));
	cout<<endl;
	
    return 0;
}

//
void printBinary(const unsigned char val)
{
    for ( int i=7; i>=0; i-- )
	{
	    if (val & (1 << i))
		    cout<<"1";
		else
		    cout<<"0";
	}
}

//
unsigned char rol(unsigned char val)
{
    unsigned char highbit = (val & 0x80) ? 1 :0;
	val <<= 1;
	val |= highbit;
	return val;
}

//
unsigned char ror(unsigned char val)
{
    unsigned char lowbit = (val & 1) ? 0x80 : 0;
	val >>= 1;
	val |= lowbit;
	return val;
}

