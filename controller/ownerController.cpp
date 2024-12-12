#include "../model/owner/owner.h"

void Owner::Create(){
    int confirmar;
    string linea;
    ifstream input("../model/owner/owner.csv");
    ofstream Vout("../model/owner/temp.csv");  cin.ignore(100,'\n');
    cout<<"Nombre y apellido: "; getline(cin,nombre);
    cout<<"Cedula: "; cin>>cedula;
    cout<<"Email: "; cin>>email; cin.ignore(100,'\n');
    cout<<"Telefono: "; getline(cin,telefono);
    cout<<"Nombre de la mascota: "; cin>> pet;
    cout<<"Tipo de mascota "; cin>>pet_tipo;
    while(getline(input, linea)){
        Vout<<linea<<endl;
    }
    Vout<<nombre<<","<<cedula<<","<<email<<","<<telefono<<","<<pet<<","<<pet_tipo<<endl;   
    cout<<"Desea confirmar los cambios? 1. Si | 2. No"<<endl; cin>>confirmar;
    Vout.close();
    input.close();
    if(confirmar==1){
        remove("../model/owner/owner.csv");
        rename("../model/owner/temp.csv", "../model/owner/owner.csv");
    } else if (confirmar==2){
        remove("../model/owner/temp.csv");
    } else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        remove("../model/owner/temp.csv");
    }
}

void Owner::Read(){
    ifstream input("../model/owner/owner.csv");
    string cedula_consulta;
    cout<<"Introduzca la cedula de identidad del owner a consultar: "; cin>>cedula_consulta;
    string linea;
    while (getline(input, linea)) {
        stringstream ss(linea);
        string cedula, nombre, email, telefono, pet, pet_tipo;
        getline(ss, nombre, ','); getline(ss, cedula, ','); getline(ss, email, ',');
        getline(ss, telefono, ','); getline(ss, pet, ','); getline(ss, pet_tipo, ',');
        if (cedula == cedula_consulta){
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Cedula del cliente: "<<cedula<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Numero de Telefono: "<<telefono<<endl;
            cout<<"Nombre de la mascota: "<<pet<<endl;
            cout<<"Tipo de mascota: "<<pet_tipo<<endl;
        }
    }
    input.close();
}

void Owner::Update(){
    ifstream input("../model/owner/owner.csv");
    ofstream temp("../model/owner/temp.csv");
    int numero_fila=0;
    int fila_actualizar, columna_actualizar;
    string nuevoDato;
    string linea;
    int confirmar;
    cout<< "Ingrese la fila a actualizar: " ; cin>>fila_actualizar; fila_actualizar -=1;
    if(fila_actualizar == 1){
        cout<<"No se puede borrar la fila 1 ya que es la cabecera del archivo..."<<endl;
        return;
    }
    cout<< "Ingrese el dato a actualizar:  1.Nombre del owner | 2.Cedula | 3.Email | 4.Telefono | 5.Nombre de la mascota | 6.Tipo de mascota"<<endl; 
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
        remove("../model/owner/owner.csv");
        rename("../model/owner/temp.csv", "../model/owner/owner.csv");
    } else if(confirmar==2){
        remove("model/onwer/temp.csv");
    }else {
        cout<<"Error en la confirmacion, cancelando cambios...";
        remove("../model/owner/temp.csv");
    }
}

void Owner::Delete(){
    int confirmar;
    ifstream input("../model/owner/owner.csv");
    ofstream temp("../model/owner/temp.csv");
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
        remove("../model/owner/owner.csv");
        rename("../model/owner/temp.csv", "../model/owner/owner.csv");
    } else if (confirmar==2){
        remove("../model/owner/temp.csv");
    }
}