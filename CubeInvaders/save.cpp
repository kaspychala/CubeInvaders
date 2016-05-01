#include "save.h"

void Save::saveConfig(int speed, int amount) {
	std::fstream file;
	file.open("config.cfg", std::ios::out); {
		file << speed;
		file << std::endl;
		file << amount;
	}
	file.close();
}

int Save::opponentSpeed() {
	std::fstream file;
	std::string line;
	file.open("config.cfg", std::ios::in);
	if (file.good() == true) {
		getline(file, line);
		return std::stoi(line);
	}
	else {
		return default_speed;
	}
	file.close();
}

int Save::opponentAmount() {
	std::fstream file;
	std::string line;
	file.open("config.cfg", std::ios::in);
	if (file.good() == true) {
		getline(file, line);
		getline(file, line);
		return std::stoi(line);
	}
	else {
		return default_amount;
	}
	file.close();
}