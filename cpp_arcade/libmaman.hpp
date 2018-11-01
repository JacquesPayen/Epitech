//
// EPITECH PROJECT, 2018
// libmaman.hh
// File description:
// mfedkz
//

class libGraphic
{
public:
//constructeur vide dans les libs enfants, la fonction createW() s'occupe de setup
	
	//destrcuteur sans arguments, il fait rien
	virtual ~libGraphic();

	//refresh l'affichage (pas de clear, seulement un update)
	virtual	void	refreshW() = 0;

	//clear tout ce qu'il y a sur la window
	virtual	void	clearW() = 0;

	//recupere la touche pressé par l'utilisateur en mofiant l'int recu
	virtual	void	getKey(int *key) = 0;

	//dessine un carrée de la couleur "cell" en position x, y
	virtual	void	setCell(const int &x, const int &y, const int &cell) = 0;

	//ecrit le texte en argument en position x, y
	virtual	void	setText(const int &x, const int &y, const std::string &text) = 0;
	
}
