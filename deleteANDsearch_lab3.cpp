#include <iostream>
#include <fstream>
#include "add_lab3.hpp"
#include "deleteANDsearch_lab3.hpp"
using namespace std;

void DeleteFile(int Id, string NameFile, Mag * Prod, int temp){
ofstream file(NameFile);
	if(file.good())
	{
		int i=0;
        	while(i<temp)
       		{
                	if(Id!=i){file<<Prod[i];}
                	i++;
        	}
		file.close();
	}
}


void Delete(Mag * Prod,int temp, string NameFile)
{
int MenuPar=0;
string NewType="", NewName="";int NewKol=-1;double NewPrice=-1;
string NameDelete,check;
int i=0, IdDelete=-1, Menu=0;
cout<<"Введите наименование товара ";
cin>>NameDelete;
	while(i<temp)
	{
	if(Prod[i].name==NameDelete){cout<<Prod[i];IdDelete=i;break;}
	i++;
	}
	Menu:
	cout<<"\n1.Удалить товар \n2.Редактировать товар \n";
	cin>>Menu;
		switch (Menu)
		{
			case 1:
			{
				if(IdDelete>=0){
				cout<<"Вы хотите продать этот товар? (д/н)";cin>>check;
        			if(check=="д" || check=="Д"){DeleteFile(IdDelete,NameFile, Prod,temp);}
				}
			break;
			}
			case 2:
			{
			MenuPar:
			cout<<"Какой параметр необходимо изменить?\n"<<"1.Тип \n2.Имя \n3.№ полки \n4.Цена \n5.Закончить редактирование \n ";
			cin>>MenuPar;
				switch(MenuPar)
				{
					case 1:
					{
					NewType="";
					cout<<"Введите новый тип: ";
					cin>>NewType;goto MenuPar;break;
					}
					case 2:
					{
					NewName="";
					cout<<"Введите новое имя: ";
                                        cin>>NewName;goto MenuPar;break;
					}
					case 3:
					{
					NewKol=-1;
                                        cout<<"Введите новый номер полки: ";
                                        cin>>NewKol;goto MenuPar;break;
                                        }
					case 4:
					{
					NewPrice=-1;
                                        cout<<"Введите новую цену: ";
                                        cin>>NewPrice;goto MenuPar;break;
                                        }
					case 5:
					{
					cout<<"Желаете сохранить изменения?(д/н)\n";
					cin>>check;
						if(check=="д" || check=="Д")
						{
							if(NewType!=""){Prod[IdDelete].type=NewType;NewType="";}
							if(NewName!=""){Prod[IdDelete].name=NewName;NewName="";}
							if(NewKol!=-1){Prod[IdDelete].kol=NewKol;NewKol=-1;}
							if(NewPrice!=-1){Prod[IdDelete].price=NewPrice;NewPrice=-1;}
							cout<<"\n"<<Prod[IdDelete];
							DeleteFile(-1,NameFile, Prod,temp);
						}
					break;
					}
				}
			break;
			}
			default:cout<<"Неверный выбор меню";goto Menu;break;
		}
}

void Search(Mag * Prod,int temp,int MenuRes,string parametr)
{
int i=0;
        if(MenuRes==6){
                while(i<temp)
                {
                        if(parametr==Prod[i].type){cout<<Prod[i];}
                        i++;
                }
        }
        else if(MenuRes==7){
                 while(i<temp)
                {
                       if(parametr==Prod[i].name){cout<<Prod[i];}
                        i++;
                }

        }
}
