#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Logger {
private:
	Logger();

	static Logger* pointer;
	static int count;
	fstream obj;
public:
	static Logger* getInstance();
	void initialize(const std::string& filename);
	void cleanup();
	void write(const string& level, const string& error_message);
	void writeInfo(const std::string& error_message);
	void writeError(const string& error_message);
	~Logger();
};



