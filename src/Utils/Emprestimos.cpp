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
         << " | Categoria do Leitor: " << categoriaLeitor
         << " | Categoria do Livro: " << categoriaLivro
         << " | Id do Livro: " << idLivro
         << " | Titulo: " << tituloLivro
         << " | Data de Emprestimo: " << dataEmprestimoStr
         << " | Data de Devolucao: " << dataDevolucaoStr << endl;
}

string Emprestimo::getNifEmprestimo() const{
    return NIFLeitor;
}

string Emprestimo::getIDLivroEmprestimo() const{
    return idLivro;
}

string Emprestimo::getCategoriaLeitorEmprestimo() const{
    return categoriaLeitor;
};

string Emprestimo::getCategoriaLivroEmprestimo() const{
    return categoriaLivro;
};

time_t Emprestimo::getDataDevolucaoEmprestimo() const{
    return dataDevolucao;
};

bool Emprestimo::escreverFicheiro(ofstream& file) const{
    if (!file.is_open()) {
        return false;
    }
    file<< NIFLeitor << " ; "
    << nomeLeitor << " ; "
    << categoriaLivro << " ; "
    << categoriaLeitor << " ; "
    << tituloLivro << " ; "
    << idLivro << " ; "
    << dataEmprestimo << " ; "
    << dataDevolucao << "\n";
    return true;
} 


bool Emprestimo::operator==(const Emprestimo& other) const {
    return (NIFLeitor == other.NIFLeitor &&
            idLivro == other.idLivro &&
            categoriaLivro == other.categoriaLivro &&
            categoriaLeitor == other.categoriaLeitor &&
            tituloLivro == other.tituloLivro &&
            dataEmprestimo == other.dataEmprestimo &&
            dataDevolucao == other.dataDevolucao);
}