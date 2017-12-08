import urllib.request
import http.client
from bs4 import BeautifulSoup
from time import sleep

quote_page = 'http://192.168.4.1/'

while(1):
	try: page = urllib.request.urlopen(quote_page, timeout = 1)
	except urllib.error.URLError as e:
		print(e.reason)
		continue
	except urllib.error.HTTPError as e:
		continue
	soup = BeautifulSoup(page, 'html.parser')
	text = soup.get_text()
	if text == 'old':
		print(text)
	else:
		print("new")

	sleep(.5)
