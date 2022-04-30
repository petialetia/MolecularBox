I am not good enough in English to describe my project in it.

# Это есть мой проект по предмету "Технологии программирования" - "Коробка с молекулами".

> [Описание можно прочитать в папке description](description/Description.md)

## Как запускать:

1) Запустите скрипт build.sh

2) Если всё пройдёт штатно, после этого появится папка bin, а в ней исполняемый файлик MolecularBox.out. Запустить его можно как ручками, так и с помощью скриптика execute.sh

## ChangeLog:

### 03.04.2022: 

1) Отказался от тэг-диспатчинга у Interaction-ов в пользу наследования. Мне кажется, это куда лучше передаёт, к примеру, то что PredictableInteraction есть лишь частный случай обычного Interaction, а потому, скажем, каст будет работать только лишь в одну сторону

2) Отказался от хранения в объектах поля type_ в пользу использования std::variant. Да, быть может, это дольше, но это в большей степени по SOLID, плюс никто не заставляет ограничиваться std::variant, насколько я понимаю, variant из boost-а будет работать значительно быстрее, быть может даже бытрее чем изначальная версия с возвратом type_.

### 08.04.2022:

1) Вынес координату центра из круга. Таким образом, теперь форма круг определяется лишь своим радиусом, т.е. 2 равных круга с разными центрами теперь действительно равны с точки зрения Shape-ов. Подобная практика продолжится и далее при добавлении других Shape-ов.

2) Организовал ObjectStorage, который внутри себя производит всю коммуникацию между хранилищем Shape-ов, их координатами и их скоростями. Теперь добавление новой молекулы - одна операция (без учёта её подписывания).

### 09.04.2022:

1) Реализован адаптер над графической библиотекой, реализовал адаптер для SDL2.

2) Добавлен класс CoordinateSystem для лёгкого перевода координат объектов в конкретные пиксели на экране.

### 10.04.2022:

1) Переписан адаптер по паттерну CRTP для более быстрой работы.

### 11.04.2022:

1) Реализован адаптер для таймера по тому же принципу, что и адаптер для графической библиотеки.

### 15.04.2022:

1) Использован паттерн синглетон по отношению к адаптерам над графикой и таймером.

### 24.04.2022:

1) Полностью имплементировано движение и рисование объектов.
2) Расширен функционал графического адаптера

### 28.04.2022:

1) Переделано рисование, теперь это отдельное взаимодействие, одно на все объекты. Соответственно, все объекты рисуются единовременно, при этом оптимизируется кол-во проверок.

### 30.04.2022:

1) Реализованы основные части просчёта примитивных коллизий без учёта массы объектов.
2) Всё полностью готово для пошаговой реализации просчёта событий.