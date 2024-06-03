#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

using namespace std;

/**
 * @file Photo.h
 * @brief contient la déclaration et la définition de la classe Photo
 * @details Le classe Photo est une sous classe de la classe Multimedia
 * Elle possède des attributs pour la latitude et la longitude
 */

class Photo : public Multimedia {
private :
    double latitude =  0; //latitude est un réel initialisé
    double longitude = 0 ; //longitude est un réel initialisé

public :
    /**
     * @brief Constructeur par défaut pour la classe Photo
     */
    Photo();

    /**
     * @brief Constructeur pour la classe Photo
     * @param name est le nom de l'objet
     * @param fileName est le chemin du fichier
     * @param latitude est un réel pour la dimension de l'objet
     * @param longitude est un réel pour la dimension de l'objet
     */
    Photo(string name, string fileName, double latitude, double longitude) : Multimedia(name, fileName),latitude(latitude), longitude(longitude) {}

    /**
     * @brief printVariables affiche les variables de l'objet
     * @param flux de type ostream&
     */
    void printVariables(ostream & flux) const override {
       Multimedia::printVariables(flux);
       flux << "Latitude : " << latitude << "   ";
       flux << " Longitude : " << longitude <<"   " ;

    }

    /**
     * @brief play permet d'afficher l'image
     */
    void play() const override {
        string command = "imagej " + fileName + " &";
        cout << "Voila l'image : " << endl;
        system(command.c_str());

    }

    /**
     * @brief setLatitude
     * @param latitude_
     */
    void setLatitude(double latitude_){
        latitude = latitude_ ;

    }

    /**
     * @brief setLongitude
     * @param longitude_
     */
    void setLongitude(double longitude_){
        longitude = longitude_;
    }

    /**
     * @brief getLatitude
     * @return latitude
     */
    double getLatitude() const{
        return latitude;
    }

    /**
     * @brief getLongitude
     * @return longitude
     */
    double getLongitude() const{
        return longitude;
    }


};

using PhPtr = shared_ptr<Photo>; //smart pointers

#endif // PHOTO_H
