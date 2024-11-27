#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <string>
#include <iostream>
#include <ctime>
#include "Leitor.h"

using namespace std;

class Emprestimo {
private:
    Leitor* leitor;
    Geral* livro;
    time_t dataEmprestimo;
    int prazo;

public:
    Emprestimo(Leitor* leitor, Geral* livro)
        : leitor(leitor), livro(livro) {
        dataEmprestimo = time(nullptr);
        prazo = leitor->prazoEmprestimo(*livro);
    }

    void detalhes() const {
        cout << "Leitor: " << leitor->getNome() << " | Livro: " << livro->getTitulo() 
             << " | Prazo: " << prazo << " dias\n";
    }
};

#endif
