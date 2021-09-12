#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class cesar
{
private :
	string message; 
	string messageCrypte;
public : 
	void InitMessageFromString(string MessageSource);
	int InitMessageFromFile(string MessageFroms);
	int SaveMessage(string NomFichierSource);
	void CrypteMessage(unsigned short cle);
	void AfficheMessage(string Texte);
	void DecrypteMessage(unsigned short cle);
	//int SaveMessage(string NomduFicherSauvegarde);
};

