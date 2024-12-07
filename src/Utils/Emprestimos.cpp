#include "../../include/Utils/Emprestimos.h"
#include <cstring> 

Emprestimo::Emprestimo(string NIFLeitor, string nomeLeitor, string categoriaLivro, 
                string tituloLivro, time_t dataEmprestimo, time_t dataDevolucao,string idLivro,string categoriaLeitor):NIFLeitor(NIFLeitor), nomeLeitor(nomeLeitor), categoriaLivro(categoriaLivro),
            tituloLivro(tituloLivro), dataEmprestimo(dataEmprestimo), dataDevolucao(dataDevolucao), idLivro(idLivro),categoriaLeitor(categoriaLeitor) {}

Emprestimo::~Emprestimo(){

}; 

void Emprestimo::Descricao() const {
    // Removendo a nova linha gerada por ctime() ao imprimir a data
    char* dataEmprestimoStr = ctime(&dataEmprestimo);
    dataEmprestimoStr[strlen(dataEmprestimoStr) - 1] = '\0';

    char* dataDevolucaoStr = ctime(&dataDevolucao);
    dataDevolucaoStr[strlen(dataDevolucaoStr) - 1] = '\0'; 

    cout << "NIF: " << NIFLeitor
         << " | Nome do leitor: " << nomeLeitor
         << " | Categoria de Livro: " << categoriaLeitor
         << " | Categoria de Livro: " << categoriaLivro
         << " | Identificador do Livro: " << idLivro
         << " | Titulo: " << tituloLivro
         << " | Data de Emprestimo: " << dataEmprestimoStr
         << " | Data de Devolucao: " << dataDevolucaoStr << endl;
}

string Emprestimo::getNif() const{
    return NIFLeitor;
}

string Emprestimo::getIDLivro() const{
    return idLivro;
}

string Emprestimo::getCategoriaLeitor() const{
    return categoriaLeitor;
};

string Emprestimo::getCategoriaLivro() const{
    return categoriaLivro;
};

time_t Emprestimo::getDataDevolucao() const{
    return dataDevolucao;
};
