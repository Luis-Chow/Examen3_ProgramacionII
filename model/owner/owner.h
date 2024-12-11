#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Owner{
    private:
    string cedula;
    string nombre;
    string email;
    string telefono;
    string pet;
    string pet_tipo;

    public:
    void Create();
    void Read();
    void Update();
    void Delete();
};