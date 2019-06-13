//g++ main.cpp -o main -llog4cpp -pthread
//export LD_LIBRARY_PATH=/usr/local/lib
//g++ main.cpp -o main -llog4cpp -pthread -L/usr/local/lib -I/usr/local/include
//-L/lib_Path
//-I/include_Path
//-llibname
#include<iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>



// 输出到std::cout
//log4cpp::Appender *appender = new log4cpp::OstreamAppender("root", &std::cout);
// 输出到log文件
log4cpp::Appender *appender = new log4cpp::FileAppender("root", "test.log");

#define LOG(__level) log4cpp::Category::getRoot() << log4cpp::Priority::__level << __FILE__ << " " << __LINE__ << ": "

int main()
{
    log4cpp::PatternLayout *patternLayout = new log4cpp::PatternLayout();
    patternLayout->setConversionPattern("%d [%p] - %m%n");
    appender->setLayout(patternLayout);


    log4cpp::Category &root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::INFO);
    root.addAppender(appender);


    LOG(DEBUG) << "i am happy.";
    LOG(INFO)  << "oh, you happy, we happy.";
    LOG(NOTICE)<< "please do not contact me. ";
    LOG(WARN)  << "i am very busy now.";
    LOG(ERROR) << "oh, what happed?";

    return 0;
}
