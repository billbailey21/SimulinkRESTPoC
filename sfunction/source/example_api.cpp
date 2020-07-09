#include "example_api.h"

//using namespace utility;                    // Common utilities like string conversions
//using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
//using namespace concurrency::streams;       // Asynchronous streams

void initializeAPI() {
	api_client = http_client(L"http://127.0.0.1:8000");
}

void callAPI(double& input_value, double& output_value) {
	// Build request URI and start the request.
	uri_builder builder(U("/mvp/sqrt"));
	std::wstring input_value_str = std::to_wstring(input_value);
	const wchar_t* check = input_value_str.c_str();
	builder.append_query(U("value"), check); // input_value_str);
	//const wchar_t* val = U("abc");

	web::json::value response = api_client.request(methods::GET, builder.to_string()).get().extract_json().get();
	output_value = response.at(utility::conversions::to_string_t("value")).as_double();
	cachedOutput = output_value;
}

int main() {
	// Source for client library: https://github.com/yhirose/cpp-httplib
	initializeAPI();
	double input_value = 2.0;
	double output_value;
	callAPI(input_value, output_value);
	printf("Got a response");
}