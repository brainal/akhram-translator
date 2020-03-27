#include <iostream>
#include <bitset>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <string>
#include <limits>

std::string phrase;

std::string string_to_bitset(const std::string& phrase) {
	std::string bitset = "";

	for (const char& ch : phrase)
		bitset += std::bitset<8>(ch).to_string();

	return bitset;
}

std::string text_to_Akhram(const std::string& phrase) {
	std::string translated_string = "";

    std::string bitset_string = string_to_bitset(phrase);

	for (const char& ch : bitset_string) {
        if (ch == '0')
            translated_string += "tipo ";
        else if (ch == '1')
            translated_string += "compa' ";
	}

	return translated_string;
}

int main() {

    std::ofstream filebuf_for_write_data("translated_akhram.txt");

	std::cout << "immetti la frase da tradurre da testo ad Akhram: ";
	std::getline(std::cin, phrase);

	std::string translated_phrase = text_to_Akhram(phrase);

    if (filebuf_for_write_data.is_open()) {
        filebuf_for_write_data << translated_phrase;
        std::cout << "La frase e' stata scritta su translated_akhram.txt" << std::endl;
    } else {
        std::cout << "Errore nella scrittura del file. ";
    }


    filebuf_for_write_data.clear();
    filebuf_for_write_data.close();

	return 0;
}
