
set GMOCK=e:/gmock-1.7.0
set GTEST=e:/gmock-1.7.0/gtest

g++ -g -isystem %GMOCK%/include -isystem %GTEST%/include -L%GMOCK%/lib -L%GTEST%/lib -lgmock_main -Wall -std=c++11 SoundexTest.cpp -o SoundexTest
