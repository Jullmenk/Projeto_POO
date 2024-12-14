#include "../../include/Livros/LivroFiccao.h"

LivroFiccao::LivroFiccao(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,string Genero_Literario,int Faixa_Etaria):Geral(categoria,titulo,autor,ano, disponivel),Genero_Literario(Genero_Literario),Faixa_Etaria(Faixa_Etaria),isbn(isbn)
{
    //ctor
}

LivroFiccao::~LivroFiccao()
{
           cout << categoria << " destruído com sucesso.\n";
}

void LivroFiccao::descricao() const {
    Geral::descricao();
    cout 
         << " | Género Literário: " << Genero_Literario
         << " | Faixa Etaria: " << Faixa_Etaria 
         << " | ISBN: " << isbn << endl;
}

string LivroFiccao::getCodigo() const {
    return isbn;
}

bool LivroFiccao::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Faixa_Etaria << " ; "
    << isbn << " ; "
    << Genero_Literario << " \n";
    return true;
} 

void LivroFiccao::AlterarInformacaoDoLivro(){
    int type=0;
    int faix=-1;
    while(type<1 || type>2){
    system("cls");
    cout << "\nNos Livros de Ficção Só é possivel alterar a Faixa Etária e o Género Literário\n";
    cout << "\t1. Faixa Etária" << endl;
    cout << "\t2. Género Literário" << endl;
    cout << "Selecione o Número do que deseja alterar : ";
    cin>> type;
    }

    switch (type)
    {
    case 1:
        while(faix<0){
        cout << "\n Digite a nova  Faixa Etária do Livro : ";
        cin >> faix;
        }
        Faixa_Etaria = faix;
        break;
    case 2:
        cout << "\n Digite o novo Género Literário : ";
        cin.ignore(); 
        getline(cin, Genero_Literario);
        break;
    }
}