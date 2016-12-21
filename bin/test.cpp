#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#include <unistd.h>
#include <fstream>
#include <sys/stat.h>
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

std::fstream f;
std::string c = "";

int main();
int ok2();


int main()
{
	int h = 90;
	int h2 = 10;
	std::string td = "/home/survari/test.txt";
	std::string text = "Gib eine Zahl ein: ";
	std::string tx = _SN;
	f.open(td, std::ios::out);
	f << "[CBN6]:[FS]:[NOERR]" << std::endl;
	f.close();

	f.open(td, std::ios::out);
	f << text << std::endl;
	f.close();
	
	std::string line = td;
	std::string filename49 = line;
	std::ifstream f49 = std::ifstream(filename49);

	while (std::getline(f49, line))
	{

		c = c + line;
	}

	f49.close();
	tx = c;
	std::cout << tx;
	std::cin >> h;
	remove(td.c_str());;
	exit(0);
	h = h / h2;
	std::cout << h;
	std::cout << std::endl;
	std::cout << "Hallo Welt! von Main";
	std::cout << std::endl;
	ok2();

	std::cout << "Wieder MAIN!";
	std::cout << std::endl;
	exit(0);
}

int ok2()
{
begOk2:
	_axs = "Hallo";
	_cxs = "Hallo von OK2!";
	std::cout << "Schleife?";
	std::cout << std::endl;
	std::cout << _cxs;
	std::cout << std::endl;
	_cxi = _cxi + 1;
	std::cout << _cxi;
	std::cout << std::endl;
	if (_cxi != 1)
		goto begOk2;
endOk2:
	return 0;
}

