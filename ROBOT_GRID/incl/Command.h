#ifndef COMMAND_H
#define COMMAND_H

/******************************************************************************************
Command: This is an interface class that defines the execute method. 
All other command classes inherit from this class and implement the execute method to perform their specific action.
*******************************************************************************************/

#include <string>

class Command
{
public:
    virtual void execute() = 0;
};

#endif // COMMAND_H