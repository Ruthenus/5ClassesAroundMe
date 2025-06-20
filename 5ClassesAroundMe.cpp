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
        if (cin.fail()) exit(1);
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


    // Методи встановлення значень приватних полів

    Chandelier& SetStyle(string style)
    {
        if (style.empty()) throw string("Бажано визначити стиль люстри!");
        this->style = style;
        return *this;
    }

    Chandelier& SetLampPower(unsigned short lampPower)
    {
        lampPower = abs(lampPower);
        if (lampPower == 0 || lampPower > 60)
            throw string("Раджу лампи розжарювання потужністю 40 або 60 Вт!");
        this->lampPower = lampPower;
        return *this;
    }

    Chandelier& SetTotalCups(unsigned short totalCups)
    {
        totalCups = abs(totalCups);
        if (totalCups == 0)
            throw string("Люстра повинна мати хоча б одну чашечку!");
        this->totalCups = totalCups;
        return *this;
    }

    Chandelier& SetRightSideLamps(unsigned short rightSideLamps)
    {
        rightSideLamps = abs(rightSideLamps);
        if (rightSideLamps > totalCups / 2 + (totalCups % 2))
            throw string("Занадто багато ламп з правого боку люстри!");
        this->rightSideLamps = rightSideLamps;
        return *this;
    }

    Chandelier& SetLeftSideLamps(unsigned short leftSideLamps)
    {
        leftSideLamps = abs(leftSideLamps);
        if (leftSideLamps > totalCups / 2)
            throw string("Занадто багато ламп з лівого боку люстри!");
        this->leftSideLamps = leftSideLamps;
        return *this;
    }

    Chandelier& SetRightSideChandelierOn(bool rightSideChandelierOn)
    {
        this->rightSideChandelierOn = rightSideChandelierOn;
        return *this;
    }

    Chandelier& SetLeftSideChandelierOn(bool leftSideChandelierOn)
    {
        this->leftSideChandelierOn = leftSideChandelierOn;
        return *this;
    }


    // Методи одержання значень приватних полів

    string GetStyle() const { return style; }

    unsigned short GetLampPower() const { return lampPower; }

    unsigned short GetTotalCups() const { return totalCups; }

    unsigned short GetRightSideLamps() const { return rightSideLamps; }

    unsigned short GetLeftSideLamps() const { return leftSideLamps; }

    bool GetRightSideChandelierOn() const { return rightSideChandelierOn; }

    bool GetLeftSideChandelierOn() const { return leftSideChandelierOn; }

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
    // bool toSummer = false;  // true, щоб перевести на 1 годину вперед
    unsigned short alarmHours = 5;     // година сигналу будильника
    unsigned short alarmMinutes = 15;  // хвилина сигналу будильника
    bool alarmIsAM = false;  // ранковий чи вечірній час пробудження
    bool alarmSet = true;    // будильник поставлено

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

                if (period == 'A' || period == 'a') alarmIsAM = true;
                else if (period == 'P' || period == 'p') alarmIsAM = false;
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


    // Метод, що реалізує перехід на літній/зимовий час.
    // Можна було б перевантажити метод: з параметром
    // або без параметра, використовуючи змінну класу.
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

                // Перехід AM/PM або навпаки, якщо нова година — 12
                if (hours == 12) isAM = !isAM;
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
                // Зсув назад
                if (hours == 1) {
                    hours = 12;
                    isAM = !isAM;  // Перехід на іншу половину доби
                }
                else {
                    hours--;
                    if (hours == 11) isAM = !isAM;
                }
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
            if (!is24HourFormat) cout << (alarmIsAM ? " AM" : " PM");
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

                if (!is24HourFormat) { // годинник у 12-годинному форматі
                    // Зміна періоду AM/PM опівдні та опівночі
                    if (hours == 12) isAM = !isAM;
                    if (hours > 12) hours = 1;  // після 12 йде 1
                }
                else hours %= 24;  // 24-годинний формат: нормалізація
            }
        }

        // Перевірка на час будильника
        if (alarmSet && hours == alarmHours &&
            minutes == alarmMinutes && seconds == 0 &&
            (is24HourFormat || !is24HourFormat && isAM == alarmIsAM)) {
            cout << "\n\n\t* Дзвенить будильник! *" << "\n\n";
            // Генеруємо звуковий сигнал
            Beep(1000, 2000);  // 1000 Гц, тривалість 2 с
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


    // Методи встановлення значень приватних полів

    AlarmClock& SetHours(unsigned short hours)
    {
        if (this->is24HourFormat && (hours >= 0 && hours <= 23) ||
            !(this->is24HourFormat) && (hours >= 1 && hours <= 12))
            this->hours = hours;
        else throw string("Невірне значення годин!");
        return *this;
    }

    AlarmClock& SetMinutes(unsigned short minutes)
    {
        if (minutes >= 0 && minutes < 60) this->minutes = minutes;
        else throw string("Невірне значення хвилин!");
        return *this;
    }

    AlarmClock& SetSeconds(unsigned short seconds = 0)
    {
        if (seconds >= 0 && seconds < 60) this->seconds = seconds;
        else throw string("Невірне значення секунд!");
        return *this;
    }

    AlarmClock& Set24HourFormat(bool is24HourFormat)
    {
        this->is24HourFormat = is24HourFormat;
        if (this->is24HourFormat) {
            this->isAM = true;
            this->alarmIsAM = true;
        }
        else {
            // Нормалізація для 12-годинного формату
            if (this->hours == 0) this->hours = 12;
            else if (this->hours > 12) this->hours = this->hours % 12;
            if (this->alarmHours == 0) this->alarmHours = 12;
            else if (this->alarmHours > 12)
                this->alarmHours = this->alarmHours % 12;
        }
        return *this;
    }

    AlarmClock& SetAM(bool isAM)
    {
        if (!this->is24HourFormat) this->isAM = isAM;
        else
            throw string("Неможливо встановити AM/PM у 24-годинному форматі!");
        return *this;
    }

    AlarmClock& SetAlarmHours(unsigned short alarmHours)
    {
        if (this->is24HourFormat && (alarmHours >= 0 && alarmHours <= 23) ||
            !(this->is24HourFormat) && (alarmHours >= 1 && alarmHours <= 12))
            this->alarmHours = alarmHours;
        else throw string("Невірне значення годин будильника!");
        return *this;
    }

    AlarmClock& SetAlarmMinutes(unsigned short alarmMinutes)
    {
        if (alarmMinutes >= 0 && alarmMinutes < 60)
            this->alarmMinutes = alarmMinutes;
        else throw string("Невірне значення хвилин будильника!");
        return *this;
    }

    AlarmClock& SetAlarmActive(bool alarmSet)
    {
        this->alarmSet = alarmSet;
        return *this;
    }

    AlarmClock& SetAlarmAM(bool alarmIsAM)
    {
        if (!this->is24HourFormat) this->alarmIsAM = alarmIsAM;
        else
            throw string("Неможливо встановити AM/PM у 24-годинному форматі!");
        return *this;
    }


    // Методи одержання значень приватних полів

    unsigned short GetHours() const { return hours; }

    unsigned short GetMinutes() const { return minutes; }

    unsigned short GetSeconds() const { return seconds; }

    bool Get24HourFormat() const { return is24HourFormat; }

    bool GetIsAM() const { return isAM; }

    unsigned short GetAlarmHours() const { return alarmHours; }

    unsigned short GetAlarmMinutes() const { return alarmMinutes; }

    bool GetAlarmActive() const { return alarmSet; }

    bool GetAlarmIsAM() const { return alarmIsAM; }

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


    // Методи встановлення значень приватних полів

    void SetBrand(const string& brand)
    {
        if (brand.empty()) throw string("Бажано зазначити бренд телескопа!");
        this->brand = brand;
    }

    void SetModel(const string& model)
    {
        if (model.empty()) throw string("Бажано зазначити модель телескопа!");
        this->model = model;
    }

    void SetOpticalDesign(const string& opticalDesign)
    {
        if (opticalDesign.empty()) throw string("Рефрактор чи рефлектор?..");
        this->opticalDesign = opticalDesign;
    }

    void SetAperture(const string& aperture)
    {
        if (aperture.empty())
            throw string("Будь ласка, вкажіть діаметр об'єктива в міліметрах");
        this->aperture = aperture;
    }

    void SetFocalLength(const string& focalLength)
    {
        if (focalLength.empty())
            throw string("Будь ласка, вкажіть фокусну відстань телескопа "
                "в міліметрах, сантиметрах, метрах!..");
        this->focalLength = focalLength;
    }

    void SetMountType(const string& mountType)
    {
        if (mountType.empty())
            throw string("Монтування азимутальне, екваторіальне, Добсона, "
                "виделкове, екваторіально-азимутальне?..");
        this->mountType = mountType;
    }

    void SetEyepiece(const string& eyepiece)
    {
        if (eyepiece.empty()) throw string("Спробуйте з комплектним окуляром");
        this->eyepiece = eyepiece;
    }

    void SetterFilter(const string& filter)
    {
        if (filter.empty())
            throw string("Передивіться свій новий набір світлофільтрів.");
        this->filter = filter;
    }

    void SetIsAimed(bool isAimed = true)
    {
        this->isAimed = isAimed;
    }

    void SetIsFocused(bool isFocused = true)
    {
        this->isFocused = isFocused;
    }

    void SetSkyObject(const string& skyObject)
    {
        if ((skyObject == "Сонце" || skyObject == "The Sun" ||
            skyObject == "Sun") && (this->filter != "Сонячний"))
            throw string("Ніколи не дивіться на Сонце без спеціального "
                "сонячного світлофільтра — це дуже небезпечно!"
                " Найкраще — використовуйте метод проєкції на екран.");
        this->skyObject = skyObject;
    }


    // Методи одержання значень приватних полів

    string GetBrand() const { return brand; }

    string GetModel() const { return model; }

    string GetOpticalDesign() const { return opticalDesign; }

    string GetAperture() const { return aperture; }

    string GetFocalLength() const { return focalLength; }

    string GetMountType() const { return mountType; }

    string GetEyepiece() const { return eyepiece; }

    string GetFilter() const { return filter; }

    bool GetIsAimed() const { return isAimed; }

    bool GetIsFocused() const { return isFocused; }

    string GetSkyObject() const { return skyObject; }

};


class WaterBottle  // Цей клас я почав писати до аварії на водогоні
{
private:
    string brand = "Моршинська";
    string producer = "Моршинський завод мінеральних вод \"Оскар\"";
    float capacity = 6.0f;                  // об'єм бутеля води
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
        if (isOpened && currentVolume >= 3.0)
        {
            isBeingPoured = true;
            currentVolume -= 3.0;
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


    // Методи встановлення значень приватних полів

    void SetBrand(const string& brand)
    {
        if (!brand.empty()) this->brand = brand;
    }

    void SetProducer(const string& producer)
    {
        if (!producer.empty()) this->producer = producer;
    }

    void SetCapacity(float capacity)
    {
        if (capacity < 1.0 || capacity > 25.0)
            throw string("Об'єм бутеля має бути в межах 1 - 25 літрів!");
        this->capacity = capacity;
        if (this->currentVolume > this->capacity)
            this->currentVolume = this->capacity;
    }

    void SetCurrentVolume(float currentVolume)
    {
        if (currentVolume < 0 || currentVolume > this->capacity)
            throw string("Поточний об'єм води в літрах має бути в межах "
                "від 0 до максимальної ємності бутеля!");
        this->currentVolume = currentVolume;
    }

    void SetExpirationDate(const string& expirationDate)
    {
        if (expirationDate.length() != 8 || expirationDate[2] != '.' ||
            expirationDate[5] != '.')
            throw string("Дата має бути вказана щонайменше у форматі"
                " ДД.ММ.РР та проходити повну валідацію!");
        this->expirationDate = expirationDate;
    }

    void SetMineralization(const string& mineralization)
    {
        if (!mineralization.empty()) this->mineralization = mineralization;
    }

    void SetMaterial(const string& material)
    {
        if (material != "Пластик" && material != "пластик" &&
            material != "Скло" && material != "скло" &&
            material != "Нержавіюча сталь" && material != "нержавіюча сталь" &&
            material != "Харчовий пластик" && material != "харчовий пластик")
            throw string("Виберіть придатний матеріал для зберігання води!");
        this->material = material;
    }

    void SetIsExpired(bool isExpired = true)
    {
        this->isExpired = isExpired;
    }

    void SetIsOpened(bool isOpened = true)
    {
        this->isOpened = isOpened;
    }

    void SetIsBeingPoured(bool isBeingPoured = true)
    {
        this->isBeingPoured = isBeingPoured;
    }

    void SetIsWiped(bool isWiped = true)
    {
        this->isWiped = isWiped;
    }


    // Методи одержання значень приватних полів

    string GetBrand() const { return brand; }

    string GetProducer() const { return producer; }

    float GetCapacity() const { return capacity; }

    float GetCurrentVolume() const { return currentVolume; }

    string GetExpirationDate() const { return expirationDate; }

    string GetMineralization() const { return mineralization; }

    string GetMaterial() const { return material; }

    bool GetIsExpired() const { return isExpired; }

    bool GetIsOpened() const { return isOpened; }

    bool GetIsBeingPoured() const { return isBeingPoured; }

    bool GetIsWiped() const { return isWiped; }

};


class Car  // Штудіювання книги "Пришвидшений курс PYTHON" 28.10.2023
{
private:
    string make = "Mercedes-Benz";     // марка автомобіля
    string model = "S-Class";          // модель
    unsigned short year = 2025;        // рік випуску
    unsigned int odometerReading = 0;  // пробіг за одометром
    float fuelLevel = 57.0f;              // рівень пального

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


    // Прості методи встановлення значень приватних полів

    void setMake(const string& m)
    {
        make = m;
    }

    void setModel(const string& mod)
    {
        model = mod;
    }

    void setYear(unsigned short y)
    {
        year = y;
    }

    void setOdometerReading(unsigned int odo)
    {
        odometerReading = odo;
    }

    void setFuelLevel(float f)
    {
        fuelLevel = f;
    }


    // Методи одержання значень приватних полів

    string GetMake() const { return make; }

    string GetModel() const { return model; }

    unsigned short GetYear() const { return year; }

    unsigned int GetOdometer() const { return odometerReading; }

    float GetFuelLevel() const { return fuelLevel; }

};


class GetterShowCaseTask
{
public:

    static void DisplayChandelierFields(const Chandelier* chandelier)
    {  // VCR003 Функцию 'DisplayChandelierFields' можно сделать статической

        if (!chandelier) {
            cout << "Об'єкт Chandelier не знайдено за вказаною адресою!\n";
            return;
        }

        cout << "\n\n\n\t==== Chandelier Object State ====\n\n";
        cout << "class Chandelier\n";
        cout << "{\n";
        cout << "private:\n";
        cout << "\tstring style = \"" << chandelier->GetStyle() << "\";\n";
        cout << "\tunsigned short lampPower = "
            << chandelier->GetLampPower() << ";\n";
        cout << "\tunsigned short totalCups = "
            << chandelier->GetTotalCups() << ";\n";
        cout << "\tunsigned short rightSideLamps = "
            << chandelier->GetRightSideLamps() << ";\n";
        cout << "\tunsigned short leftSideLamps = "
            << chandelier->GetLeftSideLamps() << ";\n";
        cout << "\tbool rightSideChandelierOn = "
            << (chandelier->GetRightSideChandelierOn() ? "true" : "false")
            << ";\n";
        cout << "\tbool leftSideChandelierOn = "
            << (chandelier->GetLeftSideChandelierOn() ? "true" : "false")
            << ";\n";
    }


    static void DisplayAlarmClockFields(const AlarmClock* alarmClock)
    {
        if (!alarmClock) {
            cout << "Об'єкт AlarmClock не знайдено за вказаною адресою!\n";
            return;
        }

        cout << "\n\n\n\t==== AlarmClock Object State ====\n\n";
        cout << "class AlarmClock\n";
        cout << "{\n";
        cout << "private:\n";
        cout << "\tunsigned short hours = " << alarmClock->GetHours() << ";\n";
        cout << "\tunsigned short minutes = "
            << alarmClock->GetMinutes() << ";\n";
        cout << "\tunsigned short seconds = "
            << alarmClock->GetSeconds() << ";\n";
        cout << "\tbool is24HourFormat = "
            << (alarmClock->Get24HourFormat() ? "true" : "false") << ";\n";
        cout << "\tbool isAM = "
            << (alarmClock->GetIsAM() ? "true" : "false") << ";\n";
        cout << "\tunsigned short alarmHours = "
            << alarmClock->GetAlarmHours() << ";\n";
        cout << "\tunsigned short alarmMinutes = "
            << alarmClock->GetAlarmMinutes() << ";\n";
        cout << "\tbool alarmIsAm = "
            << (alarmClock->GetAlarmIsAM() ? "true" : "false") << ";\n";
        cout << "\tbool alarmSet = "
            << (alarmClock->GetAlarmActive() ? "true" : "false") << ";\n";
    }


    static void DisplayTelescopeFields(const Telescope* telescope)
    {
        if (!telescope) {
            cout << "Об'єкт Telescope не знайдено за вказаною адресою!\n";
            return;
        }

        cout << "\n\n\n\t==== Telescope Object State ====\n\n";
        cout << "class Telescope\n";
        cout << "{\n";
        cout << "private:\n";
        cout << "\tstring brand = \"" << telescope->GetBrand() << "\";\n";
        cout << "\tstring model = \"" << telescope->GetModel() << "\";\n";
        cout << "\tstring opticalDesign = \""
            << telescope->GetOpticalDesign() << "\";\n";
        cout << "\tstring aperture = \""
            << telescope->GetAperture() << "\";\n";
        cout << "\tstring focalLength = \""
            << telescope->GetFocalLength() << "\";\n";
        cout << "\tstring mountType = \""
            << telescope->GetMountType() << "\";\n";
        cout << "\tstring eyepiece = \""
            << telescope->GetEyepiece() << "\";\n";
        cout << "\tstring filter = \"" << telescope->GetFilter() << "\";\n";
        cout << "\tbool isAimed = "
            << (telescope->GetIsAimed() ? "true" : "false") << ";\n";
        cout << "\tbool isFocused = "
            << (telescope->GetIsFocused() ? "true" : "false") << ";\n";
        cout << "\tstring skyObject = \""
            << telescope->GetSkyObject() << "\";\n";
    }


    static void DisplayWaterBottleFields(const WaterBottle* waterbottle)
    {
        if (!waterbottle) {
            cout << "Об'єкт WaterBottle не знайдено за вказаною адресою!\n";
            return;
        }

        cout << "\n\n\n\t==== WaterBottle Object State ====\n\n";
        cout << "class WaterBottle\n";
        cout << "{\n";
        cout << "private:\n";
        cout << "\tstring brand = \"" << waterbottle->GetBrand() << "\";\n";
        cout << "\tstring producer = \""
            << waterbottle->GetProducer() << "\";\n";
        cout << "\tfloat capacity = " << waterbottle->GetCapacity() << ";\n";
        cout << "\tfloat currentVolume = "
            << waterbottle->GetCurrentVolume() << ";\n";
        cout << "\tstring expirationDate = \""
            << waterbottle->GetExpirationDate() << "\";\n";
        cout << "\tstring mineralization = \""
            << waterbottle->GetMineralization() << "\";\n";
        cout << "\tstring material = \""
            << waterbottle->GetMaterial() << "\";\n";
        cout << "\tbool isExpired = "
            << (waterbottle->GetIsExpired() ? "true" : "false") << ";\n";
        cout << "\tbool isOpened = "
            << (waterbottle->GetIsOpened() ? "true" : "false") << ";\n";
        cout << "\tbool isBeingPoured = "
            << (waterbottle->GetIsBeingPoured() ? "true" : "false") << ";\n";
        cout << "\tbool isWiped = "
            << (waterbottle->GetIsWiped() ? "true" : "false") << ";\n";
    }


    static void DisplayCarFields(const Car* car)
    {
        if (!car) {
            cout << "Об'єкт Car не знайдено за вказаною адресою!\n";
            return;
        }

        cout << "\n\n\n\t==== Car Object State ====\n\n";
        cout << "class Car\n";
        cout << "{\n";
        cout << "private:\n";
        cout << "\tstring make = \"" << car->GetMake() << "\";\n";
        cout << "\tstring model = \"" << car->GetModel() << "\";\n";
        cout << "\tunsigned short year = " << car->GetYear() << ";\n";
        cout << "\tunsigned int odometerReading = "
            << car->GetOdometer() << ";\n";
        cout << "\tfloat fuelLevel = " << car->GetFuelLevel() << ";\n";
    }
};


int main()
{
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

    Chandelier lustra2;
    try {
        lustra2.SetLampPower(60).SetStyle("Модерн").SetTotalCups(9).
            SetRightSideLamps(4).SetRightSideChandelierOn(false).
            SetLeftSideLamps(3).SetLeftSideChandelierOn(false);
        GetterShowCaseTask::DisplayChandelierFields(&lustra2); Sleep(5000);

        lustra2.SwitchOnChandelier(); lustra2.PrintInfo();
        GetterShowCaseTask::DisplayChandelierFields(&lustra2); Sleep(10000);

        lustra2.SwitchOffLeftLamps(); lustra2.PrintInfo();
        GetterShowCaseTask::DisplayChandelierFields(&lustra2); Sleep(4000);

        lustra2.SwitchOnLeftLamps(); lustra2.PrintInfo();
        GetterShowCaseTask::DisplayChandelierFields(&lustra2); Sleep(6000);

        lustra2.SwitchOffChandelier(); lustra2.PrintInfo();
        GetterShowCaseTask::DisplayChandelierFields(&lustra2); Sleep(8000);

        lustra2.SwitchOnRightLamps(); lustra2.PrintInfo();
        GetterShowCaseTask::DisplayChandelierFields(&lustra2); Sleep(4000);

        lustra2.SwitchOffRightLamps(); lustra2.PrintInfo();
        GetterShowCaseTask::DisplayChandelierFields(&lustra2); Sleep(8000);
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    AlarmClock myNewAlarmClock;
    myNewAlarmClock.SetTime(); Sleep(10000);
    myNewAlarmClock.SetAlarm(); Sleep(10000);
    myNewAlarmClock.MoveHands(true); Sleep(10000);
    myNewAlarmClock.MoveHands(false); Sleep(10000);
    myNewAlarmClock.PrintInfo();
    myNewAlarmClock.RunClock(); Sleep(120000);

    AlarmClock anotherAlarmClock;
    try {
        anotherAlarmClock.Set24HourFormat(false).
            SetHours(10).SetMinutes(35).SetSeconds().
            SetAlarmActive(true).SetAlarmHours(10).SetAlarmMinutes(38).
            SetAM(false).SetAlarmAM(false);
        GetterShowCaseTask::DisplayAlarmClockFields(&anotherAlarmClock);
        Sleep(10000);

        anotherAlarmClock.SetAlarmActive(false).MoveHands(false);
        GetterShowCaseTask::DisplayAlarmClockFields(&anotherAlarmClock);
        Sleep(10000);

        anotherAlarmClock.SetAlarmActive(true).MoveHands(true);
        GetterShowCaseTask::DisplayAlarmClockFields(&anotherAlarmClock);
        Sleep(10000);

        anotherAlarmClock.Set24HourFormat(true).
            SetHours(23).SetMinutes(21).SetSeconds(29).
            SetAlarmHours(23).SetAlarmMinutes(23);
        system("cls");
        anotherAlarmClock.PrintInfo();
        anotherAlarmClock.RunClock(); Sleep(120000);
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

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

    Telescope newTelescope;
    try {
        GetterShowCaseTask::DisplayTelescopeFields(&newTelescope);
        Sleep(15000);
        system("cls");

        newTelescope.SetBrand("Celestron");
        newTelescope.SetModel("AstroMaster 130");
        newTelescope.SetOpticalDesign("Рефлектор Ньютона");
        newTelescope.SetAperture("130 мм");
        newTelescope.SetFocalLength("750 мм");
        newTelescope.SetMountType("Екваторіальне з автостеженням");
        newTelescope.SetEyepiece("Стандартний окуляр 10 мм");
        newTelescope.SetterFilter("Світло-жовтий");
        newTelescope.SetIsAimed();
        newTelescope.SetIsFocused();
        newTelescope.SetSkyObject("Місяць біля Сатурна, Нептуна, Урана і "
            "Плеяд");
        newTelescope.PrintInfo("");
        GetterShowCaseTask::DisplayTelescopeFields(&newTelescope);
        Sleep(15000);
        system("cls");

        newTelescope.SetIsAimed(false);
        newTelescope.SetIsFocused(false);
        newTelescope.SetFilter("Сонячний");
        newTelescope.SetSkyObject("Сонце");
        newTelescope.FocusTelescope();
        newTelescope.PrintInfo("DANGER");
        GetterShowCaseTask::DisplayTelescopeFields(&newTelescope);
        Sleep(30000);
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

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

    WaterBottle anotherBottle;
    try {
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(15000);
        system("cls");

        anotherBottle.SetBrand("AquaLife");
        anotherBottle.SetProducer("Миргородський завод мінеральних вод");
        anotherBottle.SetCapacity(5.0f);
        anotherBottle.SetCurrentVolume(5.0f);
        anotherBottle.SetExpirationDate("05.06.26");
        anotherBottle.SetMineralization("300-500 мг/л");
        anotherBottle.SetMaterial("Харчовий пластик");
        anotherBottle.SetIsExpired(false);
        anotherBottle.SetIsOpened(false);
        anotherBottle.SetIsBeingPoured(false);
        anotherBottle.SetIsWiped(false);
        anotherBottle.PrintInfo("Принесли з магазину");
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(20000);
        system("cls");

        anotherBottle.CheckExpiration();
        anotherBottle.WipeBottle();
        anotherBottle.PrintInfo("Ще раз перевірили дату, протремо");
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(20000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    Car myDreamCar;
    myDreamCar.InputCarData();
    myDreamCar.PrintInfo();
    myDreamCar.UpdateOdometer(1000);
    myDreamCar.PrintInfo();
    myDreamCar.IncrementOdometer(400);
    myDreamCar.FillGasTank(10);
    myDreamCar.PrintInfo();

    Car myGirlfriendCar;
    GetterShowCaseTask::DisplayCarFields(&myGirlfriendCar);

    return 0;
}