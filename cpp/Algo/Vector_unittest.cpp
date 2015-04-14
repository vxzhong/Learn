#include "Vector.h"
#include "gmock/gmock.h"

TEST(DefaultInit, Init)
{
	Vector<int> vec;
	ASSERT_TRUE(vec.size() == 0);
}

