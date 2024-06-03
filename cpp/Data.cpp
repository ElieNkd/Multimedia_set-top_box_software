/**
 * @file Data.cpp
 * @brief contient la définition de la classe Data
 * @details la classe data permet de fabriquer et manipuler les données de
 * manière cohérente. Elle contient une table de tous les objets multimedia et une
 * table de tous les groupes.
 */

#include "Data.h"

/**
 * @brief Data::Data constructeur par défaut de le class Data
 */
Data::Data()
{

}

PhPtr Data::createPhoto(string name, string fileName, double latitude, double longitude){

    PhPtr photo = PhPtr(new Photo(name,fileName,latitude,longitude));
    objects[name]=photo; //on ajoute la photo à la table des objets multimedia
    return photo;

}


VPtr Data::createVideo(string name, string fileName, int duration){

    VPtr video = VPtr(new Video(name, fileName,duration));
    objects[name]=video; //on ajoute la video à la table des objets multimedia
    return video;

}

FPtr Data::createFilm(string name, string fileName, int duration, int number, const int * chapters){

    FPtr film = FPtr(new Film(name, fileName,duration, number, chapters));
    objects[name]=film; //on ajoute le film à la table des objets multimedia
    return film;

}

GrPtr Data::createGroup(string name){

    GrPtr group =GrPtr(new Group(name)); //on créé un nouveau groupe avec new
    groups[name]=group; //on ajoute le group à la table des groupes
    return group;

}

MulPtr Data::searchMult(string name) const{
    auto object = objects.find(name); //index de l'objet dans la table
    if (object == objects.end()){ //on arrive à la fin = on a rien trouvé
        cout << "error";
        return nullptr;
    } else {
        return object -> second ;
    }
}

void Data::printMult(string name) const{
    auto object = objects.find(name);
    if (object == objects.end()){ //l'objet n'est pas dans la table
        cout << "error";
    } else {
        return object -> second -> printVariables(cout); //on affiche les variables
    }
}

GrPtr Data::searchGroups(string name) const{
    auto group = groups.find(name);
    if (group == groups.end()){
        cout << "error";
        return nullptr;
    } else {
        return group -> second ;
    }
}

void Data::printGroups(string name) const{
    auto group = groups.find(name);
    if (group == groups.end()){
        cout << "error";
    } else {
        group -> second -> printGroup(cout);
    }
}

void Data::play(string name) const{
    auto object = objects.find(name);
    if (object == objects.end()){
        cout << "error";
    } else {
        object -> second -> play();
    }

}

void Data::deleteObject(string name){
    auto object = objects.find(name);
    if (object == objects.end()){
        cout << "error"; //l'objet n'existe pas
    } else {
        objects.erase(object);} //on supprime l'objet
}

void Data::deleteGroup(string name){
    auto group = groups.find(name);
    if (group == groups.end()){
        cout << "error";
    } else {
        groups.erase(group); //on supprime la groupe
    }
}

bool Data::processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cerr << "\nRequest: '" << request << "'" << endl;

    stringstream stream(request);
    // 1) pour decouper la requête:

    string function ;
    string name ;

    stream >> function ;
    stream >> name ;

    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);
    stringstream stream_rep ;

    //TCPLock lock(cnx);

    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client


    if(function == "gsearch"){ //requete : chercher unn groupe
        GrPtr result = searchGroups(name);

        if (result == nullptr){
            response = "Le groupe n'a pas été trouvé\n";
        } else {
            result -> printGroup(stream_rep);
            response = stream_rep.str() + "\n";
    }


    } else if (function == "msearch"){ //requete : chercher un objet multimedia
        auto result = searchMult(name);
        if (result == nullptr){
            response = "Le fichier n'a pas été trouvé\n";
        } else {
            result -> printVariables(stream_rep);
            response = stream_rep.str() + "\n";
    }

    } else if (function == "play"){ //requete : jouer un objet multimedia
        auto result = searchMult(name);
        if (result == nullptr){
            response = "Le fichier n'a pas été trouvé\n";
        } else {
            result -> play();
            response = "Le fichier s'affiche !\n";
        }

    } else if (function == "quit"){ //pour clore la connexion avec le client
        response = "Au revoir !\n";
        return false;


    }
    else {

        response = "Je n'ai pas compris votre demande...\n"; //requête inconnue
    }

    cerr << "reponse: " << response << endl;

    return true;
  }

