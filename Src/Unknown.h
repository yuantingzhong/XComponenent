#ifndef __UNKNOWN_H__
#define __UNKNOWN_H__

#include <string>

namespace Component {

class IFactoryUnknown
{
public:
	virtual ~IFactoryUnknown() {}

	virtual const char* clsid() = 0;

	bool registerFactory(const char* iid);

	bool unregisterFactory(const char* iid);
};

/// 组件实现类ID
struct ClassID
{
	explicit ClassID(const char* str):m_str(str){};
	const char* m_str;

	/// 本地组件的类ID
	static const ClassID local;
};

/// 取ClassID列表助手类，得到已经注册的接口ID的全部类ID
class ClassIDList
{
	ClassIDList(ClassIDList const&);
	ClassIDList& operator=(ClassIDList const&);

public:
	/// 构造函数
	/// \param iid 接口ID
	ClassIDList(const char* iid);

	/// 析构函数
	~ClassIDList();

	/// 取元素个数
	size_t count() const;

	/// 取第 index 个 ClassID 名称
	std::string operator[](int index) const;

private:
	struct ClassIDListInternal;
	ClassIDListInternal* m_internal;
};

}

#endif

