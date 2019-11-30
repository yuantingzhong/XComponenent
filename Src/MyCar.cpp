#include <cstdio>
#include "MyCar.h"

namespace MyCar{

CMyCar::CMyCar()
{
	printf("CMyCar::ctor\n");
}

CMyCar::~CMyCar()
{
	printf("CMyCar::dtor\n");
}

bool CMyCar::startEngine()
{
	printf("CMyCar::startEngine\n");
	return true;
}

bool CMyCar::stopEngine()
{
	printf("CMyCar::stopEngine\n");
	return true;
}

bool CMyCar::drive()
{
	printf("CMyCar::drive\n");
	return true;
}

//////////////////////////////////////////////////////

CarSPtr CMyCar::CFactory::sCarSP;

CMyCar::CFactory::CFactory()
{
	printf("CFactroy::ctor[%p]\n",this);
	registerFactory(iid());
}

CMyCar::CFactory::~CFactory()
{
	printf("CFactroy::dtor[%p]\n",this);
	unregisterFactory(iid());
}

CarSPtr CMyCar::CFactory::instance()
{
	if(!sCarSP) {
		sCarSP = std::shared_ptr<CMyCar>(new CMyCar);
	}

	return sCarSP;	
}

////////////////////////////////////////////////////////////////////////////////////////////////////

CMyCar2::CMyCar2()
{
	printf("CMyCar2::ctor\n");
}

CMyCar2::~CMyCar2()
{
	printf("CMyCar2::dtor\n");
}

bool CMyCar2::startEngine()
{
	printf("CMyCar2::startEngine\n");
	return true;
}

bool CMyCar2::stopEngine()
{
	printf("CMyCar2::stopEngine\n");
	return true;
}

bool CMyCar2::drive()
{
	printf("CMyCar2::drive\n");
	return true;
}

//////////////////////////////////////////////////////

CarSPtr CMyCar2::CFactory2::sCarSP;

CMyCar2::CFactory2::CFactory2()
{
	printf("CFactroy2::ctor[%p]\n",this);
	registerFactory(iid());
}

CMyCar2::CFactory2::~CFactory2()
{
	printf("CFactroy2::dtor[%p]\n",this);
	unregisterFactory(iid());
}

CarSPtr CMyCar2::CFactory2::instance()
{
	if(!sCarSP) {
		sCarSP = std::shared_ptr<CMyCar2>(new CMyCar2);
	}

	return sCarSP;	
}

}

extern "C" void InitComponentCarLibrary() {
	static MyCar::CMyCar::CFactory myCarFactory;
}

extern "C" void InitComponentCar2Library() {
	static MyCar::CMyCar2::CFactory2 myCarFactory2;
}


