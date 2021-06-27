#include <iostream>
#include <iomanip>
#include "function.h"

using namespace std;

Animal:: Animal(Zoo *zoo, string name){
    species = name;
    belong = zoo;
    belong->born(species);
}

Dog::Dog(Zoo *zoo):Animal(zoo,"Dog"){

}
Dog::~Dog(){

}
Cat::Cat(Zoo *zoo):Animal(zoo,"Cat"){

}
Cat::~Cat(){}

Caog::Caog(Zoo *zoo):Dog(zoo),Cat(zoo),Animal(zoo,"Caog"){

}         // TODO
void Caog::barking(){
    cout << "woof!woof!meow!\n";
}
void Caog::carton(){
    cout << "it looks so happy!\n";
}
void Caog::throwBall(){
    cout <<  "it looks happy!\n";
}   
Caog::~Caog(){

}  