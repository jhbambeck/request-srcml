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

    return 0;
}
