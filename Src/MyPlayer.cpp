#include "MyPlayer.h"

namespace MyPlayer 
{

CMyPlayer::CMyPlayer(int channel):mChannel(channel)
{
	printf("CMyPlayer[%d] ctor\n",mChannel);
}

CMyPlayer::~CMyPlayer()
{
	printf("CMyPlayer[%d] dtor\n",mChannel);
}

bool CMyPlayer::open()
{
	printf("CMyPlayer[%d] open\n",mChannel);
}

bool CMyPlayer::play()
{
	printf("CMyPlayer[%d] play\n",mChannel);
}

bool CMyPlayer::close()
{
	printf("CMyPlayer[%d] play\n",mChannel);
}


CMyPlayer::CFactory::CFactory()
{
	registerFactory(iid());
}

CMyPlayer::CFactory::~CFactory()
{
	unregisterFactory(iid());	
}

PlayerSPtr CMyPlayer::CFactory::create(int channel)
{
	return std::shared_ptr<CMyPlayer>(new CMyPlayer(channel));
}

}

extern "C" void InitComponentPlayerLibrary() {
	static MyPlayer::CMyPlayer::CFactory sMyPlayerFactory;
}
