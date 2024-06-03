#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <sstream>
#include <ostream>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;

/**
 * @file Data.h
 * @brief contient la déclaration de la classe Data
 * @details Le classe Data permet de fabriquer et manipuler tous les objets
 * de manière cohérente. Elle contient une table de tous les objets multimedia et
 * une table de tous les groupes.
 */

class Data
{
private:

    map<string, MulPtr> objects ; //table des objets multimedia
    map<string,GrPtr> groups; // table des groupes

public:

    Data();
    /**
     * @brief createPhoto permet de créer une photo
     * @param name
     * @param fileName
     * @param latitude
     * @param longitude
     * @return
     */
    PhPtr createPhoto(string name, string fileName, double latitude, double longitude);

    /**
     * @brief createVideo permet de créer une vidéo
     * @param name
     * @param fileName
     * @param duration
     * @return
     */
    VPtr createVideo(string name, string fileName, int duration);

    /**
     * @brief createFilm permet de créer un film
     * @param name
     * @param fileName
     * @param duration
     * @param number
     * @param chapters
     * @return
     */
    FPtr createFilm(string name, string fileName, int duration, int number, const int * chapters);

    /**
     * @brief createGroup permet de créer un groupe
     * @param name
     * @return
     */
    GrPtr createGroup(string name);

    /**
     * @brief searchMult de chercher un objet multimedia à partir de son nom
     * @param name
     * @return
     */
    MulPtr searchMult(string name) const;

    /**
     * @brief printMult permet d'afficher un objet multimedia à partir de son nom
     * @param name
     */
    void printMult(string name) const;

    /**
     * @brief searchGroups permet de chercher un groupe à partir de son nom
     * @param name
     * @return
     */
    GrPtr searchGroups(string name) const;

    /**
     * @brief printGroups permet d'affiche un groupe à partir de son nom
     * @param name
     */
    void printGroups(string name) const;

    /**
     * @brief play permet de jouer un objet multimedia
     * @param name
     */
    void play(string name) const;

    /**
     * @brief deleteObject permet de supprimer un objet multimedia
     * à partir de son nom
     * @param name
     */
    void deleteObject(string name);

    /**
     * @brief deleteGroup permet de supprimer un groupe à partir
     * de son nom
     * @param name
     */
    void deleteGroup(string name);

    /**
     * @brief processRequest permet de gérer les requête avec le serveur
     * @param cnx
     * @param request
     * @param response
     * @return
     */
    bool processRequest(TCPConnection& cnx, const string& request, string& response);

};

#endif // DATA_H
