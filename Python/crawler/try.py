# # �����ó���ģ�������������һ����ַ���Ӹ���ַ�л�ȡ����Դ��������
# from urllib.request import urlopen
# # ȷ��Ҫ��ȡ��ַ��·��
# url = "http://www.baidu.com"
# # ������ַ�õ���Ӧ
# resp = urlopen(url)
# # ��õ�����
# # decode ����Ϊ�˽���,��utf-8����ʽ����
# # print(resp.read().decode("utf-8"))
# with open("mybaidu.html", mode="w", encoding="utf-8") as f:
#     f.write(resp.read().decode("utf-8"))  # ����Ӧ�ж�ȡ��ҳ��Դ����
# print("ok")
