#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

StudentWorld* Actor::getStudentWorld()
{
	return myWorld;
}
 
void Iceman::doSomething() {

	/*MOVEMENT KEYS*/

	StudentWorld* sw = getStudentWorld();
	int key;
	if (sw->getKey(key) == true)
	{
		if (key == KEY_PRESS_UP) {
			if (getDirection() == up && getY() != 60)
				moveTo(getX(), getY() + 1);
			else
				setDirection(up);
		}
		else if (key == KEY_PRESS_DOWN) {
			if (getDirection() == down && getY() != 0)
				moveTo(getX(), getY() - 1);
			else
				setDirection(down);
		}
		else if (key == KEY_PRESS_LEFT) {
			if (getDirection() == left && getX() != 0)
				moveTo(getX() - 1, getY());
			else
				setDirection(left);
		}
		else if (key == KEY_PRESS_RIGHT) {
			if (getDirection() == right && getX() != 60)
				moveTo(getX() + 1, getY());
			else
				setDirection(right);
		}
		//}
		//	/* ACTION COMMANDS */

		//	/* SQUIRT */
		//	if (the key pressed is spacebar)
		//		Iceman getDirection
		//			if (facing left)
		//				if ( getX == 2 or less )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					break
		//				else ( getX == 3 or higher )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					Spawn Squirt Object at (getX - 3, getY)
		//					break
		//			if (facing right)
		//				if ( getX == 58 or higher )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					break
		//				else ( getX == 57 or less )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					Spawn Squirt Object at (getX + 3, getY)
		//					break
		//			if (facing up)
		//				if ( getY == 58 or higher )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					break
		//				else ( getY == 57 or less )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					Spawn Squirt Object at (getX, getY + 3)
		//					break
		//			if (facing down)
		//				if ( getY == 2 or less )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					break
		//				else ( getY == 3 or higher )
		//					SOUND_PLAYER_SQUIRT
		//					decAmmo
		//					Spawn Squirt Object at (getX, getY - 3)
		//					break
		//	
		//	/* SONAR */

		//	if (key pressed is 'Z' || 'z')
		//		decSonar
		//		All Object <= 12 units from Iceman setVisible 

		//	/* GOLD */
		//	if (key pressed is TAB)
		//		decGold
		//		Place Gold at (getX,getY)

	}

}

void Ice::doSomething() {
	StudentWorld * sw = getStudentWorld();
	if ((sw->getPlayerX() <= getX()) && (sw->getPlayerX() > getX() - 4) && (sw->getPlayerY() <= getY()) && (sw->getPlayerY() > getY() - 4))
	{
		//Play sound effect
		//SOUND_DIG
		sw->playSound(SOUND_DIG);
		setVisible(false);
		Died();
	}
}