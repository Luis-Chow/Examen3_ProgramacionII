#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;    

class Pets{
    private:
    string nombre;
    string pet_tipo;
    string edad;
    string owner;
    string owner_cedula;

    public:
    void Create();
    void Read();
    void Update();
    void Delete();
};