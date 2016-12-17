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

int main()
{
	int z1 = _IN;
	int z2 = _IN;
	std::cout << "--- Taschenrechner in Ny++6";
	std::cout << std::endl;
	std::cout << "1. Zahl: ";
	std::cin >> z1;
	std::cout << "2. Zahl: ";
	std::cin >> z2;
	std::cout << _NL;
	std::cout << "Zahl 1: ";
	std::cout << z1;
	std::cout << std::endl;
	std::cout << "Zahl 2: ";
	std::cout << z2;
	std::cout << std::endl;
	std::cout << _NL;
	std::cout << "Addition       ::  ";
	_axi = z1;
	_cxi = z2;
	_axi = _axi + _cxi;
	std::cout << _axi;
	std::cout << std::endl;
	std::cout << "Subtraktion    ::  ";
	_axi = z1;
	_cxi = z2;
	_axi = _axi - _cxi;
	std::cout << _axi;
	std::cout << std::endl;
	std::cout << "Multiplikation ::  ";
	_axi = z1;
	_cxi = z2;
	_axi = _axi * _cxi;
	std::cout << _axi;
	std::cout << std::endl;
	std::cout << "Division       ::  ";
	_axi = z1;
	_cxi = z2;
	_axi = _axi / _cxi;
	std::cout << _axi;
	std::cout << " R ";
	_axi = z1;
	_cxi = z2;
	_axi = _axi % _cxi;
	std::cout << _axi;
	std::cout << std::endl;
	std::cout << "Potenz         ::  ";
	_axi = z1;
	_cxi = z2;
	_axi = pow(_axi, _cxi);
	std::cout << _axi;
	std::cout << std::endl;
}

