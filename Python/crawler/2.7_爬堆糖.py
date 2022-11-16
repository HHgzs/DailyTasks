import requests
from bs4 import BeautifulSoup
import time

keyword = input("Enter your keyword : ")
main_url = "https://www.duitang.com"
url = f"https://www.duitang.com/search/?kw={keyword}&type=feed"
resp = requests.get(url)

main_page = BeautifulSoup(resp.text, "html.parser")
a_list = main_page.find_all("a", class_="a")
for i in a_list:
    href = i.get('href')
    # img_name = href.split("=")[-1]
    second_page_resp = requests.get(main_url + href)
    second_page_text = second_page_resp.text
    second_page = BeautifulSoup(second_page_text, "html.parser")
    div_img = second_page.find("div", id="content")
    a2 = div_img.find("a", class_="img-out")
    img = a2.find("img")
    src = img.get("src")
    img_resp = requests.get(src)
    img_name = src.split("/")[-1]
    with open("crawler/Files/img_2" + img_name, 'wb') as f:
        f.write(img_resp.content)
    print("over", img_name)
    time.sleep(1)
resp.close()
print("over_all")
