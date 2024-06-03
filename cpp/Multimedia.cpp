/**
 * @file Multimedia.cpp
 * @brief contient la définition de la classe Multimedia
 */

#include "Multimedia.h"


Multimedia::Multimedia()
{
}

/**
 * @brief définition de la méthode qui affiche les variables de l'objet
 * @param flux de type ostream&
 */
void Multimedia::printVariables(ostream &flux) const{
    flux << "name : " << name << "  ";
    flux << "file name : " << fileName << "  ";
}
