#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <vector>
#include <memory>
#include <sstream>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
const size_t MAX_X = 64;
const size_t MAX_Y = 60;
class StudentWorld : public GameWorld
{

public:
	StudentWorld(std::string assetDir) : GameWorld(assetDir) {}

	virtual int init()
	{
		playerHP = 100;
		playerAmmo = 5;
		barrelsLeft = CalculateBarrels();
		playerGold = 0;
		playerSonar = 1;
		playerScore = 0;

		IceM = std::shared_ptr<Actor>(new Iceman(30, 60, this));

		for (size_t i = 0; i < MAX_Y; i++)
		{
			for (size_t j = 0; j < MAX_X; j++)
			{
				if (j >= 30 && j <= 33 && i >= 4) {

				}
				else {
					std::shared_ptr<Actor> sa(new Ice(j, i, this));
					VActors.push_back(sa);
				}

			}
		}

		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move()
	{
		updateDisplayText();
		setPlayerPos();
		IceM->doSomething();
		for (size_t i = 0; i < VActors.size(); i++)
		{
			if (VActors[i]->getAlive())
			{
				VActors[i]->doSomething();
				if (playerdied())
				{
					//SOUNDEFFECT
					decLives();
					return GWSTATUS_PLAYER_DIED;
				}

				if (completelevel())
				{
					//COMPLETED LEVEL SOUNDEFFECT
					return GWSTATUS_FINISHED_LEVEL;
				}

			}
		}

		return GWSTATUS_CONTINUE_GAME;

		if (playerdied())
		{
			//SOUNDEFFECT
			decLives();
			return GWSTATUS_PLAYER_DIED;
		}

		if (completelevel())
		{
			//COMPLETED LEVEL SOUNDEFFECT
			return GWSTATUS_FINISHED_LEVEL;
		}

		return GWSTATUS_CONTINUE_GAME;
	}

	virtual void cleanUp()
	{
		for (size_t i = 0; i < VActors.size(); i++)
		{
			VActors[i].reset();
			IceM.reset();
		}
	}


	virtual ~StudentWorld()
	{
		for (size_t i = 0; i < VActors.size(); i++)
		{
			VActors[i].reset();
			IceM.reset();
		}
	};
private:
	std::vector<std::shared_ptr<Actor>> VActors;
	std::shared_ptr<Actor> IceM;
	int playerHP;
	int playerAmmo;
	int playerGold;
	int barrelsLeft;
	int playerScore;
	int playerSonar;
	int playerX;
	int playerY;

	//
	void updateDisplayText()
	{
		std::ostringstream o;
		o << "Lvl: " << getLevel() << " Lives: " << getLives() << " Hlth: " << getHP() << "% Wtr: " << getAmmo()
			<< " Gld: " << getGold() << " Oil Left: " << getBarrelsLeft() << " Sonar: " << getSonar() << " Scr: " << getScore();
		setGameStatText(o.str());
	}
	void removeDeadGameObjects()
	{
		for (size_t i = 0; i < VActors.size(); i++)
		{
			if (!VActors[i]->getAlive())
			{
				VActors[i].reset();
			}
		}
	}
	bool playerdied()
	{
		if (playerHP <= 0)
			return true;
		return false;
	}

	bool completelevel()
	{
		if (barrelsLeft == 0)
		{
			return true;
		}
		return false;
	}


	void playerAttacked()
	{
		playerHP -= 20;   ///temp
	}

	void CollectedBarrel()
	{
		barrelsLeft--;
	}

	int CalculateBarrels()
	{
		return 2 + getLevel();
	}
	int CalculateGold()
	{
		if (getLevel() > 5)
			return 0;
		return 5 - getLevel();
	}
	int CalculateBoulders()
	{
		return getLevel() + 2;
	}


public:
	void setPlayerPos() {
		playerX = IceM->getX();
		playerY = IceM->getY();
	}


	void decAmmo()
	{
		playerAmmo--;
	}
	void decGold()
	{
		playerGold--;
	}
	void decSonar()
	{
		playerSonar--;
	}


	void incAmmo()
	{
		playerAmmo++;
	}
	void incGold()
	{
		playerGold++;
	}
	void incSonar()
	{
		playerSonar++;
	}



	int getAmmo()
	{
		return playerAmmo;
	}
	int getGold()
	{
		return playerGold;
	}
	int getHP()
	{
		return playerHP;
	}
	int getBarrelsLeft()
	{
		return barrelsLeft;
	}
	int getSonar()
	{
		return playerSonar;
	}

	int getPlayerX()
	{
		return playerX;
	}

	int getPlayerY()
	{
		return playerY;
	}
};

#endif // STUDENTWORLD_H_