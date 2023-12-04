struct GENERO
{
	string disco;
	string genero;
	string titulo;
	string gravadora;
	string compositor;
	string novoCD;
};



vector<GENERO> listaGeneros;


void generoCRUD()
{
	bool achei;
	int posicao;
	string resp;
	GENERO registro;
	
	desenharMoldura(10,4,75,13);
	centralizar("Cadastro de Músicas",6,13,75);
	gotoxy(11,7); cout << "Disco : ";
	gotoxy(11,8); cout << "Gênero : ";
	gotoxy(11,9); cout << "Título : ";
	gotoxy(11,10); cout << "Gravadora : ";
	gotoxy(11, 11); cout << "Compositor : ";
	
	// Pergunta o disco da Música
	gotoxy(20,7); cin >> registro.disco;
	
	// Procura pelo código do disco, para verificar se já possui cadastro
	achei = false;
	for (int x=0; x<listaGeneros.size(); x++)
	{
		if (listaGeneros[x].disco == registro.disco)
		{
			achei = true;
			posicao = x;
			registro = listaGeneros[x];
			break;
		}
	}
	
	if (achei)
	{
		// Se achou a música, mostra os dados
		fflush(stdin);
		gotoxy(20,7);
		cout << registro.disco;
		gotoxy(20,8);
		cout << registro.genero;
		gotoxy(20, 9);
		cout << registro.titulo;
		gotoxy(20, 10);
		cout << registro.gravadora;
		gotoxy(20, 11);
		cout << registro.compositor;
		
		// pergunta se deseja alterar ou excluir
		resp = perguntar(11,12,"Deseja alterar/excluir/voltar (A/E/V) :");
		if (resp == "A")
		{
			// o usuário deseja alterar os dados da música
			// limpa a area para entrar os novos dados
			limparArea(20,8,69,10);
			fflush(stdin);
			gotoxy(20,7); 
			getline(cin, registro.disco);
			gotoxy(20,8); 
			getline(cin, registro.genero);
			gotoxy(20,9);
			getline(cin, registro.titulo);
			gotoxy(20,10);
			getline(cin, registro.gravadora);
			gotoxy(20, 11);
			getline(cin, registro.compositor);
			
			// solicita confirmaçao da alteração
			resp = perguntar(11,12,"Confirma alteracao (S/N) :");
			if (resp == "S")
			{
				listaGeneros[posicao] = registro;
			}
		}
		if (resp == "E")
		{
			// o usuário deseja excluir a música
			resp = perguntar(11,12,"Confirma exclusao (S/N) :");
			if (resp == "S")
			{
				listaGeneros.erase(listaGeneros.begin()+posicao);
			}
		}
	}
	else
	{
		// Se não achou, pergunta se deseja cadastrar uma nova música
		resp = perguntar(11,12,"Disco Não encontrado. Cadastrar Novo? (S/N) :");
		
		if (resp == "S")
		{
			// O usuário deseja cadatrar nova música
			// Pergunta os dados
			fflush(stdin);
			gotoxy(20,7);
			getline(cin, registro.disco);
			gotoxy(20,8);
			getline(cin, registro.genero);
			gotoxy(20, 9);
			getline(cin, registro.titulo);
			gotoxy(20,10);
			getline(cin, registro.gravadora);
			gotoxy(20, 11);
			getline(cin, registro.compositor);
			
			resp = perguntar(11,12,"Confirma cadastro (S/N) :");
			if (resp == "S")
			{
				// usuário confirmou o cadastro
				listaGeneros.push_back(registro);
			}
		}
	}
	
}

void cadastrarCD()
{
	desenharMoldura(10,4,75,13);
	centralizar("Adicionar mais Música no CD",6,13,75);
    string disco;
    fflush(stdin);
    
    gotoxy(11, 8);
    cout << "Digite o nome do DISCO: ";
    getline(cin, disco);
    
    

    // Procura pelo código do disco para verificar se já possui cadastro
    bool achei = false;
    int posicao = 0;
    for (int x = 0; x < listaGeneros.size(); x++)
    {
        if (listaGeneros[x].disco == disco)
        {
            achei = true;
            posicao = x;
            break;
        }
    }

    if (!achei)
    {
    	gotoxy(11, 10);
        cout << "CD não encontrado no disco atual.";
        gotoxy(11, 11);
        cout << "Deseja cadastrar um novo CD?(S/N)";
        string resp;
        getline(cin, resp);
        
        limparArea(20,8,69,10);
        desenharMoldura(10,4,75,13);

        if (resp == "S" || resp == "s")
        {
            GENERO novoCD;
            novoCD.disco = disco;

            // Pergunta os dados para cada música
            do
            {   
            	gotoxy(11, 5);
            	cout << "Cadastrando novo CD/Disco: ";
            	gotoxy(11, 6);
            	cout << "CD: ";
            	getline(cin, novoCD.disco);
            	gotoxy(11, 7);
                cout << "Gênero da música: ";
               	getline(cin, novoCD.genero);
               	gotoxy(11, 8);
                cout << "Título da música: ";
                getline(cin, novoCD.titulo);
                gotoxy(11, 9);
                cout << "Gravadora: ";
                getline(cin, novoCD.gravadora);
                gotoxy(11, 10);
                cout << "Compositor: ";
                getline(cin, novoCD.compositor);

                listaGeneros.push_back(novoCD);

				gotoxy(11, 11);
                cout << "Deseja cadastrar outra música neste CD? (S/N): ";
                cin >> resp;

            } while (resp == "s" || resp == "s");
        }
        else
        {
            cout << "Cadastro cancelado." << endl;
        }
    }
    else
    {
    	
        cout << "CD encontrado. Não é possível cadastrar músicas diretamente neste CD." << endl;
        gotoxy(11, 12);
    }
}






