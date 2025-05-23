# 513-і, Золотухін Андрій, Лабораторна 11
# 5. При додаванні у свою БД даних отриманих у вигляді XML-файлів перевірити на наявність таких даних у своєї базі. Якщо дані існують – не додавати їх.
'''
Уся логіка попередньої перевірки даних на те, чи є вони в бд, покладена на саму бд, замість а використовуємо б.
Реалізовувати логіку перевірки кодом python все одно б вимагало попереднього вивантаження даних, що може бути зроблено великою кількістю SELECT запитів, а це не зменшить навантаження на БД. Тому, щоб не навантажувати БД Select і далі Insert, вся логіка перевірки і завантаження реалізовується на самій бд з використанням Insert
'''

import xmlschema
import xmltodict

xsd = 'Laba-9_DB_Movies_XSD.xsd'
xml = 'Laba-9_DB_Movies.xml'

# Створюємо об'єкт схеми XSD
schema = xmlschema.XMLSchema(xsd)

# Перевіряємо, чи відповідає XML файл схемі XSD
validator = schema.is_valid(xml)

if validator:
    print(f"XML-файл '{xml}' відповідає схемі '{xsd}' - ТАК")

    def cast_value(value, xsd_type):
        """Перетворення значення згідно з типом з XSD"""
        if xsd_type is None:
            return f"'{value}'"
        if xsd_type.name == 'boolean':
            return True if value.lower() in ['true', '1'] else False
        if xsd_type.name in ['integer', 'int', 'decimal', 'float', 'double']:
            return value  # Числа не обгортаємо в лапки
        return f"'{value}'"  # Для string та інших

    # Рекурсивна функція для обробки структури XML
    def qqq(item, pre_type=None, path="MovieDatabase"):
        if isinstance(item, dict):
            for key, value in item.items():
                full_path = f"{path}/{key}"
                qqq(value, key, full_path)
        elif isinstance(item, list):
            for i in item:
                if isinstance(i, dict):
                    columns = []
                    values = []

                    for col_name, col_value in i.items():
                        element_path = f"{path}/{col_name}"
                        xsd_element = schema.find(element_path)
                        xsd_type = xsd_element.type if xsd_element else None
                        columns.append(f"'{col_name}'")
                        values.append(cast_value(col_value, xsd_type))

                    sql = f"REPLACE INTO {pre_type} ({', '.join(columns)}) VALUES ({', '.join(values)});"
                    print(sql)
                else:
                    print(f"Невідомий елемент списку: {i}")
        else:
            print(f"Невідомий тип: {type(item).__name__}")

    # Зчитуємо XML-файл і перетворюємо в словник
    with open(xml, 'r', encoding='utf-8') as file:
        data = xmltodict.parse(file.read())

    # Запускаємо обробку з кореня структури XML
    qqq(data['MovieDatabase'])

else:
    print(f"XML-файл '{xml}' НЕ відповідає схемі '{xsd}' - НІ")