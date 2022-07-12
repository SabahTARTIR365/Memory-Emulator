#pragma once
#include <queue>
#include "StrutureHelper.cpp"
#include <unordered_map>

/**
 * @brief Services class used for command 4 main process add, execute, abort and delete.
 */


class Services
{

public:
    std::queue<Command> PriorityQueue;
    unordered_map<uint8_t, uint8_t> Memory;
    bool isExcute = true;
    void Add(Command command);
    void Excute();
    void Remove(int Id);
    void Abort();
    void pushOnTheFrontOfQueue(Command Currentcommand);
    bool isExist(int Id);
    void swap(queue<Command> SwapedQueue);
    void deleteFromAnyPlace(int Id);
};

