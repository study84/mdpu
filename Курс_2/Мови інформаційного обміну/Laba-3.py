import xml.etree.ElementTree as ET


try:
    dom = ET.parse('Laba-3_Books.xml').getroot()
except ET.ParseError as e:
    print("Помилка парсингу XML:", e)
    exit()
except FileNotFoundError:
    print("Файл не знайдено")
    exit()

gitem = dom.tag, dom[0].tag

unique_tags = set()

for d in dom.findall(gitem[1]):
    for child in d:
        unique_tags.add(child.tag)
else:
    print(gitem, unique_tags)
    string = '\t'.join([f'{{:<{20}}}'] * len(unique_tags))
    #print(string)
    for d in dom:
        item = [d.find(tag).text for tag in unique_tags]
        print(string.format(*item))







