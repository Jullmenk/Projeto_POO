#include "../../include/Livros/LivroCientifico.h"


LivroCientifico::LivroCientifico(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn, string area,string edicao):Geral(categoria,titulo,autor,ano, disponivel),isbn(isbn),area(area),edicao(edicao)
{
    //ctor
}

LivroCientifico::~LivroCientifico()
{
           cout << categoria << " destruído com sucesso.\n";
}

void LivroCientifico::descricao() const {
    Geral::descricao();
    cout << " | Área: " << area
         << " | ISBN: " << isbn
         << " | Edição: " << edicao << endl;
}

string LivroCientifico::getCodigo() const {
    return isbn;
}

bool LivroCientifico::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << area << " ; "
    << isbn << " ; "
    << edicao << " \n";
    return true;
}


void LivroCientifico::AlterarInformacaoDoLivro(){
    int type=0;

    while(type<1 || type>2){
    system("cls");
    cout << "\nNos Livros Cientificos Só é possivel alterar a Área e Edição\n";
    cout << "\t1. Área" << endl;
    cout << "\t2. Edição" << endl;
    cout << "Selecione o Número do que deseja alterar : ";
    cin>> type;
    }

    switch (type)
    {
    case 1:
        cout << "\n Digite a nova Área do Livro : ";
        cin.ignore(); 
        getline(cin, area);
        break;
    case 2:
        cout << "\n Digite a nova Edição do Livro : ";
        cin.ignore(); 
        getline(cin, edicao);
        break;
    }
}