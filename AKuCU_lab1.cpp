// AKuCU_lab1.cpp
// читать с начала и в main

#include <iostream>
#include <map>
#include <fstream>


using namespace std;
//читать тут.





int main(int argc, char* argv[]){
    // для начала надо определиться с хранением данных о каждом символе. Самым подходящим вариантом является словарь(map).
    map<char, unsigned int> counter;
    //теперь надо открыть фаил и посчитать колличество символов

    //блок считывания повторений символов
    ifstream in;       // поток для чтения
    in.open("micro_original.txt"); // открываем файл для чтения
    for (; !(in.eof());) {// пока фаил не закончился
        char c = in.get(); // берем 1 символ из файла
        counter[c]++; // увеличиваем значение частоты символа в словаре
    }
    in.close();//закрываем. Он закончился
    cout << counter['c'] << endl;//вывели произвольный символ





    cout << "Hello World!\n";
    return 0;
}

