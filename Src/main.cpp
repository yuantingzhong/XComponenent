#include <cstdio>
#include "Factory.h"
#include "Car.h"
#include "Player.h"

extern "C" void InitComponentCarLibrary();
extern "C" void InitComponentCar2Library();
extern "C" void InitComponentPlayerLibrary();


void test()
{
		MyCar::CarSPtr sp = Component::getComponentInstance<MyCar::ICar>();
		if(sp) {
			sp->startEngine();
			sp->drive();
			sp->stopEngine();
		} else {
			printf("getComponentInstance of ICar failed!\n");
		}

		printf("\n");

		MyCar::CarSPtr sp2 = Component::getComponentInstance<MyCar::ICar>(Component::ClassID("Foreign"));
		if(sp2) {
			sp2->startEngine();
			sp2->drive();
			sp2->stopEngine();
		} else {
			printf("getComponentInstance of ICar failed!\n");
		}

		printf("\n");
}

void test2()
{
	MyPlayer::PlayerSPtr sp = Component::createComponentObject<MyPlayer::IPlayer>(9);
	if(sp) {
		sp->open();
		sp->play();
		sp->close();
	} else {
		printf("createComponentObject of IPlayer failed!\n");
	}
}

void  test3()
{
	Component::ClassIDList clsListOfCar(MyCar::ICar::IFactory::iid());
	printf("iid: %s\n",MyCar::ICar::IFactory::iid());
	for(size_t idx = 0; idx < clsListOfCar.count(); idx++) {
		printf("-->clsid: %s\n",clsListOfCar[idx].c_str());
	}
	printf("\n");

	Component::ClassIDList clsListOfPlayer(MyPlayer::IPlayer::IFactory::iid());
	printf("iid: %s\n",MyPlayer::IPlayer::IFactory::iid());
	for(size_t idx = 0; idx < clsListOfPlayer.count(); idx++) {
		printf("-->clsid: %s\n",clsListOfPlayer[idx].c_str());
	}
	printf("\n");
}

int main()
{	
	InitComponentCarLibrary();
	InitComponentCar2Library();
	test();

	printf("\n");

	InitComponentPlayerLibrary();
	test2();

	printf("\n");
	test3();

	return 0;
}

/*
ytz@ubuntu:~/ComponetResearch/ComponentDemo$ sh build_run.sh 
/home/ytz/ComponetResearch/ComponentDemo
-- Configuring done
-- Generating done
-- Build files have been written to: /home/ytz/ComponetResearch/ComponentDemo/build
[100%] Built target CompoentDemo.out
[100%] Built target CompoentDemo.out
Install the project...
-- Install configuration: ""
-- Up-to-date: /home/ytz/ComponetResearch/ComponentDemo/output/bin/CompoentDemo.out
CFactroy::ctor[0x60e230]
registerFactory iid=Car,clsid=Local
Factory iid:Car
-->clsid:Local, addr:0x60e230

CFactroy2::ctor[0x60e238]
registerFactory iid=Car,clsid=Foreign
Factory iid:Car
-->clsid:Foreign, addr:0x60e238
-->clsid:Local, addr:0x60e230

getComponentFactory iid=Car,clsid=Local
Factory iid:Car
-->clsid:Foreign, addr:0x60e238
-->clsid:Local, addr:0x60e230
getComponentInstance cf=0x60e230
CMyCar::ctor
CMyCar::startEngine
CMyCar::drive
CMyCar::stopEngine

getComponentFactory iid=Car,clsid=Foreign
Factory iid:Car
-->clsid:Foreign, addr:0x60e238
-->clsid:Local, addr:0x60e230
getComponentInstance cf=0x60e238
CMyCar2::ctor
CMyCar2::startEngine
CMyCar2::drive
CMyCar2::stopEngine


registerFactory iid=Player,clsid=Local
Factory iid:Car
-->clsid:Foreign, addr:0x60e238
-->clsid:Local, addr:0x60e230
Factory iid:Player
-->clsid:Local, addr:0x60e248

getComponentFactory iid=Player,clsid=Local
Factory iid:Car
-->clsid:Foreign, addr:0x60e238
-->clsid:Local, addr:0x60e230
Factory iid:Player
-->clsid:Local, addr:0x60e248
createComponentObject cf=0x60e248
CMyPlayer[9] ctor
CMyPlayer[9] open
CMyPlayer[9] play
CMyPlayer[9] play
CMyPlayer[9] dtor

iid: Car
-->clsid: Foreign
-->clsid: Local

iid: Player
-->clsid: Local

CFactroy2::dtor[0x60e238]
CFactroy::dtor[0x60e230]
CMyCar2::dtor
CMyCar::dtor
ytz@ubuntu:~/ComponetResearch/ComponentDemo$ 
*/

