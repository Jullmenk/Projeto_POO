#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <list>
#include <map>
#include "Pessoa.h"
#include "Geral.h"
using namespace std;

class Biblioteca {
private:
    // Armazena os livros organizados por categoria
    map<string, list<Geral*>> livrosPorCategoria;

public:
    Biblioteca() = default;
    virtual ~Biblioteca();
    bool SaveToFile(const string& nf);
    bool LoadFile(const string& nf);
    void RelatorioCategoria(const string& cat) const;
    void Prorrogacao_Emprestimos();
    void Sistema_Notificacoes_Atraso();
    void listarLivros() const;  // Lista todos os livros
    void listarLivrosDisponiveis() const;
    void adicionarLivro(const string& categoria, Geral* livro);
    Geral* buscarLivro(int codigo);
    void removerLivro(const string& categoria, int codigo);
};

#endif // BIBLIOTECA_H
