#include "../model/pets/pets.h"

void Pets::Create(){
    int confirmar;
    string linea;
    ifstream input("../model/pets/pets.csv");
    ofstream Vout("../model/pets/temp.csv"); cin.ignore(100,'\n');
    cout<<"Nombre de la mascota: "; getline(cin,nombre);
    cout<<"Tipo de la mascota: "; cin>>pet_tipo;
    cout<<"Edad de la mascota: "; cin>>edad; cin.ignore(100,'\n');
    cout<<"Owner: "; getline(cin,owner);
    cout<<"Cedula: "; cin>>owner_cedula;
    while(getline(input, linea)){
        Vout<<linea<<endl;
    }
    Vout<<nombre<<","<<pet_tipo<<","<<edad<<","<<owner<<","<<owner_cedula<<","<<endl;   
    cout<<"Desea confirmar los cambios? 1. Si | 2. No"<<endl; cin>>confirmar;
    Vout.close();
    input.close();
    if(confirmar==1){
        remove("../model/pets/pets.csv");
        rename("../model/pets/temp.csv", "../model/pets/pets.csv");
    } else if (confirmar==2){
        remove("../model/pets/temp.csv");
    } else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        remove("../model/pets/temp.csv");
    }
}

void Pets::Read(){
    ifstream input("../model/pets/pets.csv");
    string cedula_consulta;
    cout<<"Introduzca la cedula de identidad del owner de la mascota a consultar: "; cin>>cedula_consulta;
    string linea;
    while (getline(input, linea)) {
        stringstream ss(linea);
        string owner_ced, nombre, pet_tipo, edad, owner;
        getline(ss, nombre, ','); getline(ss, pet_tipo, ','); getline(ss, edad, ',');
        getline(ss, owner, ','); getline(ss, owner_ced, ',');
        if (owner_ced == cedula_consulta){
            cout<<"Nombre de la mascota: "<<nombre<<endl;
            cout<<"Tipo de mascota: "<<pet_tipo<<endl;
            cout<<"Edad de la mascota: "<<edad<<endl;
            cout<<"Owner: "<<owner<<endl;
            cout<<"Cedula: "<<owner_ced<<endl;
        }
    }
    input.close();
}

void Pets::Update(){
    ifstream input("../model/pets/pets.csv");
    ofstream temp("../model/pets/temp.csv");
    int numero_fila=0;
    int fila_actualizar, columna_actualizar;
    string nuevoDato;
    string linea;
    int confirmar;
    cout<< "Ingrese la fila a actualizar: " ; cin>>fila_actualizar; fila_actualizar -=1;
    if(fila_actualizar == 1){
        cout<<"No se puede actualizar la fila 1 ya que es la cabecera del archivo..."<<endl;
        return;
    }
    cout<< "Ingrese el dato a actualizar:  1.Nombre | 2.Tipo de la mascota | 3.Edad | 4.Nombre del owner | 5.Cedula del owner"<<endl; 
    cin>>columna_actualizar; 
    cin.ignore(100,'\n');
    while(getline(input, linea)) {
        if (numero_fila==fila_actualizar){
            cout<< "Ingrese el nuevo dato: "; getline(cin,nuevoDato);
            stringstream ss(linea);
            string resto_de_fila;
            int columna_actual= 1;
            bool columna1= true;
            while(getline(ss,resto_de_fila,',')){
                if (!columna1){
                    temp<<",";
                }
                if (columna_actual == columna_actualizar){
                    temp<< nuevoDato;
                } else {
                    temp << resto_de_fila;
                }
                columna_actual++;
                columna1= false;
            }
            temp<< endl;
        } else{
            temp<< linea << endl;
        }
        numero_fila++;
    }
    input.close();
    temp.close();
    cout<<"Quieres confirmar los cambios? 1. Si | 2. No: "; cin>>confirmar;
    if(confirmar==1){
        remove("../model/pets/pets.csv");
        rename("../model/pets/temp.csv", "../model/pets/pets.csv");
    } else if(confirmar==2){
        remove("../model/onwer/temp.csv");
    }else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        remove("../model/pets/temp.csv");
    }
}

void Pets::Delete(){
    int confirmar;
    ifstream input("../model/pets/pets.csv");
    ofstream temp("../model/pets/temp.csv");
    int numero_fila=1;
    int filaABorrar;
    cout<< "Ingrese la fila a borrar: " ; cin>>filaABorrar;
    if(filaABorrar == 1){
        cout<<"No se puede borrar la fila 1 ya que es la cabecera del archivo..."<<endl;
        return;
    }
    string linea;
    while(getline(input, linea)) {
        if (numero_fila != filaABorrar) {
            temp << linea << endl;
        }
        numero_fila++;
    }
    input.close();
    temp.close();
    cout<<"Desea confirmar el cambio?  1. Si |  2. No"<<endl; cin>>confirmar;
    if (confirmar==1){
        remove("../model/pets/pets.csv");
        rename("../model/pets/temp.csv", "../model/pets/pets.csv");
    } else if (confirmar==2){
        remove("../model/pets/temp.csv");
    }
}