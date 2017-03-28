/*
  @file request_srcml_t.cpp
  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

	// all filenames and languages empty
    {
    	srcml_request request = { "", "", "", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
    }

    //request_filename

    //request_filename works if option_filename provided
    {
        srcml_request request = { "file.cpp", "", "", ""};
    	assert(request_filename(request) == "file.cpp");
    }

    //request_filename returns entry_filename if no option_filename
    {
        srcml_request request = { "", "", "entry.file", ""};
        assert(request_filename(request) == "entry.file");
    }

    //request_filename returns local_filename if entry_filename is "data"
    {
        srcml_request request = { "", "local.file", "data", ""};
        assert(request_filename(request) == "local.file");
    }

    //request_filename returns option_filename if all three provided
    {
        srcml_request request = {"option.file", "local.fie", "data", ""};
        assert(request_filename(request) == "option.file");
    }

    //request_language returns option_language
    {
        srcml_request request = {"option.file", "local.file", "data", "option_language"};
        assert(request_language(request, request_filename(request)) == "option_language");
    }

    //request_language gets lang from get_language_from_filename if no option_filename
    {
        srcml_request request = {"option.cpp", "local.file", "data", ""};
        assert(request_language(request, request_filename(request)) == "C++");
    }

    //local_filename is from stdin, entry_filename is "data", no option_filename
    {
        srcml_request request = {"", "-", "data", ""};
        assert(request_filename(request) == "");
    }

    return 0;
}
