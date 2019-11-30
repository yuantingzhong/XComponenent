#ifndef __CAR_H__
#define __CAR_H__

#include <memory>
#include "Unknown.h"

namespace MyCar {

class ICar 
{
public:
	class IFactory : public Component::IFactoryUnknown 
	{
		public:
			static const char* iid() { return "Car"; }
			virtual ~IFactory() {}
			virtual std::shared_ptr<ICar> instance() = 0;
	};

	virtual ~ICar() {}

	virtual bool startEngine() = 0;

	virtual bool stopEngine() = 0;

	virtual bool drive() = 0;

};

typedef std::shared_ptr<ICar> CarSPtr;

}

#endif

