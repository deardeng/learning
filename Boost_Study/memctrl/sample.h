#ifndef _SAMPLE_H_
#define _SAMPLE_H_
#include <boost/smart_ptr.hpp>


class sample
{
private:
	class impl;
	boost::shared_ptr<impl> p;
public:
	sample();
	void print();
};

#endif //_SAMPLE_H_