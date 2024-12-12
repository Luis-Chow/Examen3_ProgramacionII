#include "../controller/ownerController.cpp"
#include "../controller/petsController.cpp"

int main(){
    int opcion1, opcion2;
    Owner o;
    Pets p;
    cout<<"Que archivo desea leer? \n1. Owner | 2. Pets "<<endl; cin>>opcion1;
    switch(opcion1){
        case 1:
            cout<<"Que desea hacer? \n1. Crear | 2. Leer | 3. Actualizar | 4. Borrar"<<endl; cin>>opcion2;
            switch(opcion2){
                case 1:
                    o.Create();
                    break;
                case 2:
                    o.Read();
                    break;
                case 3:
                    o.Update();
                    break;
                case 4:
                    o.Delete();
                    break;
                default:
                    cout<<"Opcion no valida..."<<endl;
                    break;
            }
            break;

        case 2:
            cout<<"Que desea hacer? \n1. Crear | 2. Leer | 3. Actualizar | 4. Borrar"<<endl; cin>>opcion2;
            switch(opcion2){
                case 1:
                    p.Create();
                    break;
                case 2:
                    p.Read();
                    break;
                case 3:
                    p.Update();
                    break;
                case 4:
                    p.Delete();
                    break;
                default:
                    cout<<"Opcion no valida..."<<endl;
                    break;
            }
            break;

        default:
            cout<<"Opcion no valida..."<<endl;
            break;
        }
    return 0;
}