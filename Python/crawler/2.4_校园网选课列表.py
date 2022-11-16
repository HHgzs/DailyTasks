import requests
import re
import csv

url = "http://classes.tju.edu.cn/eams/practice/election/practice-std-elect-course!search.action"

headers = {
    'User-Agent':
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.42",
    'Cookie':
    "semester.id=76; JSESSIONID=3628BFFF8D3BE3B1D98602731C52BAE8.std5; "
    "Hm_lvt_0eac3f7954950aa62e0d5e0919956fec=1660370227,1660960446,1661145129,1661147649; GSESSIONID=3628BFFF8D3BE3B1D98602731C52BAE8.std5; UqZBpD3n3iXPAw1X=v1gyM9JVmUlVO; JSESSIONID=4839B542EFAE1ABA0E5D8DCCA80896ED.std5"
}
resp = requests.get(url, headers=headers)

page_content = resp.text
# print(page_content)

obj = re.compile(
    r'<td class="gridselect">.*?<td>(?P<task_code>.*?)</td>'
    r'<td>(?P<course_code>.*?)</td>.*?title.*?">(?P<name>.*?)'
    r'</a>.*?<td>(?P<type>.*?)</td><td>(?P<hours>.*?)</td><td>(?P<credits>.*?)</td>', re.S  # 匹配换行
)

result = obj.finditer(page_content)
with open("crawler/Files/选修课列表.csv", mode="w", encoding='utf-8') as f:
    csvwriter = csv.writer(f)
    for it in result:
        # print(it.group("task_code"))
        # print(it.group("course_code"))
        # print(it.group("name"))

        # 将内容转入字典
        dic = it.groupdict()
        csvwriter.writerow(dic.values())
    f.close()
resp.close()
print("over")
