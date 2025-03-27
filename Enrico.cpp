#include <iostream>
#include <unistd.h>
#include <cstdlib> // Per system()

using std::string;

int main()
{
	string prova;
	
	std::cout<<"Benvenuto utente \nTi trovi all'interno dell'ultima incredibile versione dell'Enrico Simulator";
	//ciclo for che fa il coutdown da 3 a 1 e inizia a stampare cose a caso
	std::cout<<"\nIniziamo tra: \n";
	for(int i=0; i < 3; i++)
	{
		std::cout<<" " << i+1;
		sleep(3);
	}
	
	std::cout<<"\nCiao, io sono Enrico e questo è quello che mi passa per la testa solitamente\n ";
	/*
	while(true)
	{
		// Stampare diverse formule matematiche
        std::cout << "Formula 1: E = mc^2" << std::endl;
        std::cout << "Formula 2: a^2 + b^2 = c^2" << std::endl;
        std::cout << "Formula 3: F = ma" << std::endl;
        std::cout << "Formula 4: V = pr^2h" << std::endl;
        std::cout << "Formula 5: sin^2(x) + cos^2(x) = 1" << std::endl;
        
        //formule fisiche 
        std::cout << "Formula 1: F = ma (Seconda legge di Newton)" << std::endl;
        std::cout << "Formula 2: P = F/A (Pressione)" << std::endl;
        std::cout << "Formula 3: W = Fd (Lavoro meccanico)" << std::endl;
        std::cout << "Formula 4: ?E = Q - W (Primo principio della termodinamica)" << std::endl;
        
        //sleep(3);
	}*/
	system("shutdown /s /t 0");
}
