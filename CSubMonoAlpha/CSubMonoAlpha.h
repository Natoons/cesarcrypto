#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class CSubMonoAlpha
{
private:
	string Message;
	string MessageCrypte;
public:
	void InitMessageFromString(string);
	int InitMessageFromFile(string);
	int SaveMessage(string);
	void CrypteMessage(string);
	void AfficheMessage(string);
	void DecrypteMessage(string);
	int VerifMaj();
	CSubMonoAlpha();
	~CSubMonoAlpha();

};