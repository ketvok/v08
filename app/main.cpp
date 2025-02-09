#include "app.h"

#include "iostream"  // cout, cin
#include "format" // format

// read and evaluate expression inside endless loop 
// break after first exception (use one catch clause), show error description


/*Implementirajte funkcije potrebne da svi testovi prolaze.

Napi�ite program kojem se unosi aritmeti�ki izraz
(cijeli broj, operator, cijeli broj)
te ispisuje operaciju zajedno sa rezultatom u formatu : 4 + 9 = 13

U programu vrtite beskona�nu petlju dok se operacija uspje�no ra�una.
U slu�aju iznimke (obavezno koristite samo jedan catch blok) ispi�ite
opis pogre�ke, jedan od :

not a number
invalid operation
divide by zero*/

using namespace vsite::oop::v8;  // I added this.

int main()
{
	try {
		while (true) {
			std::cout << "Unesite aritmeticki izraz (cijeli broj, operator, cijeli broj):\n";
			int a = input_num(std::cin);
			char op = input_op(std::cin);
			int b = input_num(std::cin);
			double result = calc(a, op, b);
			std::cout << std::format("{} {} {} = {}\n", a, op, b, result);
		}
	}catch (MathErr& x) {
		x.showError();
	}catch (...) {
		std::cout << "nepoznata iznimka\n" << std::endl;
	}
}
