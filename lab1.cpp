#include <iostream>
#include <cstdint>
#include "bitstring.h"

int main() {

  uint32_t first;
  uint64_t second;
  uint32_t onlyfirst = 0x1234;
  uint64_t onlysecond = 0x12345678;
  const uint32_t bitleft = 3;
  const uint32_t bitright = 5;
  uint32_t incfirst;
  uint64_t incsecond;
  
  std::cout << "Введите данные в следующем формате: *32-битовая строка* + *64-битовая строка*.\n";
  std::cin >> first >> second;
  bitstring a{first, second};
  bitstring f{onlyfirst};
  bitstring s{0 , onlysecond};
  bitstring test{onlyfirst, onlysecond};
  bitstring zero{};

  std::cout << "Сейчас будут выведены следующие строки через отступ - " << onlyfirst << " 0, 0 " << onlysecond << ", 0 0." << std::endl;
  f.print();
  s.print();
  zero.print();
  
  std::cout << "Сейчас будут проведены стандартные битовые операции с вашей строкой." << std::endl;
  std::cout << a.getF() << " " << a.getS() << " & " << test.getF() << " " << test.getS() << " = ";
  (a.And(test)).print();
  std::cout << a.getF() << " " << a.getS() << " | " << test.getF() << " " << test.getS() << " = ";
  (a.Or(test)).print();
  std::cout << a.getF() << " " << a.getS() << " ^ " << test.getF() << " " << test.getS() << " = ";
  (a.Xor(test)).print();
  std::cout << "~(" << a.getF() << " " << a.getS() << ") = ";
  (a.Not()).print();

  std::cout << "Сейчас будет проведен сдвиг на " << bitleft << " битов влево и на " << bitright << "битов вправо. После сдвига будет печататься состояние строки." << std::endl;
  a.shiftLeft(bitleft);
  a.print();
  a.shiftRight(bitright);
  a.print();
  
  std::cout << "А теперь проверим еще функции. Для того, чтобы проверить функцию включения, введите еще одно число в следующем формате: *32-битовая строка* + *64-битовая строка*." << std::endl;
  std::cin >> incfirst >> incsecond;
  bitstring inc{incfirst, incsecond};
  std::cout << "Кол-во единиц равно " << a.countone() << std::endl;
  std::cout << a.getF() << " " << a.getS() << " == " << inc.getF() << " " << inc.getS() << "? Это " << (a.equal(inc) ? "правда" : "неправда") << std::endl;
  std::cout << "В " << a.getF() << " " << a.getS() << " включено " << inc.getF() << " " << inc.getS() << "? Это " << (a.include(inc) ? "правда" : "неправда") << std::endl;
  return 0;
}