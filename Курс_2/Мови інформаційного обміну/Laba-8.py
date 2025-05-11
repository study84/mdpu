# 513-і, Золотухин Андрій, Лабораторна № 8, варіант 2: опис фільмів відеотеки

import json
import pprint
import os
from prettytable import PrettyTable as pt


def get_unique_keys_nested(d):
    result = {}

    if isinstance(d, dict):
        for key, value in d.items():
            if isinstance(value, dict):
                result[key] = get_unique_keys_nested(value)
            elif isinstance(value, list):
                result[key] = [get_unique_keys_nested(item) if isinstance(item, dict) else None for item in value]
            else:
                result[key] = None

    return result


def read_json_file(file_path):
    if not os.path.exists(file_path):
        print(f"Ошибка: файл '{file_path}' не найден.")
        return None
    if os.path.getsize(file_path) == 0:
        print(f"Ошибка: файл '{file_path}' пустой.")
        return None
    try:
        with open(file_path, 'r') as file:
            return json.load(file)
    except json.JSONDecodeError:
        print("Ошибка: не удалось декодировать JSON из файла.")
        return None



file_path = r'./Laba-8.json'

data = read_json_file(file_path)

unique_keys_nested = get_unique_keys_nested(data)

#pprint.pprint(unique_keys_nested)

####################



table = pt()
table.field_names = ["Original Title", "Ukrainian Title", "Year", "Country", "Production Company", "Director", "Budget", "Box Office"]
for movie in data["movies"]:
    table.add_row([movie["original_title"], movie["ukrainian_title"], movie["year"], movie["country"], movie["production_company"], movie["director"], movie["budget"], movie["box_office"]])

print(table)
