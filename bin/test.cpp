#include <iostream>
#include <cstdlib>
#include <cstdio>


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

int main();

	int z1 = 1;
	int z2 = 46;
int main()
{
	_exs = "Hallo Welt";
	z1 = 1;
	_cxs = _exs[1];
	std::cout << "_CXS: ";
	std::cout << _cxs;
	std::cout << std::endl;
	std::cout << "_EXS: ";
	std::cout << _exs;
	std::cout << std::endl;
	std::cout << "Z1:   ";
	std::cout << z1;
	std::cout << std::endl;
	std::cout << "FOS:  ";
	std::cout << _fos;
	std::cout << std::endl;
	std::string s2 = "Hallo 2";
	_exs = _exs + s2;
	std::cout << _exs;
	exit(0);
}

