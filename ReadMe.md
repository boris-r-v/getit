#GetIt
=======

Решает задачу сортировки заказов:


**Дано:**

    Есть 5 фирм – продавцов фруктов, от каждой фирмы мы получаем список того, что она хочет иметь.
    Список этот – это файл в формате: название товара (фрукта), максимальная цена, производитель товара (желаемый), количество (в килограммах).
    Каждая запись в одну строку, поля разделяются запятыми.

        Пример:
            яблоки,52.2,Бабушкины_фрукты,100
            апельсины,212.2,Дедушкины_овощи,123
    
    
Есть три менеджера, которым нужны результаты обработки этих файлов –
    - первому в виде списка для производителя 1,
    - второму для другого производителя и
    - третьему нужна информация по всем яблокам.
Т.е. этих людей интересует кто и сколько товара заказал.

**Задание:**

    Нужно написать программу на С/С++, которая будет принимать пять файлов и на выходе давать три файла.
    Еще если время позволит и будет желание было бы интересно чтобы эта программка получала файлы динамически,
        т.е. отслеживала бы содержимое каталога с входными файлами, и если они изменились, то обновляла бы и результирующие три файла.

**Ограничения данной версии:**

1.Все контейнеры std::list - не самый подходящий вариант по быстродействию .

2.Политика обновления базы данных - всегда добавляем данные, даже если они дублируют уже существующие, не было оговорено. В зависимости от задачи можно изменить реализацию базы данных.

3.Валидация данных не проводится

4.Тестирование не проводилось


**Сборка запуск:**

Использован cmake, поэтому все стандарто (проверено на Ubuntu 14.04):

    1. cd getit && mkdir build && cd build
    2. cmake .. && make && make doc
    3. ./getit -c config/config.xml
    
Файлы с заказами в ./config/customers (от каталога build)
Файлы для менеджеров в ./config/managers (от каталога build)

**Конфигурационный xml-файл:**

    <?xml version='1.0'?>
    <root>
        <!-- Указание путей к файлам -->
        <path customers="./config/customers/" managers="./config/managers" />   - тут указаны пути к каталогам с файлами
        <!-- Описание того, что хотят менеджеры -->
        <managers>
            <manager filename="first.csv" producer="Бабушкины_фрукты" merch="" />   - этот хочет заказ на производителя "Бабушкины_фрукты", и просит положить данные в файл first.csv
            <manager filename="second.csv" producer="Дедушкины_овощи" merch="" />   - этот хочет заказ на производителя "Дедушкины_овощи", и просит положить данные в файл second.csv
            <manager filename="third.csv" producer="" merch="яблоки" /> - этот по яблокам работает, и работу ожидает в файле third.csv
        </managers>
    </root>


**Документация:**

Использован Doxygen, настроена генерация HTML. Сделано описание классов, методы не документированы - пока излишне.

Документация доступна в каталоге ./build/doc/doxygen/html
