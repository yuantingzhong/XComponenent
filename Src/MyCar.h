#ifndef __MYCAR_H__
#define __MYCAR_H__

#include "Car.h"

namespace MyCar {

class CMyCar : public ICar
{
public:
	class CFactory : public ICar::IFactory
	{
		public:
			const char* clsid() { return "Local"; }
			CFactory();
			~CFactory();
			CarSPtr instance();
		private:
			static CarSPtr sCarSP;
	};

	CMyCar();

	~CMyCar();

	bool startEngine();

	bool stopEngine();

	bool drive();
private:
	
};


class CMyCar2 : public ICar
{
public:
	class CFactory2 : public ICar::IFactory
	{
		public:
			const char* clsid() { return "Foreign"; }
			CFactory2();
			~CFactory2();
			CarSPtr instance();
		private:
			static CarSPtr sCarSP;
	};

	CMyCar2();

	~CMyCar2();

	bool startEngine();

	bool stopEngine();

	bool drive();
private:
	
};


}

#endif

