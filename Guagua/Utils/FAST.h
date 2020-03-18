#pragma once

namespace Guagua {
	namespace Utils {



class CFAST
{
public:
	///��������.
	static UINT8  CheckSum(BYTE* lpBuff,int nLength);


	//--------------------------------------------------------------------------------------
	// ����

	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_UINT8(BYTE* pData,UINT8 nNum);


	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_INT8(BYTE* pData,INT8 nNum);


	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_UINT16(BYTE* pData,UINT16 nNum);


	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_INT16(BYTE* pData,INT16 nNum);


	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_UINT32(BYTE* pData,UINT32 nNum);


	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_INT32(BYTE* pData,INT32 nNum);


	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_UINT64(BYTE* pData,UINT64 nNum);


	///�����ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param nNum  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_INT64(BYTE* pData,INT64 nNum);



	///��ASCIIString���ݱ��뵽ָ���ڴ���
	///@param pDate ��ű�������ݵĻ���.
	///@param pASCIIString  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_ASCIIString(BYTE* pData,char* pASCIIString);


	///��CNString���ݱ��뵽ָ���ڴ���,CNString �ɰ�������֮��Ķ��ֽ��ַ�.
	///@param pDate ��ű�������ݵĻ���.
	///@param pCNString  �����������.
	///@return ���ر����ռ�õ��ֽ���
	static inline int Encode_CNString(BYTE* pData,char* pCNString);


	//--------------------------------------------------------------------------------------
	// ����

	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_UINT8(BYTE* pData,UINT8& nNum);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_INT8(BYTE* pData, INT8& nNum);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_UINT16(BYTE* pData,UINT16& nNum);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_INT16(BYTE* pData,INT16& nNum);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_UINT32(BYTE* pData,UINT32& nNum);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_INT32(BYTE* pData,INT32& nNum);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_UINT64(BYTE* pData,UINT64& nNum);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param nNum  ��Ž�������
	///@return ���ؽ�����ֽ���
	static inline int Decode_INT64(BYTE* pData,INT64& nNum);



	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param pASCIIString  ��Ž�������
	///@param nMaxLen  pASCIIString ��ָ�ܴ�ŵ���󳤶�
	///@return ���ؽ�����ֽ���
	static inline int Decode_ASCIIString(BYTE* pData,char* pASCIIString,int nMaxLen);


	///�����ݴ�ָ���ڴ��н���
	///@param pDate �����������.
	///@param pCNString  ��Ž�������
	///@param nMaxLen  pCNString ��ָ�ܴ�ŵ���󳤶�
	///@return ���ؽ�����ֽ���
	static inline int Decode_CNString(BYTE* pData,char* pCNString,int nMaxLen);

public:
	CFAST();
	~CFAST();
};
	}
}