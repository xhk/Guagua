#include "StdAfx.h"
#include "Buffer.h"

namespace Guagua {
	namespace System {
		namespace Memory {
			Buffer::Buffer(void)
			{
				m_pData = nullptr;
				m_nSize = 0;
			}


			Buffer::~Buffer(void)
			{
				if (m_pData) {
					delete[]m_pData;
				}
			}

			char * Buffer::Get(int nSize)
			{
				if (m_default_buf_size >= nSize) {
					return m_data;
				}

				if (m_pData) {
					if (m_nSize >= nSize) {
						return m_pData;
					}
					delete[]m_pData;
				}

				m_pData = new char[nSize];
				m_nSize = nSize;
				return m_pData;
			}
		}
	}
}