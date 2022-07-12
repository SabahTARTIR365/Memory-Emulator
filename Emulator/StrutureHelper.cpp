#pragma once
#include <cstdint>
#include <string>
#include <iostream>
using namespace std;
//#pragma warning

struct Data {
	//uint8_t Length;
	uint8_t Value = 0x00;// [Length] ;// 
	uint8_t Address = 0x00;

};
struct Command {
	int Id;
	string Type = "write";
	bool Priority = true;
	Data StoredData;

	string IsQuickCommand()const {
		return Priority ? "Quick command " : "Simple command";
	}
	void print()const {
		
		cout << "Command #" << Id << "( " + Type + ") " << IsQuickCommand() << "data =" << std::to_string(StoredData.Value) << "at address" << std::to_string(StoredData.Address) << "\n";
	}

	Command(int id, string type, bool priority) {
		Id = id;
		Type = type;
		Priority = priority;
	}
	Command() {}
};


struct Response
{
	Command command;
	string status;

	void print()const {
	
		cout << "Response (" + status + ") for Command #" << command.Id << ",(" + command.Type + ") " << command.IsQuickCommand() << "\n";
	}

};