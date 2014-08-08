#ifndef _DEBUG_NEW_H_
#define _DEBUG_NEW_H_
#include "Tracer.h"
#ifndef NDEBUG
#define  new new(__FILE__,__LINE__)
#endif//NDEBUG
#endif//_DEBUG_NEW_H_