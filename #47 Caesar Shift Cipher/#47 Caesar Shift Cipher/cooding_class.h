//
//  cooding_class.h
//  #47 Caesar Shift Cipher
//
//  Created by Владислав Легков on 08/05/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#ifndef cooding_class_h
#define cooding_class_h

#include "cooding_class.cpp"
#include "pch.h"

class cooding {
public:
    cooding (string&, int&);
    
private:
    string code_str; //запись строки из файла
    long int l_str; //длина строки
    string decode_str; //декодированное сообщение
    int code_swipe; //на сколько символов кодировка сдвигает алфавит
};

#endif /* cooding_class_h */
