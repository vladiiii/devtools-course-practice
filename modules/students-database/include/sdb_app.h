// Copyright 2019 Kutovoi Vadim


#ifndef DEVTOOLS_SDB_APP_H
#define DEVTOOLS_SDB_APP_H

class SdbApp {
        public:
        SdbApp();
        std::string operator()(int argc, const char** argv);
        std::string Help(const char* appname);

        private:
        std::string message_;

};

#endif //DEVTOOLS_SDB_APP_H
