#pragma once

namespace Guagua {
	namespace Utils {



class CFAST
{
public:
	///计算检验和.
	static UINT8  CheckSum(BYTE* lpBuff,int nLength);


	//--------------------------------------------------------------------------------------
	// 编码

	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_UINT8(BYTE* pData,UINT8 nNum);


	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_INT8(BYTE* pData,INT8 nNum);


	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_UINT16(BYTE* pData,UINT16 nNum);


	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_INT16(BYTE* pData,INT16 nNum);


	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_UINT32(BYTE* pData,UINT32 nNum);


	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_INT32(BYTE* pData,INT32 nNum);


	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_UINT64(BYTE* pData,UINT64 nNum);


	///将数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param nNum  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_INT64(BYTE* pData,INT64 nNum);



	///将ASCIIString数据编码到指定内存中
	///@param pDate 存放编码后数据的缓存.
	///@param pASCIIString  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_ASCIIString(BYTE* pData,char* pASCIIString);


	///将CNString数据编码到指定内存中,CNString 可包含中文之类的多字节字符.
	///@param pDate 存放编码后数据的缓存.
	///@param pCNString  欲编码的数据.
	///@return 返回编码后占用的字节数
	static  int Encode_CNString(BYTE* pData,char* pCNString);

	static int Encode_CNString(BYTE* pData, char* pCNString, int nSize);

	//--------------------------------------------------------------------------------------
	// 解码

	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_UINT8(BYTE* pData,UINT8& nNum);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_INT8(BYTE* pData, INT8& nNum);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_UINT16(BYTE* pData,UINT16& nNum);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_INT16(BYTE* pData,INT16& nNum);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_UINT32(BYTE* pData,UINT32& nNum);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_INT32(BYTE* pData,INT32& nNum);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_UINT64(BYTE* pData,UINT64& nNum);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param nNum  存放解后的数据
	///@return 返回解码的字节数
	static  int Decode_INT64(BYTE* pData,INT64& nNum);



	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param pASCIIString  存放解后的数据
	///@param nMaxLen  pASCIIString 所指能存放的最大长度
	///@return 返回解码的字节数
	static  int Decode_ASCIIString(BYTE* pData,char* pASCIIString,int nMaxLen);


	///将数据从指定内存中解码
	///@param pDate 欲解码的数据.
	///@param pCNString  存放解后的数据
	///@param nMaxLen  pCNString 所指能存放的最大长度
	///@return 返回解码的字节数
	static  int Decode_CNString(BYTE* pData,char* pCNString,int nMaxLen);

	static void SetCmpFlag(char *_nch_ccmp_flag_data__, int n);
	static int GetCmpFlag(char *__nch_dcmp_flag_data, int n);

	static int CmpCompress(int cmpNum, int cpsNum, char *flag, int nFlagPos, BYTE *pData);
	static int CmpCompress(const unsigned int cmpNum, const unsigned int cpsNum, char *flag, int nFlagPos, BYTE *pData);
	static int CmpCompress(__int64 cmpNum, __int64 cpsNum, char *flag, int nFlagPos, BYTE *pData);
	static int CmpDecompress(int cmpNum, int & cpsNum, char *flag, int nFlagPos, BYTE *pData);
	static int CmpDecompress(unsigned int cmpNum, unsigned int & cpsNum, char *flag, int nFlagPos, BYTE *pData);
	static int CmpDecompress(__int64 cmpNum, __int64 & cpsNum, char *flag, int nFlagPos, BYTE *pData);

public:
	CFAST();
	~CFAST();
};
	}
}