// Strings.cpp
#define   TCLib
#define   UNICODE
#define   _UNICODE
#include  <windows.h>
#ifdef    TCLib
   #include  "string.h"
   #include  "stdio.h"
   #include  "tchar.h"
   #include  "memory.h"
   #define   NEW new
   extern "C" int _fltused=1;
#else
   #include  <string>
   #include  <cstdio>
   #include  <tchar.h>
   #include  <new>
   #define   NEW new(std::nothrow)
#endif
#include  "Strings.h"


String operator+(TCHAR* lhs, String& rhs)    //global function
{
 String sr=lhs;
 sr=sr+rhs;

 return sr;
}


#ifdef FLOATING_POINT_CONVERSIONS            // Constructor creates String from floating point number, e.g., String s(3.14159);
   String Str(double dblNum)
   {
    return dblNum;
   }
#endif

 
#ifdef INTEGRAL_CONVERSIONS
#ifdef x64
   String Str(int iNum)
   {
    return iNum;
   }


   String Str(unsigned int iNum)
   {
    return iNum;
   }

   String Str(SSIZE_T iNum)
   {
    return iNum;
   }


   String Str(size_t iNum)
   {
    return iNum;
   }
#else
   String Str(int iNum)
   {
    return iNum;
   }


   String Str(unsigned int iNum)
   {
    return iNum;
   }
#endif
#endif


String::String() : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)
{
 this->lpBuffer=NEW TCHAR[MINIMUM_ALLOCATION];
 if(this->lpBuffer)
 {
    this->lpBuffer[0]=0;
    this->iLen=0;
    this->iCapacity=MINIMUM_ALLOCATION-1;
    this->blnSucceeded=TRUE;
 }
}


String::String(const size_t iSize, bool blnFillNulls) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)  // Constructor Creates String With Custom Sized
{                                                                                                                   // Buffer (rounded up to paragraph boundary) and
 size_t iNewSize       = (iSize/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;                                           // optionally filled with NULLs.
 TCHAR* pChar          = NEW TCHAR[iNewSize];
 if(pChar)
 {
    this->lpBuffer     = pChar;
    this->iCapacity    = iNewSize-1;
    this->iLen         = 0;
    this->lpBuffer[0]  = _T('\0');
    this->blnSucceeded=TRUE;
    if(blnFillNulls)
       memset(this->lpBuffer,0,iNewSize*sizeof(TCHAR));
 }
}


String::String(size_t iCount, const TCHAR ch)
{
 size_t iNewSize=(iCount/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
 TCHAR* pChar=NEW TCHAR[iNewSize];
 if(pChar)
 {
    this->iCapacity=iNewSize-1;
    this->lpBuffer=pChar;
    #ifdef UNICODE
    wmemset(this->lpBuffer,ch,iCount);
    #else
    memset(this->lpBuffer,ch,iCount);
    #endif
    this->lpBuffer[iCount]=_T('\0');
    this->iLen=iCount;
    this->blnSucceeded=TRUE;
 }
}


String::String(const TCHAR ch) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)                          //Constructor: Initializes with wchar_t
{
 this->lpBuffer=NEW TCHAR[MINIMUM_ALLOCATION];
 if(this->lpBuffer)
 {
    this->iLen         = 1;
    this->iCapacity    = MINIMUM_ALLOCATION-1;
    this->lpBuffer[0]  = ch;
    this->lpBuffer[1]  = _T('\0');
    this->blnSucceeded = TRUE;
 }
}


String::String(const TCHAR* pStr) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)                      //Constructor: Initializes with TCHAR*
{
 size_t iStrLen  = _tcslen(pStr);
 size_t iNewSize = (iStrLen/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
 this->lpBuffer=NEW TCHAR[iNewSize];
 if(this->lpBuffer)
 {
    _tcscpy(this->lpBuffer,pStr);
    this->iCapacity    = iNewSize-1;
    this->iLen         = iStrLen;
    this->blnSucceeded = TRUE;
 }
}


String::String(const String& s) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)                       //Constructor Initializes With Another String, i.e., Copy Constructor
{
 size_t iNewSize = (s.iLen/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
 this->lpBuffer  = NEW TCHAR[iNewSize];
 if(this->lpBuffer)
 {
    _tcscpy(this->lpBuffer,s.lpBuffer);
    this->iLen         = s.iLen;
    this->iCapacity    = iNewSize-1;
    this->blnSucceeded = TRUE;
 }
}


#ifdef INTEGRAL_CONVERSIONS
   String::String(int iNum) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)
   {
    this->lpBuffer = NEW TCHAR[MINIMUM_ALLOCATION];
    if(this->lpBuffer)
    {
       this->iCapacity    = MINIMUM_ALLOCATION-1;
       this->iLen         =_stprintf(this->lpBuffer,_T("%d"),iNum);
       this->blnSucceeded = TRUE;
    }
   }


   String::String(unsigned int iNum) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)
   {
    this->lpBuffer = NEW TCHAR[MINIMUM_ALLOCATION];
    if(this->lpBuffer)
    {
       this->iCapacity    = MINIMUM_ALLOCATION-1;
       this->iLen         =_stprintf(this->lpBuffer,_T("%u"),iNum);
       this->blnSucceeded = TRUE;
    }
   }


   #ifdef x64
      String::String(size_t iNum) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)
      {
       this->lpBuffer=NEW TCHAR[32];
       if(this->lpBuffer)
       {
          this->iCapacity=31;
          this->iLen=_stprintf(this->lpBuffer,_T("%Iu"),iNum);
          this->blnSucceeded = TRUE;
       }
      }


      String::String(ssize_t iNum) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)
      {
       this->lpBuffer = NEW TCHAR[32];
       if(this->lpBuffer)
       {
          this->iCapacity    = 31;
          this->iLen         = _stprintf(this->lpBuffer,_T("%Id"),iNum);
          this->blnSucceeded = TRUE;
       }
      }
   #endif
#endif


#ifdef FLOATING_POINT_CONVERSIONS
   String::String(double dblNumber) : lpBuffer(NULL), iLen(0), iCapacity(0), blnSucceeded(FALSE)
   {
    this->lpBuffer = NEW TCHAR[24];
    if(this->lpBuffer)
    {
       this->iCapacity    = 23;
       this->iLen         = _stprintf(this->lpBuffer,_T("%-23.6f"),dblNumber);
       this->blnSucceeded = TRUE;
    }
   }
#endif


String& String::operator=(const TCHAR ch)
{
 this->lpBuffer[0]=ch, this->lpBuffer[1]=_T('\0');
 this->iLen=1;
 this->blnSucceeded=TRUE;

 return *this;
}


String& String::operator=(const TCHAR* pStr)   // Assign TCHAR* to String
{
 size_t iNewLen=_tcslen(pStr);
 if(iNewLen>this->iCapacity)
 {
    size_t iNewSize=(iNewLen*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
    TCHAR* pCh=NEW TCHAR[iNewSize];
    if(pCh)
    {
       delete [] this->lpBuffer;
       this->lpBuffer=pCh;
       _tcscpy(this->lpBuffer,pStr);
       this->iCapacity=iNewSize-1;
       this->iLen=iNewLen;
       this->blnSucceeded=TRUE;
    }
    else
    {
       this->blnSucceeded=FALSE;
    }
 }
 else
 {
    _tcscpy(this->lpBuffer,pStr);
    this->iLen=iNewLen;
    this->blnSucceeded=TRUE;
 }

 return *this;
}


String& String::operator=(const String& strAnother)
{
 if(this==&strAnother)
    return *this;
 if(strAnother.iLen>this->iCapacity)
 {
    size_t iNewSize=(strAnother.iLen*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
    TCHAR* pCh=NEW TCHAR[iNewSize];
    if(pCh)
    {
       delete [] this->lpBuffer;
       this->lpBuffer=pCh;
       _tcscpy(this->lpBuffer,strAnother.lpBuffer);
       this->iCapacity=iNewSize-1;
       this->iLen=strAnother.iLen;
       this->blnSucceeded=TRUE;
    }
    else
    {
       this->blnSucceeded=FALSE;
    }
 }
 else
 {
    _tcscpy(this->lpBuffer,strAnother.lpBuffer);
    this->iLen=strAnother.iLen;
    this->blnSucceeded=TRUE;
 }

 return *this;
}


String& String::Make(const TCHAR ch, size_t iCount)    //Creates (Makes) a String with iCount TCHARs
{
 if(iCount>this->iCapacity)
 {
    size_t iNewSize=(iCount*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
    TCHAR* pCh=NEW TCHAR[iNewSize];
    if(pCh)
    {
       delete [] this->lpBuffer;
       this->lpBuffer=pCh;
       this->iCapacity=iNewSize-1;
       for(size_t i=0; i<iCount; i++)
           this->lpBuffer[i]=ch;
       this->lpBuffer[iCount]=0;
       this->iLen=iCount;
       this->blnSucceeded=TRUE;
    }
    else
    {
       this->blnSucceeded=FALSE;
    }
 }
 else
 {
    for(size_t i=0; i<iCount; i++)
        this->lpBuffer[i]=ch;
    this->lpBuffer[iCount]=0;
    this->iLen=iCount;
    this->blnSucceeded=TRUE;
 }

 return *this;
}


#ifdef INTEGRAL_CONVERSIONS
   #ifdef x64
      String& String::operator=(size_t iNum)
      {
       if(this->iCapacity>=23)
       {
          this->iLen=_stprintf(this->lpBuffer,_T("%Iu"),iNum);
          this->blnSucceeded=TRUE;
       }
       else
       {
          TCHAR* pCh=NEW TCHAR[24];
          if(pCh)
          {
             if(this->lpBuffer)
                delete [] this->lpBuffer;
             this->lpBuffer=pCh;
             this->iCapacity=23;
             this->iLen=_stprintf(this->lpBuffer,_T("%Iu"),iNum);
             this->blnSucceeded=TRUE;
          }
          else
          {
             this->blnSucceeded=FALSE;

          }
       }

       return *this;
      }


      String& String::operator=(ssize_t iNum)
      {
       if(this->iCapacity>=23)
       {
          this->iLen=_stprintf(this->lpBuffer,_T("%Id"),iNum);
          this->blnSucceeded=TRUE;
       }
       else
       {
          TCHAR* pCh=NEW TCHAR[24];
          if(pCh)
          {
             if(this->lpBuffer)
                delete [] this->lpBuffer;
             this->lpBuffer=pCh;
             this->iCapacity=23;
             this->iLen=_stprintf(this->lpBuffer,_T("%Id"),iNum);
             this->blnSucceeded=TRUE;
          }
          else
          {
             this->blnSucceeded=FALSE;
          }
       }

       return *this;
      }
   #endif


   String& String::operator=(int iNum)
   {
    if(this->iCapacity>=15)
    {
       this->iLen=_stprintf(this->lpBuffer,_T("%d"),iNum);
       this->blnSucceeded=TRUE;
    }
    else
    {
       TCHAR* pCh=NEW TCHAR[MINIMUM_ALLOCATION];
       if(pCh)
       {
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pCh;
          this->iCapacity=15;
          this->iLen=_stprintf(this->lpBuffer,_T("%d"),iNum);
          this->blnSucceeded=TRUE;
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }

    return *this;
   }


   String& String::operator=(unsigned int iNum)
   {
    if(this->iCapacity>=15)
    {
       this->iLen=_stprintf(this->lpBuffer,_T("%u"),iNum);
       this->blnSucceeded=TRUE;
    }
    else
    {
       TCHAR* pCh=NEW TCHAR[MINIMUM_ALLOCATION];
       if(pCh)
       {
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pCh;
          this->iCapacity=15;
          this->iLen=_stprintf(this->lpBuffer,_T("%u"),iNum);
          this->blnSucceeded=TRUE;
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }

    return *this;
   }
#endif


#ifdef FLOATING_POINT_CONVERSIONS
   String& String::operator=(double dblNumber)
   {
    if(this->iCapacity>=24)
    {
       this->iLen=_stprintf(this->lpBuffer,_T("%-23.6f"),dblNumber);
       this->blnSucceeded=TRUE;
    }
    else
    {
       TCHAR* pCh=NEW TCHAR[24];
       if(pCh)
       {
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pCh;
          this->iCapacity=23;
          this->iLen=_stprintf(this->lpBuffer,_T("%-23.6f"),dblNumber);
          this->blnSucceeded=TRUE;
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }

    return *this;
   }
#endif


String String::operator+(const TCHAR ch)
{
 int iNewLen=this->iLen+1;

 String s(iNewLen,false);
 if(s.blnSucceeded)
 {
    _tcscpy(s.lpBuffer,this->lpBuffer);
    s.lpBuffer[iNewLen-1]=ch;
    s.lpBuffer[iNewLen]=_T('\0');
    s.iLen=iNewLen;
 }

 return s;
}


String String::operator+(const TCHAR* pStr)
{
 int iNewLen=_tcslen(pStr)+this->iLen;
 String s(iNewLen,false);
 if(s.blnSucceeded)
 {
    _tcscpy(s.lpBuffer,this->lpBuffer);
    _tcscat(s.lpBuffer,pStr);
    s.iLen=iNewLen;
 }

 return s;
}


String String::operator+(String& strRef)
{
 int iNewLen=strRef.iLen+this->iLen;
 String s(iNewLen,false);
 if(s.blnSucceeded==TRUE)
 {
    _tcscpy(s.lpBuffer,this->lpBuffer);
    _tcscat(s.lpBuffer,strRef.lpBuffer);
    s.iLen=iNewLen;
 }

 return s;
}


#ifdef PLUS_EQUAL
   String& String::operator+=(const TCHAR ch)
   {
    size_t iTot=this->iLen+1;
    if(iTot>this->iCapacity)
    {
       int iNewSize=(iTot*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
       TCHAR* pNew=NEW TCHAR[iNewSize];
       if(pNew)
       {
          _tcscpy(pNew,this->lpBuffer);
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pNew;
          this->lpBuffer[iTot-1]=ch;
          this->lpBuffer[iTot]=_T('\0');
          this->iCapacity=iNewSize-1;
          this->iLen=iTot;
          this->blnSucceeded=TRUE;
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }
    else
    {
       this->lpBuffer[iTot-1]=ch;
       this->lpBuffer[iTot]=_T('\0');
       this->iLen=iTot;
       this->blnSucceeded=TRUE;
    }

    return *this;
   }


   String& String::operator+=(const TCHAR* pStr)
   {
    size_t iStrlen=_tcslen(pStr);
    size_t iTot=iStrlen+this->iLen;
    if(iTot>this->iCapacity)
    {
       int iNewSize=(iTot*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
       TCHAR* pNew=NEW TCHAR[iNewSize];
       if(pNew)
       {
          _tcscpy(pNew,this->lpBuffer);
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pNew;
          _tcscat(pNew,pStr);
          this->iCapacity=iNewSize-1;
          this->iLen=iTot;
          this->blnSucceeded=TRUE;
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }
    else
    {
       _tcscat(this->lpBuffer,pStr);
       this->iLen=iTot;
       this->blnSucceeded=TRUE;
    }

    return *this;
   }


   String& String::operator+=(const String& strRef)
   {
    size_t iTot=strRef.iLen+this->iLen;
    if(iTot>this->iCapacity)
    {
       int iNewSize=(iTot*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
       TCHAR* pNew=NEW TCHAR[iNewSize];
       if(pNew)
       {
          _tcscpy(pNew,this->lpBuffer);
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pNew;
          _tcscat(pNew,strRef.lpBuffer);
          this->iCapacity=iNewSize-1;
          this->iLen=iTot;
          this->blnSucceeded=TRUE;
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }
    else
    {
       _tcscat(this->lpBuffer,strRef.lpBuffer);
       this->iLen=iTot;
       this->blnSucceeded=TRUE;
    }

    return *this;
   }
#endif


bool String::operator==(String strRef)
{
 if(_tcscmp(this->lpStr(),strRef.lpStr())==0)
    return true;
 else
    return false;
}


bool String::operator==(const TCHAR* pStr)
{
 if(_tcscmp(this->lpStr(),pStr)==0)
    return true;
 else
    return false;
}


bool String::operator!=(TCHAR* pStr)
{
 if(_tcscmp(this->lpStr(),pStr)==0)
    return false;
 else
    return true;
}


String String::Left(size_t iNum)   //  strncpy = _tcsncpy
{
 if(iNum<this->iLen)
 {
    size_t iNewSize=(iNum*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
    String sr(iNewSize,true);
    if(sr.blnSucceeded)
    {
       _tcsncpy(sr.lpBuffer,this->lpBuffer,iNum);   // wcsncpy(wchar_t pDest, wchar_t pSource, size_t iCount);
       sr.lpBuffer[iNum]=_T('\0');
       sr.iLen=iNum;
       sr.blnSucceeded=TRUE;
       return sr;
    }
    else
    {
       sr.blnSucceeded=FALSE;
       return sr;
    }
 }
 else
 {
    String sr=*this;
    sr.iLen=this->iLen;
    sr.blnSucceeded=TRUE;
    return sr;
 }
}


String String::Right(size_t iNum)  //Returns Right$(strMain,iNum)
{
 if(iNum<this->iLen)
 {
    size_t iNewSize=(iNum*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
    String sr(iNewSize,false);
    if(sr.blnSucceeded)
    {
       _tcsncpy(sr.lpBuffer,this->lpBuffer+this->iLen-iNum,iNum);
       sr.lpBuffer[iNum]=_T('\0');
       sr.iLen=iNum;
       sr.blnSucceeded=TRUE;
       return sr;
    }
    else
    {
       sr.blnSucceeded=FALSE;
       return sr;
    }
 }
 else
 {
    String sr=*this;
    sr.iLen=this->iLen;
    sr.blnSucceeded=TRUE;
    return sr;
 }
}


String String::Mid(size_t iStart, size_t iCount)
{
 if(iStart<1)
 {
    String sr;
    return sr;
 }
 if(iCount+iStart>this->iLen)
    iCount=this->iLen-iStart+1;
 String sr(iCount,false);
 if(sr.blnSucceeded)
 {
    _tcsncpy(sr.lpBuffer,this->lpBuffer+iStart-1,iCount);
    sr.lpBuffer[iCount]=_T('\0');
    sr.iLen=iCount;
    sr.blnSucceeded=TRUE;
 }
 else
    sr.blnSucceeded=FALSE;

 return sr;
}


void String::LTrim()
{
 size_t iCt=0;

 for(size_t i=0; i<this->iLen; i++)
 {
     if(this->lpBuffer[i]==9||this->lpBuffer[i]==10||this->lpBuffer[i]==13||this->lpBuffer[i]==32)
        iCt++;
     else
        break;
 }
 if(iCt)
 {
    for(size_t i=iCt; i<=this->iLen; i++)
        this->lpBuffer[i-iCt]=this->lpBuffer[i];
 }
 this->iLen=this->iLen-iCt;
 this->blnSucceeded=TRUE;
}


void String::RTrim()
{
 int iCt=0;

 for(int i=this->iLen-1; i>0; i--)
 {
     if(this->lpBuffer[i]==9||this->lpBuffer[i]==10||this->lpBuffer[i]==13||this->lpBuffer[i]==32)
        iCt++;
     else
        break;
 }
 this->lpBuffer[this->iLen-iCt]=0;
 this->iLen=this->iLen-iCt;
 this->blnSucceeded=TRUE;
}


void String::Trim()
{
 this->LTrim();
 this->RTrim();
 this->blnSucceeded=TRUE;
}


int String::ParseCount(const TCHAR delimiter)   //returns one more than # of
{                                               //delimiters so it accurately
 size_t iCountQuotes = 0;                       //reflects # of strings delimited
 int    iCtr         = 0;                       //by delimiter.             
 TCHAR* p;                                      
 
 p=this->lpBuffer;
 while(*p)
 {
   if(*p==34)                                   //Has a double quote been encountered?
   {                                            //If so, increment variable iCountQuotes to 1.
      if(iCountQuotes)                          //If iCountQuotes is already 1, then decrement
         iCountQuotes--;                        //it to zero (0).
      else        
         iCountQuotes++;
   } 
   else
   {    
      if(*p==delimiter && iCountQuotes==0)      //Only increment iCtr if a delimiter has been
         iCtr++;                                //encountered, and iCountQuotes is zero, i.e.,
   }                                            //we're not on a quoted string.
   p++;
 }
 this->blnSucceeded=TRUE;

 return ++iCtr;
}


void String::Parse(String* pStr, TCHAR delimiter, size_t iParseCount)
{
 size_t iCountQuotes = 0;
 TCHAR* pBuffer=NEW TCHAR[this->iLen+1];
 if(pBuffer)
 {
    TCHAR* p=pBuffer;
    TCHAR* c=this->lpBuffer;

    while(*c)
    {
       if(*c==34)                                   
       {                                            
          if(iCountQuotes)                          
             iCountQuotes--;                        
          else        
             iCountQuotes++;
       } 
       else
       { 
          if(*c==delimiter && iCountQuotes==0)
             *p=0;
          else
          {
             *p=*c;
          }
       }
       p++, c++;
    }

    *p=0, p=pBuffer;
    for(size_t i=0; i<iParseCount; i++)
    {
        pStr[i]=p;
        p=p+pStr[i].iLen+1;
    }
    delete [] pBuffer;
    this->blnSucceeded=TRUE;
 }
 else
    this->blnSucceeded=FALSE;
}


int iMatch(TCHAR* pThis, const TCHAR* pStr, bool blnCaseSensitive, bool blnStartBeginning, int i, int iParamLen)
{
 if(blnCaseSensitive)
 {
    if(_tcsncmp(pThis+i,pStr,iParamLen)==0)   //_tcsncmp
       return i+1;
    else
       return 0;
 }
 else
 {
    if(_tcsnicmp(pThis+i,pStr,iParamLen)==0)  //__tcsnicmp
       return i+1;
    else
       return 0;
 }
}


int String::InStr(const TCHAR* pStr, bool blnCaseSensitive, bool blnStartBeginning)
{
 ssize_t i,iParamLen,iRange,iReturn;

 if(*pStr==0)
 {
    this->blnSucceeded=FALSE;
    return 0;
 }
 iParamLen=_tcslen(pStr);
 iRange=this->iLen-iParamLen;
 if(blnStartBeginning)
 {
    if(iRange>=0)
    {
       for(i=0; i<=iRange; i++)
       {
           iReturn=iMatch(this->lpBuffer,pStr,blnCaseSensitive,blnStartBeginning,i,iParamLen);
           if(iReturn)
           {
              this->blnSucceeded=TRUE;
              return iReturn;
           }
       }
    }
    else
       this->blnSucceeded=FALSE;
 }
 else
 {
    if(iRange>=0)
    {
       for(i=iRange; i>=0; i--)
       {
           iReturn=iMatch(this->lpBuffer,pStr,blnCaseSensitive,blnStartBeginning,i,iParamLen);
           if(iReturn)
           {
              this->blnSucceeded=TRUE;
              return iReturn;
           }
       }
    }
    else
       this->blnSucceeded=FALSE;
 }
 this->blnSucceeded=TRUE;

 return 0;
}


int String::InStr(const String& s, bool blnCaseSensitive, bool blnStartBeginning)
{
 ssize_t i,iParamLen,iRange,iReturn;

 if(s.iLen==0)
 {
    this->blnSucceeded=FALSE;
    return 0;
 }
 iParamLen=s.iLen;
 iRange=this->iLen-iParamLen;
 if(blnStartBeginning)
 {
    if(iRange>=0)
    {
       for(i=0; i<=iRange; i++)
       {
           iReturn=iMatch(this->lpBuffer,s.lpBuffer,blnCaseSensitive,blnStartBeginning,i,iParamLen);
           if(iReturn)
           {
              this->blnSucceeded=TRUE;
              return iReturn;
           }
       }
    }
    else
       this->blnSucceeded=FALSE;
 }
 else
 {
    if(iRange>=0)
    {
       for(i=iRange; i>=0; i--)
       {
           iReturn=iMatch(this->lpBuffer,s.lpBuffer,blnCaseSensitive,blnStartBeginning,i,iParamLen);
           if(iReturn)
           {
              this->blnSucceeded=TRUE;
              return iReturn;
           }
       }
    }
 }
 this->blnSucceeded=TRUE;

 return 0;
}


String String::Remove(const TCHAR* pStr)   // Individual character removal, i.e., if this contains the
{                                          // English alphabet...
 size_t i,j,iStrLen,iParamLen;             //
 TCHAR *pThis, *pThat, *p;                 // abcdefghijklmnopqrstuvwxyz
 bool blnFoundBadTCHAR;                    //
                                           // ...and pStr is this...
 iStrLen=this->iLen;                       //
 String sr((int)iStrLen,false);            // "aeiou"
 if(sr.blnSucceeded)                       //
 {                                         // ,,,then this will be returned in the returned String...
    iParamLen=_tcslen(pStr);               //
    pThis=this->lpBuffer;                  // bcdfghjklmnpqrstvwxyz
    p=sr.lpStr();                          //
    for(i=0; i<iStrLen; i++)               // That is, the vowels will be individually removed
    {
        pThat=(TCHAR*)pStr;
        blnFoundBadTCHAR=false;
        for(j=0; j<iParamLen; j++)
        {
            if(*pThis==*pThat)
            {
               blnFoundBadTCHAR=true;
               break;
            }
            pThat++;
        }
        if(!blnFoundBadTCHAR)
        {
           *p=*pThis;
           p++;
           *p=_T('\0');
        }
        pThis++;
    }
    sr.iLen=_tcslen(sr.lpStr());
    sr.blnSucceeded=TRUE;
 }
 else
    sr.blnSucceeded=FALSE;

 return sr;
}


String String::Remove(const TCHAR* pMatch, bool blnCaseSensitive)
{
 size_t i,iCountMatches=0,iCtr=0;

 size_t iLenMatch=_tcslen(pMatch);
 for(i=0; i<this->iLen; i++)
 {
     if(blnCaseSensitive)
     {
        if(_tcsncmp(lpBuffer+i,pMatch,iLenMatch)==0)  //_tcsncmp
           iCountMatches++;
     }
     else
     {
        if(_tcsnicmp(lpBuffer+i,pMatch,iLenMatch)==0) //__tcsnicmp
           iCountMatches++;
     }
 }
 ssize_t iAllocation=this->iLen-(iCountMatches*iLenMatch);
 String sr(iAllocation,false);
 if(sr.blnSucceeded)
 {
    for(i=0; i<this->iLen; i++)
    {
        if(blnCaseSensitive)
        {
           if(_tcsncmp(this->lpBuffer+i,pMatch,iLenMatch)==0)
              i+=iLenMatch-1;
           else
           {
              sr.lpBuffer[iCtr]=this->lpBuffer[i];
              iCtr++;
           }
           sr.lpBuffer[iCtr]=_T('\0');
        }
        else
        {
           if(_tcsnicmp(this->lpBuffer+i,pMatch,iLenMatch)==0)
              i+=iLenMatch-1;
           else
           {
              sr.lpBuffer[iCtr]=this->lpBuffer[i];
              iCtr++;
           }
           sr.lpBuffer[iCtr]=_T('\0');
        }
    }
    sr.iLen=iCtr;
    sr.blnSucceeded=TRUE;
 }
 else
    sr.blnSucceeded=FALSE;

 return sr;
}


String String::Replace(TCHAR* pMatch, TCHAR* pNew)  //strncmp = _tcsncmp
{
 size_t i,iLenMatch,iLenNew,iCountMatches,iExtra,iExtraLengthNeeded,iAllocation,iCtr;

 iLenMatch=_tcslen(pMatch);
 iCountMatches=0, iAllocation=0, iCtr=0;
 iLenNew=_tcslen(pNew);
 if(iLenNew==0)
 {
    String sr=this->Remove(pMatch,true); //return
    sr.blnSucceeded=TRUE;
    return sr;
 }
 else
 {
    iExtra=iLenNew-iLenMatch;
    for(i=0; i<this->iLen; i++)
    {
        if(_tcsncmp(lpBuffer+i,pMatch,iLenMatch)==0)
           iCountMatches++;  //Count how many match strings
    }
    iExtraLengthNeeded=iCountMatches*iExtra;
    iAllocation=this->iLen+iExtraLengthNeeded;
    String sr(iAllocation,false);
    if(sr.blnSucceeded)
    {
       for(i=0; i<this->iLen; i++)
       {
           if(_tcsncmp(this->lpBuffer+i,pMatch,iLenMatch)==0)
           {
              _tcscpy(sr.lpBuffer+iCtr,pNew);
              iCtr+=iLenNew;
              i+=iLenMatch-1;
           }
           else
           {
              sr.lpBuffer[iCtr]=this->lpBuffer[i];
              iCtr++;
           }
           sr.lpBuffer[iCtr]=_T('\0');
       }
       sr.iLen=iCtr;
       sr.blnSucceeded=TRUE;
       return sr;
    }
    else
    {
       sr.blnSucceeded=FALSE;
       return sr;
    }
 }
}


#ifdef FORMATTING
   void String::Format(double dblNumber, size_t iFieldSize, size_t iDecPlaces, TCHAR cDecimalSeperator, bool blnRightJustified)
   {
    String strFldSpec,strDecPlaces,strFldSize;

    strFldSpec=_T('%');
    strFldSize=iFieldSize;
    strDecPlaces=iDecPlaces;
    if(blnRightJustified)
       strFldSpec=strFldSpec+strFldSize+cDecimalSeperator+strDecPlaces;
    else
       strFldSpec=strFldSpec+_T('-')+strFldSize+cDecimalSeperator+strDecPlaces;
    strFldSpec=strFldSpec+_T('f');
    if(this->iCapacity<iFieldSize)
    {
       TCHAR* pCh=NEW TCHAR[iFieldSize+1];
       if(pCh)
       {
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pCh;
          this->iCapacity=iFieldSize;
          this->blnSucceeded=TRUE;
          this->iLen=_stprintf(this->lpBuffer,strFldSpec.lpStr(),dblNumber);
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }
    else
    {
       this->iLen=_stprintf(this->lpBuffer,strFldSpec.lpStr(),dblNumber);
       this->blnSucceeded=TRUE;
    }
   }


   void String::Format(double dblNumber, size_t iFieldSize, size_t iDecimalPlaces, TCHAR cThousandsSeperator, TCHAR cDecimalSeperator, bool blnRightJustified)
   {
    size_t iLenStr=0,iPadding=0;
    int iDecPt=0;
    ssize_t iInt;

    if(this->iCapacity<iFieldSize+1)
    {
       size_t iNewSize=(iFieldSize/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
       TCHAR* pCh=NEW TCHAR[iNewSize];
       if(pCh)
       {
          if(this->lpBuffer)
             delete [] this->lpBuffer;
          this->lpBuffer=pCh;
          this->iCapacity=iNewSize-1;
          this->lpBuffer[0]=0;
       }
       else
       {
          this->blnSucceeded=FALSE;
          return;
       }
    }
    String s1(24,true);
    s1.Format(dblNumber,24,iDecimalPlaces,cDecimalSeperator,false);
    s1.Trim();
    if(iDecimalPlaces)
    {
       iDecPt=s1.InStr(cDecimalSeperator,false,false);
       String s2=s1.Left(iDecPt-1);
       iInt=_ttoi64(s2.lpStr());
    }
    else
       iInt=_ttoi64(s1.lpStr());
    String s3(28,true);
    if(iInt==0 && dblNumber<0.0)
       s3=_T("-0");
    else
       s3.Format((ssize_t)iInt,28,cThousandsSeperator,false);
    s3.Trim();
    if(iDecimalPlaces)
    {
       String s4=s1.Mid(iDecPt,iDecimalPlaces+1);
       s3=s3+s4;
    }
    iLenStr=s3.Len();
    if(iLenStr>this->iCapacity)
       return;
    iPadding=iFieldSize-iLenStr;
    if(blnRightJustified)
    {
       for(size_t i=0; i<iPadding; i++)
           this->lpBuffer[i]=32;
       this->lpBuffer[iPadding]=0;
       _tcscat(this->lpBuffer, s3.lpStr());
    }
    else
    {
       _tcscpy(this->lpBuffer,s3.lpStr());
       for(size_t i=iLenStr; i<iFieldSize; i++)
           this->lpBuffer[i]=32;
       this->lpBuffer[iFieldSize]=0;
    }
    this->iLen=_tcslen(this->lpBuffer);
   }


   void String::Format(ssize_t iNumber, size_t iFieldSize, TCHAR cThousandsSeperator, bool blnRightJustified)
   {
    bool blnPositive;
    TCHAR szBuf1[28];
    TCHAR szBuf2[28];
    size_t iLenStr=0;
    size_t iDigit=0;
    size_t iCtr=1;
    size_t j=0;

    memset(szBuf1,0,28*sizeof(TCHAR));
    memset(szBuf2,0,28*sizeof(TCHAR));
    if(iNumber<0)
       blnPositive=false;
    else
       blnPositive=true;
    #ifdef x64
       iNumber=_abs64(iNumber);
    #else
       iNumber=abs(iNumber);
    #endif
    #ifdef x64
       _stprintf(szBuf1,_T("%Iu"),(size_t)iNumber);
    #else
       _stprintf(szBuf1,_T("%u"),(size_t)iNumber);
    #endif
    _tcsrev(szBuf1);
    iLenStr=_tcslen(szBuf1);
    for(size_t i=0; i<iLenStr; i++)
    {
        if(iCtr==3)
        {
           iDigit++;
           szBuf2[j]=szBuf1[i];
           if(iDigit<iLenStr)
           {
              j++;
              szBuf2[j]=cThousandsSeperator;
           }
           j++, iCtr=1;
        }
        else
        {
           iDigit++;
           szBuf2[j]=szBuf1[i];
           j++, iCtr++;
        }
    }
    _tcsrev(szBuf2); // Done With Creating String With Commas
    memset(szBuf1,0,28*sizeof(TCHAR));  // Reuse szBuf1
    if(blnPositive)
       _tcscpy(szBuf1,szBuf2);
    else
    {
       szBuf1[0]=_T('-');
       _tcscat(szBuf1,szBuf2);
    }
    size_t iRequiredBytes;         // Find out which of two is larger - length of string necessary
    iLenStr=_tcslen(szBuf1);          // or iFldLen
    if(iFieldSize<iLenStr)
       return;
    iRequiredBytes=iFieldSize+1;
    if(iRequiredBytes>(size_t)this->iCapacity)
    {
       delete [] this->lpBuffer;
       int iNewSize=(iRequiredBytes*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
       this->lpBuffer=NEW TCHAR[iNewSize];
       this->iCapacity=iNewSize-1;
    }

    memset(this->lpBuffer,0,(this->iCapacity+1)*sizeof(TCHAR));
    ssize_t iDifference=iFieldSize-iLenStr;
    if(blnRightJustified)
    {
       if(iDifference > 0)
       {
          for(size_t i=0; i<(size_t)iDifference; i++)
              this->lpBuffer[i]=_T(' ');  // 32
       }
       _tcscat(this->lpBuffer,szBuf1);
    }
    else
    {
       _tcscpy(this->lpBuffer,szBuf1);
       if(iDifference>0)
       {
          for(size_t i=iLenStr; i<iDifference+iLenStr; i++)
              this->lpBuffer[i]=_T(' ');  // 32
       }
    }
    this->iLen=_tcslen(this->lpBuffer);
  }
#endif


ssize_t String::iVal()
{
 #ifdef x64
    return _ttoi64(this->lpBuffer);
 #else
    return _ttoi(this->lpBuffer);  //_ttoi
 #endif
}


String String::UCase()
{
 String s(*this);
 CharUpper(s.lpBuffer);
 return s;
}


TCHAR* String::lpStr()
{
 return this->lpBuffer;
}


size_t String::Len(void)
{
 return this->iLen;
}


size_t String::Capacity(void)
{
 return this->iCapacity;
}


bool String::blnSuccess()
{
 return this->blnSucceeded;
}


#ifdef CONSOLE_IO
   void String::Print(bool blnCrLf)
   {
    _tprintf(_T("%s"),this->lpBuffer);
    if(blnCrLf)
       _tprintf(_T("\n"));
   }


   void String::Print(const TCHAR* pStr, bool blnCrLf)
   {
    _tprintf(_T("%s%s"),pStr,lpBuffer);
    if(blnCrLf)
       _tprintf(_T("\n"));
   }
#endif


#ifdef FILE_IO
   void String::Print(FILE* fp1, bool blnCrLf)
   {
    _ftprintf(fp1, _T("%s"),lpBuffer);
    if(blnCrLf)
       _ftprintf(fp1,_T("\n"));
   }


   void String::Print(FILE* fp1, TCHAR* pStr, bool blnCrLf)
   {
    _ftprintf(fp1, _T("%s%s"),pStr,lpBuffer);
    if(blnCrLf)
       _ftprintf(fp1,_T("\n"));
   }

   
   BOOL String::LineInput(FILE* fp)
   {
    TCHAR* pStr=NULL;
    TCHAR szBuffer[1028];
    
    pStr=_fgetts(szBuffer,1028,fp);
    //printf("pStr = %u\t",pStr);
    if(!pStr)
    {
       this->blnSucceeded=FALSE;     
       return FALSE;
    }   
    size_t iNewLen=_tcslen(szBuffer);
    if(szBuffer[iNewLen-1]==10)
    { 
       szBuffer[iNewLen-1]=0;
       iNewLen--;  
    }   
    if(iNewLen>this->iCapacity)
    {
       size_t iNewSize=(iNewLen*EXPANSION_FACTOR/MINIMUM_ALLOCATION+1)*MINIMUM_ALLOCATION;
       TCHAR* pCh=NEW TCHAR[iNewSize];
       if(pCh)
       {
          delete [] this->lpBuffer;
          this->lpBuffer=pCh;
          _tcscpy(this->lpBuffer,pStr);
          this->iCapacity=iNewSize-1;
          this->iLen=iNewLen;
          this->blnSucceeded=TRUE;
       }
       else
       {
          this->blnSucceeded=FALSE;
       }
    }
    else
    {
       _tcscpy(this->lpBuffer,pStr);
       this->iLen=iNewLen;
       this->blnSucceeded=TRUE;
    }
    
    return TRUE;
   }
#endif


String::~String()
{
 if(this->lpBuffer)
    delete [] this->lpBuffer;
}
// End Strings.cpp
