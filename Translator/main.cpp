//
//  main.cpp
//  Assembler
//
//  Created by Иван Белых on 01.04.17.
//  Copyright © 2017 Иван Белых. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
const int quantity_of_cicle = 2;

using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;
using std::endl;
using std::cout;

int main(int argc, const char * argv[]) {
    
    vector<int> array_comand;
    vector<int> array_label;
    
    size_t for_ret = -1;
    int n = 0;
    int with_arg_2 = 0, with_arg_3 = 0;
    
    while (n < quantity_of_cicle){
        
        ifstream fin;
        fin.open("/Users/home/Technoatom/CPU/cmake-build-debug/script_file.txt");
        ofstream fout;
        fout.open("/Users/home/Technoatom/CPU/cmake-build-debug/command_file.txt");
        
        while (!fin.eof()){
            
            string cmd;
            fin >> cmd;
            
            if (with_arg_2){
                if (cmd == "x0"){
                    array_comand.push_back(1000);
                    
                    fout << 1000 << endl << endl;
                }
                else if (cmd == "x1"){
                    array_comand.push_back(1001);
                        
                    fout << 1001 << endl << endl;
                }
                    else
                        if (cmd == "x2"){
                            array_comand.push_back(1002);
                            
                            fout << 1002 << endl << endl;
                        }
                        else
                            if (cmd == "y0"){
                                array_comand.push_back(2000);
                                
                                fout << 2000 << endl << endl;
                            }
                            else
                                if (cmd == "y1"){
                                    array_comand.push_back(2001);
                                    
                                    fout << 2001 << endl << endl;
                                }
                                else
                                    if (cmd == "y2"){
                                        array_comand.push_back(2002);
                                        
                                        fout << 2002 << endl << endl;
                                    }
                                    else{
                                        cout << "Command \"" << cmd << "\" is not exist." << endl;
                                        exit(13);
                                    }
                with_arg_2 = 0;
            }
            else
                if (with_arg_3){
                    if (cmd[0] == ':'){
                        size_t size = cmd.size();
                        int lable = 0;
                        for (int i = 0; i < size-1; i++){
                            lable = (cmd[i+1] - '0') * pow(10,i);
                        }
                        while (array_label.size() < lable+1){
                            array_label.push_back(0);
                        }
                        array_label[lable] = (int)array_comand.size() + 1;
                    }
                    else{
                        cout << "Command \"" << cmd << "\" is not exist." << endl;
                        exit(13);
                    }
                    with_arg_3 = 0;
                }
                else
                    if (cmd == "end"){
                        array_comand.push_back(0);
                        
                        fout << 0 << endl << endl;
                    }
                    else
                        if (cmd == "add"){
                            array_comand.push_back(101);
                            
                            fout << 101 << endl << endl;
                        }
                        else
                            if (cmd == "div"){
                                array_comand.push_back(102);
                                
                                fout << 102 << endl << endl;
                            }
                            else
                                if (cmd == "mod"){
                                    array_comand.push_back(103);
                                    
                                    fout << 103 << endl << endl;
                                }
                                else
                                    if (cmd == "deduct"){
                                        array_comand.push_back(104);
                                        
                                        fout << 104 << endl << endl;
                                    }
                                    else
                                        if (cmd == "multiply"){
                                            array_comand.push_back(105);
                                            
                                            fout << 105 << endl << endl;
                                        }
                                        else
                                    if (cmd == "push"){
                                        array_comand.push_back(201);
                                        
                                        fout << 201 << " ";
                                        
                                        with_arg_2 = 1;
                                    }
                                    else
                                        if (cmd == "push_const"){
                                            array_comand.push_back(202);
                                            
                                            fout << 202 << " ";
                                            
                                            int const_to_push;
                                            fin >> const_to_push;
                                            array_comand.push_back(const_to_push);
                                            
                                            fout << const_to_push << endl << endl;
                                        }
                                        else
                                            if (cmd == "pop"){
                                                array_comand.push_back(203);
                                                
                                                fout << 203 << " ";
                                                
                                                with_arg_2 = 1;
                                            }
                                            else
                                                if (cmd == "top"){
                                                    array_comand.push_back(204);
                                                    
                                                    fout << 204 << " ";
                                                    
                                                    with_arg_2 = 1;
                                                }
                                                else

                                                if (cmd == "jmp"){
                                                    array_comand.push_back(301);
                                                    
                                                    fout << 301 << " ";
                                                    
                                                    string where;
                                                    fin >> where;
                                                    size_t size = where.size();
                                                    int lable = 0;
                                                    for (int i = 0; i < size-1; i++){
                                                        lable = (where[i+1] - '0') * pow(10,i);
                                                    }
                                                    while (array_label.size() < lable + 1){
                                                        array_label.push_back(0);
                                                    }
                                                    array_comand.push_back(array_label[lable]);
                                                    
                                                    fout << array_label[lable] << endl << endl;
                                                }
                                                else
                                                    if (cmd == "call"){
                                                        array_comand.push_back(302);
                                                        
                                                        fout << 302 << " ";
                                                        
                                                        string where;
                                                        fin >> where;
                                                        
                                                        if (where[0] != ':'){
                                                            cout << "Error argyment" << endl;
                                                            exit(3);
                                                        }
                                                        
                                                        size_t size = where.size();
                                                        int lable = 0;
                                                        for (int i = 0; i < size-1; i++){
                                                            lable = (where[i+1] - '0') * pow(10,i);
                                                        }
                                                        
                                                        while (array_label.size() < lable + 1){
                                                            array_label.push_back(0);
                                                        }
                                                        array_comand.push_back(array_label[lable]);
                                                        for_ret = array_comand.size();
                                                        
                                                        fout << array_label[lable] << endl << endl;
                                                        
                                                    }
                                                    else
                                                        if (cmd == "ret"){
                                                            array_comand.push_back(303);
                                                            
                                                            fout << 303 << " ";
                                                            
                                                            array_comand.push_back((int)for_ret);
                                                            
                                                            fout << for_ret << endl << endl;
                                                        }
            
                                                        else
                                                            if (cmd == "je"){
                                                                array_comand.push_back(401);
                                                                
                                                                fout << 401 << endl << endl;
                                                                
                                                                string where;
                                                                fin >> where;
                                                                size_t size = where.size();
                                                                int lable = 0;
                                                                for (int i = 0; i < size-1; i++){
                                                                    lable = (where[i+1] - '0') * pow(10,i);
                                                                }
                                                                while (array_label.size() < lable + 1){
                                                                    array_label.push_back(0);
                                                                }
                                                                array_comand.push_back(array_label[lable]);
                                                                
                                                                fout << array_label[lable] << endl << endl;
                                                            }
                                                            else
                                                                if (cmd == "ja"){
                                                                    array_comand.push_back(402);
                                                                    
                                                                    fout << 402 << endl << endl;
                                                                    
                                                                    string where;
                                                                    fin >> where;
                                                                    size_t size = where.size();
                                                                    int lable = 0;
                                                                    for (int i = 0; i < size-1; i++){
                                                                        lable = (where[i+1] - '0') * pow(10,i);
                                                                    }
                                                                    while (array_label.size() < lable + 1){
                                                                        array_label.push_back(0);
                                                                    }
                                                                    array_comand.push_back(array_label[lable]);
                                                                    
                                                                    fout << array_label[lable] << endl << endl;
                                                                }
                                                                else
                                                                    if (cmd == "jae"){
                                                                        array_comand.push_back(403);
                                                                        
                                                                        fout << 403 << endl << endl;
                                                                        
                                                                        string where;
                                                                        fin >> where;
                                                                        size_t size = where.size();
                                                                        int lable = 0;
                                                                        for (int i = 0; i < size-1; i++){
                                                                            lable = (where[i+1] - '0') * pow(10,i);
                                                                        }
                                                                        while (array_label.size() < lable + 1){
                                                                            array_label.push_back(0);
                                                                        }
                                                                        array_comand.push_back(array_label[lable]);
                                                                        
                                                                        fout << array_label[lable] << endl << endl;
                                                                    }
                                                                    else
                                                                        if (cmd == "jb"){
                                                                            array_comand.push_back(404);
                                                                            
                                                                            fout << 404 << endl << endl;
                                                                            
                                                                            string where;
                                                                            fin >> where;
                                                                            size_t size = where.size();
                                                                            int lable = 0;
                                                                            for (int i = 0; i < size-1; i++){
                                                                                lable = (where[i+1] - '0') * pow(10,i);
                                                                            }
                                                                            while (array_label.size() < lable + 1){
                                                                                array_label.push_back(0);
                                                                            }
                                                                            array_comand.push_back(array_label[lable]);
                                                                            
                                                                            fout << array_label[lable] << endl << endl;
                                                                        }
                                                                        else
                                                                            if (cmd == "jbe"){
                                                                                array_comand.push_back(405);
                                                                                
                                                                                fout << 405 << endl << endl;
                                                                                
                                                                                string where;
                                                                                fin >> where;
                                                                                size_t size = where.size();
                                                                                int lable = 0;
                                                                                for (int i = 0; i < size-1; i++){
                                                                                    lable = (where[i+1] - '0') * pow(10,i);
                                                                                }
                                                                                while (array_label.size() < lable + 1){
                                                                                    array_label.push_back(0);
                                                                                }
                                                                                array_comand.push_back(array_label[lable]);
                                                                                
                                                                                fout << array_label[lable] << endl << endl;
                                                                            }
                                                                            else
                                                                                if (cmd == "jne"){
                                                                                    array_comand.push_back(406);
                                                                                    
                                                                                    fout << 406 << endl << endl;
                                                                                    
                                                                                    string where;
                                                                                    fin >> where;
                                                                                    size_t size = where.size();
                                                                                    int lable = 0;
                                                                                    for (int i = 0; i < size-1; i++){
                                                                                        lable = (where[i+1] - '0') * pow(10,i);
                                                                                    }
                                                                                    while (array_label.size() < lable + 1){
                                                                                        array_label.push_back(0);
                                                                                    }
                                                                                    array_comand.push_back(array_label[lable]);
                                                                                    
                                                                                    fout << array_label[lable] << endl << endl;
                                                                                }
                                                                                else
                                                                                    if (cmd[0] == ':'){
                                                                                        size_t size = cmd.size();
                                                                                        int lable = 0;
                                                                                        for (int i = 0; i < size-1; i++){
                                                                                            lable = (cmd[i+1] - '0') * pow(10,i);
                                                                                        }
                                                                                        while (array_label.size() < lable+1){
                                                                                            array_label.push_back(0);
                                                                                        }
                                                                                        array_label[lable] = (int)array_comand.size();
                                                                                    }
                                                                                    else
                                                                                        if (!fin.eof()){
                                                                                            cout << "Command \"" << cmd << "\" is not exist." << endl;
                                                                                            exit(13);
                                                                                        }
        }
        
        fin.close();
        fout.close();
        if (n == 0)
            array_comand.clear();
        n++;
        
    }
    
    cout << "Массив меток:" << endl;
    for (int i = 1; i < array_label.size(); i++)
        cout << i << ": " << array_label[i] << endl;
    
    cout << endl << "Массив команд:" << endl;
    for (int i = 0; i < array_comand.size(); i++)
        cout << i << ": " << array_comand[i] << endl;
}
