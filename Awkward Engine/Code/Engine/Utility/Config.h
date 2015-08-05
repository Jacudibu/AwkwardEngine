#pragma once

#include <SDL.h>

#include <string>
#include <map>

class Config
{
public:
	// Loads the Settings in the config.ini file.
	void load();

	// Saves the Settings into the config.ini file.
	void save();

	// Generates a new config.ini file.
	void init();

	// Edit data inside the config.ini file.
	void set(std::string id, std::string value);

	// Returns the string associated with the key
	std::string query(std::string id);

	// Getters for important values
	inline int getScreenWidth() { return screenwidth; }
	inline int getScreenHeight() { return screenheight; }

private:
	std::map<std::string, const std::string> data;

	std::string path = "config.ini";

	int screenwidth;
	int screenheight;
};