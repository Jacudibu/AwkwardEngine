#include "Config.h"
#include <fstream>

void Config::load()
{
	std::ifstream file(path);
	if (file.good())
	{
		std::string line;
		int posOfEquals;

		while (std::getline(file, line))
		{
			posOfEquals = line.find("=");
			data.insert(std::pair<std::string, std::string>
				(line.substr(0, posOfEquals),
				 line.substr(posOfEquals + 1)));
		}

		// Set values that are obvious enough to get direct access
		screenheight = atoi(data.find("screenheight")->second.c_str());
		screenwidth = atoi(data.find("screenwidth")->second.c_str());
	}
	else
	{
		init();
	}
}

void Config::save()
{
	SDL_RWops* file = SDL_RWFromFile(path.c_str(), "wb");
	std::string text;

	for (std::pair<std::string, std::string> data : data)
	{
		text = data.first + "=" + data.second;
		SDL_RWwrite(file, &text, sizeof(text) - 1, 1);
	}
}

void Config::init()
{
	SDL_RWops* file = SDL_RWFromFile(path.c_str(), "wb");

	SDL_RWwrite(file, &"screenwidth=640\n", sizeof("screenwidth=640\n") - 1, 1);
	SDL_RWwrite(file, &"screenheight=480\n", sizeof("screenheight=480\n") - 1, 1);
	SDL_RWwrite(file, &"version=0.0.0.0.0.0.0.0.1h\n", sizeof("version=0.0.0.0.0.0.0.0.1h\n") - 1, 1);

	SDL_RWclose(file);

	load();
}

void Config::set(std::string id, std::string value)
{
	data.erase(id);
	data.insert(std::pair<std::string, std::string>(id, value));
}

std::string Config::query(std::string id)
{
	if (data.find(id) != data.end())
		return data.find(id)->second;
	else
		return "NO DATA FOUND!";
}