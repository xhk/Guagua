#include "../StdAfx.h"
#include "FAST.h"

namespace Guagua {
	namespace Utils {


#define MASK1(n,p)	((~((~(INT64)0)<<n))<<p)

#define MASK0(n,p)	(~MASK1(n,p))

static const UINT64  MDHQ_ENCODE_7  = MASK1((64-7),7);
static const UINT64  MDHQ_ENCODE_14  = MASK1((64-14),14);
static const UINT64  MDHQ_ENCODE_21  = MASK1((64-21),21);
static const UINT64  MDHQ_ENCODE_28  = MASK1((64-28),28);
static const UINT64  MDHQ_ENCODE_35  = MASK1((64-35),35);
static const UINT64  MDHQ_ENCODE_42  = MASK1((64-42),42);
static const UINT64  MDHQ_ENCODE_49  = MASK1((64-49),49);
static const UINT64  MDHQ_ENCODE_56  = MASK1((64-56),56);
static const UINT64  MDHQ_ENCODE_63  = MASK1((64-63),63);


static const UINT64  MDHQ_ENCODE_64_NO_FLAG  = MASK1(63,0);	



static const UINT64  MDHQ_ENCODE_6  = MASK1((64-6),6);
static const UINT64  MDHQ_ENCODE_13  = MASK1((64-13),13);
static const UINT64  MDHQ_ENCODE_20  = MASK1((64-20),20);
static const UINT64  MDHQ_ENCODE_27  = MASK1((64-27),27);
static const UINT64  MDHQ_ENCODE_34  = MASK1((64-34),34);
static const UINT64  MDHQ_ENCODE_41  = MASK1((64-41),41);
static const UINT64  MDHQ_ENCODE_48  = MASK1((64-48),48);
static const UINT64  MDHQ_ENCODE_55  = MASK1((64-55),55);
static const UINT64  MDHQ_ENCODE_62  = MASK1((64-62),62);


static const UINT8	 MDHQ_BYTE_L6		=  MASK1(6,0);
static const UINT8	 MDHQ_BYTE_L7		=  MASK1(7,0);


CFAST::CFAST(void)
{
}


CFAST::~CFAST(void)
{
}

UINT8  CFAST::CheckSum(BYTE* lpBuff,int nLength)
{
	long idx; 
	unsigned int cks; 
	for( idx = 0L, cks = 0; idx < nLength; cks += (unsigned int)lpBuff[ idx++ ] ); 
	return cks%256;
}

////////////////////////////编码部分////////////////////////////////////
//带符号数，计算需要字节数
static int CalcNeedByte_SIGNED(INT64 nValue)
{
	if(nValue < 0)
	{
		nValue = (~(nValue))+1;
	}

	if( (nValue & MDHQ_ENCODE_6) == 0 )
	{
		return 1;
	}else if( (nValue & MDHQ_ENCODE_13) == 0 )
	{
		return 2;
	}else if( (nValue & MDHQ_ENCODE_20) == 0 )
	{
		return 3;
	}else if( (nValue & MDHQ_ENCODE_27) == 0 )
	{
		return 4;
	}else if( (nValue & MDHQ_ENCODE_34) == 0 )
	{
		return 5;
	}else if( (nValue & MDHQ_ENCODE_41) == 0 )
	{
		return 6;
	}else if( (nValue & MDHQ_ENCODE_48) == 0 )
	{
		return 7;
	}else if( (nValue & MDHQ_ENCODE_55) == 0 )
	{
		return 8;
	}else if( (nValue & MDHQ_ENCODE_62) == 0 )
	{
		return 9;
	}else
	{
		return 10;
	}
}

//无符号数，计算需要字节数
static int CalcNeedByte_UNSIGNED(UINT64 nValue)
{

	if( (nValue & MDHQ_ENCODE_7) == 0 )
	{
		return 1;
	}else if( (nValue & MDHQ_ENCODE_14) == 0 )
	{
		return 2;
	}else if( (nValue & MDHQ_ENCODE_21) == 0 )
	{
		return 3;
	}else if( (nValue & MDHQ_ENCODE_28) == 0 )
	{
		return 4;
	}else if( (nValue & MDHQ_ENCODE_35) == 0 )
	{
		return 5;
	}else if( (nValue & MDHQ_ENCODE_42) == 0 )
	{
		return 6;
	}else if( (nValue & MDHQ_ENCODE_49) == 0 )
	{
		return 7;
	}else if( (nValue & MDHQ_ENCODE_56) == 0 )
	{
		return 8;
	}else if( (nValue & MDHQ_ENCODE_63) == 0 )
	{
		return 9;
	}else
	{
		return 10;
	}
}

int CFAST::Encode_UINT8(BYTE* pData,UINT8 nNum)
{
	return Encode_UINT64(pData,nNum);
}

int CFAST::Encode_UINT16(BYTE* pData,UINT16 nNum)
{
	return Encode_UINT64(pData,nNum);
}
int CFAST::Encode_UINT32(BYTE* pData,UINT32 nNum)
{
	return Encode_UINT64(pData,nNum);
}
int CFAST::Encode_UINT64(BYTE* pData,UINT64 nNum)
{
	int nBytes = CalcNeedByte_UNSIGNED(nNum);
	for(int i=nBytes-1;i>=0;--i)
	{
		//Big Endian.
		pData[i] = ( nNum & MDHQ_BYTE_L7 );
		if(i == nBytes -1 )
		{
			pData[i] |= 0x80;
		}
		nNum = (nNum>>7);
	}
	return nBytes;		
}


int CFAST::Encode_INT8(BYTE* pData,INT8 nNum)
{
	return Encode_INT64(pData,nNum);
}
int CFAST::Encode_INT16(BYTE* pData,INT16 nNum)
{
	return Encode_INT64(pData,nNum);
}
int CFAST::Encode_INT32(BYTE* pData,INT32 nNum)
{
	return Encode_INT64(pData,nNum);
}
int CFAST::Encode_INT64(BYTE* pData,INT64 nNum)
{
	bool bNegative = (nNum<0)?true:false;

	INT64 nNumTemp = (nNum & MDHQ_ENCODE_64_NO_FLAG);

	int nBytes = CalcNeedByte_SIGNED(nNum);

	for(int i=nBytes-1;i>=0;--i)
	{
		//Big Endian.
		pData[i] = ( nNumTemp & MDHQ_BYTE_L7 );
		if(i == nBytes -1 )
		{
			pData[i] |= 0x80;
		}
		nNumTemp = (nNumTemp>>7);
	}
		
	if(bNegative)
		pData[0] |= 0x40;

	return nBytes;		
}

int CFAST::Encode_ASCIIString(BYTE* pData,char* pASCIIString)
{
	int nPos = strlen(pASCIIString);
	if(nPos>0)
	{
		memcpy(pData,pASCIIString,nPos);
		pData[nPos-1] |= 0x80;
		return nPos;
	}else
	{
		pData[0] = 0x80;
		return 1;
	}
}
int CFAST::Encode_CNString(BYTE* pData,char* pCNString)
{
	int nPos = strlen(pCNString);
	int nByte = Encode_INT32(pData,nPos);		
	if(nPos>0)
	{
		memcpy(pData+nByte,pCNString,nPos);
	}
	return nPos + nByte;
}

//////////////////////////////////////////////////////////////////////////
//解码
int CFAST::Decode_INT64(BYTE* pData,INT64& nNum)
{
	int i=0;
	nNum = ( pData[0] & 0x40 )?-1:0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

int CFAST::Decode_INT32(BYTE* pData,INT32& nNum)
{
	int i=0;
	nNum = ( pData[0] & 0x40 )?-1:0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

int CFAST::Decode_INT16(BYTE* pData,INT16& nNum)
{
	int i=0;
	nNum = ( pData[0] & 0x40 )?-1:0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

int CFAST::Decode_INT8(BYTE* pData,INT8& nNum)
{
	int i=0;
	nNum = ( pData[0] & 0x40 )?-1:0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

	


int CFAST::Decode_UINT64(BYTE* pData,UINT64& nNum)
{
	int i=0;
	nNum = 0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

int CFAST::Decode_UINT32(BYTE* pData,UINT32& nNum)
{
	int i=0;
	nNum = 0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

int CFAST::Decode_UINT16(BYTE* pData,UINT16& nNum)
{
	int i=0;
	nNum = 0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

int CFAST::Decode_UINT8(BYTE* pData,UINT8& nNum)
{
	int i=0;
	nNum = 0;
	do
	{
		nNum = (nNum<<7) | ( pData[i] & 0x7F);
		++i;
		if(pData [i-1] & 0x80)
		{
			//高位为1,最后一字节，
			break;
		}
	}while(  true );
	return i;
}

///将数据从指定内存中解码
///@param pDate 欲解码的数据.
///@param pASCIIString  存放解后的数据
///@param nMaxLen  pASCIIString 所指能存放的最大长度
///@return 返回解码的字节数
int CFAST::Decode_ASCIIString(BYTE* pData,char* pASCIIString,int nMaxLen)
{
	if(pData[0]==0x80)
	{
		pASCIIString[0]=0;
		return 1;
	}

	*pASCIIString=0;
	int i=0;
	bool bContinue=true;

	for(;i<nMaxLen-1;)
	{
		if(pData[i]&0x80)
		{		
			pASCIIString[i] = pData[i]&0x7F;
			++i;
			bContinue =false;
			break;
		}else
		{
			pASCIIString[i] = pData[i];
			++i;
		}
	}
	pASCIIString[i]=0;

	for(;bContinue;)
	{
		++i;
		if(pData[i]&0x80)
		{
			break;
		}
	}
	return i;


}


///将数据从指定内存中解码
///@param pDate 欲解码的数据.
///@param pCNString  存放解后的数据
///@param nMaxLen  pCNString 所指能存放的最大长度
///@return 返回解码的字节数
int CFAST::Decode_CNString(BYTE* pData,char* pCNString,int nMaxLen)
{
	int nstrlen;
	int nlen = Decode_INT32(pData,nstrlen);
	if(nstrlen>0)
	{
		memcpy(pCNString,(char*)pData+nlen, nstrlen>nMaxLen-1?nMaxLen-1:nstrlen);
		pCNString[nstrlen>nMaxLen-1?nMaxLen-1:nstrlen] = 0;
	}
	else
	{
		pCNString[0] = 0;
	}
	return nlen+nstrlen;
}
	}
}