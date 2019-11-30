#ifndef __COMPONENT_HELPER_H__
#define __COMPONENT_HELPER_H__

#include "Unknown.h"

namespace Component {

class CComponentHelper
{
public:
	static IFactoryUnknown* getComponentFactory(const char* iid, const char* clsid);
};

}

#endif
