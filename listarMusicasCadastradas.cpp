void listarMusicasCadastradas() {
    desenharMoldura(8, 6, 95, 26);
    centralizar("Lista de M�sicas Cadastradas", 7, 1, 70);

    if (listaGeneros.empty()) {
        gotoxy(11, 9);
        cout << "Nenhuma m�sica cadastrada.";
    } else {
        int linha = 15;
        
        // Cabe�alho da tabela
        gotoxy(11, linha++);
        cout << setw(15) << "Disco" << setw(15) << "G�nero" << setw(15) << "T�tulo" << setw(15) << "Gravadora" << setw(15) << "Compositor";
        
        // Linha horizontal separadora
        gotoxy(11, linha++);
        cout << setfill('-') << setw(84) << "" << setfill(' ');

        // Dados das m�sicas
        for (const GENERO& musica : listaGeneros) {
            gotoxy(11, linha++);
            cout << setw(15) << musica.disco << setw(15) << musica.genero << setw(15) << musica.titulo << setw(15) << musica.gravadora << setw(15) 
				 << musica.compositor;
        }
    }

    // Aguarda o usu�rio pressionar uma tecla antes de retornar ao menu principal
    gotoxy(11, 22);
    cout << "Pressione qualquer tecla para voltar.";
    _getch();
}
