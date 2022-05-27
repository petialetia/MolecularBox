I am not good enough in English to describe my project in it.

# Это есть мой проект "Коробка с молекулами".

> Полное описание можно прочитать в файле [documentation/Description.md](documentation/Description.md)

> ChangeLog лежит в файле [documentation/ChangeLog.md](documentation/ChangeLog.md)

## Идея:

Есть некое ограниченное тело, внутри которого перемещаются и взаимодействуют друг с другом молекулы. Природа взаимодействий, потенциально, любая: механические столкновения, передача тепла, быть может даже "химическая", когда одни молекулы при столкновении с другими порождают новые. Соответственно, необходимо просчитывать и отрисовывать положения молекул.

## Прогресс на данный момент:

На данный момент реализован лишь самый примитивный метод просчёта взаимодействий между молекулами - пошаговый (подробнее о методах просчёта взаимодействий смотри полное описание), и реализованы лишь их столкновения (примитивный образ, считая все объекты имеющими одинаковую массу).

Пошаговый метод просчёта взаимодействий допускает проникновение объектов друг друга, более точная его работа привязана к длине шага, чем она меньше, тем точнее. Но при этом чем меньше длина шага, тем медленнее в целом идёт симуляция. Сейчас шаг выставлен как 1/4096, это позволяет работать симуляции достаточно точно, при этом на моей машине она продолжает работать достаточно быстро. Если на вашей это не так, рассмотрите возможность увеличения длины шага.

## Как запускать:

### 1) Установка зависимостей:

#### Под ubuntu:

Запустить скрипт requirements_ubuntu.sh.

#### Под другими дистрибутивами или ОС:

Нужно установить все необходимые зависимости из requirements_ubuntu.sh:

а) Компилятор c++.

б) CMake.

в) SDL2.

г) GTests (для тестов).

### 2) Сборка:

#### Под linux:

Запустить скрипт build.sh.

#### Под другими ОС:

Нужно исполнить команды из build.sh, собрав проект с помощью CMake.

### 3) Запуск

Если всё пройдёт штатно, должна появится папка bin, а в ней исполняемый файлик MolecularBox.out. Запустить его можно ручками, либо же с помощью скриптика execute.sh (под Linux).