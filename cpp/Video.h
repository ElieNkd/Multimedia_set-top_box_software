#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

using namespace std;

/**
 * @file Video.h
 * @brief contient la déclaration et la définition de la classe Video
 * @details Le classe Video est est une sous classe de la classe
 * multimedia. Elle possède un attribut pour la durée.
 */

class Video : public Multimedia {

private :
    int duration = 0 ; //attribut pour la durée initialisé

public :
    /**
     * @brief Constructeur par défaut de la classe Video
     */
    Video();

    /**
     * @brief Constructeur de la classe Vidéo
     * @param name est un string pour le nom du fichier
     * @param fileName est un string pour le chemin du fichier
     * @param duration est un int pour la durée de la vidéo
     */
    Video(string name, string fileName, int duration) : Multimedia(name, fileName), duration(duration){}

    /**
     * @brief printVariables méthode héritée pour afficher les variables
     * @param flux de type ostream&
     */
    void printVariables(ostream & flux) const override {
        Multimedia::printVariables(flux);
        flux << "Duree : " << duration << " ";

    }
    /**
     * @brief play permet de jouer la video
     */
    void play() const override {
        string command = "mpv " + fileName + " &";
        system(command.c_str());

    }

    /**
     * @brief setDuration
     * @param duration_
     */
    void setDuration(int duration_){
        duration = duration_;
    }

    /**
     * @brief getDuration
     * @return
     */
    int getDuration() const{
        return duration ;
    }


};

using VPtr = shared_ptr<Video>; //smart pointers

#endif // VIDEO_H
