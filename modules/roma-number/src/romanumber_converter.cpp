// Copyright 2019 Pinaev Danil

#include "include/romanumber.h"
#include "include/romanumber_converter.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

RomaNumberConverter::RomaNumberConverter() : message_("") {}

void RomaNumberConverter::help(const char* message) {
	message_ =
		std::string(message) +
		"This is a roma number converter application.\n\n" +
		"Please provide arguments in the following format:\n\n" +

		"  $ " + " <roma_number> or <araqbic number> " +

		"Where argument is ineger number or roma number \n";
}

bool RomaNumberConverter::validateNumberOfArguments(int argc, const char** argv) {
	if (argc != 1) {
		help("ERROR: Should be 1 argument.\n\n");
		return false;
	}

	return true;
}

std::string parseRoma(const char* arg) { return std::string(arg); }

int parseArab(const char* arg) { return atoi(arg); }

std::string RomaNumberConverter::operator()(int argc, const char** argv) {
	RomaNumber converter;
	std::ostringstream stream;

	if (!validateNumberOfArguments(argc, argv)) {
		return message_;
	}

	if (converter.IsArabStringCorrect(argv[1])) {
		try {
			converter.ArabToRoma(atoi(argv[1]));
		}
		catch (std::string& str) {
			return str;
		}
		stream << "Roma number is " << converter.GetRoma() << std::endl;
	}

	if (converter.IsRomaStringCorrect(argv[1])) {
		try {
			converter.RomaToArab(std::string(argv[1]));
		}
		catch (std::string& str) {
			return str;
		}
		stream << "Arabic number is " << converter.GetArabic() << std::endl;
	}
	message_ = stream.str();

	return message_;
}