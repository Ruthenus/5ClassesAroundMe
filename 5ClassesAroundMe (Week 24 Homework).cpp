#include <windows.h>
#include <iostream>
#include <cstdlib>  // srand(), rand()
#include <ctime>    // time_t, time(), tm, localtime()
#include <iomanip>  // setw(), setfill()
#include <string>   // getline()

using namespace std;


class Chandelier  // Люстра в кімнаті
{
private:  // приватна квартира, тож поля закриті
    string style = "Бароко";
    unsigned short lampPower = 40;  // лампи розжарювання найкращі для очей
    unsigned short totalCups = 8;   // кількість чашечок для лампочок
    // Кількість вкручених неперегорілих ламп у справні патрони:
    unsigned short rightSideLamps = 4;  // це як подивитись,
    unsigned short leftSideLamps = 4;   // з якого боку
    bool rightSideChandelierOn = false; // cтан "правої" половини люстри
    bool leftSideChandelierOn = false;  // cтан "лівої" половини люстри

public:
    // Метод для заповнення полів об'єкта згідно із заданою умовою
    void InstallChandelier()
    {
        system("cls");  // очищення консолі для кожного завдання
        cout << "\tАБСТРАГУВАННЯ ПЕРШЕ: ЛЮСТРА В ЗАЛІ\n\n";

        cout << "В якому стилі люстра? ";
        cin >> style;

        cout << "На скільки ват лампочки? ";
        cin >> lampPower;
        if (cin.fail()) exit(1);  // або через throw("FATAL ERROR");
        lampPower = abs(lampPower);  // виправлення від'ємного числа
        if (lampPower > 60) {
            cout << "Забагато. Не більше шістдесяти! 40 Вт достатньо.\n";
            lampPower = 40;
        }

        cout << "Скільки ламп можна закрутити в люстру? ";
        cin >> totalCups;
        if (cin.fail()) exit(1);
        totalCups = abs(totalCups);
        if (totalCups == 0) totalCups = 1;  // інакше це не світильник

        cout << "З одного боку люстри закрутили ламп: ";
        cin >> rightSideLamps;
        if (cin.fail()) exit(1);
        rightSideLamps = abs(rightSideLamps);
        if (rightSideLamps > totalCups / 2 + (totalCups % 2)) {
            rightSideLamps = totalCups / 2 + (totalCups % 2);
        }  // нормалізація в разі непарної кількості чашечок

        cout << "З іншого боку люстри закрутили ламп: ";
        cin >> leftSideLamps;
        if (cin.fail()) exit(1);
        leftSideLamps = abs(leftSideLamps);
        if (leftSideLamps > totalCups / 2) leftSideLamps = totalCups / 2;
    }


    // Метод виведення інформації про об'єкт відповідно до заданої умови
    void PrintInfo() const  // тобто метод не змінює стан об'єкта
    {
        system("cls");  // очищення консолі під час "керування люстрою"

        cout << "Стиль люстри: " << style << "\n";
        cout << "Потужність ламп з однієї коробки: " << lampPower << " Вт\n";
        cout << "Кількість чашечок у люстрі: " << totalCups << "\n";
        cout << "Усього вкручено лампочок: " << rightSideLamps + leftSideLamps
            << "\n";

        cout << "\n\t        |";  // спрощене псевдографічне зображення
        cout << "\n\t" << (leftSideChandelierOn ? "СВІТЛО" : " Темно")
            << " -|- " << (rightSideChandelierOn ? "СВІТЛО" : "Темно");
        cout << "\n\t        |\n";

        if (rightSideChandelierOn && leftSideChandelierOn) {
            cout << "\nГорить ламп: "
                << rightSideLamps + leftSideLamps << "\n";
            cout << "Потужність споживання люстри: "
                << (rightSideLamps + leftSideLamps) * lampPower << " Вт\n";
            cout << "Можна додатково вкрутити лампочок: "
                << totalCups - (rightSideLamps + leftSideLamps) << "\n";
        }
        else if (rightSideChandelierOn && !leftSideChandelierOn) {
            cout << "\nГорить ламп праворуч: " << rightSideLamps << "\n";
            cout << "Потужність споживання люстри: "
                << rightSideLamps * lampPower << " Вт\n";
            cout << "Можна ввімкнути лампочок: " << leftSideLamps << "\n";
        }
        else if (!rightSideChandelierOn && leftSideChandelierOn) {
            cout << "\nГорить ламп ліворуч: " << leftSideLamps << "\n";
            cout << "Потужність споживання люстри: "
                << leftSideLamps * lampPower << " Вт\n";
            cout << "Можна ввімкнути лампочок: " << rightSideLamps << "\n";
        }
        else {
            cout << "\nУвімкніть нарешті люстру! "
                << "Спробуйте поклацати вимикачем." << "\n";
        }
    }


    // Методи керування люстрою за допомогою двоклавішного вимикача

    void SwitchOnChandelier()  // увімкнути всі лампочки в люстрі
    {
        if (rightSideLamps > 0) rightSideChandelierOn = true;
        if (leftSideLamps > 0) leftSideChandelierOn = true;
    }

    void SwitchOffChandelier()  // вимкнути люстру повністю
    {
        rightSideChandelierOn = false; leftSideChandelierOn = false;
    }

    void SwitchOnRightLamps()  // увімкнути частину ламп
    {
        if (rightSideLamps > 0) rightSideChandelierOn = true;
    }

    void SwitchOffRightLamps()  // вимкнути ці лампи
    {
        rightSideChandelierOn = false;
    }

    void SwitchOnLeftLamps()
    {
        if (leftSideLamps > 0) leftSideChandelierOn = true;
    }

    void SwitchOffLeftLamps() { leftSideChandelierOn = false; }

    void TransmitLightSignals()  // імітація гри зі світлом
    {
        short HvatitIgratsaSoSvetom = rand() % (100 - 20 + 1) + 20;
        for (short i = 0; i < HvatitIgratsaSoSvetom; i++) {
            rightSideChandelierOn = (rightSideLamps > 0) ? rand() % 2 : false;
            leftSideChandelierOn = (leftSideLamps > 0) ? rand() % 2 : false;
            Sleep(400);
            PrintInfo();
        }
    }
};


class AlarmClock  // Новий будильник
{
private:
    unsigned short hours = 11;   // поточна або встановлена година
    unsigned short minutes = 59; // поточна або встановлена хвилина
    unsigned short seconds = 0;  // поточна секунда
    // Формат часу: true — 24-годинний, false — 12-годинний:
    bool is24HourFormat = false;
    bool isAM = true;  // для визначення AM / PM у 12-годинному форматі
    // Перевірка, чи використовується перехід на літній або зимовий час:
    bool toSummer = false;  // true, щоб перевести на 1 годину вперед
    unsigned short alarmHours = 5;     // година сигналу будильника
    unsigned short alarmMinutes = 15;  // хвилина сигналу будильника
    bool alarmSet = true;  // бульник поставлено

public:
    // Метод для встановлення часу на годиннику за допомогою cin
    void SetTime()
    {
        system("cls");
        cout << "\tАБСТРАГУВАННЯ ДРУГЕ: КУПИТИ Б ЩЕ ОДИН ГОДИННИК\n\n";

        // Запит формату часу
        string formatChoice;
        cout << "Виберіть формат часу (24-годинний - '24', "
            << "12-годинний - '12'): ";
        cin >> formatChoice;

        if (formatChoice == "24") is24HourFormat = true;
        else if (formatChoice == "12") is24HourFormat = false;
        else {
            cout << "\nПомилка: введіть 24 або 12.\n";
            exit(1);
        }

        while (true) {
            cout << "\nВведіть години та хвилини через пробіл: ";
            cin >> hours >> minutes;  // секунди не встановлюємо

            if (cin.fail()) {
                cout << "\nПомилка: неправильний ввід. Годинник зламався!\n";
                exit(1);
            }

            // Коректна перевірка для 12-годинного формату
            if (hours < (is24HourFormat ? 0 : 1) ||
                hours >(is24HourFormat ? 23 : 12)) {
                cout << "\nПомилка: години повинні бути в межах "
                    << (is24HourFormat ? "0-23" : "1-12") << ".\n";
                continue;  // перехід до наступної спроби ввести час
            }

            if (minutes < 0 || minutes >= 60) {
                cout << "\nПомилка: хвилини повинні бути в межах 0-59.\n";
                continue;
            }

            if (!is24HourFormat) {
                char period;
                cout << "\nВкажіть період доби: до полудня (ante meridiem) або"
                    << " після полудня (post meridiem) (A/P) : ";
                cin >> period;

                if (period == 'A' || period == 'a') isAM = true;
                else if (period == 'P' || period == 'p') isAM = false;
                else {
                    cout << "\nПомилка: введіть A або P для AM/PM.\n";
                    continue;
                }
            }

            break;  // вихід з циклу після успішного введення
        }

        cout << "\nНа годиннику виставлено: \n";
        PrintInfo(hours, minutes, 0);
    }


    // Метод налаштування будильника
    void SetAlarm()
    {
        system("cls");

        while (true) {
            cout << "\nВведіть години та хвилини для будильника: ";
            cin >> alarmHours >> alarmMinutes;

            if (cin.fail()) {
                cout << "\nПомилка: неправильний ввід. Годинник зламався!\n";
                exit(1);
            }

            if (alarmHours < (is24HourFormat ? 0 : 1) ||
                alarmHours >(is24HourFormat ? 23 : 12)) {
                cout << "\nПомилка: години повинні бути в межах "
                    << (is24HourFormat ? "0-23" : "1-12") << ".\n";
                continue;
            }

            if (alarmMinutes < 0 || alarmMinutes >= 60) {
                cout << "\nПомилка: хвилини повинні бути в межах 0-59.\n";
                continue;
            }

            if (!is24HourFormat) {
                char period;
                cout << "\nВкажіть період доби: до полудня (ante meridiem) або"
                    << " після полудня (post meridiem) (A/P) : ";
                cin >> period;

                if (period == 'A' || period == 'a') isAM = true;
                else if (period == 'P' || period == 'p') isAM = false;
                else {
                    cout << "\nПомилка: введіть A або P для AM/PM.\n";
                    continue;
                }
            }

            break;
        }

        alarmSet = true;
        cout << "\nБудильник поставлено на: \n";
        PrintInfo(alarmHours, alarmMinutes, 0);
    }


    // Метод, що реалізує перехід на літній/зимовий час
    void MoveHands(bool toSummer)  // виклик з false - на зимовий час
    {
        if (toSummer) {  // в останню неділю березня
            if (is24HourFormat) {
                hours = (hours + 1) % 24;  // нормалізація годин 0-23
            }
            else {
                hours = (hours % 12) + 1;
                // hours % 12 перетворює час у діапазон від 0 до 11
                // (оскільки у 12-год форматі немає значення "0", а є "12")

                if (hours == 13) hours = 1;
                // після 12 години знову буде 1, а не 13 година
            }
            cout << "\n\nПерехід на літній час (+1 година)\n";
        }
        else {  // перехід на справжній час в останню неділю жовтня
            if (is24HourFormat) {
                hours = (hours - 1 + 24) % 24;
                // +24 гарантує, що якщо hours було 0 (опівночі),
                // після віднімання воно не стане -1, а коректно
                // перетвориться на 23 годину.
            }
            else {
                hours = (hours == 1) ? 12 : hours - 1;
            }
            cout << "\n\nПерехід на зимовий час (-1 година)\n";
        }
    }


    // Метод виведення часу за допомогою cout (поточного та конкретного)
    void PrintInfo(short h = -1, short m = -1, short s = -1) const
    {
        // Значення -1 у параметрах h, m, s використовується як ознака
        // того, що параметр не був переданий, тобто слід використати
        // поточні значення часу (hours, minutes, seconds).
        if (h == -1) h = hours;
        if (m == -1) m = minutes;
        if (s == -1) s = seconds;

        // Цей підхід дозволяє викликати функцію PrintInfo()
        // без аргументів, і вона автоматично виведе поточний час.
        // Якщо ж передати конкретні значення h, m, s, то вони будуть
        // використані для виводу замість поточних значень.

        // Форматуємо вивід (факультативно можна приховати курсор)
        // https://en.cppreference.com/w/cpp/io/manip/setw
        cout << "\rКиївський час: "
            << setw(2) << setfill(' ') << h << ":"
            << setw(2) << setfill('0') << m << ":"
            << setw(2) << setfill('0') << s;
        // https://en.cppreference.com/w/cpp/io/manip/setfill
        // Додаємо AM/PM, якщо використовується 12-годинний формат
        if (!is24HourFormat) cout << (isAM ? " AM" : " PM");

        // Додатковий вивід часу будильника
        if (alarmSet) {
            cout << " | Будильник: "
                << setw(2) << setfill(' ') << alarmHours << ":"
                << setw(2) << setfill('0') << alarmMinutes;
            if (!is24HourFormat) cout << (isAM ? " AM" : " PM");
        }

        cout << flush;  // flush гарантує миттєвий вивід змін
        // https://en.cppreference.com/w/cpp/io/manip/flush
    }


    // Метод оновлення часу, зважаючи на принципи 12-годинного часу
    void TickTuck()
    {
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
            if (minutes >= 60) {
                minutes = 0;
                hours++;

                if (!is24HourFormat) {
                    // Якщо годинник у 12-годинному форматі
                    if (hours > 12) hours = 1;  // після 12 йде 1
                    // Зміна періоду AM/PM опівдні та опівночі
                    if (hours == 12) isAM = !isAM;
                }
                else hours %= 24;  // 24-годинний формат: нормалізація
            }
        }

        // Перевірка на час будильника
        if (alarmSet && hours == alarmHours
            && minutes == alarmMinutes && seconds == 0) {
            cout << "\n\n\t* Дзвенить будильник! *" << "\n\n";
            // Генеруємо звуковий сигнал
            Beep(1000, 15000);  // 1000 Гц, тривалість 15 с
        }
    }


    // Метод для імітації годинникового механізму з оновленням щосекунди
    void RunClock()
    {  // існують точніші інструменти для роботи з реальним часом у С++
        system("cls");
        cout << "\t\tAjanta® QUARTZ\n\n";
        while (true) {
            TickTuck();
            PrintInfo();
            Sleep(1000);
        }
    }
};


class Telescope
{
private:
    string brand = "Celestron";
    string model = "PowerSeeker 70 AZ";
    string opticalDesign = "Рефрактор";       // оптична конструкція
    string aperture = "70 мм";                // діаметр об'єктива
    string focalLength = "70 см";             // фокусна відстань
    string mountType = "Азимутальне";         // монтування
    string eyepiece = "20 мм (35x), 1,25\"";  // опис окуляра
    string filter = "Відсутній";  // світлофільтр при великому збільшенні
    bool isAimed = false;         // чи наведено телескоп на об'єкт?
    bool isFocused = false;       // чи виконано фокусування?
    string skyObject = "Місяць";  // небесне тіло

public:
    // Метод для встановлення характеристик телескопа
    void InputTelescopeData()
    {
        system("cls");
        cout << "\tАБСТРАГУВАННЯ ТРЕТЄ: ДАВНО НЕ СПОСТЕРІГАВ ЗОРЯНЕ НЕБО\n\n";

        string input;  // допоміжна змінна для збереження введеного тексту

        cout << "Маєте телескоп? Введіть бренд: ";
        // Натискаємо Enter та насолоджуємося значеннями за замовчуванням!
        getline(cin, input);
        // https://en.cppreference.com/w/cpp/string/basic_string/getline
        if (!input.empty()) brand = input;
        // https://www.geeksforgeeks.org/std-string-empty-in-cpp/

        cout << "Введіть модель телескопа: ";
        // Натискаємо Enter та насолоджуємося значеннями за замовчуванням!
        getline(cin, input);
        if (!input.empty()) model = input;

        cout << "Введіть різновид оптичної конструкції: ";  // або Enter
        getline(cin, input);
        if (!input.empty()) opticalDesign = input;

        cout << "Введіть діаметр об'єктива (зазначте одиницю): ";
        getline(cin, input);
        if (!input.empty()) aperture = input;

        cout << "Введіть фокусну відстань (зазначте одиницю): ";
        getline(cin, input);
        if (!input.empty()) focalLength = input;

        cout << "Введіть тип монтування: ";  // і тут Enter
        getline(cin, input);
        if (!input.empty()) mountType = input;
    }


    // Метод для наведення на астрономічний об'єкт
    void AimAtObject(const string& skyObject)
    {
        isAimed = true;  // телескоп наведений
    }


    // Метод для фокусування
    void FocusTelescope()
    {
        if (isAimed) isFocused = true;  // телескоп сфокусований
    }


    // Метод для заміни окуляра
    void ChangeEyepiece(const string& otherEyepiece)
    {
        eyepiece = otherEyepiece;
        isFocused = false;  // потрібно заново сфокусуватися
    }


    // Метод для встановлення світлофільтра
    void SetFilter(const string& newFilter)
    {
        filter = newFilter;
    }


    // Метод для виведення всієї інформації та стану дій
    void PrintInfo(const string& comment) const
    {
        system("cls");
        cout << "\tПрограма - журнал спостережень зоряного неба\n\n";
        cout << "Телескоп: " << brand << " " << model << "\n";
        cout << "Оптична конструкція: " << opticalDesign << "\n";
        cout << "Діаметр об'єктива: " << aperture << "\n";
        cout << "Фокусна відстань: " << focalLength << "\n";
        cout << "Тип монтування: " << mountType << "\n";
        cout << "\nОкуляр: " << eyepiece << "\n";
        cout << "Світлофільтр: " << filter << "\n";
        cout << "\nТелескоп " << (isAimed ? "наведено на " + skyObject + "." :
            "ще не наведено, скористайтесь шукачем!") << "\n";
        cout << "Фокусування " << (isFocused ? "виконано!" :
            "ще не виконано!") << "\n";
        cout << "\n\nКОМЕНТАР: " << comment << "\n";
    }
};


class WaterBottle  // Цей клас я почав писати до аварії на водогоні
{
private:
    string brand = "Моршинська";
    string producer = "Моршинський завод мінеральних вод \"Оскар\"";
    float capacity = 6.0;                   // об'єм бутеля води
    float currentVolume = capacity;         // поточний рівень води
    string expirationDate = "02.11.25";     // кінцева дата споживання
    string mineralization = "0,1-0,4 г/л";  // мінералізація води
    string material = "Пластик";
    bool isExpired = false;      // Чи термін споживання закінчився?
    bool isOpened = false;       // Чи відкритий бутель?
    bool isBeingPoured = false;  // Чи наливається вода?
    bool isWiped = false;        // Чи бутель був протертий серветкою?

public:
    // Метод для введення характеристик бутеля
    void InputBottleData()
    {
        system("cls");
        cout << "\tАБСТРАГУВАННЯ ЧЕТВЕРТЕ: НЕМАЄ ВОДИ\n\n";

        string input;

        cout << "Введіть відомий бренд: ";  // Послідовно натискаємо Enter
        getline(cin, input);
        if (!input.empty()) brand = input;

        cout << "Введіть завод-виробник: "; // Просто натискаємо Enter
        getline(cin, input);
        if (!input.empty()) producer = input;

        cout << "Введіть об'єм бутеля: ";
        cin >> capacity;  // тут треба ввести '6'
        if (cin.fail()) exit(1);
        cin.ignore();  // очищуємо залишковий символ нового рядка

        cout << "Введіть кінцеву дату споживання у форматі ЧЧ.ММ.РР: ";
        getline(cin, input);
        if (!input.empty()) expirationDate = input;

        cout << "Визначте рівень мінералізації води: ";
        getline(cin, input);
        if (!input.empty()) mineralization = input;

        cout << "Зазначте матеріал бутеля: ";
        getline(cin, input);
        if (!input.empty()) material = input;
    }


    // Метод для перевірки терміну придатності
    void CheckExpiration()
    {
        // Отримуємо поточний час у секундах з 1970-01-01 (epoch time)
        time_t now = time(nullptr);
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/time-time32-time64?view=msvc-170
        // Перетворюємо часовий штамп у локальний час
        struct tm localTime;
        localtime_s(&localTime, &now);
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170

        // Доступ до компонентів дати - поточні день, місяць, рік:
        int todayDay = localTime.tm_mday;
        int todayMonth = localTime.tm_mon + 1; // tm_mon починається з 0
        int todayYear = localTime.tm_year + 1900; // відлік з 1900

        // Перетворюємо кінцеву дату споживання, використовуючи метод для 
        // отримання підрядка та функцію для перетворення рядка на число
        int day = stoi(expirationDate.substr(0, 2));
        int month = stoi(expirationDate.substr(3, 2));
        int year = stoi(expirationDate.substr(6, 2)) + 2000;

        // Оновлюємо булеву змінну "прострочено"
        isExpired = year < todayYear ||
            (year == todayYear && month < todayMonth) ||
            (year == todayYear && month == todayMonth && day < todayDay + 2);
    }


    // Метод для відкривання бутеля
    void OpenBottle()
    {
        if (!isExpired) isOpened = true;
    }


    // Метод для закриття бутеля
    void CloseBottle()
    {
        isBeingPoured = false;
        isOpened = false;
    }


    // Метод для наливання води (по 3 л за раз)
    void PourWater()
    {
        if (isOpened && currentVolume >= 3)
        {
            isBeingPoured = true;
            currentVolume -= 3;
        }
        else
        {
            isBeingPoured = false;
            cout << "Води більше немає!" << "\n";
        }
    }


    // Метод для протирання бутеля серветкою
    void WipeBottle()
    {
        isWiped = true;
    }


    // Метод для виведення інформації про бутель
    void PrintInfo(const string& comment) const
    {
        system("cls");
        cout << "\tСТАН БУТЕЛЯ ВОДИ\n\n";
        cout << "Бренд води для щоденного вживання: " << brand << "\n";
        cout << "Виробник: " << producer << "\n";
        cout << "Об'єм: " << capacity << "\n";
        cout << "Вжити до: " << expirationDate << "\n";
        cout << "Мінералізація води: " << mineralization << "\n";
        cout << "Матеріал бутеля: " << material << "\n";
        cout << "\nБутель " << (isWiped ? "протертий вологою серветкою!" :
            "ще не протертий") << "\n";
        cout << (isExpired ? "Термін споживання закінчився!" :
            "Термін споживання ще не закінчився") << "\n";
        cout << "Бутель " << (isOpened ? "відкритий!" : "закритий") << "\n";
        cout << "Поточний рівень води: " << currentVolume << " л\n";
        cout << (isBeingPoured ? "Наливаємо воду!" : "") << "\n";
        cout << "\nКОМЕНТАР: " << comment << "\n";
    }
};


class Car  // Штудіювання книги "Пришвидшений курс PYTHON" 28.10.2023
{
private:
    string make = "Mercedes-Benz";     // марка автомобіля
    string model = "S-Class";          // модель
    unsigned short year = 2025;        // рік випуску
    unsigned int odometerReading = 0;  // пробіг за одометром
    float fuelLevel = 57;              // рівень пального

public:
    // Метод для введення даних автомобіля від користувача
    void InputCarData()
    {
        system("cls");
        cout << "\tАБСТРАГУВАННЯ П'ЯТЕ, ПОВНЕ\n\n";

        string input;

        cout << "Enter car make: ";
        getline(cin, input);
        if (!input.empty()) make = input;

        cout << "Enter car model: ";
        getline(cin, input);
        if (!input.empty()) model = input;

        cout << "Enter car year: ";
        cin >> year;
        if (cin.fail()) exit(1);

        cout << "Enter odometer reading: ";
        cin >> odometerReading;
        if (cin.fail()) exit(1);
        if (odometerReading < 0) {
            cout << "You can't roll back an odometer!" << "\n";
            odometerReading = 0;
        }

        cout << "Enter fuel level (liters): ";
        cin >> fuelLevel;
        if (cin.fail()) exit(1);
        if (fuelLevel < 0) {
            cout << "Fuel level cannot be negative!" << "\n";
            fuelLevel = 0;
        }
    }


    // Метод для виведення інформації про автомобіль
    void PrintInfo() const
    {
        cout << "\nCar Information: " << year << " " << make << " "
            << model << "\n";
        cout << "Odometer Reading: " << odometerReading << " miles" << "\n";
        cout << "Fuel Level: " << fuelLevel << " liters" << "\n";
    }


    // Метод для оновлення одометра (не дозволяє зменшувати пробіг)
    void UpdateOdometer(int mileage)
    {
        if (mileage >= odometerReading) {
            odometerReading = mileage;   // оновлення пробігу
        }
        else {
            cout << "You can't roll back an odometer!" << "\n";
        }
    }


    // Метод для збільшення пробігу (не дозволяє від'ємне значення)
    void IncrementOdometer(int miles)
    {
        if (miles > 0) {
            odometerReading += miles;  // збільшення пробігу
        }
        else {
            cout << "You can't roll back an odometer!" << "\n";
        }
    }


    // Метод для заправки паливного бака
    void FillGasTank(float liters)
    {
        if (liters > 0) {
            fuelLevel += liters;
            cout << "Filled gas tank with " << liters << " liters." << "\n";
        }
        else {
            cout << "You must add a positive amount of fuel!" << "\n";
        }
    }
};


int main() {
    srand(static_cast<unsigned>(time(nullptr)));  // srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Chandelier lustra;
    lustra.InstallChandelier();
    lustra.SwitchOnChandelier(); lustra.PrintInfo(); Sleep(5000);
    lustra.SwitchOffLeftLamps(); lustra.PrintInfo(); Sleep(2000);
    lustra.SwitchOnLeftLamps(); lustra.PrintInfo(); Sleep(3000);
    lustra.SwitchOffChandelier(); lustra.PrintInfo(); Sleep(4000);
    lustra.SwitchOnRightLamps(); lustra.PrintInfo(); Sleep(2000);
    lustra.SwitchOffRightLamps(); lustra.PrintInfo(); Sleep(4000);
    lustra.TransmitLightSignals();

    AlarmClock myNewAlarmClock;
    myNewAlarmClock.SetTime(); Sleep(10000);
    myNewAlarmClock.SetAlarm(); Sleep(10000);
    myNewAlarmClock.MoveHands(true); Sleep(10000);
    myNewAlarmClock.MoveHands(false); Sleep(10000);
    myNewAlarmClock.PrintInfo();
    myNewAlarmClock.RunClock(); Sleep(120000);

    Telescope myTelescope;
    myTelescope.InputTelescopeData();
    myTelescope.PrintInfo("Підготовка телескопа"); Sleep(20000);
    myTelescope.AimAtObject("Місяць");
    myTelescope.PrintInfo("Захоплення в поле зору"); Sleep(20000);
    myTelescope.FocusTelescope();
    myTelescope.PrintInfo("Спостереження з малим збільшенням"); Sleep(20000);
    myTelescope.ChangeEyepiece("4 мм (175х), 1,25\"");
    myTelescope.SetFilter("Місячний фільтр");
    myTelescope.PrintInfo("Установлення аксесуарів"); Sleep(20000);
    myTelescope.FocusTelescope();
    myTelescope.PrintInfo("Спостереження з великим збільшенням"); Sleep(30000);

    WaterBottle oneBottle;
    oneBottle.InputBottleData();
    oneBottle.PrintInfo("Стоїть бутель"); Sleep(10000);
    oneBottle.CheckExpiration();
    oneBottle.PrintInfo("Перевіримо дату"); Sleep(10000);
    oneBottle.WipeBottle();
    oneBottle.PrintInfo("Треба протерти від пилу"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("Відкриваємо бутель"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("Наливаємо 3 л"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("Закриваємо кришкою"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("Відкриваємо бутель"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("Наливаємо 3 л"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("Закриваємо кришкою"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("Відкриваємо бутель"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("А бутель спорожнів"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("Закриваємо кришкою"); Sleep(30000);

    Car myDreamCar;
    myDreamCar.InputCarData();
    myDreamCar.PrintInfo();
    myDreamCar.UpdateOdometer(1000);
    myDreamCar.PrintInfo();;
    myDreamCar.IncrementOdometer(400);
    myDreamCar.FillGasTank(10);
    myDreamCar.PrintInfo();

    return 0;
}