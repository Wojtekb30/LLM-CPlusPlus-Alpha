//Tested on C++17, Ubuntu Mate x64, Intel Compiler, Code::Blocks 20.03
#ifndef ALGORYTMAIV01_H
#define ALGORYTMAIV01_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include <random>

void appendStringToFile(const std::filesystem::path filename, const std::string& content, const unsigned int milisecond_delay=0, bool output_success = false); //utility

void algorytmv01train(const std::filesystem::path source_path, const std::filesystem::path destination_path, bool output_success = false, const unsigned int milisecond_delay=0);

std::string getlastword(const std::string& text); //utility

std::filesystem::path getrandompath(const std::filesystem::path path); //utility

std::string getrandompathvect(const std::vector<std::string>& vect); //utility

std::string algorytmv01generatewords(const std::filesystem::path model_path, std::string& text, const unsigned int words);

#endif // ALGORYTMAIV01_H
