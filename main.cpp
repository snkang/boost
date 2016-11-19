#include <QCoreApplication>
#include <boost/regex.hpp>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
    fstream file("jayne.txt", fstream::in );
    string text;
    getline( file, text, '\0');

    //    boost::u32regex r = boost::make_u32regex("(?:\\A|.*\\\\)([^\\\\]+)");
    //    boost::regex pat( "(?<Protocol>\\w+):\\/\\/(?<Domain>[\\w@][\\w.:@]+)\\/?[\\w\.?=%&=\-@/$,]*" );
    //    boost::regex pat( "^From: (Re: |Aw: )*(.*)" );
//    regex pat( "Subject: (Re: |Aw: )*(.*)" );
    //    regex pat( "(http(|s):\\/\\/).+(?=\"\\B)" );
    //    regex pat( "http(.*)" );
//    regex pat( "\^\<A HREF\=\"(http\:\/\/.+)" );
    //    regex pat( "(?<Protocol>\w+)://(?<Domain>[\w@][\w.:@]+)/?[\w\.?=%&-@/$,]*" );
    //                (?<Protocol>\w+):\/\/(?<Domain>[\w@][\w.:@]+)\/?[\w\.?=%&=\-@/$,]*
//    regex pat( "(?<Protocol>\w+)\:\/\/.*" );
//    regex pat( "\b(\w.+)\b" );
//    regex pat( "(^To:\\s\\bGeorge\\b\\s\\bShmidlap\\b)(\\sFrom:\\s\\bRita\\b\\s\\bMarlowe\\b).*" );
    regex pat( ".*((?<Protocol>http|ftp|file)\:\/\/(?<Domain>[\\w\@][\\w\.\:\@]+)(\/\?[\\w\\.?=%&-@/$,]*)).*" );
    smatch m;

    cout << "\n--------------------- Input text ----------------------" << endl;
    cout << text << endl;
    cout << "\n--------------------- Pattern ----------------------" << endl;
    cout << pat << endl;
    cout << "\n--------------------- Match results ----------------------" << endl;

    if (regex_match(text, m, pat)) {
        cout << "Size : " << m.size() << "(The total number of '()'s in pattern.)" << endl;
        cout << "m[0] = Whole input text." << endl;
        cout << "m[1] = Final Match result(The result of the first '()' in pattern)." << endl;
        cout << "m[2] = Sub Match result(The result of the second '()' in pattern, (Protocol))." << endl;
        cout << "m[3] = Sub Match result(The result of the third '()' in pattern, (Domain))." << endl;
        cout << "m[4] = Sub Match result(The result of the fourth '()' in pattern, (parameters)).\n" << endl;
    cout << "\n----------------------------------------------------------------" << endl;
        if ( m.empty() == false ) {
            cout << "# m.empty() : false" << endl;
            for (int i=0; i<m.size(); i++) {
                cout << "# m[" << i << "] : \n" << m[i] << endl;
                //                    cout << "m[" << i << "].first : " << m[i].first << endl;
                //                    cout << "m[" << i << "].second : " << m[i].second << endl;
                //                    cout << "m[" << i << "].matched : " << m[i].matched << endl;
            }
        } else cout << ", m.empty() : true" << endl;
    } else {
        cout << "Match is not found!\n" << endl;
    }

    file.close();
    QCoreApplication a(argc, argv);
    return a.exec();
}
