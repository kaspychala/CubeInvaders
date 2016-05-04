#ifndef save_h
#define save_h
#include <fstream>
#include <string>

class Save {
protected:
	static const int default_speed = 2;
	static const int default_amount = 3;
	const std::string default_mode = "single";

public:
	void saveConfig(int, int, std::string);
	int opponentSpeed();
	int opponentAmount();
	std::string gameMode();
};
#endif