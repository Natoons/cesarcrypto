// Cesar.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include "CSubMonoAlpha.h"

using namespace std;

CSubMonoAlpha::CSubMonoAlpha()
{
}

CSubMonoAlpha::~CSubMonoAlpha()
{
}

void CSubMonoAlpha::AfficheMessage(string texte)
{
	cout << "Le message est " << texte << endl;
}

void CSubMonoAlpha::CrypteMessage(string cl�)
{
	MessageCrypte.resize(Message.size());
	for (int x = 0; x != Message.size(); x++)
	{
		MessageCrypte[x] = cl� [Message[x] - 'A'];
	}
	AfficheMessage(MessageCrypte);
}

void CSubMonoAlpha::DecrypteMessage(string cl�)
{
	Message.resize(MessageCrypte.size());
	for (int t = 0; t < MessageCrypte.length(); t++)
	{
		for (int j = 0; j < cl�.length(); j++)
		{
			if (MessageCrypte[t] == cl�[j])
			{
				int tASCII = j + 'A';
				Message[t] = tASCII;
			}
		}
	}
	AfficheMessage(Message);
}

int CSubMonoAlpha::InitMessageFromFile(string NomFichierSource)
{
	int erreur = 0;
	ifstream fichier(NomFichierSource);

	if (fichier)
	{
		Message = "";
		string temp;
		while (!fichier.eof())
		{
			if (fichier >> temp)
			{
				Message = Message + temp;
			}
		}
		erreur = VerifMaj();
	}
	else { erreur = -1; }
	return erreur;
}

void CSubMonoAlpha::InitMessageFromString(string MessageSource)
{
	Message = MessageSource;
	int TailleMessage = Message.size();
	if (TailleMessage > 0)
	{
		cout << "La taille du message est de " << TailleMessage << endl;
		cout << MessageSource[MessageSource.size() - 1] << endl;
	}
	else { cout << "La chaine ne contient rien" << endl; }
}

int CSubMonoAlpha::SaveMessage(string NomFichierSauvegarde)
{
	int erreur = 0;
	ofstream fichier(NomFichierSauvegarde, ios::in | ios::trunc);
	if (fichier)
	{
		fichier << MessageCrypte << endl;
	}
	else { erreur = -1; }
	return erreur;
}

int CSubMonoAlpha::VerifMaj()
{
	int erreur = 0;
	int i = 0;
	while (i < Message.size() && isupper(Message.at(i))) //tant que pas fin de chaine et caractere est une majuscule je vais au caractere suivant
	{
		i++;
	}
	if (i < Message.size())
	{
		erreur = -1;
	}
	return erreur;
}
