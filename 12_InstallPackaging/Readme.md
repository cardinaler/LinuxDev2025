## Сборка и установка программы в систему (нужен @root)
autoreconf -fisv

./configure --libdir=/usr/lib

make

make install

## Запуск программы 
prog

## Запуск программы в римской системе
prog -r

## man страница 
man prog

## Запуск локального сервера для чтения документации к исходникам
python3 -m http.server --directory /usr/local/share/doc/prog/html

## Удаление программы из системы (нужен @root)
make uninstall
