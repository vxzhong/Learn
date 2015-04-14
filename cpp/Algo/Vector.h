#ifndef __VECTOR_H__
#define __VECTOR_H__ __VECTOR_H__

template <typename T>
class Vector
{
public:
#define D_VECTOR_DEFAULT_CAP 8
	typedef int pos_type;
	Vector(size_t cap=D_VECTOR_DEFAULT_CAP) : size_(0), capacity_(cap), elem_(new T[cap]){}
	Vector(const T *that, pos_type begin, pos_type end) {
		copyFrom(that, begin, end);
	}
	Vector(const Vector& that) {copyFrom(that.elem(), 0, that.size());}
	Vector& operator=(const Vector& that) {
		if (that != this) {
			copyFrom(that.elem(), 0, that.size());
		}
		return *this;
	}
	~Vector() { delete [] elem_;}

	size_t size() const {return size_;}
	size_t capacity() const {return capacity_;}
	const T* elem() const {return elem_;}

private:
	void expand() {
		if (size_ < capacity_) { return;}
		size_t new_cap = capacity_ << 2;
		T *new_elem = new T[new_cap];
		for (int i = 0; i < size_; ++i) {
			new_elem[i] = elem_[i];
		}

		delete [] elem_;

		capacity_ = new_cap;
		elem_ = new_elem;
	}

	void copyFrom(const T *that, pos_type begin, pos_type end) {
		if (capacity_ < (end - begin)) {
			expand();
		}

		size_ = 0;
		pos_type iter = begin;
		while (iter < end) {
			elem_[size_++] = that[iter++];
		}
	}

	size_t size_;
	size_t capacity_;
	T *elem_;
};

#endif

