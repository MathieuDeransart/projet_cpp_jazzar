cmake_minimum_required(VERSION 3.17)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet main.cpp
        Bibliotheque.cpp Bibliotheque.h
        Adherent.cpp Adherent.h
        Livre.cpp Livre.h
        Emprunt.cpp Emprunt.h
        Echange.cpp Echange.h
        Chaine.cpp Chaine.h)