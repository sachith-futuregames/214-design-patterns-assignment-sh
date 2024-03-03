#include "DelegateSystem.h"
#include "Observer.h"

DelegateSystem* DelegateSystem::_instance = nullptr;

void DelegateSystem::ProcessBroadcast()
{
	for (auto Obs : _Observers)
		Obs->Broadcast();
}

void DelegateSystem::RegisterObserver(Observer* _NewObserver)
{
	_Observers.push_back(_NewObserver);
}


