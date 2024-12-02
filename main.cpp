#include <iostream>
using namespace std;
#include "include/Biblioteca.h"
#include "include/Utils/menu.h"
#include "include/Utils/Uteis.h"


int main() {
    Biblioteca biblioteca;
    Uteis uteis;
    MENU_PRINCIPAL(biblioteca,uteis);
    return 0;
}
