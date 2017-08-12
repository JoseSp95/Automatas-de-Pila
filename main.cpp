#include <iostream>
#include <cstring>
#include <stack>

using  namespace std;

int menu(){
    cout<<"\t\t\t MENU"<<endl;
    cout<<"\t 1. w = 0n 1m 0n, n,m >=0"<<endl;
    cout<<"\t 2. w empieza y termina con el mismo simbolo"<<endl;
    cout<<"\t 3. |w| es par "<<endl;
    cout<<"\t 4. an bm, n != 2m "<<endl;
    cout<<"\t 5. |w| es impar "<<endl;
    cout<<endl;
    cout<<"\t Elija una opcion : ";

    int opcion;
    cin>>opcion;

    return opcion;
}

void automata1(){

    char caracteresAceptados [2];
    caracteresAceptados[0] = '0';
    caracteresAceptados[1] = '1';

    char cadena [20];
    cout<<"\t Ingrese Palabra a verificar : ";
    cin>>cadena;

    bool band;
    for(int i = 0; i < strlen(cadena) ; i++){
        band = false;
        for (char caracteresAceptado : caracteresAceptados) {
            if(cadena[i] == caracteresAceptado){
                band = true;
                break;
            }
        }

        if(!band){
            cout<<"\t La Cadena ingresada tiene caracteres invalidos";
            return;
        }
    }

    //comprobamos si todos son 0 o si todos son 1
    bool todosCero = true;
    bool todosUno = true;

    for(int i=0; i < strlen(cadena) ; i++){
        if(cadena[i] != '0'){
            todosCero = false;
        }

        if(cadena[i] != '1'){
            todosUno = false;
        }
    }

    bool salir = false;

    if(todosUno){
        cout<<"\t Cadena Aceptada"<<endl;
        salir = true;
    }
    else if(todosCero){
        int size = strlen(cadena);
        if(size % 2 == 0){
            cout<<"\t Cadena Aceptada"<<endl;
        }
        else{
            cout<<"\t Cadena Rechazada"<<endl;
        }
        salir = true;
    }


    if(!salir){

        stack<char> pila;
        bool pasamosUnUno = false;
        bool pasamosSegundosCeros = false;
        bool error = false;
        for(int i=0; i < strlen(cadena) ; i++){
            if(cadena[i] == '0'){
                if(!pasamosUnUno){
                    pila.push('x');
                }
                else{
                    if(!pila.empty()){
                        pila.pop();
                        pasamosSegundosCeros = true;
                    }
                    else{
                        error = true;
                        break;
                    }

                }
            }
            else if(cadena[i] == '1'){
                if(pasamosSegundosCeros){
                    error = true;
                    break;
                }
                pasamosUnUno = true;
            }
        }

        if(error){
            cout<<"\t Cadena Rechazada"<<endl;
        }
        else{
            if(pila.empty()){
                cout<<"\t Cadena Aceptada"<<endl;
            }
            else{
                cout<<"\t Cadena Rechazada"<<endl;
            }
        }
    }

}


int main(){

    bool band = true;

    while(band){
        int opcion = menu();
        switch (opcion){
            case 1 : automata1();
            default:break;
        }
    }


}