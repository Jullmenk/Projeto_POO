#include <iostream>
#include <cstdlib> // Para exit e system("cls")
using namespace std;
#include "../include/menu.h"
#include "../include/Biblioteca.h"
#include "../include/Uteis.h"

void MENU_PRINCIPAL(Biblioteca &biblioteca) {

    int num;
    do {
        // Limpa a tela 
        system("cls");

        // Exibe o menu principal
        cout << "\n\t***** Biblioteca *****" << endl;
        cout << "\t1. Livros" << endl;
        cout << "\t2. Utilizador" << endl;
        cout << "\t0. Sair" << endl;
        cout << "\n\tEscolha uma opcao: ";

        // Recebe a entrada do usuário
        cin >> num;

        // Limpa a tela
        system("cls");

        // Processa a escolha do usuário
        switch (num) {
            case 1:
                // Chamar o menu do administrador
                // MENU_ADM();
                MENU_LIVROS(biblioteca);
                system("pause");
                break;

            case 2:
                // Chamar o menu do utilizador
                // MENU_LIVRO_USER();
                cout << "Menu do Utilizador (em desenvolvimento)" << endl;
                break;

            case 0:
                cout << "Saindo do programa..." << endl;
                exit(0);
                break;

            default:
                cout << "\n\tOpcao invalida!" << endl;
                break;
        }
    } while (num != 0);
}



void MENU_LIVROS(Biblioteca &biblioteca) {
    int num;
    do {
        // Limpa a tela
        system("cls");

        // Exibe o menu principal
        cout << "\n\t***** Biblioteca - LIVROS *****" << endl;
        cout << "\t1. Ver Livros" << endl;
        cout << "\t2. Adicionar Livros" << endl;
        cout << "\t3. Emprestar Livro" << endl;
        cout << "\t4. Remover Livro" << endl;
        cout << "\t5. Devolver Livro" << endl;
        cout << "\t6. Relatorios de Livros por Categoria" << endl;
        cout << "\n\tEscolha uma opcao: ";

        // Recebe a entrada do usuário
        cin >> num;

        // Limpa a tela
        system("cls");

        // Processa a escolha do usuário
        switch (num) {
            case 1:{
                // Chamar o menu do administrador
                // MENU_ADM();
                biblioteca.listarLivros();
                system("pause");
                break;
}
            case 2:{
                // Chamar o menu do utilizador
                // MENU_LIVRO_USER();
                Uteis uteis;
                cout << "\n\t***** Adicionar Livros *****" << endl;
                uteis.CriarLivroUser(biblioteca);
                cout << "" << endl;
                break;}

            case 0:
                cout << "Saindo do programa..." << endl;
                exit(0);
                break;

            default:
                cout << "\n\tOpcao invalida!" << endl;
                break;
        }
    } while (num != 0);
}
