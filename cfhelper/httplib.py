__author__ = 'mac'
import urllib.request
import re

invalid_escape = re.compile(r'\\x([0-9]|[a-f]){1,3}')  # up to 3 digits for byte values up to FF

def replace_with_byte(match):
    return chr(int(match.group(0)[2:], 16))

def repair(brokenjson):
    return invalid_escape.sub(replace_with_byte, brokenjson)

def get(url, params = {}):
    if url[-1] != '?':
        url += '?'
    for key, value in params.items():
        url += str(key) + '=' + str(value) + '&'
    url = url[:len(url)-1]
    #print(url)
    response = urllib.request.urlopen(url)
    ans = str(response.read())
    ans = repair(ans[2:len(ans)-1])
    response.close()
    return ans