#pragma once
#include <cstdint>
#include <string>
#include <iostream>
using namespace std;
//#pragma warning
	/**
	* @brief the structure that contain the data 
	*/
struct Data {
	
	uint8_t Value = 0x00;
	uint8_t Address = 0x00;

};
/**
* @brief structure for the command that include Id, type and priority.
*/
struct Command {
	int Id;
	string Type = "write";
	bool Priority = true;
	Data StoredData;

	/**
     * @brief to check if the desied command has quick priority or simple.
     */
	string IsQuickCommand()const {
		return Priority ? "Quick command " : "Simple command";
	}

	/**
    * @brief to print the stucture container
    */
	void print()const {
		
		cout << "Command #" << Id << "( " + Type + ") " << IsQuickCommand() << "data =" << std::to_string(StoredData.Value) << "at address" << std::to_string(StoredData.Address) << "\n";
	}

	/**
  * Create a new command object.
  * @brief Constructor.
  * @param Id The id of the command .
  * @param type The type of the command.
  * @param priority the value to set who execute first.
  * @see Command()
  */
	Command(int id, string type, bool priority) {
		Id = id;
		Type = type;
		Priority = priority;
	}


	/**
	 * @brief Construct a new command object
	 * @see Command()
	 * @see Command(int id, string type, bool priority) 
	 */
	Command() {}
};

/**
* @brief structure for the response of each command 
* as each response has a command (composition).
*/
struct Response
{
	Command command;
	string status;

	void print()const {
	
		cout << "Response (" + status + ") for Command #" << command.Id << ",(" + command.Type + ") " << command.IsQuickCommand() << "\n";
	}

};
/**
* @brief structure for the Read command
* that inherete the shared parameters from the command structure
*/
struct Read:Command
{

};
/**
* @brief structure for the Write command
* that inherete the shared parameters from the command structure in
* addition to have the data.
*/
struct Write:Command
{

};
/**
* @brief structure for the Delete command
* that inherete the shared parameters from the command structure
*/
struct Delete :Command
{

};