#include <iostream>
#include <string>

int main (void){
	int numeroEstados	= 6;
	int tamanoAlfabeto	= 26;
	int primerSimbolo = 'a';
	int estadoInicial	= 0;
	int tamanoEstadosFinales = 1;
	int estadosFinales[tamanoEstadosFinales]= {5};
	int funcionDelta[numeroEstados][tamanoAlfabeto] = {
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}};
	
	std::cout	<< "\nPractica 0\n"
				<< "Lenguajes y Automatas\n"
				<< "Jorge Perales Diaz\n\n"
				<< "En este programa va a admitir el nombre jorge, los demas casos no seran aceptados\n\n";
	
	while(true){	
		std::cout << "Escriba la palabra de entrada: ";
		std::string palabraEntrada;
		std::cin >> palabraEntrada;
		std::cout << "\n";
	
		bool palabraValida = true;
	
		for(int i = 0; i < palabraEntrada.length(); i++){
			int indiceSimbolo = (int)palabraEntrada[i] - primerSimbolo;

			if(indiceSimbolo > tamanoAlfabeto)
				palabraValida = false;
		}
	
		if(!palabraValida){
			std::cout << "\tError: La palabra \"" << palabraEntrada << "\" tiene simbolos que no pertenecen al alfabeto de este AFD\n\n";
			continue;
		}	
	
		int estadoActual = estadoInicial;
		
		for (int i = 0; i < palabraEntrada.length(); i++){
			std::cout << "[[q" << estadoActual << ", \"";
			for(int k = i; k < palabraEntrada.length(); k++)
				std::cout << palabraEntrada[k];
			std::cout << "\"]]\n";
		
			int indiceSimbolo = (int)palabraEntrada[i] - primerSimbolo;		
			estadoActual = funcionDelta[estadoActual][indiceSimbolo];
		}
		std::cout << "[[q" << estadoActual << ", \"\"]]\n";
	
		bool aceptada = false;	
		
		for(int i = 0; i < tamanoEstadosFinales; i++)
			if(estadosFinales[i] == estadoActual)
				aceptada = true;
			
		std::cout << "\n\tLa palabra \"" << palabraEntrada << "\" ";
		aceptada? std::cout << "es aceptada\n\n" : std::cout << "no es aceptada\n\n";
	}
	
	return 1;
}
