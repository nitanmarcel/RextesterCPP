#ifndef REXTESTERPP_REXTESTER_H
#define REXTESTERPP_REXTESTER_H

#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <vector>

using json = nlohmann::json;


namespace client{


class Client{
public:
    std::vector<std::string> rexec(std::string lang, std::string code, std::string stdin = NULL);
private:
    std::string url = "https://rextester.com/rundotnet/api";


    std::string to_compile;
    std::string response_;
    json langs_;
    json args_;
    json response_js;
    std::vector<std::string> rextester_result;

    static size_t write_response(void *ptr, size_t size, size_t count, void *stream);

    std::string languages_ = "{\n"
                             "  \"ada\": \"39\",\n"
                             "  \"bash\": \"38\",\n"
                             "  \"brainfuck\": \"44\",\n"
                             "  \"c (clang)\": \"26\",\n"
                             "  \"c (gcc)\": \"6\",\n"
                             "  \"c (vc)\": \"29\",\n"
                             "  \"c#\": \"1\",\n"
                             "  \"c++ (clang)\": \"27\",\n"
                             "  \"c++ (gcc)\": \"7\",\n"
                             "  \"c++ (vc++)\": \"28\",\n"
                             "  \"d\": \"30\",\n"
                             "  \"elixir\": \"41\",\n"
                             "  \"erlang\": \"40\",\n"
                             "  \"f#\": \"3\",\n"
                             "  \"fortran\": \"45\",\n"
                             "  \"go\": \"20\",\n"
                             "  \"haskell\": \"11\",\n"
                             "  \"java\": \"4\",\n"
                             "  \"javascript\": \"17\",\n"
                             "  \"kotlin\": \"43\",\n"
                             "  \"lisp\": \"18\",\n"
                             "  \"lua\": \"14\",\n"
                             "  \"mysql\": \"33\",\n"
                             "  \"nasm\": \"15\",\n"
                             "  \"node.js\": \"23\",\n"
                             "  \"objective-c\": \"10\",\n"
                             "  \"ocaml\": \"42\",\n"
                             "  \"octave\": \"25\",\n"
                             "  \"oracle\": \"35\",\n"
                             "  \"pascal\": \"9\",\n"
                             "  \"perl\": \"13\",\n"
                             "  \"php\": \"8\",\n"
                             "  \"postgresql\": \"34\",\n"
                             "  \"prolog\": \"19\",\n"
                             "  \"python\": \"5\",\n"
                             "  \"python 3\": \"24\",\n"
                             "  \"r\": \"31\",\n"
                             "  \"ruby\": \"12\",\n"
                             "  \"scala\": \"21\",\n"
                             "  \"scheme\": \"22\",\n"
                             "  \"sql server\": \"16\",\n"
                             "  \"swift\": \"37\",\n"
                             "  \"tcl\": \"32\",\n"
                             "  \"vb.net\": \"2\"\n"
                             "}";

    std::string compiler_args_ = "{\n"
                                 "  \"c (clang)\": \"-Wall -std=gnu99 -O2 -o a.out source_file.c\",\n"
                                 "  \"c (gcc)\": \"-Wall -std=gnu99 -O2 -o a.out source_file.c\",\n"
                                 "  \"c (vc)\": \"source_file.c -o a.exe\",\n"
                                 "  \"c++ (clang)\": \"-Wall -std=c++14 -stdlib=libc++ -O2 -o a.out source_file.cpp\",\n"
                                 "  \"c++ (gcc)\": \"-Wall -std=c++14 -O2 -o a.out source_file.cpp\",\n"
                                 "  \"c++ (vc++)\": \"source_file.cpp -o a.exe /EHsc /MD /I C:\\\\boost_1_60_0 /link /LIBPATH:C:\\\\boost_1_60_0\\\\stage\\\\lib\",\n"
                                 "  \"d\": \"source_file.d -ofa.out\",\n"
                                 "  \"go\": \"-o a.out source_file.go\",\n"
                                 "  \"haskell\": \"-o a.out source_file.hs\",\n"
                                 "  \"objective-c\": \"-MMD -MP -DGNUSTEP -DGNUSTEP_BASE_LIBRARY=1 -DGNU_GUI_LIBRARY=1 -DGNU_RUNTIME=1 -DGNUSTEP_BASE_LIBRARY=1 -fno-strict-aliasing -fexceptions -fobjc-exceptions -D_NATIVE_OBJC_EXCEPTIONS -pthread -fPIC -Wall -DGSWARN -DGSDIAGNOSE -Wno-import -g -O2 -fgnu-runtime -fconstant-string-class=NSConstantString -I. -I /usr/include/GNUstep -I/usr/include/GNUstep -o a.out source_file.m -lobjc -lgnustep-base\"\n"
                                 "}";
        };
}

#endif //REXTESTERPP_REXTESTER_H
