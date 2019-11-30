#pragma once

#include "Player.h"

namespace MyPlayer
{

class CMyPlayer : public IPlayer
{
public:
	class CFactory : public IFactory
	{
		public:
			const char* clsid() { return "Local"; }
			CFactory();
			~CFactory();
			PlayerSPtr create(int channel = 0);
	};

	CMyPlayer(int channel);

	~CMyPlayer();

	bool open();

	bool play();

	bool close();

private:
	int mChannel;
};

}

