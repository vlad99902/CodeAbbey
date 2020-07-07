//
//  global_functions.cpp
//  #47 Caesar Shift Cipher
//
//  Created by Владислав Легков on 08/05/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include "pch.h"

int read_num_and_swipe (ifstream &fin, int &n, int &swipe){  //чтение количества элементов и размера сдвига
    string line;
    getline (fin,line);
    n = atoi(&line[0]);
    swipe = atoi(&line[2]);
    if (n == 0 || swipe == 0)     //если возвращается 0, ввод некорректен
        return 0;
    return 1;
}
