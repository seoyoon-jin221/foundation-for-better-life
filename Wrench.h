//
// Created by John Paul Dillard on 9/16/19.
//

#ifndef FOUNDATION_FOR_BETTER_LIFE_WRENCH_H
#define FOUNDATION_FOR_BETTER_LIFE_WRENCH_H

#include "Player.h"
#include "GameObject.h"

class Wrench : public GameObject{
private:
	const int ADD_TO_HEALTH = 1;
public:
	virtual void influencePlayer(Player&);
	virtual ~Wrench() {};
};


#endif //FOUNDATION_FOR_BETTER_LIFE_WRENCH_H
