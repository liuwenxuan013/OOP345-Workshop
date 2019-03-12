#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;
void exit_1(){
    std::cout <<"Loading file failed..."<<std::endl;
}
void exit_2(){
    std::cout <<"Lose files"<<std::endl;
}
void exit_3(){
    std::cout <<"More files"<<std::endl;
}
template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
    std::ifstream file(filename);
    
    if (!file) {
        //throw "Loading file failed...";
        atexit(exit_1);
        exit(1);
        L list(0);
        return std::move(list);
    }
    int no_records = 0;
    do {
        char c = file.get();
        if (file.good() && c == '\n') no_records++;

    } while (!file.eof());
    file.clear();
    file.seekg(std::ios::beg);
    L list(no_records);
    do {
        K key;
        V value;
        file >> key;
        if (file) {
            file >> value;
            file.ignore();
            list.push_back(T(key, value));
        }
    } while (file);
    
    return std::move(list);
}




int main(int argc, char* argv[]) {
    std::cout << "Command Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    //try{
    // check for command line errors
        if (argc < 3){
        //throw "Lose files";
        atexit(exit_2);
            exit(2);}
        if(argc >3){
        //throw "More files";
        atexit(exit_3);
            exit(3);}
    else
    // set for fixed, 2-decimal point output
    std::cout <<std::fixed << std::setprecision(2);
    
        // process price list file
    KVList<KVPair<std::string, float>> priceList = createList<
    KVList<KVPair<std::string, float>>,
    KVPair<std::string, float>,
    std::string,
    float>
    (argv[1]);
    std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
    std::cout << "Description:      Price Price+Tax\n";
    priceList.display(std::cout, Taxable(HST));

    
        //process student list file
    KVList<KVPair<int,float>> studentList = createList<KVList<KVPair<int ,float>>,KVPair<int,float>,int,float>(argv[2]);
        std::cout << "\nStudent List Letter Grades Included\n==================================\n";
        std::cout << "Student No :      Grade    Letter\n";
//         auto transGrades = [](float g) {
//            std::string a ;
//            if (g >= 90)
//                a = "A+";
//            else if (g >= 85)
//                a = "A ";
//            else if (g >= 80)
//                a = "A-";
//            else if (g >= 77)
//                a = "B+";
//            else if (g >= 73)
//                a = "B ";
//            else if (g>= 70)
//                a = "B-";
//            else if (g >= 67)
//                a = "C+";
//            else if (g >= 63)
//                a = "C ";
//            else if (g >= 60)
//                a = "C-";
//            else if (g >= 55)
//                a  = "D+";
//            else if (g>= 50)
//                a = "D ";
//            else
//                a = "F ";
//            return a;
//        };
    
       // studentList.display(std::cout,transGrades);
//    }catch(const char* msg){
//        std::cerr<<msg<<std::endl;
//    }


    
    studentList.display(std::cout,[](float g){
                    std::string a ;
                    if (g >= 90)
                        a = "A+";
                    else if (g >= 85)
                        a = "A ";
                    else if (g >= 80)
                        a = "A-";
                    else if (g >= 77)
                        a = "B+";
                    else if (g >= 73)
                        a = "B ";
                    else if (g>= 70)
                        a = "B-";
                    else if (g >= 67)
                        a = "C+";
                    else if (g >= 63)
                        a = "C ";
                    else if (g >= 60)
                        a = "C-";
                    else if (g >= 55)
                        a  = "D+";
                    else if (g>= 50)
                        a = "D ";
                    else
                        a = "F ";
        return a;});

}

