void listarMusicasCadastradas() {
    desenharMoldura(8, 6, 95, 26);
    centralizar("Lista de Músicas Cadastradas", 7, 1, 70);

    if (listaGeneros.empty()) {
        gotoxy(11, 9);
        cout << "Nenhuma música cadastrada.";
    } else {
        int linha = 15;
        
        // Cabeçalho da tabela
        gotoxy(11, linha++);
        cout << setw(15) << "Disco" << setw(15) << "Gênero" << setw(15) << "Título" << setw(15) << "Gravadora" << setw(15) << "Compositor";
        
        // Linha horizontal separadora
        gotoxy(11, linha++);
        cout << setfill('-') << setw(84) << "" << setfill(' ');

        // Dados das músicas
        for (const GENERO& musica : listaGeneros) {
            gotoxy(11, linha++);
            cout << setw(15) << musica.disco << setw(15) << musica.genero << setw(15) << musica.titulo << setw(15) << musica.gravadora << setw(15) 
				 << musica.compositor;
        }
    }

    // Aguarda o usuário pressionar uma tecla antes de retornar ao menu principal
    gotoxy(11, 22);
    cout << "Pressione qualquer tecla para voltar.";
    _getch();
}
