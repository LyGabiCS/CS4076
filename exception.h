#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using std::string;

// REQUIREMENT - NAMESPACES
namespace exception
{
    class MyException : public std::exception{

    public:

//INLINE EXCEPTION HANDLER
const char * noRoom() throw () {return "There is no room here!";}

    };
}

#endif // EXCEPTION_H
