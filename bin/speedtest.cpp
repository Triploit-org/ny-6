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
	_cxi = _cxi + 1;
	std::cout << _cxi;
	std::cout << std::endl;
	if (_cxi < 99999)
		main();;
	exit(0);
}

