//Tested on C++17, Ubuntu Mate x64, Intel Compiler, Code::Blocks 20.03
#include "AlgorytmAIV01.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include <random>

//-----------------------------


void appendStringToFile(const std::filesystem::path filename, const std::string& content, const unsigned int milisecond_delay, bool output_success)
{
    std::ofstream file(filename, std::ios_base::app);
    if (file.is_open())
    {
        file << content << " ";
        std::chrono::milliseconds duration(milisecond_delay);
        std::this_thread::sleep_for(duration);

        file.close();
        if (output_success==true)
        {
            std::cout << "String " << content << " appended to file " << filename << " successfully." << std::endl;
        }

    }
    else
    {
        std::cerr << "Error: Unable to open file " << content << " for appending." << std::endl;
    }
}


//-----------------------------


void algorytmv01train(const std::filesystem::path source_path, const std::filesystem::path destination_path, bool output_success, const unsigned int milisecond_delay)
{
    std::vector<std::filesystem::path> pliki;
    for (const auto& entry : std::filesystem::directory_iterator(source_path))
    {
        if (std::filesystem::is_regular_file(entry.path()))
        {
            pliki.push_back(entry.path().filename());
        }
    }
    std::cout<<"Training started..."<<std::endl;
    std::string word;
//std::string old_word = "[old_word_var]";
    std::string new_word = "[new_word_var]";
    std::filesystem::path old_word_path;
    for (std::filesystem::path s : pliki)
    {
        std::ifstream file(source_path/s);
        bool first_iter_done = false;

        while (file >> word)
        {
            //std::cout << word << std::endl;
            old_word_path = new_word;
            new_word = word;
            if (first_iter_done==true)
            {
                appendStringToFile(destination_path/old_word_path,new_word,milisecond_delay,output_success);
            }
            else
            {
                first_iter_done = true;
            }

        }
        file.close();
    }
    std::cout<<std::endl<<"Training done."<<std::endl;
}


//-----------------------------


std::string getlastword(const std::string& text)
{
    std::vector<std::string> text_vec;
    std::string word;
    std::istringstream iss(text);
    while (iss >> word)
    {
        text_vec.push_back(word);
    }
    if (text_vec.size()<1)
    {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(34,125);
    char znak = static_cast<char>(distribution(gen));
    std::string znak_string(1, znak);
    word = znak_string;

    } else {
    word = text_vec[text_vec.size()-1];
    }
    text_vec.clear();
    return word;
}


//-----------------------------


std::filesystem::path getrandompath(const std::filesystem::path path)
{
    std::vector<std::string> files;
    std::filesystem::path plik;
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        if (std::filesystem::is_regular_file(entry.path()))
        {
            files.push_back(entry.path().string());
        }
    }
    //std::cout<<files.size()<<std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, files.size()-1);
    plik = files[distribution(gen)];
    files.clear();
    //std::cout<<plik<<std::endl;
    return plik;
}


//-----------------------------


std::string getrandompathvect(const std::vector<std::string>& vect)
{
    std::string plik;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, vect.size()-1);
    plik = vect[distribution(gen)];
    return plik;

}


//-----------------------------


std::string algorytmv01generatewords(const std::filesystem::path model_path, std::string& text, const unsigned int words)
{

    std::string nowy_tekst = "";
    std::string last_word;
    std::filesystem::path filePath;

    std::vector<std::string> zawartosc;
    std::string word;

    for (unsigned int i=0; i < words; i++)
    {
        last_word = getlastword(text);
        filePath = last_word;
        if (!(std::filesystem::exists(model_path/filePath) && std::filesystem::is_regular_file(model_path/filePath)))
        {
            filePath = getrandompath(model_path);
        }
        else
        {
            filePath = model_path/filePath;
        }
        //std::cout<<filePath<<std::endl;

        std::ifstream file(filePath);

        while (file >> word)
        {
            zawartosc.push_back(word);
        }
        file.close();
        word = getrandompathvect(zawartosc);
        zawartosc.clear();
        //std::cout<<word;
        nowy_tekst = nowy_tekst + " " + word;
        text = text + " " + word;

    }
    return nowy_tekst;
}
