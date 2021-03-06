#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <cmath>


#ifdef _WIN32
int _fos = 0;
#elif _WIN64
int _fos = 1;
#elif __unix || __unix__
int _fos = 2;
#elif __APPLE__ || __MACH__
int _fos = 3;
#elif __linux__
int _fos = 4;
#elif __FreeBSD__
int _fos = 5;
#else
int _fos = 6;
#endif

std::string _SN = "";
int _IN = 0;

int _axi = 0;
int _cxi = 0;
int _dxi = 0;
int _exi = 0;

std::string _axs = "";
std::string _cxs = "";
std::string _dxs = "";
std::string _exs = "";
std::string _NL = "\n";

int main();
int ok2();


int main()
{
	int h = 90;
	int h2 = 10;
	int x = 0;
beb:
	h = 90;
	h2 = 10;
	x = x + 1;
	h = h / h2;
	std::cout << h;
	std::cout << std::endl;
	std::cout << "[ MAIN\t]\tX |\t| ";
	std::cout << x;
	std::cout << std::endl;
	std::cout << "Hallo Welt! von Main";
	std::cout << std::endl;
	ok2();

	std::cout << "Wieder MAIN!";
	std::cout << std::endl;
	if (x < h2)
		goto beb;
	std::cout << "\t(TAB) = %tX";
	std::cout << std::endl;
	exit(0);
}

int ok2()
{
	std::cout << "OK2";
	std::cout << std::endl;
	int x = 0;
begOk2:
	_axs = "Hallo";
	_cxs = "Hallo von OK2!";
	std::cout << "Schleife?";
	std::cout << std::endl;
	std::cout << _cxs;
	std::cout << std::endl;
	x = x + 1;
	std::cout << "[ OK2\t]\tX(2) |\t| ";
	std::cout << x;
	std::cout << std::endl;
	if (x != 1)
		goto begOk2;
endOk2:
	return 0;
}

