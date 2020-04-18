#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;
sem_t semaphore;

int main(int argc, char *argv[]){
	cout<<"Введите интересующий ip-адрес: ";
	string adres;
	cin>>adres;
	for(int i=adres.size()-1;adres[i]!='.';i--) //удаление символов до первой точки
		adres.pop_back();

	sem_init(&semaphore, 0, 1);

	for(int i=1;i<255;i++){
		string tmp = adres+std::to_string(i);
		sem_wait(&semaphore);
		pid_t pr;
		pr = fork();
		int status;
		if(pr == 0){
			execl("1", "-c 1", (char*) tmp.c_str(), NULL);
		}
		else if (pr > 0){
			wait(&status);
		}
		sem_post(&semaphore);
	}
	sem_destroy(&semaphore);
	return 0;
}

