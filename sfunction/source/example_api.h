#pragma once
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <Windows.h>
#include <iostream>

using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features

__declspec(dllexport) http_client api_client = http_client(L"http://127.0.0.1:8000");

__declspec(dllexport) void initializeAPI();
__declspec(dllexport) void callAPI(double& input, double& output);

__declspec(dllexport) double cachedOutput = 0.0;