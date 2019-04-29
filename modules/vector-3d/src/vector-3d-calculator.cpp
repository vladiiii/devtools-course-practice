// Copyright 2019 Soluyanov Alexsey

#include "include/vector_3d.h"
#include "include/vector-3d-calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

VectorCalculator::VectorCalculator() : message_("") {}

void VectorCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a vector-3d calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <x1> <y1> <z1> " +
          "<x2> <y2> <z2> <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of '+', '-', '*'.\n";
}

bool VectorCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "ERROR: Should be 7 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string VectorCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.x1 = parseDouble(argv[1]);
        args.y1 = parseDouble(argv[2]);
        args.z1 = parseDouble(argv[3]);
        args.x2 = parseDouble(argv[4]);
	args.y2 = parseDouble(argv[5]);
	args.z2 = parseDouble(argv[6]);
        args.operation = parseOperation(argv[7]);
    }
    catch(std::string& str) {
        return str;
    }

    Vector3d v1;
    Vector3d v2;

    v1.setX(args.x1);
    v1.setY(args.y1);
    v1.setZ(args.z1);
    v2.setX(args.x2);
    v2.setY(args.y2);
    v2.setZ(args.z2);

    Vector3d v;
    double res;
    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        v = v1 + v2;
        stream << "X = " << v.getX() << " "
               << "Y = " << v.getY() << " "
	       << "Z = " << v.getZ() << "\n";
        break;
     case '-':
        v = v1 - v2;
        stream << "X = " << v.getX() << " "
               << "Y = " << v.getY() << " "
	       << "Z = " << v.getZ() << "\n";
        break;
     case '*':
        res = v1 * v2;
        stream << "Result = " << res << "\n";
        break;
    }
    message_ = stream.str();

    return message_;
}

