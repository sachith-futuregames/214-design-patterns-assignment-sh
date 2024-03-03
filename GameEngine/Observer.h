#pragma once


/// <summary>
/// INterface To build the Observer Pattern
/// </summary>
class Observer {
public:
    virtual void Broadcast() = 0;
};