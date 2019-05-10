// Copyright 2019 Kutovoi Vadim

#include "include/sdb.h"
#include "include/sdb_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

SdbApp::SdbApp() : message_("") {}

void SdbApp::Help(const char* appname, const char* message) {
    message_ =
            std::string(message) +
            "This is a Student database application.\n\n" +
            "Please provide arguments in the following format:\n\n"+

            "  $ " + appname + " <price> <nominal_price> " +
            "<months> <year> <percentage> <current_year> " +
            "<current_month> <metric>\n\n";
}

bool SdbApp::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 8) {
        Help(argv[0], "ERROR: Should be 7 arguments.\n\n");
        return false;
    }
    return true;
}

int ParseInteger (const char* arg) {
    int tmp = atoi(arg);

    if (tmp < 0) {
        throw std::string("Wrong number format!");
    }

    return tmp;
}

std::string ParseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "total") == 0) {
        op = "GET_NUMBER_STUDENTS";
    } else if (strcmp(arg, "good") == 0) {
        op = "GET_GOOD_STUDENTS";
    } else if (strcmp(arg, "bad") == 0) {
        op = "GET_BAD_STUDENTS";
    } else if (strcmp(arg, "add") == 0) {
        op = "ADD_STUDENT";
    } else if (strcmp(arg, "remove") == 0) {
        op = "REMOVE_STUDENT";
    } else if (strcmp(arg, "mark") == 0) {
        op = "ADD_MARK";
    } else if (strcmp(arg, "average") == 0) {
        op = "GET_AVG_MARK";
    } else {
        throw std::string("Wrong metric!");
    }
    return op;
}

std::string SdbApp::operator()(int argc, const char** argv) {
    Arguments args;
    Sdb database_;
    if (argc == 2) {
        std::string operation = ParseOperation(argv[1]);
        if (operation == "GET_GOOD_STUDENTS") {
            database_.GetNumberOfGoodStudents();
        } else if (operation == "GET_BAD_STUDENTS") {
            database_.GetNumberOfBadStudents();
        } else if (operation == "GET_TOTAL_STUDENTS") {
            database_.GetNumberOfStudents();
        } else {
            throw "Number of arguments and " +
                  "operation is incompatible";
        }
    } else if (argc == 3) {

    }

        try {
        args.fname = (argv[1]);
        args.lname = (argv[2]);
        args.mark  = ParseInteger(argv[3]);
    } catch(std::string& str) {
        return str;
    }

    return message_;
}
//
//    if (!ValidateNumberOfArguments(argc, argv)) {
//        return message_;
//    }
//
//    catch(std::string& str) {
//        return str;
//    }

//    BondCalculator bcalc;
//    bond bond_;
//    std::vector<int> mnths = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//
//    bond_.price = args.price;
//    bond_.nominal_price = args.nominal_price;
//    bond_.year = args.year;
//    bond_.percentage = args.percentage;
//    bond_.months = mnths;

//    std::ostringstream stream;

//    if (args.metric == "all") {
//        std::vector<payment> payments =
//                bcalc.CalculatePayments(bond_,
//                                        args.current_month,
//                                        args.current_year);
//        payment totalIncome =
//                bcalc.CalculateTotalIncome(bond_,
//                                           args.current_month,
//                                           args.current_year);

//        stream << "Payments : " << std::endl;
//        for (auto i : payments) {
//            stream << "\tYear : " << i.year <<
//                   " Month : " << i.month <<
//                   " Value : " << i.value << std::endl;
//        }
//
//        stream << "Relative income : " << std::endl <<
//               "\t" <<
//               bcalc.CalculateRelativeIncome(bond_,
//                                             args.current_month,
//                                             args.current_year)
//               << std::endl;
//
//        stream << "Total Income : " << std::endl <<
//               "\tYear : " << totalIncome.year << std::endl <<
//               "\tMonth : " << totalIncome.month << std::endl <<
//               "\tValue : " << totalIncome.value << std::endl;
//
//        stream << "Yearly internal income :" << std::endl <<
//               "\t" <<
//               bcalc.CalculateYearlyInternalIncome(bond_,
//                                                   args.current_year)
//               << std::endl;
//    } else if (args.metric == "payments") {
//        std::vector<payment> payments =
//                bcalc.CalculatePayments(bond_,
//                                        args.current_month,
//                                        args.current_year);
//
//        stream << "Payments : " << std::endl;
//        for (auto i : payments) {
//            stream << "\tYear : " << i.year <<
//                   " Month : " << i.month <<
//                   " Value : " << i.value << std::endl;
//        }
//    } else if (args.metric == "relative") {
//        stream << "Relative income : " << std::endl <<
//               "\t" <<
//               bcalc.CalculateRelativeIncome(bond_,
//                                             args.current_month,
//                                             args.current_year)
//               << std::endl;
//    } else if (args.metric == "yearly") {
//        stream << "Yearly internal income :" << std::endl <<
//               "\t" <<
//               bcalc.CalculateYearlyInternalIncome(bond_,
//                                                   args.current_year)
//               << std::endl;
//    } else if (args.metric == "total") {
//        payment totalIncome =
//                bcalc.CalculateTotalIncome(bond_,
//                                           args.current_month,
//                                           args.current_year);
//
//        stream << "Total income : " << std::endl <<
//               "\tYear : " << totalIncome.year << std::endl <<
//               "\tMonth : " << totalIncome.month << std::endl <<
//               "\tValue : " << totalIncome.value << std::endl;
//    }
//
//    message_ = stream.str();

//    return message_;

