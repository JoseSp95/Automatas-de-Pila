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

    char caracteresAceptados [2]; // caracteres que acepta el automata
    caracteresAceptados[0] = '0';
    caracteresAceptados[1] = '1';

    char cadena [20];
    cout<<"\t Ingrese Palabra a verificar : ";
    cin>>cadena;

    if(cadena[0] == ' '){
        cout<<"\t Cadena Aceptada"<<endl;
        return;
    }

    // verifica si la cadena ingresada contiene los caracteres aceptados por el automata
    bool band;
    for(int i = 0; i < strlen(cadena) ; i++){
        band = false;
        for (int j = 0; j < strlen(caracteresAceptados); j++) {
            if(cadena[i] == caracteresAceptados[j]){
                band = true;
                break;
            }
        }

        if(!band){
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }

    //---------------------------------------------------

    //comprobamos si todos son 0 o si todos son 1,
    //osea si la cadena ingresada es '000' solo verificamos que su tamaño sea par
    //para la cadena '111' (puros unos) siempre sera aceptada
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
//---------------------------------------------

    if(!salir){

        /*Como el automata acepta palabras de esta forma 0n 1m 0n , entonces como ya sabemos que este contendra unos y ceros,
         * porque ya verificamos si la cadena es puros ceros o puros unos, entonces
         * por cada uno que encontramos al inicio de la cadena metemos un 'x' a la pila.
         * Cuando encontramos un UNO se pone a true la varibale pasamosUnUno para saber que los ceros que puedan seguir
         * desempilaran un valor de la pila, cuando encontramos unos CEROS ya pasados los UNOS, se activa la variable
         * pasamosSegundosCeros = true , para que ya no exista ningun UNO despues de esos ceros
         * */
        stack<char> pila;
        bool pasamosUnUno = false;
        bool pasamosSegundosCeros = false;
        bool error = false;
        for(int i=0; i < strlen(cadena) ; i++){ //recorremos la cadena
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

    // verifica si la cadena ingresada contiene los caracteres aceptados por el automata
    bool band;
    for(int i = 0; i < strlen(cadena) ; i++){
        band = false;
        for (int j = 0; j < strlen(caracteresAceptados); j++) {
            if(cadena[i] == caracteresAceptados[j]){
                band = true;
                break;
            }
        }

        if(!band){
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }
    //----------------------------------------------------------------

    /*Como el automata pide que la palabra ingresada debe poseer la misma letra al inicio y al final
     * entonces, si la primera letrade la cadena es 'a' se apila un valor 'x', si
     * es 'b' se apila 'y'
     * ahora se verifica que la ultima letra de la cadena sea la misma letra , por lo tanto lo verificamos
     * y si no es asi no acepta la cadena
     * */


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

    if(cadena[0] == ' '){
        cout<<"\t Cadena Aceptada"<<endl;
        return;
    }

    // verifica si la cadena ingresada contiene los caracteres aceptados por el automata
    bool band;
    for(int i = 0; i < strlen(cadena) ; i++){
        band = false;
        for (int j = 0; j < strlen(caracteresAceptados); j++) {
            if(cadena[i] == caracteresAceptados[j]){
                band = true;
                break;
            }
        }

        if(!band){
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }

    /*Como ya sabemos que la cadena contiene caracteres validos
     * por cada letra de la cadena , sacamos su indice correspondiente y verificamos s es modulo de 2
     * si es asi se apila un dato a la pila, si el indice es impar se desapila
     * si la pila queda vacia se acepta la cadena porque es de tamaño par
     * */

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

void automata4(){

    char caracteresAceptados [2];
    caracteresAceptados[0] = 'a';
    caracteresAceptados[1] = 'b';

    char cadena [20];
    cout<<"\t Ingrese Palabra a verificar : ";
    cin>>cadena;

    // verifica si la cadena ingresada contiene los caracteres aceptados por el automata
    bool band;
    for(int i = 0; i < strlen(cadena) ; i++){
        band = false;
        for (int j = 0; j < strlen(caracteresAceptados); j++) {
            if(cadena[i] == caracteresAceptados[j]){
                band = true;
                break;
            }
        }

        if(!band){
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }

    //verificamos que despues del an bm no haya mas letras
    bool pasamosLosB = false;
    bool error = false;
    for(int i = 0; i < strlen(cadena) ; i++){
        if(cadena[i] == 'b'){
            pasamosLosB = true;
        }
        else if(cadena[i] == 'a'){
            if(pasamosLosB){
                error = true;
                break;
            }
        }
    }

    if(error){
        cout<<"\t Cadena Rechazada"<<endl;
        return;
    }


    /*cada letra 'a' empialara un X y poca da letra 'b' desempilaraun valor X , si esta queda vacia se rechaza la cadena
     *si la pila queda vacia y se quiere desempilar mas 'b's entonces si acepta porque la condicion es que
     * el numero de 'b' no sea igual al doble de 'a'
     * por ejemplo :  aab --> rechazada ,   ab -> aceptada,  abbb-> acepatda,  aaaabb  -> rechazada
     * */
    band = false;
    stack<char> pila;
    for(int i = 0; i < strlen(cadena) ; i++){
        if(cadena[i] == 'a'){
            pila.push('x');
        }
        else if(cadena[i] == 'b'){
            if(pila.empty()){
                band = true;
                break;
            }
            pila.pop();
            pila.pop();
        }
    }

    if(pila.empty() && !band){
        cout<<"\t Cadena Rechazada"<<endl;
    }
    else if(band || !pila.empty()){
        cout<<"\t Cadena Aceptada"<<endl;
    }

}

void automata5(){

    char caracteresAceptados [2];
    caracteresAceptados[0] = 'a';
    caracteresAceptados[1] = 'b';

    char cadena [20];
    cout<<"\t Ingrese Palabra a verificar : ";
    cin>>cadena;

    // verifica si la cadena ingresada contiene los caracteres aceptados por el automata
    bool band;
    for(int i = 0; i < strlen(cadena) ; i++){
        band = false;
        for (int j = 0; j < strlen(caracteresAceptados); j++) {
            if(cadena[i] == caracteresAceptados[j]){
                band = true;
                break;
            }
        }

        if(!band){
            cout<<"\t La Cadena ingresada tiene caracteres invalidos"<<endl;
            return;
        }
    }

    /*Como ya sabemos que la cadena contiene caracteres validos
     * por cada letra de la cadena , sacamos su indice correspondiente y verificamos s es modulo de 2
     * si es asi se apila un dato a la pila, si el indice es impar se desapila
     * si la pila queda vacia se rechaza la cadena porque es de tamaño par
     * */

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
                break;
            case 2 : automata2();
                break;
            case 3 : automata3();
                break;
            case 4 : automata4();
                break;
            case 5 : automata5();
                break;
            default:break;
        }

        system("pause");
        system("cls");
    }


}