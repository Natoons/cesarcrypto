// Cesar.cpp : Ce fichier contient la fonction 'main'. L'ex?cution du programme commence et se termine ? cet endroit.
//

#include <iostream>
#include "cesar.h"

int main()
{
	cesar crypto;
	// crypto.InitMessageFromString("Salutation");
	crypto.InitMessageFromFile("salut.txt");
	//crypto.SaveMessage("sauvegarde.txt");
	crypto.CrypteMessage(2);
	crypto.DecrypteMessage(2);

}

// Ex?cuter le programme?: Ctrl+F5 ou menu D?boguer?> Ex?cuter sans d?bogage
// D?boguer le programme?: F5 ou menu D?boguer?> D?marrer le d?bogage

// Astuces pour bien d?marrer?: 
//   1. Utilisez la fen?tre Explorateur de solutions pour ajouter des fichiers et les g?rer.
//   2. Utilisez la fen?tre Team Explorer pour vous connecter au contr?le de code source.
//   3. Utilisez la fen?tre Sortie pour voir la sortie de la g?n?ration et d'autres messages.
//   4. Utilisez la fen?tre Liste d'erreurs pour voir les erreurs.
//   5. Acc?dez ? Projet?> Ajouter un nouvel ?l?ment pour cr?er des fichiers de code, ou ? Projet?> Ajouter un ?l?ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc?dez ? Fichier?> Ouvrir?> Projet et s?lectionnez le fichier .sln.
