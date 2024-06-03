#include <iostream>
#include <sstream>
#include <memory>
#include <list>
#include <stdio.h>
#include <unistd.h>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "tcpserver.h"
#include "Data.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

/**
 * @brief Programme principal qui permet de lancer le serveur
 * @details Pour observer les différentes étapes, veuillez décommenter
 * certaines parties du code
 * @file main.cpp
 * @param argc
 * @param argv
 * @return int
 */

int main(int argc, const char* argv[])
{


    shared_ptr<TCPServer> server = shared_ptr<TCPServer>(new TCPServer());

    shared_ptr<Data> data = shared_ptr<Data>(new Data());

    VPtr video = data -> createVideo("supernova","supernova.mp4",120);

    PhPtr photo = data -> createPhoto("universe", "universe.jpg", 100, 100);

    GrPtr group = data -> createGroup("group");

    group->push_back(photo);

    group->push_back(video);

    GrPtr group2 = data->searchGroups("group");

    data -> printGroups("group");

    server -> setCallback(*data,&Data::processRequest);

    cout << "Serveur sur le port " << PORT << "----";

    int status = server->run(PORT);

    if(status <0 ){
        cout << "erreur" << "----";
    }

    std::cout << "Hello brave new world" << std::endl;

    //partie 3
    //attention la classe est abstraite
    //Multimedia *multimedia = new Multimedia("bds", "bds.png");
    //multimedia -> printVariables(cout);

    //partie 4
    //Photo *photo = new Photo("bds", "bds.png", 100, 100);
    //photo->printVariables(cout);
    //photo->play();
    //Video *video = new Video("telecom,"telecom.mp4,120);
    //video -> printVariables(cout);
    //video -> play();

    //partie 5
    //Multimedia * m[2];
    //m[0] = new Photo("bds","bds.png",100,100);
    //m[1] = new Video("telecom","telecom.mp4",120);
    //for (int i = 0 ; i<2 ; i++){
        //m[i]->printVariables();
        //m[i]->play();
    //}

    //partie 6
    //int * chapters = new int[3];
    //chapters[0]=2;
    //chapters[1]=3;
    //chapters[2]=4;
    //Film * film = new Film("telecom","telecom.mp4",120, 3, chapters);
    //film -> display(cout);
    //int * set = new int[5];
    //for (int i=0 ; i<5 ; i++){
        //set[i] = i*i ;
    //}
    //film -> setChapters(set,5);
    //film -> display(cout);

    //partie 7
    //int * obj = film -> getChapters();
    //obj[0] = 3;
    //film -> display(cout);
    //delete[] chapters;
    //delete[] set;
    //delete[] obj;

    //partie 8

    //GrPtr group = GrPtr(new Group("Salut"));
    //group->printGroup(cout);
    //PhPtr photo = PhPtr(new Photo("bds", "bds.png", 100, 100));
    //VPtr video =  VPtr(new Video("telecom","telecom.mp4",120));
    //group->push_back(photo);
    //group->push_back(video);
    //group->printGroup(cout);
    //delete group;


    //partie 10




    return 0;
}
