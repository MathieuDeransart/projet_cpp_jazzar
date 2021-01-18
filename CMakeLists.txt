cmake_minimum_required(VERSION 3.17)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet main.cpp
        Bibliotheque.cpp Bibliotheque.h
        Adherent.cpp Adherent.h
        Livre.cpp Livre.h
        Emprunt.cpp Emprunt.h
        Echange.cpp Echange.h
        Chaine.cpp Chaine.h
        Maille.cpp Maille.h Achat.cpp Achat.h Date.cpp Date.h MiseAuPilon.cpp MiseAuPilon.h Perte.cpp Perte.h Livres/Roman.h Livres/Bandedessinee.h Livres/Theatre.h Livres/Album.h Livres/Poesie.h Livres/Roman.cpp Livres/Bandedessinee.cpp Livres/Theatre.cpp Livres/Album.cpp Livres/Poesie.cpp)