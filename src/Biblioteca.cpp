#include "../include/Biblioteca.h"
#include "../include/LivroCientifico.h"
#include <iostream>
#include <algorithm>
using namespace std;

Biblioteca::~Biblioteca() {
    for (auto& categoria : livrosPorCategoria) {
        for (auto& livro : categoria.second) {
            delete livro;
        }
    }
}

void Biblioteca::adicionarLivro(const string& categoria, Geral* livro) {
    livrosPorCategoria[categoria].push_back(livro);
}

void Biblioteca::removerLivro(const string& categoria, int codigo) {
    auto it = livrosPorCategoria.find(categoria);
    if (it != livrosPorCategoria.end()) {
        auto& listaLivros = it->second;
        auto livroIt = find_if(listaLivros.begin(), listaLivros.end(),
                                    [codigo](Geral* livro) { return livro->getCodigo() == codigo; });

        if (livroIt != listaLivros.end()) {
            delete *livroIt;  // Libera a memória
            listaLivros.erase(livroIt);  // Remove da lista
        }
    }
}

void Biblioteca::listarLivros() const {
    if(livrosPorCategoria.empty()){
        cout << "Lista se encontra vazia";
    }
    else{
        for (const auto& categoria : livrosPorCategoria) {
            cout << "\nCategoria: " << categoria.first << "\n";
            for (const auto& livro : categoria.second) {
                livro->descricao();
                cout << "-------------------\n";
            }
        }
    }
}

void Biblioteca::listarLivrosDisponiveis() const {
    for (const auto& categoria : livrosPorCategoria) {
        for (const auto& livro : categoria.second) {
            if (livro->isDisponivel()) {
                livro->descricao();
                cout << "-------------------\n";
            }
        }
    }
}

Geral* Biblioteca::buscarLivro(int codigo) {
    for (auto& categoria : livrosPorCategoria) {
        for (auto& livro : categoria.second) {
            // Verifica se o código do livro é correspondente (simula código como `ano`)
            if (livro->getCodigo() == codigo) {
                return livro;
            }
        }
    }
    return nullptr;
}

void Biblioteca::RelatorioCategoria(const string& cat) const {
    auto it = livrosPorCategoria.find(cat);
    if (it != livrosPorCategoria.end()) {
        cout << "\nRelatorio da categoria: " << cat << "\n";
        for (const auto& livro : it->second) {
            livro->descricao();
        }
    } else {
        cout << "Categoria nao encontrada.\n";
    }
}

// bool Biblioteca::SaveToFile(string nf)
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }

// bool Biblioteca::LoadFile(string nf)
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }


// void Biblioteca::Prorrogacao_Emprestimos()
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
// }
// void Biblioteca::Sistema_Notificacoes_Atraso()
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
// }

// bool Biblioteca::Add_Leitores()
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }
// bool Biblioteca::Add_Leitor(Pessoa *P)
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }

