#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

//déclaration des objets de la bibliothèque standard
#include <string>
#include <iostream>
#include <memory>
using namespace std;

/**
 * @file Multimedia.h
 * @brief contient la déclaration de la classe Multimedia
 * @details Le classe Multimedia est la classe mère pour les objets multimedia
 */

class Multimedia
{
protected:
    string name = ""; //nom de l'objet multimedia
    string fileName = ""; //nom du fichier (chemin complet)
public:

    /**
     * @brief Constructeur par défaut de la classe Multimedia
     */
    Multimedia();

    /**
     * @brief Constructeur de le la classe Multimedia
     * @overload
     * @param name est un string associé au nom de l'objet
     * @param fileName est un string associé au chemin de fichier
     */
    Multimedia(string name, string fileName) : name(name),fileName(fileName) {}

    /**
     * @brief Destructeur de la classe Multimedia
     */
    virtual ~Multimedia(){}

    /**
     * @brief accesseur de l'attribut name
     * @return string ayant la valeur de l'attribut name
     */
    string getName() const{
        return name;
    }

    /**
     * @brief accesseur de l'attribut filename
     * @return string ayant la valeur de l'attribut fileName
     */
    string getFileName() const{
        return  fileName;
    }

    /**
     * @brief modifieur de l'attribut name
     * @param name_ string ayant la valeur du nom
     */
    void setName(string name_) {
        name = name_;
    }

    /**
     * @brief modifieur de l'attribut fileName
     * @param fileName_ string ayant la valeur du chemin du fichier
     */
    void setFileName(string fileName_) {
        fileName = fileName_;
    }

    /**
     * @brief déclaration de la méthode d'affichage
     * @details la méthode d'affichage permet d'afficher les valeurs des variables de l'objet
     * @param flux du type ostream&
     */
    virtual void printVariables(ostream & flux) const;

    /**
     * @brief déclaration de la méthode qui joue un objet multimedia
     * @details la méthode est virtuelle
     */
    virtual void play() const = 0 ;



};

using MulPtr = shared_ptr<Multimedia>; //smart pointers

#endif // MULTIMEDIA_H
