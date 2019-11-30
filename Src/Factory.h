#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <memory>
#include "ComponentHelper.h"

namespace Component{

template<typename T>
inline typename T::IFactory* getComponentFactory(const ClassID& clsid)
{
	return dynamic_cast<typename T::IFactory*>(CComponentHelper::getComponentFactory(T::IFactory::iid(), clsid.m_str));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline std::shared_ptr<T> getComponentInstance(const ClassID& clsid = ClassID::local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("getComponentInstance cf=%p\n",cf);
		return cf->instance();
	}

	return std::shared_ptr<T>();
}

template<typename T, typename A1>
inline std::shared_ptr<T> getComponentInstance(const A1& a1, const ClassID & clsid = ClassID :: local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("getComponentInstance cf=%p\n",cf);
		return cf->instance(a1);
	}

	return std::shared_ptr<T>();
}

template<typename T, typename A1, typename A2>
inline std::shared_ptr<T> getComponentInstance(const A1& a1, const A2& a2, const ClassID & clsid = ClassID :: local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("getComponentInstance cf=%p\n",cf);
		return cf->instance(a1,a2);
	}

	return std::shared_ptr<T>();
}

template<typename T, typename A1, typename A2, typename A3>
inline std::shared_ptr<T> getComponentInstance(const A1& a1, const A2& a2, const A3& a3, const ClassID & clsid = ClassID :: local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("getComponentInstance cf=%p\n",cf);
		return cf->instance(a1,a2,a3);
	}

	return std::shared_ptr<T>();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline std::shared_ptr<T> createComponentObject(const ClassID& clsid = ClassID::local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("createComponentObject cf=%p\n",cf);
		return cf->create();
	}

	return std::shared_ptr<T>();
}

template<typename T, typename A1>
inline std::shared_ptr<T> createComponentObject(const A1& a1, const ClassID& clsid = ClassID::local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("createComponentObject cf=%p\n",cf);
		return cf->create(a1);
	}

	return std::shared_ptr<T>();
}

template<typename T, typename A1, typename A2>
inline std::shared_ptr<T> createComponentObject(const A1& a1, const A2& a2,const ClassID& clsid = ClassID::local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("createComponentObject cf=%p\n",cf);
		return cf->create(a1,a2);
	}

	return std::shared_ptr<T>();
}

template<typename T, typename A1, typename A2, typename A3>
inline std::shared_ptr<T> createComponentObject(const A1& a1, const A2& a2, const A3& a3, const ClassID& clsid = ClassID::local)
{
	typename T::IFactory* cf = getComponentFactory<T>(clsid);
	if (cf != NULL)
	{
		printf("createComponentObject cf=%p\n",cf);
		return cf->create(a1,a2,a3);
	}

	return std::shared_ptr<T>();
}

}

#endif

