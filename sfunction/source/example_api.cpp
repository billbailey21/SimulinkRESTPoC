#include "example_api.h"

using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features

void initializeAPI(std::string apiAddress) {
	//Convert address into wide wstring using Windows built-in function (assume UTF-8)
	int wchars_num = MultiByteToWideChar(CP_UTF8, 0, apiAddress.c_str(), -1, NULL, 0);
	wchar_t* apiAddressWide = new wchar_t[wchars_num];
	MultiByteToWideChar(CP_UTF8, 0, apiAddress.c_str(), -1, apiAddressWide, wchars_num);
	
	// Create HTTP client object to be used for API calls
	api_client = http_client(apiAddressWide);
}

void callAPI(double& input_value, double& output_value) {
	// Build request URI and start the request.
	uri_builder builder(U("/mvp/sqrt"));
	std::wstring input_value_str = std::to_wstring(input_value);
	const wchar_t* check = input_value_str.c_str();
	builder.append_query(U("value"), check); // input_value_str);

	// Make GET request to retrieve value; skip async for now
	web::json::value response = api_client.request(methods::GET, builder.to_string()).get().extract_json().get();
	
	// Pull "value" attribute out of JSON response as a double
	output_value = response.at(utility::conversions::to_string_t("value")).as_double();
}

int main() {
	initializeAPI("http://127.0.0.1:8000");
	double input_value = 2.0;
	double output_value;
	callAPI(input_value, output_value);
	printf("Input: %f, Output: %f", input_value, output_value);
}