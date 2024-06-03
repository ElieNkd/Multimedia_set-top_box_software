#ifndef FILM_H
#define FILM_H

#include "Video.h"
using namespace std;

/**
 * @file Film.h
 * @brief contient la déclaration de la classe Film
 * @details Le classe Film est une sous-classe de Video.
 * Un film possède un certain nombre de chapitre d'une certaine durée.
 */

class Film : public Video
{

private :

    int number = 0 ; //le nombre de chapitres du film
    //le pointeur du tableau qui contient les durées est intialisé
    int * chapters = new int[number];

public:
    /**
     * @brief Constructeur par défaut du film
     */
    Film(){}

    /**
     * @brief Constructeur de la classe Film
     * @param name nom du film
     * @param fileName chemin du fichier
     * @param duration durée totale du film
     * @param number_ nombre de chapitres
     * @param chapters_ tableau des durées de chapitre
     */

    Film(string name, string fileName,int duration, int number_, const int * chapters_) : Video(name,fileName,duration){
        number = number_;
        this->setChapters(chapters_,number_);
    }

    /**
    * @brief Destructeur de Film
    */
    ~Film(){
        delete[] chapters;
    }
    /**
     * @brief display affiche les variables du film
     * @param flux de type ostream&
     */
    void display(ostream &flux) const;

    /**
     * @brief getChapters renvoie une copie du tableau des durées
     * @return le tableau des durées (copie)
     */
    const int * getChapters() const;

    /**
     * @brief getNumber
     * @return le nombre de chapitre
     */
    int * getNumber() const;

    /**
     * @brief setChapters modifieur de la durée des chapitres
     * @param chapters_
     * @param number_
     */
    void setChapters( const int* chapters_ , int number_);

    /**
     * @brief setNumber
     * @param number_
     */
    void setNumber( int number_);

    /**
     * @brief copy
     * @param table
     * @param size
     * @return
     */
    int * copy(const int *table, const int size) const;


};

using FPtr = shared_ptr<Film>;

#endif // FILM_H
