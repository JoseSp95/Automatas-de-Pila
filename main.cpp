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
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
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

void automata2(){

    char caracteresAceptados [2];
    caracteresAceptados[0] = 'a';
    caracteresAceptados[1] = 'b';

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
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }


    int size = strlen(cadena);

    stack<char> pila;

    if(cadena[0] == 'a'){
        pila.push('x');
    }
    else if(cadena[0] == 'b'){
        pila.push('y');
    }

    band = false;
    char top;
    if(cadena[size - 1] == 'a'){
        top = pila.top();
        if(top == 'x'){
            band = true;
        }
        else if(top == 'y'){
            band = false;
        }
    }
    else if(cadena[size - 1] == 'b'){
        if(top == 'x'){
            band = false;
        }
        else if(top == 'y'){
            band = true;
        }
    }

    if(band){
        cout<<"\t Cadena Aceptada"<<endl;
    }
    else{
        cout<<"\t Cadena Rechazada"<<endl;
    }
}

void automata3(){

    char caracteresAceptados [2];
    caracteresAceptados[0] = 'a';
    caracteresAceptados[1] = 'b';

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
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }

    stack<char> pila;

    for(int i = 0; i < strlen(cadena) ; i++){
        if(i % 2 == 0){
            pila.push('x');
        }
        else{
            pila.pop();
        }
    }

    if(pila.empty()){
        cout<<"\t Cadena Aceptada"<<endl;
    }
    else{
        cout<<"\t Cadena Rechazada"<<endl;
    }
}

void automata5(){

    char caracteresAceptados [2];
    caracteresAceptados[0] = 'a';
    caracteresAceptados[1] = 'b';

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
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }

    stack<char> pila;

    for(int i = 0; i < strlen(cadena) ; i++){
        if(i % 2 == 0){
            pila.push('x');
        }
        else{
            pila.pop();
        }
    }

    if(pila.empty()){
        cout<<"\t Cadena Rechazada"<<endl;
    }
    else{
        cout<<"\t Cadena Aceptada"<<endl;
    }
}

int main(){

    bool band = true;

    while(band){
        int opcion = menu();
        switch (opcion){
            case 1 : automata1();
            case 2 : automata2();
            case 3 : automata3();
            case 5 : automata5();
            default:break;
        }
    }


}