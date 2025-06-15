#include "Logger.h"

Logger::Logger() {
	count = 1;
}

Logger* Logger::getInstance() {
	if (count == 0) {
		pointer = new Logger();
		return pointer;
	}
	return pointer;
}

void Logger::initialize(const std::string& filename) {
	obj.open(filename, ios::out);
}

void Logger::cleanup() {
	obj.close();
}

void Logger::write(const string& level, const string& error_message) {
	if (obj.is_open()) {
		time_t timestamp;
		time(&timestamp);
		obj << "[" << level << "]" << error_message /*<< "  " << ctime(&timestamp)*/ << endl;
	}
	else {
		cout << "File not opened.\n";
	}
}

void Logger::writeInfo(const std::string& error_message) {
	write("INFO", error_message);
}

void Logger::writeError(const string& error_message) {
	write("ERROR", error_message);
}

Logger::~Logger() { 
	//     delete[] pointer;
}

int Logger::count = 0;
Logger* Logger::pointer = nullptr;

