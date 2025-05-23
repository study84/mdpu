# 513-і, Золотухін Андрій, Лабораторна 10
# 4. У своєму проекті розробити модуль вивантаження даних у форматі XML використовуючи XSD-шаблон.

import xml.etree.ElementTree as ET
import xmlschema
import csv

# Шляхи до файлів
xsd_path = "Laba-9_DB_Movies_XSD.xsd"
output_xml_path = "Laba-10_DB_Movies.xml"
csv_files = {
    'Actors': 'Laba-10_Actor.csv',
    'Directors': 'Laba-10_Director.csv',
    'Studios': 'Laba-10_Studio.csv',
    'Ratings': 'Laba-10_Rating.csv',
    'Movies': 'Laba-10_Movie.csv'
}

# Завантаження даних з CSV у словник
data = {}
for section, path in csv_files.items():
    with open(path, newline='', encoding='utf-8') as csvfile:
        reader = csv.DictReader(csvfile)
        data[section] = list(reader)

# Створення кореневого XML-елемента
root = ET.Element("MovieDatabase")

# Побудова XML-структури згідно з даними
for section, records in data.items():
    section_elem = ET.SubElement(root, section)
    singular = section[:-1] if section.endswith('s') else section
    for record in records:
        item_elem = ET.SubElement(section_elem, singular[:-1] if singular.endswith('s') else singular)
        for key, value in record.items():
            sub_elem = ET.SubElement(item_elem, key)
            sub_elem.text = value

# Збереження XML у файл
tree = ET.ElementTree(root)
tree.write(output_xml_path, encoding="utf-8", xml_declaration=True)

# Перевірка відповідності XSD
try:
    schema = xmlschema.XMLSchema(xsd_path)
    if schema.is_valid(output_xml_path):
        print(f"XML успішно збережено та відповідає схемі XSD: {output_xml_path}")
    else:
        print("XML збережено, але не відповідає XSD.")
except Exception as e:
    print(f"Не вдалося перевірити XSD: {e}")
