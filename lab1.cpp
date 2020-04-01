#include <iostream>
#include <fstream>
using namespace std;
ofstream fileWr("fileWrite.txt");
void tab(int rast){
	int i=0;
	while(i<rast){
	fileWr<< " ";
	i++;
	}
}

int main(int argc, char *argv[]){
	int rast=0;
	int i=0;
	int dlinn=0;
	int shir=0;
		//read
		ifstream file(argv[1]);
		file >> dlinn;
		file >> shir;
		file.close();
		//
//public ofstream fileWr("fileWrite.txt");
	//first
	tab(dlinn/2);
	fileWr<<"#\n";
	//
i=1;
int n=1;
while(i<=shir/2)
{
	rast=(dlinn/2)-i;
	tab(rast);
	fileWr<< "#";
	rast=n;
	tab(rast);
	fileWr<<"#\n";
	i++;
	n=n+2;
}
n=n-4;
i=(dlinn/2)-1;
while(i>=1)
{
	rast=(dlinn/2)-i;
	tab(rast);
	fileWr << "#";
	rast=n;
	tab(rast);
	fileWr<<"#\n";
	i--;
	n=n-2;
}
	//end
	tab(dlinn/2);
	fileWr<<"#\n";
	//
fileWr.close();
cout<< "Готово. Результат в файле fileWrite.txt"
return 0;
}
