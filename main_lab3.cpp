
#include "add_lab3.hpp"
#include "deleteANDsearch_lab3.hpp"
#include <iostream>
#include <fstream>
using namespace std;

string Search_main()
{
string parametr;
cout<<"Введите значение для поиска ";
cin>>parametr;
return parametr;
}

bool ReadFile(string nameFile,int Menu)
{
string parametr;
string str;
int temp=0;
int i=0;
ifstream fileRead(nameFile);
	if(fileRead.good())
	{
		//получаем количество строк
		while(getline(fileRead,str)){temp++;}
		fileRead.seekg(0,fileRead.end);
		Mag* Prod=new Mag[temp];
		fileRead.clear();
		fileRead.seekg(0,fileRead.beg);
		while(!fileRead.eof() && i<temp)
		{
			fileRead>>Prod[i];
			i++;
		}
		fileRead.close();
		if(Menu==1 || Menu==3)
		{
		cout<<"Тип \t\tИмя\t\t№полки\tЦена\n";
			i=0;
			while(i<temp)
			{
			cout<<Prod[i];
			i++;
			}
		}
		if(Menu==3)
		{
			Delete(Prod,temp,nameFile);
		}
		if(Menu==6 || Menu==7)
		{
			parametr=Search_main();
			Search(Prod,temp,Menu,parametr);
		}
		delete [] Prod;
	}
	else{cout<<"Не удалось прочитать файл\n";return false;}
return true;
}

void Add(string FileName)
{
cout<<"Введите значения которые необходимо добавить \n";
Mag Prod;
cout<<"Тип: ";
cin>>Prod.type;
cout<<"Имя: ";
cin>>Prod.name;
cout<<"№ полки: ";
cin>>Prod.kol;
cout<<"Цена: ";
cin>>Prod.price;
Add_Prod(FileName,Prod);
//delete Prod;
}

int main(int argc,char *argv[]){
if(argc>1 && argv[1]!="")
	{
	Menu:
	int Menu=0, MenuRes=0;
	cout<<"\nВыберете пункт меню \n";
	cout<<" 1.Вывод информации о товарах \n 2.Добавить товар \n 3.Удалить/редактировать товар \n 4.Поиск по значению \n 5.Выход \n";
	cin>>Menu;
		switch(Menu)
		{
			case 1: ReadFile(argv[1],Menu); break;
			case 2: Add(argv[1]);break; 
			case 3: ReadFile(argv[1],Menu);break;
			case 4: {
				cout<<"Выберите параметр для поиска\n";cout<<"1.Тип \n2.Имя \n";cin>>MenuRes;
				switch(MenuRes)
				{
				case 1:MenuRes=6;break;
				case 2:MenuRes=7;break;
				default:cout<<"Ошибка выбора меню\n"; break; 
				}
			ReadFile(argv[1],MenuRes);
			break;
			}
			case 5: return 0;
			default: cout<<"Ошибка выбора меню\n"; break; 
		}
	goto Menu;
	}
else{cout<<"Не введено имя файла\n";}
}
