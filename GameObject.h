#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
class GameObject: public Board {
	virtual ~GameObject(); // destructor
	virtual void influencePlayer(Player &p); // virtual function
};
#endif // GAMEOBJECT_H
