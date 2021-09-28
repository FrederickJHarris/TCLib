// Strings.h                                                    // NULL Terminated String Class With Method Naming Conventions After BASIC Model Languages.  Implemented For
#ifndef Strings_h                                               // x86 / x64, Asci / Unicode (For x86 Builds Comment Out x64 #define Below Left).
#define Strings_h

#ifndef ssize_t
typedef SSIZE_T ssize_t;                                        // ssize_t is defined in GCC, but isn't defined in VC 9-15, but rather SSIZE_T.  For symetry we'll define it.
#endif

#define MINIMUM_ALLOCATION                   16                 // allocate at least this for every String
#define EXPANSION_FACTOR                      2                 // repeated concatenations will keep doubling buffer
#define INTEGRAL_CONVERSIONS                                    // allows direct assignment of integral numeric values to Strings, e.g., String s(12345) or s=54321;  It can be remmed out.
#define FLOATING_POINT_CONVERSIONS                              // allows direct assignment of floating point values to Strings, e.g., String s(3.14159) or s=2.98;  It can be remmed out.
#define FORMATTING                                              // put commas every three places, rounding, left/right justification, specify field sizes (padding), etc.  It can be remmed out.
#define PLUS_EQUAL                                              // For += Functionality With String Concatenation;  It can be remmed out.
#define CONSOLE_IO                                              // support console output, i.e., enable String::Print();  It can be remmed out.
#define FILE_IO                                                 // Support Writing To FILEs;  It can be remmed out.
#define x64

class String
{
 public:                                                        // Constructors (10)
 String();                                                      // Uninitialized Constructor
 String(const size_t iSize, bool blnNullOut);                   // Constructor creates String of size iSize and optionally nulls out
 String(const size_t iCount, const TCHAR c);                    //Constructor initializes String with size_t # of TCHARs
 String(const TCHAR ch);                                        // Constructor creates a String initialized with a char, e.g., String c('A');
 String(const TCHAR* pStr);                                     // Constructor: Initializes with char*, e.g. s1 = "PowerBASIC! Compile Without Compromise!"
 String(const String& strAnother);                              // Constructor creates String initialized with another already existing String, e.g., String s2(s1);
 #ifdef INTEGRAL_CONVERSIONS
    String(int iNumber);                                        // Constructor creates String initialized with an int, e.g., String s1(2468); kind of Str$(2468) in PowerBASIC
    String(unsigned int uNumber);                               // Constructor creates String initialized with an unsigned int, e.g., String s1(2468); kind of Str$(2468) in PowerBASIC
    #ifdef x64
       String(size_t  uiNumber);                                // Constructor creates String from 64 bit unsigned number, e.g., String strBigNum(12345678987654);
       String(ssize_t iNumber);                                 // Constructor creates String from 64 bit signed number, e.g., String strBigNum(-12345678987654);
    #endif
 #endif
 #ifdef FLOATING_POINT_CONVERSIONS
    String(double dblNumber);                                   // Constructor creates String from floating point number, e.g., String s(3.14159);
 #endif
 String& operator=(const TCHAR c);                              // Assign a char to a String, e.g., String s='A';
 String& operator=(const TCHAR* pStr);                          // Assign a character string to a String Object, e.g.,  String s1 = "Compile Without Compromise";
 String& operator=(const String& strAnother);                   // Assign an already existing String to this one, e.g., String s2 = s1;
 String& Make(const TCHAR, size_t);                             // Returns reference to this with iCount ch TCHARs in it
 #ifdef INTEGRAL_CONVERSIONS
    String& operator=(int iNumber);                             // Assign an int converted to a String to this, e.g., String s1 = -123456789;
    String& operator=(unsigned int uNumber);                    // Assign an unsigned int converted to a String to this, e.g., String s1 =  123456789;
    #ifdef x64
       String& operator=(size_t  uNumber);                      // Assign a 64 bit unsigned quantity converted to a String to this, e.g., String s2 =  12345678987654;
       String& operator=(ssize_t iNumber);                      // Assign a 64 bit   signed quantity converted to a String to this, e.g., String s2 = -12345678987654;
    #endif
 #endif
 #ifdef FLOATING_POINT_CONVERSIONS
    String& operator=(double dblNumber);                        // Assign a double converted to a String to this, e.g., String strDouble = 3.14159;
 #endif
 String operator+(const TCHAR ch);                              // Concatenates or adds a character to an already existing String, e.g., s1 = s1 + 'A';
 String operator+(const TCHAR* pChar);                          // Concatenates or adds a character array (char*) to an already existing String, e.g., s1 = s1 + lpText;
 String operator+(String& s);                                   // Concatenates or adds another String to this one, e.g., s1 = s1 + s2;
 #ifdef PLUS_EQUAL
    String& operator+=(const TCHAR ch);                         // Add TCHAR to this
    String& operator+=(const String&);                          // Adds a String to this and assigns it to left of equal sign
    String& operator+=(const TCHAR*);                           // Adds a TCHAR* to this and assigns it to left of equal sign
 #endif
 bool operator==(String s);                                     // Compares two Strings for case sensitive equality
 bool operator==(const TCHAR* pChar);                           // Compares a String against a char* for case sensitive equality
 bool operator!=(TCHAR* pChar);                                 // Compares a String against a char* for case sensitive inequality
 void LTrim();                                                  // Removes leading white space by modifying existing String
 void RTrim();                                                  // Removes trailing white space by modifying existing String
 void Trim();                                                   // Removes leading or trailing white space from existing String
 String UCase();                                                // Returns *this in upper case
 String Left(size_t iCntChars);                                 // Returns a String consisting of left-most iCntChars of this
 String Right(size_t iCntChars);                                // Returns a String consisting of right-most iCntChars of this
 String Mid(size_t iStart, size_t iCount);                      // Returns a String consisting of iCount characters of this starting at one based iStart
 int ParseCount(const TCHAR delimiter);                         // Returns count of delimited fields as specified by char delimiter, i.e., comma, space, tab, etc.
 void Parse(String* pStr, TCHAR delimiter, size_t iParseCount); // Parses this based on delimiter.  Must pass in 1st parameter String* to sufficient number of Strings
 String Remove(const TCHAR* pCharsToRemove);                    // Returns A String With All The chars In A char* Removed (Individual char removal)
 String Remove(const TCHAR* pStrToRemove, bool bCaseSensitive); // Returns a String with 1st parameter removed.  2nd is bool for case sensitivity.
 String Replace(TCHAR* pToRevove, TCHAR* pReplacement);         // Replaces pToRemove with pReplacement in new String.  Replacement can cause String to grow
 bool blnSuccess();                                             // true if String memory allocation succeeded; false otherwise

 int InStr                                                      // Returns one based position of pStr in this by case sensitivity and left/right starting position
 (
  const TCHAR* pStr,                                            // pStr -- TCHAR* To Character String To Search For
  bool  blnCaseSensitive,                                       // true / case sensitive; false / case insensitive
  bool  blnStartLeft                                            // Can Specify Search Start From Beginning Or End
 );

 int InStr                                                      // Returns one based position of String in this by case sensitivity and left/right starting position
 (
  const String& str,                                            // String To Search For
  bool  blnCaseSensitive,                                       // true / case sensitive; false / case insensitive
  bool  blnStartLeft                                            // Can Specify Search Start From Beginning Or End
 );

 #ifdef FORMATTING
    void Format                                                 // dblNumber converted to String, in iArrayCount Buffer Size, with iDecPlaces right of decimal, left or right justified.
    (
     double dblNumber,                                          // Double To Be Formatted.
     size_t iFieldSize,                                         // Field Size In Characters.
     size_t iDecimalPlaces,                                     // Number of decimal places to right of decimal
     TCHAR  cDecimalSeperator,                                  // In US We Use '.'.  In Europe mostly this -- ','
     bool   blnRightJustified                                   // Left/Right Justify Result.
    );

    void Format                                                 // double converted to Str, in iArCnt Buf Size, with iDecPlaces right of dec, with cSeperator for thousands, l/r justified.
    (
     double dblNumber,                                          // double to be converted to String
     size_t iFieldSize,                                         // See above.
     size_t iDecimalPlaces,                                     // Number of decimal places to right of decimal
     TCHAR  cThousandsSeperator,                                // Period, comma, whatever
     TCHAR  cDecimalSeperator,                                  // Period, comma, whatever
     bool   blnRightJustified                                   // true is right justified; false left justified in iArraySizeCountOfObjects buffer
    );

    void Format                                                 // For integral numbers; can specify justification, field width, and seperator for thousands place
    (
     ssize_t iNumber,                                           // Integral number to format
     size_t  iFieldSize,                                        // See above.
     TCHAR   cThousandsSeperator,                               // Comma, period, whatever
     bool    blnRightJustified                                  // true is right justified; false left justified in iArraySizeCountOfObjects buffer
    );
 #endif

 #ifdef CONSOLE_IO
    void Print(bool blnCrLf);                                   // Outputs String with or without CrLf
    void Print(const TCHAR* pText, bool blnCrLf);               // Parameter #1 - leading text literal const; Parameter #2 - with/without CrLf
 #endif
 #ifdef FILE_IO
    void Print(FILE*, bool);                                    //Outputs String To FILE With Or Without CrLf.
    void Print(FILE*, TCHAR*, bool);                            //Outputs String To FILE With Leading Text String With Or Without CrLf.
    BOOL LineInput(FILE* fp);
 #endif
 ssize_t iVal();                                                // Returns integral value of String
 size_t Len();                                                  // accessor for String::iLen member
 size_t Capacity();                                             // Will be one less than underlying memory allocation
 TCHAR* lpStr();                                                // Same as std::string.c_str().  Returns pointer to underlying Z String
 ~String();                                                     // String Destructor

 private:
 TCHAR*    lpBuffer;                                            // Buffer controlled by String
 size_t    iLen;                                                // Keeps track of present length of String
 size_t    iCapacity;                                           // Keeps track of present capacity of String.  Will be one less element than length of this->lpBuffer memory allocation
 size_t    blnSucceeded;                                        // True if String Method Allocation/Invocation Succeeded; False Otherwise
};

String operator+(TCHAR* lhs, String& rhs);
String Str(double dblNum);                                      // Usage: String s1 = "Pi = " + Str(3.14159); // Output: Pi = 3.14159
#ifdef x64
   String Str(int iNum);                                        // Returns 32 bit int converted to String
   String Str(unsigned int iNum);                               // Returns 32 bit unsigned int converted to String
   String Str(SSIZE_T iNum);                                    // Returns 64 bit signed integral number converted to String
   String Str(size_t iNum);                                     // Returns 64 bit unsigned integral number converted to String
#else
   String Str(int iNum);                                        // Returns 32 bit int converted to String
   String Str(unsigned int iNum);                               // Returns 32 bit unsigned int converted to String
#endif
#endif
// End Strings.h
