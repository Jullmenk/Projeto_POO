#include <iostream>
#include <windows.h>
using namespace std;
#include "include/Biblioteca.h"
#include "include/Utils/menu.h"
#include "include/Utils/Uteis.h"


int main() {
    // Checkpoint 13 e Ediçao info Livro.
    // nao coloca a multa,provavel problema da leitura das datas

    SetConsoleOutputCP(CP_UTF8); 
    Biblioteca biblioteca;
    Uteis uteis;
    uteis.LerLimitesPorCategoria();
    uteis.LerDesconto();
    uteis.LerLivrosPorCategoria(biblioteca);
    uteis.LerPessoasPorCategoria(biblioteca);
    biblioteca.LerEmprestimos();
    biblioteca.LerReservas();
    MENU_PRINCIPAL(biblioteca,uteis);
    return 0;
}
