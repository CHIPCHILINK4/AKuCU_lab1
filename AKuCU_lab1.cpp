// AKuCU_lab1.cpp
// читать c main

#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;


struct HaffCodeNode{//произвольный узел
    char sumbol;//символ
    int freq;//сколько раз он повторился
    HaffCodeNode* left, * right;//листья для данного узла
    HaffCodeNode(char ch, int count) {// конструктор1 для листьев
        sumbol = ch;
        freq = count;
        left = nullptr;
        right = nullptr;
    }
    HaffCodeNode(char ch, int count, HaffCodeNode* left1, HaffCodeNode* right1) {// конструктор2 для переноса узлов 
        sumbol = ch;
        freq = count;
        left = left1;
        right = right1;
        freq = left->freq + right->freq;
    }
};
unsigned char check(string sourse_txt, string decompress_text) {

    ifstream in1;
    ifstream in2;
    in1.open(sourse_txt);
    in2.open(decompress_text);

    if (in1 && in2) {
        char tmp1 = 0;
        char tmp2 = 0;
        while (tmp1 == tmp2 && tmp1 != EOF) {
            tmp1 = in1.get();
            tmp2 = in2.get();
        }

        in1.close();
        in2.close();
        if (tmp1 != tmp2)
        {
            return 2;
        }
        return 0;
    }
    in1.close();
    in2.close();
    return 1;
}





int main(int argc, char* argv[]){// обработаем случай с входными данными для корректного их чтения/записи
    //if (argc != 4) {// пусть будет 3 аргумента
    //    cout << "  Encode: huffman 1 input.txt output.bin\n";
    //    cout << "  Decode: huffman 2 input.bin output.txt\n";
    //    cout << "  Compare: huffman 3 input.txt output.txt\n";
    //    return 1;
    //}
    //int mode = int(argv[1]);
    //string inputFile = argv[2];
    //string outputFile = argv[3];
    //это, пока, задел на будущее пока пойдем хардкодом


    // для начала надо определиться с хранением данных о каждом символе. Самым подходящим вариантом является словарь(map).
    map<char, unsigned int> counter;
    //теперь надо открыть фаил и посчитать колличество символов

    //блок считывания повторений символов
    ifstream in;       // поток для чтения
    size_t countt = 0;// общее колличество символов
    in.open("micro_original.txt"); // открываем файл для чтения
    for (; !(in.eof());) {// пока фаил не закончился
        char c = in.get(); // берем 1 символ из файла
        counter[c]++; // увеличиваем значение частоты символа в словаре
        countt++;
    }
    in.close();//закрываем. Он закончился
    cout << counter['a'] << endl;//вывели произвольный символ
    cout << countt << endl;

    //теперь нужно присвоить каждому символу лист


    //switch (mode){// как будет работать наша программа в зависимости от выбора пользователя
    //case 1://code
    //    
    //   
    //    break;
    //case 2://decode
    //    
    //    break;
    //case 3://comparing
    //    printf("Start comparing\n");
    //    unsigned char conclusion = check(inputFile, outputFile);//сравниваем
    //    printf("Comparing done\n");
    //    printf("Compare conclusion: ");
    //    switch (conclusion3)
    //    {
    //    case 0:
    //        printf("Success\n\n");
    //        break;
    //    case 1:
    //        printf("ERR: files don't oppened or created\n\n");
    //        break;
    //    case 2:
    //        printf("ERR: files are different\n\n");
    //        break;
    //    default:
    //        printf("Unknown ERR\n\n");
    //    }
    //    break;
    //default:
    //    cout << "Unknown mode : " <<mode<< endl;
    //    cout << "  Encode: huffman 1 input.txt output.bin\n";
    //    cout << "  Decode: huffman 2 input.bin output.txt\n";
    //    cout << "  Compare: huffman 3 input.txt output.txt\n";
    //    break;
    //}
    

    cout << "Hello World!\n";
    return 0;
}

