#include <cstddef>
#include <algorithm>
#include <stdexcept>

#include <boost/operators.hpp>
#include <boost/assert.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/config.hpp>
#include <vector>
namespace boost
{
	template<typename T>
	class ref_array : private boost::totally_ordered<ref_array<T> >
	{
	private:
		T* elems;
		std::size_t N;
	public:

		//type definitions
		typedef T				value_type;
		typedef T*				iterator;
		typedef	const T*		const_iterator;
		typedef T&				reference;
		typedef const T&		const_reference;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t	difference_type;

		//iterator support
		iterator begin(){return elems;}
		const_iterator begin() const{return elems;}
		iterator end() {return elems+N;}
		const_iterator end() const{return elems+N;}

		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		reverse_iterator rbegin() {return reverse_iterator(end());}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(begin());
		}

		//operator[]
		reference operator[](size_type i)
		{
			BOOST_ASSERT(i < N && "out of range");
			return elems[i];
		}
		const_reference operator[](size_type i)const
		{
			BOOST_ASSERT(i < N && "out of range");
			return elems[i];
		}

		//check range (may be private because it is static)
		void rangecheck(size_type i)
		{
			if(i >= size())
			{
				throw std::out_of_range("ref_array<>: index out of range");
			}
		}
		//at() with range check
		reference at(size_type i){rangecheck(i); return elems[i];}
		const_reference at(size_type i)const{rangecheck(i); return elems[i];}

		//front() and back()
		reference front()
		{
			return elems[0];
		}
		const_reference front() const
		{
			return elems[0];
		}
		reference back()
		{
			return elems[N-1];
		}
		const_reference back() const
		{
			return elems[N-1];
		}

		//size is constant
		size_type size() const {return N;}
		bool empty() const{return false;}
		size_type max_size() const{return N;}

		void resize(size_type n)
		{
			//only shrink allowed
			BOOST_ASSERT(n <= N);
			N = n;
		}

		//direct access to data(read-only)
		const T* data() const{return elems;}
		T* data(){return elems;}

		//use array as C array (direct read/write access to data)
		T* c_array(){return elems;}

		//assign one value to all elements
		void assign(const T& value)
		{
			std::fill_n(begin(), size(), value);
		}
		template<typename Cont>
		void assign(/*const*/ Cont& from)
		{
			std::copy(from.begin(), from.end(), begin());
		}
		template<typename Cont>
		void operator=(/*const*/ Cont& from)
		{
			assign(from);
		}

		//swap
		void swap(ref_array<T>& y)
		{
			std::swap(elems, y.elems);
			std::swap(N, y.N);
		}

		explicit ref_array(T *arr, std::size_t n) : elems(arr), N(n)
		{
			BOOST_ASSERT(arr != NULL && "array is null");
		}
		~ref_array(){}
	};

	//comparisons
	template<class T>
	bool operator==(const ref_array<T>& x, const ref_array<T>& y)
	{
		return x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin());
	}
	template<class T>
	bool operator< (const ref_array<T>& x, const ref_array<T>& y)
	{
		return std::lexicographical_compare(x.begin, x.end(), y.begin(), y.end());
	}

	//global swap()
	template<class T>
	inline void swap(ref_array<T>& x, ref_array<T>& y)
	{
		x.swap(y);
	}

	template<typename T>
	class cref_array : boost::totally_ordered<cref_array<T> >
	{
	private:
		const T* elems;
		std::size_t N;
	public:
		//type definitions
		typedef T				value_type;
		typedef T*				iterator;
		typedef const T*		const_iterator;
		typedef T&				reference;
		typedef const T&		const_reference;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t	difference_type;
		
		//const iterator support
		const_iterator begin() const {return elems;}
		const_iterator end() const {return elems + N;}

		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		//operator[]
		const_reference operator[] (size_type i) const
		{
			BOOST_ASSERT(i < N && "out of range");
			return elems[i];
		}

		//check range (may be private because it is static)
		void rangecheck(size_type i)const
		{
			if(i >= size())
			{
				throw std::out_of_range("cref_array<>: index out of range");
			}
		}

		//at() with range check
		const_reference at(size_type i)const{rangecheck(i); return elems[i];}

		//front() and back()
		const_reference front() const
		{
			return elems[0];
		}

		const_reference back() const
		{
			return elems[N-1];
		}

		//size is constant
		size_type size() const{return N;}
		bool empty() const{return false;}
		size_type max_size() const{return N;}

		//direct access to data (read-only)
		const T* data() const {return elems;}

		//use array as C array (direct read access to data)
		const T* c_array() {return elems;}

		//swap
		void swap(cref_array<T>& y)
		{
			std::swap(elems, y.elems);
			std::swap(N, y.N);
		}

		explicit cref_array(const T *arr, std::size_t n) : elems(arr), N(n)
		{
			BOOST_ASSERT(arr != NULL && "array is null");
		}
		~cref_array(){}
	};

	//comparisons
	template<class T>
	bool operator==(const cref_array<T>& x, const cref_array<T>& y)
	{
		return x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin());
	}
	template<class T>
	bool operator< (const cref_array<T>& x, const cref_array<T>& y)
	{
		return std::lexicographical_compare(x.begin(), x.end(), y.begin, y.end());
	}

	//global swap()
	template<class T>
	inline void swap(cref_array<T>& x, cref_array<T>& y)
	{
		x.swap(y);
	}
}//boost namespace


//test
void xor(unsigned char *buf, int buf_len)
{
	boost::ref_array<unsigned char> ra(buf, buf_len);

	for(BOOST_AUTO(pos, ra.begin()); pos!=ra.end(); ++pos)
	{
		*pos ^= 0x5a;
	}
}

int main()
{
	unsigned char szInt[10];
	boost::ref_array<unsigned char> ra(szInt, 10);

	std::vector<char> a;
	a.reserve(10);
	for(int i=65; i<70; i++)
		a.push_back(i);

	ra.assign(a);
	ra = a;
	ra.assign(100);
	ra[0] = 25;
	

	assert(ra.front() == 25);

	xor(ra.c_array(), ra.size());
}