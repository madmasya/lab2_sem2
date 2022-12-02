if __name__ == '__main__':
    import json
    import urllib.request

    headers = {
        'Content-Type': 'application/json',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 11_4) AppleWebKit/605.1.15 '
                      '(KHTML, like Gecko) Version/14.1.1 Safari/605.1.15',
        'Origin': 'https://yandex.ru',
        'Referer': 'https://yandex.ru/',
    }

    API_URL = 'https://zeapi.yandex.net/lab/api/yalm/text3'
    payload = {"query": "Геральт встретил Лютика", "intro": 0, "filter": 1}
    params = json.dumps(payload).encode('utf8')
    req = urllib.request.Request(API_URL, data=params, headers=headers)
    response = urllib.request.urlopen(req)
    file = open("text.txt", "w")
    text = response.read()
    text = text.decode("unicode_escape")
    cnt = 0
    text1 = ''
    for i in range(len(text)):
        if text[i] == '"':
            cnt = cnt + 1
        if (cnt == 5) & (text[i] != '"'):
            text1 = text1 + text[i]
        if (cnt == 9) & (text[i] != '"'):
            text1 = text1 + text[i]
    file.write(text1)
    file.close()
