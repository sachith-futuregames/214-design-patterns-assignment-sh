#pragma once

#include <vector>
#include "Observer.h"
class Observer;

/// <summary>
/// Class that implements the Singleton Pattern
/// </summary>
class DelegateSystem
{

public:

    // deleting copy constructor
    DelegateSystem(const DelegateSystem& obj)
        = delete;

    static DelegateSystem* getInstance()
    {
        //We only create an instance if there is no other instance
        if (_instance == nullptr)
        {
            // We can access private members 
            // within the class.
            _instance = new DelegateSystem();

            // returning the only instance of the Delegate System
            return _instance;
        }
        else
        {
            // if there is an instance then return it. 
            return _instance;
        }
    }

    /// <summary>
    /// Function that broadcasts the Observer Functions
    /// </summary>
    void ProcessBroadcast();

    /// <summary>
    /// Function used to Register the Observer
    /// </summary>
    /// <param name="_NewObserver"> POinter to the Observer</param>
    void RegisterObserver(Observer* _NewObserver);
private:

    static DelegateSystem* _instance;

    // Default constructor
    DelegateSystem()
    {
    }

    std::vector<Observer*> _Observers;

};



