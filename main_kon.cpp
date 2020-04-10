#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc==3) {
	int position;
        string sim="";
        string res="";
        int i=0;
        ifstream file(argv[1]);
        ofstream fileWr(argv[2]);
        if(file.is_open() && fileWr.is_open()) {
            while(getline(file,sim)) {
		while(i<sim.size())
               	{
			position = sim.find(' ');
			if(position!=-1)
			{
			sim.erase(position,1);
			i++;
			}
			else{break;}
		}
			res=sim;
                	fileWr<<res<<"\n";
                	i=0;
                	sim="";
                	res="";
            }
            file.close();
            fileWr.close();
            return 0;
        }
        else {
            cout << "Ошибка в открытии файла \n";
            return 0;
        }
    }
    else {
        cout << "Ошибка в ведении аргументов main \n";
        return 0;
    }
}
