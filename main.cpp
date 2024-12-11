#include <iostream>
#include <windows.h>
using namespace std;
#include "include/Biblioteca.h"
#include "include/Utils/menu.h"
#include "include/Utils/Uteis.h"


int main() {
    // Checkpoint 10.
    SetConsoleOutputCP(CP_UTF8); 
    Biblioteca biblioteca;
    Uteis uteis;
    uteis.LerLivrosPorCategoria(biblioteca);
    MENU_PRINCIPAL(biblioteca,uteis);
    return 0;
}
