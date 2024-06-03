/**
 * @file Film.cpp
 * @brief contient la définition de la classe Film
 */

#include "Film.h"


void Film::display(ostream &flux) const{
    flux << "Nombre : " << number << "  " ;
    for (int i=0 ; i<number ; i++){
        flux << "Duree chapitre numero " << i+1 << ": " << chapters[i] << "   ";
    }
}

//on renvoie une copie du tableau afin de protéger les données
const int * Film::getChapters() const {
    return copy(chapters,number);
}

//on ne modifie pas directement le tableau
void Film::setChapters( const int* chapters_ , int number_){
    number = number_;
    chapters = copy(chapters_,number_);
}

int * Film::copy(const int *table, int size) const{
    int * newTable = new int[size];
    for (int i=0; i<number;i++){
        newTable[i]= table[i];
    }
    return newTable;
}
