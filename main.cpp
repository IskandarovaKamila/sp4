#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	cout<<"Введите интересующий ip-адрес: ";
	string adres;
	cin>>adres;
	for(int i=adres.size()-1;adres[i]!='.';i--) //удаление символов до первой точки
		adres.pop_back();

	for(int i=1;i<255;i++){
		string tmp = adres+std::to_string(i);
		pid_t pr;
		pr = fork();
		int status;
		if(pr == 0){
		execl("first", "-c 1", (char*) tmp.c_str(), NULL);
	}
	else if (pr > 0){
		wait(&status);
	}

	}
	return 0;
}

