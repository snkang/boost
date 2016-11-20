/*
 * From : http://www.cplusplus.com/reference/regex/regex_search/
 */


// regex_search example
#include <QCoreApplication>
#include <iostream>
#include <string>
#include <regex>

int main(int argc, char *argv[])
{
    std::string s ("this subject has a submarine as a subsequence");
    std::smatch m;
    std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

    std::cout << "Target sequence: " << s << std::endl;
    std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
    std::cout << "The following matches and submatches were found:" << std::endl;

    while (std::regex_search (s,m,e)) {
        for (auto x:m) std::cout << x << " ";
        std::cout << std::endl;
        s = m.suffix().str();
    }

    QCoreApplication a(argc, argv);
    return a.exec();
}
