void limparArea(int colIni, int linIni, int colFin, int linFin)
{
	for (int x=colIni; x<=colFin; x++)
	{
		for (int y=linIni; y<=linFin; y++)
		{
			gotoxy(x,y); cout << " ";
		}
	}
}


void desenharMoldura(int colIni, int linIni, int colFin, int linFin)
{
	// limpa a área da moldura
	limparArea(colIni, linIni, colFin, linFin);
	
	// desenha as linhas horizontais
	for(int x=colIni; x<=colFin; x++)
	{
		gotoxy(x,linIni); 
		cout << "-";
		gotoxy(x,linFin); 
		cout << "-";
		
	}
	
	// desenha as linhas verticais
	for(int y=linIni; y<=linFin; y++)
	{
		gotoxy(colIni,y);
		cout << "|";
		gotoxy(colFin,y);
		cout << "|";
	}
	
	// arruma os cantos
	gotoxy(colIni,linIni); cout << "+";
	gotoxy(colFin,linIni); cout << "+";
	gotoxy(colIni,linFin); cout << "+";
	gotoxy(colFin,linFin); cout << "+";
}



void centralizar(string msg, int lin, int colIni, int colFin)
{
	int meio;
	meio = (colFin-colIni-msg.length())/2;
	gotoxy(meio,lin);
	cout << msg;
}



string mostrarMenu(int col, int lin, vector<string> opcoes)
{
	string op;
	int x;
	int colFin = col + opcoes[0].size() + 1;
	int linFin = lin + opcoes.size() + 3;
	
	desenharMoldura(col, lin, colFin, linFin);
	centralizar("Menu", lin+1, col, colFin);
	col ++;
	lin += 2;
	for (x=0; x<opcoes.size(); x++)
	{
		gotoxy(col, lin+x); cout << opcoes[x];
	}
	gotoxy(col, lin+x);
	cout << "Opção : ";
	op = getche();
	
	return op;
}


string perguntar(int col, int lin, string pergunta)
{
	string resp;
	gotoxy(col,lin);
	cout << pergunta;
	resp = getche();
	resp = toupper(resp[0]);
	limparArea(col,lin,col+pergunta.size()+3,lin);
	return resp;
}



