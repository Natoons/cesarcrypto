// Cesar.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "cesar.h"

void cesar::InitMessageFromString(string MessageSource)
{
    message = MessageSource; // string = string
    int TailleMessage = message.size(); // TailleMessage = le nombre de caractére
    if (TailleMessage > 0) // La taille du message doit être superieur à 0
    {
        cout << "la taille de message est de " << TailleMessage << endl; 
        cout << "la valeur du dernier caractère est " << MessageSource[MessageSource.size() -1] << endl; // on prend le dernier caractére 
    }
    else
    {
        cout << "la chaine ne contient rien" << endl;
    }
}

int cesar::InitMessageFromFile(string MessageFroms)
{
    int erreur = 0;
    ifstream fichier(MessageFroms);
    if (fichier)
    {
        message = "";
        string temp;
        while (!fichier.eof())
        {
            fichier >> temp;
            message = message + temp;
        }
    }
    else
    {
        erreur = -1; 
    }
    return erreur; 
}

int cesar::SaveMessage(string NomFichierSource)
{
    int erreur = 0; 
    ofstream fichier(NomFichierSource, ios::in | ios::trunc);
    if (fichier)
    {
        fichier << message << endl;
    }
    else { erreur = -1;  }

    return erreur;
}

void cesar::CrypteMessage(unsigned short cle)
{
    messageCrypte.resize(message.size()); // message crypte doit avoir la même taille
    for (int x = 0; x != message.size(); x++)
    {
        messageCrypte.at(x) = message[x] = (message[x] + cle);
        if (message[x] > 'Z')
        {
            messageCrypte.at(x) = message[x] = (message[x] -26);
        }
    }
    AfficheMessage(messageCrypte);
}

void cesar::AfficheMessage(string Texte)
{
        cout << "Le message est " << Texte << endl;
}

void cesar::DecrypteMessage(unsigned short cle)
{
    messageCrypte.resize(message.size()); // message crypte doit avoir la même taille
    for (int x = 0; x != message.size(); x++) // 
    {
        messageCrypte.at(x) = message[x] = (message[x] + cle);
        if (message[x] > 'A')
        {
            messageCrypte.at(x) = message[x] = (message[x] + 26);
        }
    }
    AfficheMessage(messageCrypte);
}
