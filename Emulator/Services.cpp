#include "Services.h"
#include <queue>
using namespace std;

/** Add new command to the PriorityQueue
 *
 * adding command will be according to its prority
 * 0 for normal push and 1 to be added to the top of the queue
 */
void Services::Add(Command command)
{
	command.Priority ? pushOnTheFrontOfQueue(command) : PriorityQueue.push(command);

}

/**
   * @brief Execute all the procees in the priority queue which inclue the 
   * 3 type of command read, write and delete  
   */
void Services::Excute()
{
	Command CurrentCommand;
	Response CurrentResponse;
	while (isExcute)
	{
		while (!PriorityQueue.empty())
		{

			CurrentCommand = PriorityQueue.front();
			CurrentResponse.command = CurrentCommand;
			CurrentResponse.command.Type = "Response for " + CurrentCommand.Type;
			CurrentResponse.status = "Succeeded";
			uint8_t key= CurrentCommand.StoredData.Address;
			if (CurrentCommand.Type == "read")
			{
				cout << "the data ";
				if (Memory.find(key) == Memory.end())
					cout << "at address "<<std::to_string(CurrentCommand.StoredData.Address) << " not found\n";


				// If key found then iterator to that key is returned
				else
				{
					cout << "Found at address " << CurrentCommand.StoredData.Address;
					cout << " ,data=" << Memory[CurrentCommand.StoredData.Address] << "\n";
				}

			}
			else if (CurrentCommand.Type == "write")
			{
				//insirt
				Memory[CurrentCommand.StoredData.Address] = CurrentCommand.StoredData.Value;
			}
			else if (CurrentCommand.Type == "delete")
			{
				Memory.erase(CurrentCommand.StoredData.Address);
			}
			CurrentResponse.print();
			PriorityQueue.pop();

		}
		isExcute = false;

	}
}
/**
 * @brief remove command from PriorityQueue
 * Removing command will be according to its position
 *  if it was in the top of queue will be removed directly
 *  else a sawp process will happen to remove it from the queue
 * @param id of the desired object
 */
void Services::Remove(int Id)
{
	if (isExist(Id))
	{
		PriorityQueue.front().Id == Id ? PriorityQueue.pop() : deleteFromAnyPlace(Id);
	}
	else cout << " Id is not exist";
}

/**
 * @brief set the executetion process to aborted.
 * 
 */
void Services::Abort()
{
	isExcute = false;
	cout << "The Process aborted \n";
}
/**
 * @brief push command to the front of the queue insted 
 *of tail according to priority of the command
 * @param  the desired object to be pushed
 */

void Services::pushOnTheFrontOfQueue(Command Currentcommand)
{
	queue<Command> replacmentQueue;
	while (!PriorityQueue.empty())
	{
		replacmentQueue.push(PriorityQueue.front());
		PriorityQueue.pop();
	}
	PriorityQueue.push(Currentcommand);
	swap(replacmentQueue);

}

/**
 * @brief to check if the the command is exist according to its Id
 * @param id of the desired object
 */

bool Services::isExist(int Id)
{
	queue<Command> TemporaryQueue = PriorityQueue; //copy the original queue to the temporary queue
	Command currentCommand;
	
	
	while (!TemporaryQueue.empty())
	{
		currentCommand = TemporaryQueue.front();
		if (Id == currentCommand.Id)return true;
		TemporaryQueue.pop();
	}
	cout << "The id is not exist \n";
	return false;
}
/**
 * @brief to make swapping for the priority queue that contain all the command 
 * and with another temporery queue in order to keep the FIFO principle
 * @param the swaped queue 
 */
void Services::swap(queue<Command> SwapedQueue)
{
	while (!SwapedQueue.empty())
	{
		PriorityQueue.push(SwapedQueue.front());
		SwapedQueue.pop();
	}
}

/**
 * @brief to delete any command whenever it is exist in the queue
 * and make sure to keep the FIFO principle
 * @param id of the desired object to be deleted
 */
void Services::deleteFromAnyPlace(int Id)
{
	queue<Command> replacmentQueue;
	while (!PriorityQueue.empty())
	{
		if (PriorityQueue.front().Id == Id)
		{
			PriorityQueue.pop();
		}
		else
		{
			replacmentQueue.push(PriorityQueue.front());
			PriorityQueue.pop();
		}

	}
	swap(replacmentQueue);
	cout << "Deleted successfully \n";

}
