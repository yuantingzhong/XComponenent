#pragma once

#include <memory>
#include "Unknown.h"

namespace MyPlayer{

class IPlayer
{
public:
	class IFactory : public Component::IFactoryUnknown 
	{
		public:
			static const char* iid() { return "Player"; }
			virtual ~IFactory() {}
			virtual std::shared_ptr<IPlayer> create(int channel = 0) = 0;
	};
	
	virtual ~IPlayer() {}
	
	virtual bool open() = 0;

	virtual bool play() = 0;

	virtual bool close() = 0;
	
};

typedef std::shared_ptr<IPlayer> PlayerSPtr;

}

