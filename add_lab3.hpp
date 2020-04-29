#include <iostream>
#include <fstream>
using namespace std;
class Mag{
        public:
        string type="";
        string name="";
        int kol=0;
        float price=0.0;

	friend ostream& operator<<(ostream &out,const Mag &Prod)
	{
	out<<Prod.type<<"\t\t"<<Prod.name<<"\t\t"<<Prod.kol<<"\t"<<Prod.price<<"\n";
	return out;
	}
	
	friend istream& operator>>(istream &in, Mag &Prod)
	{
	in>>Prod.type;
	in>>Prod.name;
	in>>Prod.kol;
	in>>Prod.price;
	return in;
	}
};

void Add_Prod(string FileName, Mag& object);
