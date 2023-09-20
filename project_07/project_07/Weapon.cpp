#include "Weapon.h"
class Weapon {
protected:
	int power = 0;
	int gunNum = 0;
	int swordNum = 0;
public:
	virtual void attack() = 0;
	virtual int getpower() = 0;
	int getgunNum()
	{
		return gunNum;
	}
	int getswordNum()
	{
		return swordNum;
	}
};