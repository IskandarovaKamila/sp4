#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){ 
	char *argumenty[5];
	string command = "ping";
	string par = "-c";				//посылаешь определен. кол-во запросов
	string znac = "1";				//кол-во запросов

	argumenty[0]=(char*) command.c_str();		//char значение ping
	argumenty[1]=(char*) par.c_str();		//-c
	argumenty[2]=(char*) znac.c_str();		//1
	argumenty[3]=argv[1];				//переданный ip адрес
	argumenty[4]=NULL;
	if(execvp (argumenty[0],argumenty) == -1){	
		perror ("exec");
	}
	return 0;
}
 
