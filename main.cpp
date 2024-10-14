//Tested on C++17, Ubuntu Mate x64, Intel Compiler, Code::Blocks 20.03
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>
#include <sstream>
#include <random>

#include "AlgorytmAIV01.h"

int main()
{
    std::filesystem::path wejscie = "books_txt_folder";
    std::filesystem::path wyjscie = "model_folder";
    std::string tekst = "Start string here";
    std::string nowytekst;

    //algorytmv01train(wejscie, wyjscie, true);
    //return 0;

    unsigned int n=0;
    unsigned int limit = 400;
    std::cout<<tekst;
    while (n<limit)
    {
        nowytekst = algorytmv01generatewords(wyjscie, tekst, 1);
        //std::cout<<tekst<<std::endl<<std::endl;
        std::cout<<nowytekst<<std::flush;
        std::chrono::milliseconds duration(10); //Delay for ChatGPT visual effect //Opoznienie dla efektu a'la ChatGPT
        std::this_thread::sleep_for(duration);
        n=n+1;
    }

    std::cout << std::endl << std::endl << "[koniec programu]" << std::endl;
    return 0;
}
