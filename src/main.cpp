#include <iostream>
#include "Transpiler/transpiler.hpp"

int main ()
{
	Transpiler transp;
	transp.transpile("LuaFiles/test1.lua");
	transp.transpile("testname");
}
