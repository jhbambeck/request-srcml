/*
  @file request_srcml.cpp
  Implementation of request_srcml()
*/

#include "request_srcml.hpp"
#include "get_language_from_filename.hpp"

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request) {

    std::string filename;
    if(request.option_filename != "")//if there's an option_filename use it
    {
        filename = request.option_filename;
    }

    else if(request.entry_filename == "data")
    {
        if(request.local_filename != "-")
        {
            filename = request.local_filename;
        }

        else
        {
            filename = "";
        }
    }

    else
    {
        filename = request.entry_filename;
    }

    return filename;
}

// extracts the language to use from the request, and the filename
std::string request_language(const srcml_request& request, const std::string& filename) {

    std::string language;
    if(request.option_language != "")
    {
        language = request.option_language;
    }
    else
    {
        language = get_language_from_filename(filename);
    }

    return language;
}

// generates srcML based on the request
bool generate_srcml(const srcml_request& request) {

	std::string filename = request_filename(request);

	std::string language = request_language(request, filename);

	if(language != "")
    {
        return true;
    }

	// srcML generation code that is not available yet
}
