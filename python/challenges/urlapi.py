
import urllib.request
import json

def query(title, url):
    titles = list()
    repetitions = 1
    while repetitions > 0:
        call = "{0}".format(url).replace("substr", title)
        contents = urllib.request.urlopen(call).read()
        query_response = json.loads(contents)
        print(query_response)
        for item in query_response["data"]:
            titles.append(item["Title"])

    

if __name__ == "__main__":
    title = "spiderman"
    url = "https://jsonmock.hackerrank.com/api/movies/search/?Title=substr"
    query(title, url)
