#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include <iostream>
#include "Multimedia.h"

using namespace std;

/**
 * @file Group.h
 * @brief contient la déclaration et la définition de la classe Group
 * @details Le classe Group sert à contenir des groupes d'objet qui
 * dérivent de la classe de base
 */

class Group : public list<MulPtr>
{
private :
    string name ; //nom du group

public:
    /**
     * @brief Constructeur par défaut du group
     */
    Group() : name("Untitled"){}

    /**
     * @brief Constructeur de la classe group
     * @param name_
     */
    Group(string name_){
        name = name_;
    }

    /**
     * Destructeur de group
     */
    ~Group(){
        cout << "Le group " << name << "est mort --- " ;
    }

    /**
     * @brief getName
     * @return
     */
    string getName(){
        return name;
    }

    /**
     * @brief printGroup méthode d'affichage
     * @details méthode qui affiche tous les attributs de tous les objets du groupe
     * @param flux
     */
    void printGroup(ostream &flux){
        flux << "----- Printing group : " << name << " -----   " ;
        for (auto i = this->begin() ; i != this->end() ; i++ ){
            (*i) -> printVariables(flux);
        }
    }


};

using GrPtr = shared_ptr<Group>; //smart pointers

#endif // GROUP_H
