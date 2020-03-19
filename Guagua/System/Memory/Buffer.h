#pragma once

namespace Guagua {
	namespace System{
	namespace Memory{
class  Buffer
{
public:
	Buffer(void);
	~Buffer(void);

	char *Get(int nSize);
private:
	static const int m_default_buf_size = 8*1024;
	char m_data[m_default_buf_size];
	char *m_pData;
	int m_nSize ;
};

}
}
}