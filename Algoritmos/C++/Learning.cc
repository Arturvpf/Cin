#include <iostream>
#include <string> 
using namespace std;

int main(){
    /*
    Not use using namespace std;
    int i=91; 
    std::cout << "Hello " <<i << std::endl;   printed:Hello 91\n  std::cout=printf  (<<) seria meio que uma virgula (std::endl) seria a quebra de linha
    
    int i=91; 
    std::cout << "Hello " <<i<< " ROLF" <<" aiaiaiaiai"<<std::endl; //printed:Hello 91 ROLF aiaiaiaiai\n
    */
    

    
    //ler uma string (Sem espaco)
    /*cout << "Insert a String"<<endl;
    string s;
    cin >> s endl;
    cout<<s;*/ //esse codigo nao funciona pq o cin para de ler quando encontra um espaco


    //pegar uma string com espaco
    /*cout << "Insert a String: ";
    string s;
    getline(cin, s); //precisa da biblioteca de string
    cout << s << endl;*/

    /*//exemplo da questao de hash  string1:string2 (formato de entrada)
    string str;
    cout << "Insert a String: ";
    getline(cin, str);

    // Encontrar a posição do caractere ':' na string
    size_t pos = str.find(':');

    if (pos != string::npos) {
        // Extrair as duas substrings antes e depois do ':'
        string string1 = str.substr(0, pos);
        string string2 = str.substr(pos + 1); //substr aceita 2 parametros diferenciados garotin, pos+1 eh de onde a sub string vai comecar
                                              //enquanto o substr de cima indica de onde ate onde vai comecar a substring

        cout << "String 1: " << string1 << endl;
        cout << "String 2: " << string2 << endl;
    } else {
        cout << "Formato inválido!" << endl;
    }*/


    //auto i=0;  seria o E arbitrario que o professor falou
    //goto Inicio(lembra assembly);  //goto eh um comando que faz o programa voltar para o inicio do programa


    
    return 0;

}