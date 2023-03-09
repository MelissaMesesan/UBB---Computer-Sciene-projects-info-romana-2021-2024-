#pragma once
#include "Repository.h"
class FileRepository : public Repository
{
private:

	string filepath;
	void readFromFile();
	void writeToFile();

public:
	FileRepository(string fname) : Repository{}, filepath{ fname }{
		readFromFile();
	}
	//FileRepository(const FileRepository&);

	int add(const Telefon& m) override;

};