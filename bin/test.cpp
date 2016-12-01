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

int ok();
int main();
int ok2();

int ok()
{
	std::cout << "Dann halt ein OK!";
	std::cout << std::endl;
	int t = 2;
	int t2 = 8;
	t2 = t2 % t;
	std::cout << t2;
	std::cout << std::endl;
	std::cout << t;
	std::cout << std::endl;
	return 0;
}
int main()
{
	std::cout << "Hallo Welt!";
	std::cout << std::endl;
	std::cout << "MAIN!";
	std::cout << std::endl;
	ok();

	ok2();

	std::cout << "Wieder MAIN!";
	std::cout << std::endl;
	exit(0);
}
int ok2()
{
	_axs = "Hallo";
	_cxs = "Hallo";
	std::cout << "Schleife?";
	std::cout << std::endl;
	if (_axs != _cxs)
		ok();;
	std::cout << _cxs;
	std::cout << std::endl;
	return 0;
}

