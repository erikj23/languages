
import os
import requests

req=requests.get('http://127.0.0.1/')
os.system(req.text)

