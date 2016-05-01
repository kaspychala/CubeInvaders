#ifndef save_h
#define save_h
#include <fstream>
#include <string>

class Save {
protected:
	static const int default_speed = 2;
	static const int default_amount = 3;
public:
	void saveConfig(int, int);
	int opponentSpeed();
	int opponentAmount();
};
#endif