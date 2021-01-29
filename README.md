# get_next_line
------------
Проект реализует в себе построчное считывание текста из файла

**Использование:**
- Проект подключается в вашу программу путем перемишения файлов в ваш проект.
- Компилировать файлы с файлами вашего проекта.

**Пример подключения:**
```C
#include "get_next_line.h"

int main() {
    int ret;
    char *line;

    line = 0;
    ret = get_next_line(0, &line);
    while (ret > 0) {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
        ret = get_next_line(0, &line);
    }
    if (ret == 0) {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
	}
    if (ret == -1)
        write(1, "ERROR\n", 6);
}
```
Проект был создан участником школы 21 (ncliff). Автор не разрешает использовать ( код / участки кода ) другим участникам школы 21.
