#include <iostream>
#include <string>
#include <vector>
#include <conio2.h>
#include <windows.h>
#include <iomanip>

using namespace std;

#include "funcoes.cpp"
#include "cadastrarNovoCD.cpp"
#include "musicas.cpp"
#include "listarMusicasCadastradas.cpp"

main()
{
	setlocale(LC_ALL, "Portuguese");
	string op;
	int posicao;
	
	vector<string> menuPrincipal;
	menuPrincipal.push_back("1 - Cadastrar Música    ");
	menuPrincipal.push_back("2 - Cadastrar CD        ");
	menuPrincipal.push_back("3 - Listar Músicas      ");
	menuPrincipal.push_back("0 - Sair                ");
	
	while (true)
	{
		clrscr();
		desenharMoldura(1, 1, 80, 25);
		centralizar("### Loja de Discos ###", 2, 1, 80);
		op = mostrarMenu(2,3,menuPrincipal);
		
		if (op == "0") break;
		if (op == "1") generoCRUD();
		if (op == "2") cadastrarCD();
		if (op == "3") listarMusicasCadastradas();
		
	}
	
}
