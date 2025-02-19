# Определяем компилятор
CC = gcc

# Определяем флаги компиляции
CFLAGS = -Wall -Wextra -g

# Определяем объектные файлы
OBJS = term_paper.o common.o findRoot.o calcIntegral.o

# Определяем имя исполняемого файла
TARGET = term_paper

# Правило для сборки проекта
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Правила для компиляции объектных файлов
term_paper.o: term_paper.c common.h findRoot.h calcIntegral.h
	$(CC) $(CFLAGS) -c $<

common.o: common.c common.h
	$(CC) $(CFLAGS) -c $<

findRoot.o: findRoot.c findRoot.h common.h
	$(CC) $(CFLAGS) -c $<

calcIntegral.o: calcIntegral.c calcIntegral.h common.h
	$(CC) $(CFLAGS) -c $<

# Правило для очистки
clean:
	rm -f $(TARGET) $(OBJS)
