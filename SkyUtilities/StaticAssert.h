#pragma once

// copied from https://stackoverflow.com/questions/13837668/display-integer-at-compile-time-in-static-assert

template <int64_t V1, int64_t V2> struct AssertEquality
{
	static const uint8_t not_equal_warning = 257; // (uint8_t)257 == (uint8_t)1
};

template <int64_t V> struct AssertEquality<V, V>
{
	static const uint8_t not_equal_warning = 0;
};

#define STATIC_ASSERT_EQ(V1, V2) static_assert( \
    AssertEquality<static_cast<int64_t>(V1), \
                   static_cast<int64_t>(V2)>::not_equal_warning == 0, \
    #V1 " != " #V2 );
