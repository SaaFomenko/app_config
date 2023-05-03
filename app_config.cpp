#include <fstream>
#include "app_config.h"
#include "lib/app_exception/app_exception.h"


static const std::string err_file_msg = "Не удалось прочитать файл, проерьте его наличие и праава доступа: ";

std::string app_config::get_connect(const std::string& path_str)
{
	std::string connect_str = "";

	std::ifstream fin(path_str);

	if(!fin.is_open())
	{
		throw AppException(err_file_msg + path_str);
	}

	std::string word = "";

	while (!fin.eof())
	{
		fin >> word;
		if (!fin.eof())
		{
			word += " ";
		}

		connect_str += word;
	}

	return connect_str;
}
