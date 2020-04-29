#include <iostream>
#include <fstream>
#include "add_lab3.hpp"
using namespace std;

void Add_Prod(string fileName, Mag& object)
{
ofstream file(fileName,ios::app);
	if(file.good())
	{
		file.seekp(0,file.end);
		file<<object;
		file.close();
	}else{cout<<"Не удалось открыть файл для записи";}
}
