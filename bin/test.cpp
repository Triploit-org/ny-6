#include <iostream>
#include <cstdlib>
#include <cstdio>

std::string _SN = "";
int _IN = 0;
int main();
int sas();

int e = 2;
int e1 = 2;

int main()
{
	int a = 10;
	int b = 2;
	int x = _IN;
	a = a / b;
	std::string s1 = "[ MAIN ] S1";
	std::string s = _SN;
	s = "[ MAIN ] Hallo Welt";
	x = a;
	if (e != e1)
		sas();;
	std::cout << x;
	std::cout << std::endl;
	std::cout << s;
	std::cout << std::endl;
	std::cout << s1;
	std::cout << std::endl;
	exit(0);
}
int sas() 
{
	std::cout << "[ SAS ] E(";
	std::cout << e;
	std::cout << ") !=(<>) E1(";
	std::cout << e1;
	std::cout << ")";
	std::cout << std::endl;
	return 0;
}

