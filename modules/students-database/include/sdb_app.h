// Copyright 2019 Kutovoi Vadim


#ifndef DEVTOOLS_SDB_APP_H
#define DEVTOOLS_SDB_APP_H

class SdbApp {
        public:
        SdbApp();
        std::string operator()(int argc, const char** argv);

        private:
        void Help(const char* appname, const char* message = "");
        bool ValidateNumberOfArguments(int argc, const char** argv);
        std::string message_;
        typedef struct {
            std::string fname;
            std::string lname;
            unsigned int mark;
        } Arguments;

};

#endif //DEVTOOLS_SDB_APP_H
