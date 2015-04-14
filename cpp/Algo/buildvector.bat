set GMOCK=../gmock
set GTEST=../gmock/gtest

call "%VS120COMNTOOLS%..\..\VC\vcvarsall.bat" x86

cl /I%GMOCK% /I%GTEST%/include Vector_unittest.cpp %GMOCK%/gmock_main.cc %GMOCK%/gmock-gtest-all.cc ws2_32.lib psapi.lib iphlpapi.lib advapi32.lib

PAUSE
