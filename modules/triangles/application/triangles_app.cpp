// Copyright 2019 Valiullin Damir

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/triangles_application.h"

int main(int argc, const char** argv) {
	TrianglesApp app;
	std::string output = app(argc, argv);
	printf("%s\n", output.c_str());
	return 0;
}
