#include <memory>
#include <string>
#include <map>
#include <vector>
#include "Unknown.h"
#include "ComponentHelper.h"

namespace Component {

const ClassID ClassID::local("Local");

typedef std::map<std::string, IFactoryUnknown*> FactoryMap;
typedef std::map<std::string, FactoryMap> SystemMap;

static SystemMap s_interfaces;

bool IFactoryUnknown::registerFactory(const char * iid)
{
	printf("registerFactory iid=%s,clsid=%s\n",iid,clsid());
	s_interfaces[iid][clsid()] = this;
	///////////////////////////////////////////////////////////////////////////////
	for(SystemMap::iterator outIt = s_interfaces.begin();outIt!=s_interfaces.end();outIt++) {
		printf("Factory iid:%s\n",(outIt->first).c_str());
		FactoryMap& fm = outIt->second;
		for(FactoryMap::iterator inIt = fm.begin(); inIt != fm.end(); inIt++) {
			printf("-->clsid:%s, addr:%p\n",(inIt->first).c_str(),inIt->second);
		}	
	}
	printf("\n");
	///////////////////////////////////////////////////////////////////////////////

	return true;
}

bool IFactoryUnknown::unregisterFactory(const char * iid)
{
	s_interfaces[iid][clsid()] = NULL;
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void get_class_ids(const char* iid, std::vector<std::string>& ids)
{
	ids.clear();
	ids.reserve(8);

	SystemMap::const_iterator sysit = s_interfaces.find(iid);
	if (sysit != s_interfaces.end())
	{
		FactoryMap const& fmap = sysit->second;
		ids.reserve(fmap.size());

		for (FactoryMap::const_iterator it = fmap.begin(); it != fmap.end(); ++it)
		{
			ids.push_back(it->first.c_str());
		}
	}
}

struct ClassIDList::ClassIDListInternal
{
	std::vector<std::string> ids;
};

/// 取ClassID列表助手类构造函数，得到已经注册的接口ID的全部类ID
/// \param iid 接口ID
ClassIDList::ClassIDList(const char* iid)
{
	m_internal = new ClassIDListInternal();
	get_class_ids(iid, m_internal->ids);
}

/// 析构函数
ClassIDList::~ClassIDList()
{
	delete m_internal;
}

/// 取元素个数
size_t ClassIDList::count() const
{
	return m_internal->ids.size();
}

/// 取第 index 个 ClassID 名称
std::string ClassIDList::operator[](int index) const
{
	if((size_t)index >= m_internal->ids.size()){
		return std::string();
	}
	
	return m_internal->ids[index];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IFactoryUnknown* CComponentHelper::getComponentFactory(const char* iid, const char* clsid)
{
	printf("getComponentFactory iid=%s,clsid=%s\n",iid,clsid);
	///////////////////////////////////////////////////////////////////////////////
	for(SystemMap::iterator outIt = s_interfaces.begin();outIt!=s_interfaces.end();outIt++) {
		printf("Factory iid:%s\n",(outIt->first).c_str());
		FactoryMap& fm = outIt->second;
		for(FactoryMap::iterator inIt = fm.begin(); inIt != fm.end(); inIt++) {
			printf("-->clsid:%s, addr:%p\n",(inIt->first).c_str(),inIt->second);
		}	
	}
	///////////////////////////////////////////////////////////////////////////////
	SystemMap::iterator it = s_interfaces.find(iid);
	if(it != s_interfaces.end()) {
		FactoryMap& factoryMap = it->second;
		FactoryMap::iterator iter = factoryMap.find(clsid);
		if(iter != factoryMap.end()) {
			return iter->second;
		}
	}

	printf("getComponentFactory Not found!\n");
	return NULL;
}

}

